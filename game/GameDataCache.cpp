//
// Created by dacma on 3/28/2024.
//

#include "GameDataCache.h"
#include "glm/ext/matrix_transform.hpp"

const GameData::GameTileProps GameDataCache::tileProps[] = {
        { // PLAT
            .collisionBox = {.corner1={-2.0f,-0.5f,-2.0f},.corner2={2.0f,0.5f,2.0f}}
        },
        { // BUTTON
            .collisionBox = {.corner1={-1.75f,0.5f,-1.75f},.corner2={1.75f,1.0f,1.75f}}
        },
        { // PLAYER
            .renderTransform = glm::scale(glm::mat4(1.0f), {0.155, 0.155, 0.155}), // now 1 unit wide
            .collisionBox = {.corner1={-1.0f, 0.0f, -1.0f}, .corner2={1.0f, 5.4f, 1.0f}}
        },
        { // GOAL
            .collisionBox = {.corner1={-1.5f, -1.5f, -1.5f}, .corner2={1.5f, 1.5f, 1.5f}},
            .collider = false
        },
        { // WALL_Z
            .collisionBox = {.corner1={-2.0f, -8.0f, -0.5f}, .corner2={2.0f, 8.0f, 0.5f}}
        },
        { // WALL_X
            .renderTransform = glm::rotate(glm::mat4(1.0f), glm::pi<float>() / 2, {0.0f, 1.0f, 0.0f}),
            .collisionBox = {.corner1={-0.5f, -8.0f, -2.0f}, .corner2={0.5f, 8.0f, 2.0f}}
        },
        { // BUTTON PRESSED
            .collisionBox = {.corner1={-1.75f,0.5f,-1.75f},.corner2={1.75f,0.8f,1.75f}}
        }
};

const GameData::LevelLayout* GameDataCache::levels[NUM_LEVELS] = {&level1, &level2, &level3, &winLevel};