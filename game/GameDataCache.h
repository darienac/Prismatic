//
// Created by dacma on 3/28/2024.
//

#ifndef CS455GAME_GAMEDATACACHE_H
#define CS455GAME_GAMEDATACACHE_H


#include <vector>
#include "glm/mat4x4.hpp"

namespace GameData {
    struct BoundingBox {
        glm::vec3 corner1;
        glm::vec3 corner2;
    };
    enum GameTileName {
        PLAT,
        BUTTON,
        PLAYER,
        GOAL,
        WALL_Z,
        WALL_X,
        BUTTON_PRESSED
    };
    struct GameTileButtonProps {
        bool color[3];
    };
    union GameTileSpecialProps {
        GameTileButtonProps button;
    };
    struct GameTile {
        GameTileName tileName = GameData::PLAT;
        glm::mat4 modelTransform = glm::mat4(1.0f);
        glm::vec3 pos = {0.0f, 0.0f, 0.0f};
        glm::vec3 facing = {0.0f, 0.0f, -1.0f};
        bool color[3] = {true, true, true};
        GameTileSpecialProps specialProps;
    };
    struct GameTileProps {
        glm::mat4 renderTransform = glm::mat4(1.0f);
        BoundingBox collisionBox = {.corner1={0.0f, 0.0f, 0.0f}, .corner2={0.0f, 0.0f, 0.0f}};
        bool collider = true;
    };
    struct PlayerProps {
        glm::vec3 vel = {0.0f, 0.0f, 0.0f};
        uint8_t framesJumping = 0;
    };
    struct LevelLayout {
        unsigned int levelNum = 0;
        std::vector<GameTile> tiles;
        GameTile playerRespawn;
        GameTile player;
        PlayerProps playerProps;
        GameTile goal;
        bool color[3] = {true, true, true};
    };
};

class GameDataCache {
public:
    static const unsigned int NUM_TILES = 7;
    static const unsigned int NUM_LEVELS = 4;
    static const uint8_t COLOR_TRANSITION_FRAMES = 80;
    static const GameData::GameTileProps tileProps[NUM_TILES];
    static const GameData::LevelLayout level1;
    static const GameData::LevelLayout level2;
    static const GameData::LevelLayout level3;
    static const GameData::LevelLayout winLevel;
    static const GameData::LevelLayout* levels[NUM_LEVELS];
};


#endif //CS455GAME_GAMEDATACACHE_H
