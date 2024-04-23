//
// Created by dacma on 3/31/2024.
//

#ifndef CS455GAME_GAMEENGINE_H
#define CS455GAME_GAMEENGINE_H


#include <iostream>
#include "GameState.h"
#include "../Controls.h"

class GameEngine {
private:
    static const float EPSILON;
    static const uint8_t MAX_JUMP_FRAMES;
    static const float CAMERA_BOUND;

    struct CollisionProps {
        glm::vec3 push = {0.0f, 0.0f, 0.0f};
        GameData::GameTile* tileBelow = nullptr;
    };

    GameState* state;
    Controls* controls;

    bool tileCollidesComp(GameData::GameTile &agent, GameData::GameTile &tile, uint8_t comp, float &pushBack, float &pushForward);
    bool tileCollides(GameData::GameTile &agent, GameData::GameTile &tile);
    bool tilesCollideComp(GameData::LevelLayout &level, GameData::GameTile &agent, std::vector<GameData::GameTile> &tiles, uint8_t comp, float &pushBack, float &pushForward, GameData::GameTile*& tileBack, GameData::GameTile*& tileForward);
    void pushTileWithCollision(GameData::LevelLayout &level, GameData::GameTile &agent, std::vector<GameData::GameTile> &tiles, glm::vec3 &push, CollisionProps& collision);
    void prepColorAnimation();
    void updateColorButtons();

    void moveCamera();
    void movePlayer();
    void runAnimations();
public:
    GameEngine(GameState* state, Controls* controls);

    void tick();
    void setLevel(unsigned int level);
};


#endif //CS455GAME_GAMEENGINE_H
