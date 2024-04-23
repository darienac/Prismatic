//
// Created by dacma on 2/21/2024.
//

#include <iostream>
#include "AbstractScreenUtils.h"
#include "../game/GameDataCache.h"
#include "../GlobalFlags.h"

void AbstractScreenUtils::init() {
    // All shaders, models, etc go in this object, abstract has everything except the manager object
    testShader = new TestShader("vTest.glsl", "fTest.glsl");
    testShader->link();
    sceneShader = new Shader3D("v3D.glsl", "f3D.glsl");
    sceneShader->link();
    shader2D = new Shader2D("v2D.glsl", "f2D.glsl");
    shader2D->link();
    envShader = new ShaderEnv("vEnv.glsl", "fEnv.glsl");
    envShader->link();
    spaceEnv = new Texture("space.jpg");

    controls = new Controls(getWindow());

    tileModels[GameData::GameTileName::PLAT] = new Model("platform4x4.obj");
    tileModels[GameData::GameTileName::BUTTON] = new Model("button_red_outlined.obj");
    tileModels[GameData::GameTileName::PLAYER] = new Model("character.obj");
    tileModels[GameData::GameTileName::GOAL] = new Model("goal.obj");
    tileModels[GameData::GameTileName::WALL_X] = new Model("wall4x16.obj");
    tileModels[GameData::GameTileName::WALL_Z] = tileModels[GameData::GameTileName::WALL_X];
    tileModels[GameData::GameTileName::BUTTON_PRESSED] = new Model("button_red_outlined_pressed.obj");

    for (uint8_t i = 0; i < 3; i++) {
        colorTextures[i] = new Texture(getWindow()->getWidth(), getWindow()->getHeight(), GL_RED, GL_RED, false);
        colorBuffers[i] = new GlFramebuffer({colorTextures[i]}, !GlobalFlags::USE_MULTISAMPLING);
        if (GlobalFlags::USE_MULTISAMPLING) {
            colorTexturesMS[i] = new Texture(getWindow()->getWidth(), getWindow()->getHeight(), GL_RED, GL_RED, true);
            colorBuffersMS[i] = new GlFramebuffer({colorTexturesMS[i]}, true);
        }
    }

    basicEnv = {
            .lightPos = {100000.0f, 100000.0f, 100000.0f},
            .lightColor = {1.0f, 1.0f, 1.0f},
            .ambientLightColor = {0.5f, 0.5f, 0.5f}
    };
}

AbstractScreenUtils::~AbstractScreenUtils() {
    delete testShader;
    delete sceneShader;
    delete envShader;
    delete shader2D;
    delete spaceEnv;

    delete controls;
    delete screenBuffer;

    for (auto &buffer : colorBuffers) {
        delete buffer;
    }

    for (auto &texture : colorTextures) {
        delete texture;
    }

    for (auto &buffer : colorBuffersMS) {
        delete buffer;
    }

    for (auto &texture : colorTexturesMS) {
        delete texture;
    }

    for (auto & tileModel : tileModels) {
        delete tileModel;
    }
}
