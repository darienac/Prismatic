//
// Created by dacma on 4/9/2024.
//

#include "../GameDataCache.h"

const GameData::LevelLayout GameDataCache::winLevel = {
        .levelNum = 0,
        .tiles = {
                {
                        .pos = {0.0f, 0.0f, 0.0f}
                },
                {
                        .pos = {4.0f, 0.0f, 0.0f}
                },
                {
                        .pos = {-4.0f, 0.0f, 0.0f}
                },
                {
                        .pos = {0.0f, 0.0f, 4.0f}
                },
                {
                        .pos = {4.0f, 0.0f, 4.0f}
                },
                {
                        .pos = {-4.0f, 0.0f, 4.0f}
                },
                {
                        .pos = {0.0f, 0.0f, -4.0f}
                },
                {
                        .pos = {4.0f, 0.0f, -4.0f}
                },
                {
                        .pos = {-4.0f, 0.0f, -4.0f}
                }
        },
        .player = {
                .tileName = GameData::PLAYER,
                .modelTransform = glm::mat4(1.0f),
                .pos = {0.0f, 0.501f, 0.0f},
                .facing = {0.0f, 0.0f, -1.0f}
        },
        .goal = {
                .tileName = GameData::GOAL,
                .pos = {0.0f, 8.0f, -50.0f},
                .color = {false, false, false}
        }
};