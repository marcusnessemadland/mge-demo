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

    // Game loop
    while (!window->isClosed())
    {
        // Event loop
        while (!event->empty())
        {
            const Event& ev = event->front();
            if (ev.type == EventType::Close)
            {
                window->close();
            }
            event->pop();
        }

        // Update

    }
}