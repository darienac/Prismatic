//
// Created by dacma on 3/29/2024.
//

#ifndef CS455GAME_GAMERENDERER_H
#define CS455GAME_GAMERENDERER_H


#include "../game/GameState.h"
#include "Camera.h"
#include "shader/Shader3D.h"
#include "../screens/AbstractScreenUtils.h"

class GameRenderer {
private:
    static const float CAMERA_DIST;

    GameState* state;
    Shader3D* shader3D;
    Shader2D* shader2D;
    AbstractScreenUtils* utils;
    Camera camera;

    void updateCamera();
    void drawTile(const GameData::GameTile& tile, uint8_t colorChannel);
public:
    GameRenderer(GameState* state, AbstractScreenUtils* utils);

    void drawScene();
};


#endif //CS455GAME_GAMERENDERER_H
