/// Demo example
///

#include <vulkan-renderer.h>

using namespace vr;

void _main_(int argc, const char** argv)
{
    // Create window
    auto window = createWindow("Demo", 0, 0, 1280, 720, VR_WINDOW_DEFAULT);

    // Create event queue
    auto event = createEventQueue(window);

    // Create renderer
    auto renderer = createRenderer(window, RendererType::Auto);

    // Create world
    auto world = createWorld();

    // Create camera
    auto camera = createCamera(world, Projection::Perspective);
    camera->setFOV(60.0f);

    // Create scene
    auto scene = createScene(world);

    // Game loop
    while (!window->isClosed())
    {
        // Event loop
        while (!event->empty())
        {
            const Event& ev = event->front();
            if (ev.type == EventType::Keyboard)
            {
                const KeyboardData keyboard = ev.data.keyboard;
                if (keyboard.key == Key::Escape)
                {
                    window->close();
                }
            }
            if (ev.type == EventType::Close)
            {
                window->close();
            }

            event->pop();
        }

        // Update
        world->update();
        world->render(renderer);
    }
}