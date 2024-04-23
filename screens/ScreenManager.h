//
// Created by dacma on 2/20/2024.
//

#ifndef CS455GAME_SCREENMANAGER_H
#define CS455GAME_SCREENMANAGER_H


#include "../GlWindow.h"
#include "AbstractScreenUtils.h"
#include "IScreen.h"
#include "TestScreen.h"

class ScreenManager {
private:
    static const double TICK_RATE;

    AbstractScreenUtils* utils;
    GlWindow* window;
    int fps;
    int frameNum;
    int tickNum;

    IScreen* screen;
    TestScreen* testScreen;
public:
    ScreenManager(AbstractScreenUtils *utils);

    void run();
    void tick();
    void setScreen(AbstractScreenUtils::ScreenName screenName);

    ~ScreenManager();
};


#endif //CS455GAME_SCREENMANAGER_H
