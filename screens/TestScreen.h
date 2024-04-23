//
// Created by dacma on 2/21/2024.
//

#ifndef CS455GAME_TESTSCREEN_H
#define CS455GAME_TESTSCREEN_H


#include "IScreen.h"
#include "../game/GameState.h"
#include "../render/GameRenderer.h"
#include "../game/GameEngine.h"

class TestScreen : public IScreen {
private:
    bool close = false;
    GameState state;
    GameRenderer renderer;
    GameEngine engine;
public:
    TestScreen(AbstractScreenUtils* utils);

    void enable() override;
    void disable() override;
    void renderFrame() override;
    void tick() override;
    bool shouldClose() override;
    void requestClose() override;

    ~TestScreen() override;
};


#endif //CS455GAME_TESTSCREEN_H
