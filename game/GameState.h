//
// Created by dacma on 3/28/2024.
//

#ifndef CS455GAME_GAMESTATE_H
#define CS455GAME_GAMESTATE_H


#include "GameDataCache.h"

class GameState {
public:
    GameData::LevelLayout currLevel;
    GameData::LevelLayout savedLevelProgress;
    glm::vec3 dirToCamera = glm::normalize(glm::vec3(0.0f, 1.0f, 2.0f));
    glm::vec3 cameraPos = {0.0f, 0.0f, 0.0f};
    glm::vec3 cameraVel = {0.0f, 0.0f, 0.0f};
    bool colorAnim[3] = {true, true, true};
    uint8_t colorAnimFrames = 0;
};


#endif //CS455GAME_GAMESTATE_H
