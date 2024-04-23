//
// Created by dacma on 2/20/2024.
//

#include "ScreenManager.h"
#include "TestScreen.h"
#include "../GlobalFlags.h"

const double ScreenManager::TICK_RATE = 60.0;

ScreenManager::ScreenManager(AbstractScreenUtils *utils) {
    this->utils = utils;
    this->window = utils->getWindow();

    testScreen = new TestScreen(utils);
    screen = testScreen;
}

void ScreenManager::run() {
    double lastTime = glfwGetTime();
    double lastTickTime = lastTime;
    int fpsCounter = 0;
    tickNum = 0;
    fps = 0;
    frameNum = 0;

    while (!screen->shouldClose()) {
        frameNum++;
        double time = glfwGetTime();
        fpsCounter++;
        if (time - lastTime >= 1.0) {
            lastTime++;
            fps = fpsCounter;
            fpsCounter = 0;
            if (GlobalFlags::SHOW_FPS) {
                std::cout << "FPS: " << fps << std::endl;
            }
        }

        if (glfwWindowShouldClose(window->getWindow())) {
            glfwSetWindowShouldClose(window->getWindow(), GLFW_FALSE);
            screen->requestClose();
        }

        if (time - lastTickTime >= (1.0 / TICK_RATE)) {
            int ticks = (time - lastTickTime) * TICK_RATE;
            lastTickTime += ticks / TICK_RATE;
            for (int i = 0; i < ticks; i++) {
                tick();
            }
        }

        if (utils->controls->fullscreenPressed) {
            utils->controls->fullscreenPressed = false;
            if (utils->getWindow()->isFullscreen()) {
                utils->getWindow()->disableFullscreen();
            } else {
                utils->getWindow()->enableFullscreen();
            }
        }
        if (window->isResized()) {
            glViewport(0, 0, window->getWidth(), window->getHeight());
            window->setResized(false);
        }
        screen->renderFrame();

        glFinish();
        glfwSwapBuffers(window->getWindow());
        glfwPollEvents();
    }
}

void ScreenManager::tick() {
    screen->tick();
    utils->controls->jumpPressed = false;
    tickNum++;
}

void ScreenManager::setScreen(AbstractScreenUtils::ScreenName screenName) {
    switch(screenName) {
        case AbstractScreenUtils::TEST:
        default:
            this->screen = nullptr;
            break;
    }
}

ScreenManager::~ScreenManager() {
    delete testScreen;
}
