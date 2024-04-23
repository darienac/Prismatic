#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <sstream>
#include <algorithm>
#include <forward_list>
#include <optional>
#include <charconv>
#include <format>
#include <chrono>
#include <filesystem>
#include "glm/glm.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <stb_vorbis.c>

#include "GlWindow.h"
#include "screens/ScreenManager.h"
#include "screens/ScreenUtils.h"

int main() {
    /* TODO:
     * Add a cool space background
     * Add raytrace checks for circular shadows so they don't pass beneath upper platforms (per color channel)
     * Make buttons always show in all 3 color channels
     * Fix weird crash when closing the game
     * Fix screen tearing when using the graphics card
     * Add an end screen
     * Fix issue with multi-sampled images (works fine on a graphics card)
     * Make goal more animated
     * Experiment with spherical scrolling
     * Prevent button spamming */
    if (!glfwInit()) {
        std::cerr << "GLFW init failed" << std::endl;
    }
    glfwSetErrorCallback([](int error, const char* description) {
        std::cerr << "Error: " << description << std::endl;
    });

    GlWindow window("CS455 Game", 512, 384);
    ScreenUtils options(&window);
    ScreenManager manager(&options);
    options.setManager(&manager);
    manager.run();

    // Exit
    glfwSetErrorCallback(nullptr);
    glfwTerminate();
    return 0;
}
