cmake_minimum_required(VERSION 3.27)
#cmake_minimum_required(VERSION 3.11)
project(cs455game)


set(CMAKE_CXX_STANDARD 20)

#option(ENABLE_BOOST_WORKAROUND "Enable Boost workaround" ON)

# Find and include Assimp package
find_package(PkgConfig REQUIRED)
find_package(ASSIMP REQUIRED)
#pkg_search_module(ASSIMP REQUIRED assimp)

add_executable(cs455game main.cpp
        GlWindow.cpp
        GlWindow.h
        screens/ScreenManager.cpp
        screens/ScreenManager.h
        screens/IScreen.h
        screens/AbstractScreenUtils.cpp
        screens/AbstractScreenUtils.h
        screens/TestScreen.cpp
        screens/TestScreen.h
        util/ResourceReader.cpp
        util/ResourceReader.h
        render/shader/ShaderProgram.cpp
        render/shader/ShaderProgram.h
        render/model/Texture.cpp
        render/model/Texture.h
        screens/ScreenUtils.cpp
        screens/ScreenUtils.h
        render/shader/TestShader.cpp
        render/shader/TestShader.h
        render/Camera.cpp
        render/Camera.h
        render/shader/Shader3D.cpp
        render/shader/Shader3D.h
        Controls.cpp
        Controls.h
        render/model/Mesh.cpp
        render/model/Mesh.h
        render/model/Model.cpp
        render/model/Model.h
        render/model/Material.cpp
        render/model/Material.h
        render/model/TextureCache.cpp
        render/model/TextureCache.h
        game/GameState.cpp
        game/GameState.h
        game/GameDataCache.cpp
        game/GameDataCache.h
        render/GameRenderer.cpp
        render/GameRenderer.h
        render/Environment.cpp
        render/Environment.h
        game/GameEngine.cpp
        game/GameEngine.h
        GlobalFlags.h
        render/GlFramebuffer.cpp
        render/GlFramebuffer.h
        render/GlScreenBuffer.cpp
        render/GlScreenBuffer.h
        render/shader/Shader2D.cpp
        render/shader/Shader2D.h
        game/levels/Level1.cpp
        game/levels/Level2.cpp
        game/levels/Level3.cpp
        render/shader/ShaderEnv.cpp
        render/shader/ShaderEnv.h
        game/levels/WinLevel.cpp)

find_package(glm CONFIG REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glm::glm)
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glfw)
find_package(GLEW REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE GLEW::GLEW)
find_package(Stb REQUIRED)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${Stb_INCLUDE_DIR})

# Include Assimp headers
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${ASSIMP_INCLUDE_DIRS})

# Link against Assimp library
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${ASSIMP_LIBRARIES})

#if(DEFINED POLLY_MINGW_CXX17_CMAKE_)
#    return()
#else()
#    set(POLLY_MINGW_CXX17_CMAKE_ 1)
#endif()
#
#include("${CMAKE_CURRENT_LIST_DIR}/utilities/polly_init.cmake")
#
#polly_init(
#        "mingw / gcc / c++17 support"
#        "MinGW Makefiles"
#)
#
#include("${CMAKE_CURRENT_LIST_DIR}/utilities/polly_common.cmake")
#
#include("${CMAKE_CURRENT_LIST_DIR}/compiler/gcc.cmake")
#include("${CMAKE_CURRENT_LIST_DIR}/flags/cxx17.cmake")