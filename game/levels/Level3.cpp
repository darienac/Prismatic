//
// Created by dacma on 4/6/2024.
//

#include "../GameDataCache.h"

const GameData::LevelLayout GameDataCache::level3 = {
        .levelNum = 2,
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
                    .pos = {8.0f, 0.0f, -4.0f}
                },
                {
                        .pos = {8.0f, 0.0f, 0.0f}
                },
                {
                        .pos = {8.0f, 0.0f, 4.0f}
                },
                {
                        .pos = {12.0f, 0.0f, -4.0f}
                },
                {
                        .pos = {12.0f, 0.0f, 0.0f}
                },
                {
                        .pos = {12.0f, 0.0f, 4.0f}
                },
                {
                        .pos = {16.0f, 0.0f, -4.0f}
                },
                {
                        .pos = {16.0f, 0.0f, 0.0f}
                },
                {
                        .pos = {16.0f, 0.0f, 4.0f}
                },
                {
                        .pos = {20.0f, 0.0f, -4.0f}
                },
                {
                        .pos = {20.0f, 0.0f, 0.0f}
                },
                {
                        .pos = {20.0f, 0.0f, 4.0f}
                },
                {
                        .pos = {24.0f, 0.0f, -4.0f}
                },
                {
                        .pos = {24.0f, 0.0f, 0.0f}
                },
                {
                        .pos = {24.0f, 0.0f, 4.0f}
                },
                {
                        .pos = {28.0f, 0.0f, -4.0f}
                },
                {
                        .pos = {28.0f, 0.0f, 0.0f}
                },
                {
                        .pos = {28.0f, 0.0f, 4.0f}
                },
                {
                        .pos = {32.0f, 0.0f, -4.0f}
                },
                {
                        .pos = {32.0f, 0.0f, 0.0f}
                },
                {
                        .pos = {32.0f, 0.0f, 4.0f}
                },
                {
                        .pos = {36.0f, 0.0f, -4.0f}
                },
                {
                        .pos = {36.0f, 0.0f, 0.0f}
                },
                {
                        .pos = {36.0f, 0.0f, 4.0f}
                },
                {
                        .pos = {40.0f, 0.0f, -4.0f}
                },
                {
                        .pos = {40.0f, 0.0f, 0.0f}
                },
                {
                        .pos = {40.0f, 0.0f, 4.0f}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {8.0f, 0.0f, 0.0f},
                        .specialProps = {.button = {.color = {false, false, false}}}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {16.0f, 0.0f, 0.0f},
                        .specialProps = {.button = {.color = {false, false, false}}}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {16.0f, 0.0f, -4.0f},
                        .specialProps = {.button = {.color = {false, false, false}}}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {20.0f, 0.0f, -4.0f},
                        .specialProps = {.button = {.color = {false, false, false}}}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {20.0f, 0.0f, 4.0f},
                        .specialProps = {.button = {.color = {false, false, false}}}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {24.0f, 0.0f, 4.0f},
                        .specialProps = {.button = {.color = {false, false, false}}}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {24.0f, 0.0f, 0.0f},
                        .specialProps = {.button = {.color = {false, false, false}}}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {28.0f, 0.0f, 4.0f},
                        .specialProps = {.button = {.color = {false, false, false}}}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {28.0f, 0.0f, 0.0f},
                        .specialProps = {.button = {.color = {false, false, false}}}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {32.0f, 0.0f, -4.0f},
                        .specialProps = {.button = {.color = {false, false, false}}}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {32.0f, 0.0f, 0.0f},
                        .specialProps = {.button = {.color = {false, false, false}}}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {36.0f, 0.0f, -4.0f},
                        .specialProps = {.button = {.color = {false, false, false}}}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {36.0f, 0.0f, 0.0f},
                        .specialProps = {.button = {.color = {false, false, false}}}
                },
                {
                        .tileName = GameData::BUTTON,
                        .pos = {36.0f, 0.0f, 4.0f},
                        .specialProps = {.button = {.color = {false, false, false}}}
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