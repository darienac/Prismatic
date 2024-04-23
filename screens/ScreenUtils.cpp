//
// Created by dacma on 2/21/2024.
//

#include "ScreenUtils.h"

ScreenUtils::ScreenUtils(GlWindow *window): screenBuffer(window->getWindow()) {
    this->window = window;
    this->manager = nullptr;
    init();
}

void ScreenUtils::setManager(ScreenManager *manager) {
    this->manager = manager;
}

GlWindow *ScreenUtils::getWindow() {
    return window;
}

GlScreenBuffer *ScreenUtils::getScreenBuffer() {
    return &screenBuffer;
}

void ScreenUtils::setScreen(AbstractScreenUtils::ScreenName screenName) {
    manager->setScreen(screenName);
}
