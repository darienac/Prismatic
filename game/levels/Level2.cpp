//
// Created by dacma on 4/6/2024.
//

#include "../GameDataCache.h"
#include "glm/ext/matrix_transform.hpp"

const GameData::LevelLayout GameDataCache::level2 = {
    .levelNum = 1,
    .tiles = {
            {
                    .pos = {0.0f, 0.0f, 0.0f},
                    .color = {true, false, false}
            },
            {
                    .pos = {0.0f, -4.0f, 0.0f}
            },
            {
                    .tileName = GameData::BUTTON,
                    .pos = {0.0f, -4.0f, 0.0f},
                    .specialProps = {.button = {.color = {false, true, false}}}
            },
            {
                    .pos = {4.0f, 0.0f, 0.0f},
                    .color = {true, false, false}
            },
            {
                    .pos = {-4.0f, 0.0f, 0.0f},
                    .color = {true, false, false}
            },
            {
                    .pos = {0.0f, 0.0f, 4.0f},
                    .color = {true, false, false}
            },
            {
                    .pos = {4.0f, 0.0f, 4.0f},
                    .color = {false, true, false}
            },
            {
                    .pos = {-4.0f, 0.0f, 4.0f},
                    .color = {false, true, false}
            },
            {
                    .pos = {0.0f, 0.0f, -4.0f},
                    .color = {true, false, false}
            },
            {
                    .pos = {4.0f, 0.0f, -4.0f},
                    .color = {false, true, false}
            },
            {
                    .pos = {-4.0f, 0.0f, -4.0f},
                    .color = {false, true, false}
            },
            {
                    .pos = {8.0f, 0.0f, 0.0f},
                    .color = {true, false, false}
            },
            {
                    .pos = {12.0f, 0.0f, 0.0f},
                    .color = {false, true, false}
            },
            {
                    .pos = {16.0f, 0.0f, 0.0f},
                    .color = {false, false, true}
            },
            {
                    .pos = {20.0f, 0.0f, 0.0f},
                    .color = {true, false, false}
            },
            {
                    .pos = {24.0f, 0.0f, 0.0f},
                    .color = {false, true, false}
            },
            {
                    .pos = {28.0f, 0.0f, 0.0f},
                    .color = {false, false, true}
            },
            {
                    .tileName = GameData::BUTTON,
                    .pos = {32.0f, 0.0f, 0.0f},
                    .specialProps = {.button = {.color = {false, true, true}}}
            },
            {
                    .pos = {32.0f, 0.0f, 0.0f}
            },
            {
                    .pos = {36.0f, 0.0f, 0.0f}
            },
            {
                    .tileName = GameData::WALL_X,
                    .pos = {36.0f, 9.0f, 0.0f},
                    .color = {false, true, false}
            },
            {
                    .tileName = GameData::WALL_X,
                    .pos = {36.0f, 9.0f, 4.0f},
                    .color = {false, true, false}
            },
            {
                    .tileName = GameData::WALL_X,
                    .pos = {36.0f, 9.0f, -4.0f},
                    .color = {false, true, false}
            },
            {
                    .pos = {40.0f, 0.0f, 0.0f}
            },
            {
                    .pos = {-8.0f, 4.0f, 0.0f},
                    .color = {true, true, true}
            },
            {
                    .pos = {-8.0f, 8.0f, 0.0f},
                    .color = {false, false, true}
            },
            {
                    .pos = {-8.0f, 8.0f, 4.0f}
            },
            {
                    .pos = {-8.0f, 8.0f, -4.0f}
            },
            {
                    .pos = {-4.0f, 12.0f, 0.0f}
            },
            {
                    .pos = {0.0f, 12.0f, 0.0f}
            },
            {
                    .tileName = GameData::BUTTON,
                    .pos = {0.0f, 12.0f, 0.0f},
                    .specialProps = {.button = {.color = {false, false, true}}}
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
            .pos = {40.0f, 4.0f, 0.0f},
            .color = {true, true, true}
    }
};