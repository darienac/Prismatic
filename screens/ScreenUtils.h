//
// Created by dacma on 2/21/2024.
//

#ifndef CS455GAME_SCREENUTILS_H
#define CS455GAME_SCREENUTILS_H


#include "AbstractScreenUtils.h"
#include "ScreenManager.h"

class ScreenUtils : public AbstractScreenUtils {
private:
    GlWindow* window;
    GlScreenBuffer screenBuffer;
    ScreenManager* manager;
public:
    ScreenUtils(GlWindow* window);

    void setManager(ScreenManager* manager);

    GlWindow* getWindow() override;
    GlScreenBuffer* getScreenBuffer() override;
    void setScreen(ScreenName screenName) override;
};


#endif //CS455GAME_SCREENUTILS_H
