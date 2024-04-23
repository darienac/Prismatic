//
// Created by dacma on 2/21/2024.
//

#include <iostream>
#include "TestScreen.h"

TestScreen::TestScreen(AbstractScreenUtils *utils): renderer(&state, utils), engine(&state, utils->controls) {
    this->utils = utils;
    engine.setLevel(0);
}

void TestScreen::enable() {

}

void TestScreen::disable() {

}

void TestScreen::renderFrame() {
    renderer.drawScene();
}

void TestScreen::tick() {
    engine.tick();
}

bool TestScreen::shouldClose() {
    return close;
}

void TestScreen::requestClose() {
    close = true;
}

TestScreen::~TestScreen() {
}


