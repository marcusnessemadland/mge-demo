/*
 * Copyright 2025 Marcus Nesse Madland. All rights reserved.
 * License: https://github.com/marcusnessemadland/mge/blob/main/LICENSE
 */

#include <mge.h>

#include "controller.h"

using namespace vr;

// Define main
void _main_(int argc, const char** argv)
{
    // Create window
    auto window = createWindow("Modern Graphics Engine", 1280, 720, SDL_WINDOW_RESIZABLE);

    // Create renderer
    auto renderer = createRenderer(window, bgfx::RendererType::OpenGL);

    // Create world
    auto world = createWorld();

    // Create camera
    auto camera = createCamera(world, Projection::Perspective);
    camera->setFOV(60.0f);
    camera->setPosition(Vec3(0.0f, 2.0f, 5.0f));
    camera->setTarget(Vec3(0.0f, 0.0f, 0.0f));

    // Create controller
    auto controller = createController(world, window, camera);

    // Create scene
    auto scene = loadScene(world, "scenes/sun_temple.bin" /*"scenes/bistro.bin"*/);

    // Game loop
    while (!window->isClosed())
    {
        // Update
        world->update();
        world->render(renderer);
    }
}