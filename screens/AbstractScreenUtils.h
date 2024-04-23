//
// Created by dacma on 2/20/2024.
//

#ifndef CS455GAME_ABSTRACTSCREENUTILS_H
#define CS455GAME_ABSTRACTSCREENUTILS_H


#include "../GlWindow.h"
#include "../render/shader/ShaderProgram.h"
#include "../render/shader/TestShader.h"
#include "../Controls.h"
#include "../render/model/Mesh.h"
#include "../render/shader/Shader3D.h"
#include "../render/model/Model.h"
#include "../game/GameDataCache.h"
#include "../render/Environment.h"
#include "../render/GlFramebuffer.h"
#include "../render/GlScreenBuffer.h"
#include "../render/shader/Shader2D.h"
#include "../render/shader/ShaderEnv.h"

class AbstractScreenUtils {
public:
    enum ScreenName {
        TEST,
        TITLE,
        LEVEL
    };

    TestShader* testShader;
    Shader3D* sceneShader;
    Shader2D* shader2D;
    ShaderEnv* envShader;
    Environment basicEnv;
    Texture* spaceEnv;

    GlScreenBuffer* screenBuffer;
    Texture* colorTexturesMS[3];
    GlFramebuffer* colorBuffersMS[3];
    Texture* colorTextures[3];
    GlFramebuffer* colorBuffers[3];

    Controls* controls;

    Model* tileModels[GameDataCache::NUM_TILES];

    void init();
    virtual GlWindow* getWindow() = 0;
    virtual GlScreenBuffer* getScreenBuffer() = 0;
    virtual void setScreen(ScreenName screen) = 0;

    virtual ~AbstractScreenUtils();
};


#endif //CS455GAME_ABSTRACTSCREENUTILS_H
