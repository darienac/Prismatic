//
// Created by dacma on 3/31/2024.
//

#include "GameEngine.h"
#include "glm/ext/matrix_transform.hpp"

const float GameEngine::EPSILON = 0.001f;
const uint8_t GameEngine::MAX_JUMP_FRAMES = 10;
const float GameEngine::CAMERA_BOUND = 4.0f;

bool GameEngine::tileCollidesComp(GameData::GameTile &agent, GameData::GameTile &tile, uint8_t comp, float &pushBack, float &pushForward) {
    const GameData::BoundingBox *boxA = &GameDataCache::tileProps[agent.tileName].collisionBox;
    const GameData::BoundingBox *boxT = &GameDataCache::tileProps[tile.tileName].collisionBox;

    float a0 = agent.pos[comp] + boxA->corner1[comp];
    float a1 = agent.pos[comp] + boxA->corner2[comp];
    float t0 = tile.pos[comp] + boxT->corner1[comp];
    float t1 = tile.pos[comp] + boxT->corner2[comp];
    pushBack = t0 - a1;
    pushForward = t1 - a0;
    return !(a1 < t0 || a0 > t1);
}

bool GameEngine::tileCollides(GameData::GameTile &agent, GameData::GameTile &tile) {
    float back, forward;
    bool collides = true;
    for (uint8_t i = 0; i < 3; i++) {
        if (!tileCollidesComp(agent, tile, i, back, forward)) {
            collides = false;
            break;
        }
    }
    return collides;
}


bool GameEngine::tilesCollideComp(GameData::LevelLayout &level, GameData::GameTile &agent, std::vector<GameData::GameTile> &tiles, uint8_t comp, float &pushBack, float &pushForward, GameData::GameTile*& tileBack, GameData::GameTile*& tileForward) {
    bool collides = false;
    pushBack = 0.0f;
    pushForward = 0.0f;
    tileBack = nullptr;
    tileForward = nullptr;
    for (auto &tile : tiles) {
        if (!GameDataCache::tileProps[tile.tileName].collider) {
            continue;
        }
        if (!(level.color[0] && tile.color[0]) && !(level.color[1] && tile.color[1]) && !(level.color[2] && tile.color[2])) {
            continue;
        }
        float back, forward;
        if (tileCollides(agent, tile) && tileCollidesComp(agent, tile, comp, back, forward)) {
            if (back < pushBack) {
                pushBack = back;
                tileBack = &tile;
            }
            if (forward > pushForward) {
                pushForward = forward;
                tileForward = &tile;
            }
            collides = true;
        }
    }
    return collides;
}

void GameEngine::pushTileWithCollision(GameData::LevelLayout &level, GameData::GameTile &agent, std::vector<GameData::GameTile> &tiles, glm::vec3 &push, CollisionProps& collision) {
    for (uint8_t i = 0; i < 3; i++) {
        agent.pos[i] += push[i];
        float pushBack, pushForward;
        GameData::GameTile* tileBack;
        GameData::GameTile* tileForward;
        if (tilesCollideComp(level, agent, tiles, i, pushBack, pushForward, tileBack, tileForward)) {
            if (push[i] > 0.0f) {
                agent.pos[i] += pushBack - EPSILON;
                collision.push[i] = pushBack - EPSILON;
            } else if (push[i] < 0.0f) {
                agent.pos[i] += pushForward + EPSILON;
                collision.push[i] = pushForward + EPSILON;
                if (i == 1) {
                    collision.tileBelow = tileForward;
                }
            }
            push[i] = 0.0f;
        }
    }
}

void GameEngine::prepColorAnimation() {
    state->colorAnimFrames = 0;
    state->colorAnim[0] = state->currLevel.color[0];
    state->colorAnim[1] = state->currLevel.color[1];
    state->colorAnim[2] = state->currLevel.color[2];
}

void GameEngine::updateColorButtons() {
    for (GameData::GameTile &tile : state->currLevel.tiles) {
        if (tile.tileName == GameData::BUTTON || tile.tileName == GameData::BUTTON_PRESSED) {
            bool* tileColor = tile.specialProps.button.color;
            bool* stateColor = state->currLevel.color;
            if (tileColor[0] == stateColor[0] && tileColor[1] == stateColor[1] && tileColor[2] == stateColor[2]) {
                tile.tileName = GameData::BUTTON_PRESSED;
            } else {
                tile.tileName = GameData::BUTTON;
            }
        }
    }
}

void GameEngine::movePlayer() {
    if (glm::length(controls->lStick) != 0.0f) {
        glm::vec3 z = state->dirToCamera;
        glm::vec3 x = glm::cross({0.0f, 1.0f, 0.0f}, z);
        x.y = 0.0f;
        z.y = 0.0f;
        x = glm::normalize(x);
        z = glm::normalize(z);
        state->currLevel.player.facing = controls->lStick.x * x + -controls->lStick.y * z;
        state->currLevel.playerProps.vel += glm::length(controls->lStick) * 0.05f * state->currLevel.player.facing;
    }

    state->currLevel.playerProps.vel.y -= 0.1f;
    state->currLevel.playerProps.vel.y *= 0.8f;
    if (glm::length(controls->lStick) == 0.0f) {
        state->currLevel.playerProps.vel.x *= 0.4f;
        state->currLevel.playerProps.vel.z *= 0.4f;
    } else {
        state->currLevel.playerProps.vel.x *= 0.8f;
        state->currLevel.playerProps.vel.z *= 0.8f;
    }

    CollisionProps collision;
    pushTileWithCollision(state->currLevel, state->currLevel.player, state->currLevel.tiles, state->currLevel.playerProps.vel, collision);

    if (collision.push.y > 0.0f && controls->jumpPressed) {
        state->currLevel.playerProps.vel.y = 1.0f;
        state->currLevel.playerProps.framesJumping = 1;
    } else if (state->currLevel.playerProps.framesJumping >= 1 && state->currLevel.playerProps.framesJumping < MAX_JUMP_FRAMES && controls->jumpDown) {
        state->currLevel.playerProps.vel.y = 1.0f;
    }
    if (state->currLevel.playerProps.framesJumping > 0) {
        state->currLevel.playerProps.framesJumping++;
    }
    if (state->currLevel.playerProps.framesJumping == MAX_JUMP_FRAMES || !controls->jumpDown) {
        state->currLevel.playerProps.framesJumping = 0;
    }

    if (collision.tileBelow && collision.tileBelow->tileName == GameData::GameTileName::BUTTON) {
        bool* color = collision.tileBelow->specialProps.button.color;
        if (!(state->currLevel.color[0] == color[0] && state->currLevel.color[1] == color[1] && state->currLevel.color[2] == color[2])) {
            prepColorAnimation();
            state->currLevel.color[0] = color[0];
            state->currLevel.color[1] = color[1];
            state->currLevel.color[2] = color[2];
            updateColorButtons();
        }
    }

    if (state->currLevel.player.pos.y < -10.0f) {
        prepColorAnimation();
        state->currLevel = state->savedLevelProgress;
        updateColorButtons();
    }

    if (tileCollides(state->currLevel.player, state->currLevel.goal)) {
        setLevel(state->currLevel.levelNum+1);
    }
}


void GameEngine::moveCamera() {
    controls->pollGamepadInputs(0);
    if (controls->rStick[0] != 0.0f) {
        state->dirToCamera = glm::rotate(glm::mat4(1.0f), -0.1f * controls->rStick[0], {0.0f, 1.0f, 0.0f}) * glm::vec4(state->dirToCamera, 1.0f);
    }
    glm::vec3 sideVector = glm::normalize(glm::cross({0.0f, 1.0f, 0.0f}, state->dirToCamera));
    if (controls->rStick[1] != 0.0f) {
        state->dirToCamera = glm::rotate(glm::mat4(1.0f), -0.1f * controls->rStick[1], sideVector) * glm::vec4(state->dirToCamera, 1.0f);
        if (state->dirToCamera[1] > 3.0f / std::sqrtf(10.0f)) {
            glm::vec3 newVec = state->dirToCamera;
            newVec[1] = 0.0f;
            newVec = glm::normalize(newVec);
            newVec[1] = 3.0f;
            state->dirToCamera = glm::normalize(newVec);
        }
        if (state->dirToCamera[1] < -3.0f / std::sqrtf(10.0f)) {
            glm::vec3 newVec = state->dirToCamera;
            newVec[1] = 0.0f;
            newVec = glm::normalize(newVec);
            newVec[1] = -3.0f;
            state->dirToCamera = glm::normalize(newVec);
        }
    }
    if (glm::length(controls->lStick) > 0.0f) {
        state->currLevel.player.facing.x = controls->lStick.x;
        state->currLevel.player.facing.z = controls->lStick.y;
    }

    for (uint8_t i = 0; i < 3; i++) {
        if (i == 1 && state->currLevel.playerProps.vel.y != 0.0f) {
            continue;
        }
        if (state->currLevel.player.pos[i] > state->cameraPos[i] + CAMERA_BOUND) {
            state->cameraVel[i] = (state->currLevel.player.pos[i] - state->cameraPos[i]) * 0.01f;
        } else if (state->currLevel.player.pos[i] < state->cameraPos[i] - CAMERA_BOUND) {
            state->cameraVel[i] = (state->currLevel.player.pos[i] - state->cameraPos[i]) * 0.01f;
        }
        state->cameraVel *= 0.98f;
        state->cameraPos += state->cameraVel;
    }
}

GameEngine::GameEngine(GameState *state, Controls *controls): state(state), controls(controls) {

}

void GameEngine::tick() {
    runAnimations();
    moveCamera();
    movePlayer();
}

void GameEngine::setLevel(unsigned int level) {
    prepColorAnimation();
    state->savedLevelProgress = *GameDataCache::levels[level];
    state->currLevel = state->savedLevelProgress;
    updateColorButtons();
}

void GameEngine::runAnimations() {
    bool* colorOld = state->colorAnim;
    bool* colorNew = state->currLevel.color;
    if (colorOld[0] == colorNew[0] && colorOld[1] == colorNew[1] && colorOld[2] == colorNew[2]) {
        return;
    }
    state->colorAnimFrames++;
    if (state->colorAnimFrames == GameDataCache::COLOR_TRANSITION_FRAMES) {
        state->colorAnimFrames = 0;
        colorOld[0] = colorNew[0];
        colorOld[1] = colorNew[1];
        colorOld[2] = colorNew[2];
    }
}