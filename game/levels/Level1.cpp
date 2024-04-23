//
// Created by dacma on 4/6/2024.
//

#include "../GameDataCache.h"
#include "glm/ext/matrix_transform.hpp"

const GameData::LevelLayout GameDataCache::level1 = {
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
                },
                {
                        .tileName=GameData::BUTTON,
                        .pos = {4.0f, 0.0f, 0.0f},
                        .specialProps = {.button = {.color = {true, false, false}}}
                },
                {
                        .tileName=GameData::BUTTON,
                        .pos = {-4.0f, 0.0f, 0.0f},
                        .specialProps = {.button = {.color = {false, true, false}}}
                },
                {
                        .tileName=GameData::BUTTON,
                        .pos = {0.0f, 0.0f, -4.0f},
                        .specialProps = {.button = {.color = {true, true, true}}}
                },
                {
                        .pos = {0.0f, 2.0f, -8.0f}
                },
                {
                        .pos = {-4.0f, 2.0f, -8.0f}
                },
                {
                        .pos = {4.0f, 2.0f, -8.0f}
                },
                {
                        .pos = {0.0f, 4.0f, -12.0f}
                },
                {
                        .pos = {-4.0f, 4.0f, -12.0f}
                },
                {
                        .pos = {4.0f, 4.0f, -12.0f}
                },
                {
                        .pos = {0.0f, 4.0f, -16.0f}
                },
                {
                        .pos = {-4.0f, 4.0f, -16.0f}
                },
                {
                        .pos = {4.0f, 4.0f, -16.0f}
                },
                {
                        .pos = {4.0f, 4.0f, -28.0f},
                        .color = {false, false, true}
                },
                {
                        .pos = {-4.0f, 4.0f, -24.0f},
                        .color = {false, false, true}
                },
                {
                        .pos = {0.0f, 4.0f, -36.0f},
                        .color = {true, true, true}
                },
                {
                        .tileName = GameData::WALL_Z,
                        .pos = {0.0f, 13.0f, -20.0f}
                },
                {
                        .tileName = GameData::WALL_Z,
                        .pos = {4.0f, 13.0f, -20.0f},
                        .color = {true, false, false}
                },
                {
                        .tileName = GameData::WALL_Z,
                        .pos = {-4.0f, 13.0f, -20.0f},
                        .color = {false, true, false}
                },
                {
                        .tileName = GameData::WALL_X,
                        .pos = {8.0f, 5.0f, 4.0f},
                        .color = {false, true, false}
                },
                {
                        .tileName = GameData::WALL_X,
                        .pos = {8.0f, 5.0f, 0.0f},
                        .color = {false, true, false}
                },
                {
                        .tileName = GameData::WALL_X,
                        .pos = {8.0f, 5.0f, 8.0f},
                        .color = {false, true, false}
                },
                {
                        .pos = {12.0f, 0.0f, 4.0f},
                        .color = {true, false, true}
                },
                {
                        .pos = {16.0f, 4.0f, 4.0f},
                        .color = {true, false, true}
                },
                {
                        .pos = {20.0f, 8.0f, 4.0f},
                        .color = {true, false, true}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {20.0f, 8.0f, 4.0f},
                        .specialProps = {.button = {.color = {true, false, true}}}
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
                .pos = {0.0f, 8.0f, -36.0f},
                .color = {true, true, true}
        }
};