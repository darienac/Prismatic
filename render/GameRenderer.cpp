//
// Created by dacma on 3/29/2024.
//

#include "GameRenderer.h"
#include "../GlobalFlags.h"

const glm::mat4 rMat = glm::translate(glm::mat4(1.0f), glm::vec3{0.0015f, -0.0025f, 0.0f});
const glm::mat4 gMat = glm::translate(glm::mat4(1.0f), glm::vec3{-0.0015f, -0.001f, 0.0f});
const glm::mat4 bMat = glm::translate(glm::mat4(1.0f), glm::vec3{-0.0015f, 0.002f, 0.0f});

const float GameRenderer::CAMERA_DIST = 30.0f;

glm::mat4 getTileFacingMatrix(glm::vec3 dir) {
    return glm::inverse(glm::lookAt({0.0f, 0.0f, 0.0f}, dir, {0.0f, 1.0f, 0.0f}));
}

void GameRenderer::updateCamera() {
    camera.setPos(state->cameraPos + CAMERA_DIST * state->dirToCamera);
    camera.setTarget(state->cameraPos);
}

void GameRenderer::drawTile(const GameData::GameTile &tile, uint8_t colorChannel) {
    if (!tile.color[colorChannel]) {
        return;
    }

    const GameData::GameTileProps* props = &GameDataCache::tileProps[tile.tileName];
    switch (tile.tileName) {
        case GameData::BUTTON:
        case GameData::BUTTON_PRESSED:
            glm::vec3 color;
            color.r = tile.specialProps.button.color[0] ? 0.5f : 0.0f;
            color.g = tile.specialProps.button.color[1] ? 0.5f : 0.0f;
            color.b = tile.specialProps.button.color[2] ? 0.5f : 0.0f;
            utils->tileModels[tile.tileName]->getMaterials()[3]->diffuse = color;
            break;
        default:
            break;
    }

    glm::mat4 colorMat;
    if (colorChannel == 0) {
        colorMat = rMat;
    } else if (colorChannel == 1) {
        colorMat = gMat;
    } else {
        colorMat = bMat;
    }

    shader3D->loadCamera(&camera, colorMat, glm::translate(glm::mat4(1.0f), tile.pos) * getTileFacingMatrix(tile.facing) * tile.modelTransform * props->renderTransform);
    shader3D->drawModel(utils->tileModels[tile.tileName]);
}

GameRenderer::GameRenderer(GameState *state, AbstractScreenUtils* utils): state(state), shader3D(utils->sceneShader), shader2D(utils->shader2D), utils(utils), camera(utils->getWindow()) {

}

void GameRenderer::drawScene() {
    if (utils->getWindow()->getWidth() == 0 || utils->getWindow()->getHeight() == 0) {
        return;
    }
    for (uint8_t i = 0; i < 3; i++) {
        utils->colorBuffers[i]->resize(utils->getWindow()->getWidth(), utils->getWindow()->getHeight());
        if (GlobalFlags::USE_MULTISAMPLING) {
            utils->colorBuffersMS[i]->resize(utils->getWindow()->getWidth(), utils->getWindow()->getHeight());
        }
    }

    GameData::LevelLayout* level = &state->currLevel;
    updateCamera();

    for (uint8_t i = 0; i < 3; i++) {
        if (GlobalFlags::USE_MULTISAMPLING) {
            if (!level->color[i] && !state->colorAnim[i]) {
                utils->colorBuffers[i]->bind();
                glClearColor(0.0, 0.0, 0.0, 1.0);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                continue;
            }
            utils->colorBuffersMS[i]->bind();
            glClearColor(0.0, 0.0, 0.0, 1.0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        } else {
            utils->colorBuffers[i]->bind();
            glClearColor(0.0, 0.0, 0.0, 1.0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            if (!level->color[i] && !state->colorAnim[i]) {
                continue;
            }
        }
        shader3D->bind();
        shader3D->loadEnvironment(&utils->basicEnv);
        shader3D->setSceneProps(i, level->player.pos);
        drawTile(level->player, i);
        drawTile(level->goal, i);
        for (const GameData::GameTile& tile : level->tiles) {
            drawTile(tile, i);
        }
        utils->envShader->bind();
        utils->envShader->bindTexture(*utils->spaceEnv);
        utils->envShader->setSceneProps(&utils->basicEnv, i);
        utils->envShader->loadCamera(&camera);
        utils->envShader->draw();
        if (GlobalFlags::USE_MULTISAMPLING) {
            glFlush();
            utils->colorBuffersMS[i]->copyToFramebuffer(utils->colorBuffers[i]);
        }
    }
    glFlush();

    utils->getScreenBuffer()->bind();
    shader2D->bind();
    shader2D->setColorTransitionState(state->colorAnim, state->currLevel.color, state->colorAnimFrames);
    shader2D->loadTextures(utils->colorTextures[0], utils->colorTextures[1], utils->colorTextures[2]);
    shader2D->draw();
}
