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

    // Create material
    auto material = createMaterial();
    material->setColor(loadTexture("textures/color.jpg"));
    material->setMetallic(0.5f);
    material->setRoughness(0.5f);

    // Create mesh
    std::vector<Vertex> vertices = {
        {{-0.5f, -0.5f,  0.5f}, {0, 0, 1}, {}, {}, {0, 0}, {}, 0, {}},
        {{ 0.5f, -0.5f,  0.5f}, {0, 0, 1}, {}, {}, {1, 0}, {}, 0, {}},
        {{ 0.5f,  0.5f,  0.5f}, {0, 0, 1}, {}, {}, {1, 1}, {}, 0, {}},
        {{-0.5f,  0.5f,  0.5f}, {0, 0, 1}, {}, {}, {0, 1}, {}, 0, {}},
        {{-0.5f, -0.5f, -0.5f}, {0, 0, -1}, {}, {}, {1, 0}, {}, 0, {}},
        {{ 0.5f, -0.5f, -0.5f}, {0, 0, -1}, {}, {}, {0, 0}, {}, 0, {}},
        {{ 0.5f,  0.5f, -0.5f}, {0, 0, -1}, {}, {}, {0, 1}, {}, 0, {}},
        {{-0.5f,  0.5f, -0.5f}, {0, 0, -1}, {}, {}, {1, 1}, {}, 0, {}},
        {{-0.5f, -0.5f, -0.5f}, {-1, 0, 0}, {}, {}, {0, 0}, {}, 0, {}},
        {{-0.5f, -0.5f,  0.5f}, {-1, 0, 0}, {}, {}, {1, 0}, {}, 0, {}},
        {{-0.5f,  0.5f,  0.5f}, {-1, 0, 0}, {}, {}, {1, 1}, {}, 0, {}},
        {{-0.5f,  0.5f, -0.5f}, {-1, 0, 0}, {}, {}, {0, 1}, {}, 0, {}},
        {{0.5f, -0.5f, -0.5f}, {1, 0, 0}, {}, {}, {1, 0}, {}, 0, {}},
        {{0.5f, -0.5f,  0.5f}, {1, 0, 0}, {}, {}, {0, 0}, {}, 0, {}},
        {{0.5f,  0.5f,  0.5f}, {1, 0, 0}, {}, {}, {0, 1}, {}, 0, {}},
        {{0.5f,  0.5f, -0.5f}, {1, 0, 0}, {}, {}, {1, 1}, {}, 0, {}},
        {{-0.5f, 0.5f, -0.5f}, {0, 1, 0}, {}, {}, {0, 0}, {}, 0, {}},
        {{0.5f, 0.5f, -0.5f}, {0, 1, 0}, {}, {}, {1, 0}, {}, 0, {}},
        {{0.5f, 0.5f,  0.5f}, {0, 1, 0}, {}, {}, {1, 1}, {}, 0, {}},
        {{-0.5f, 0.5f,  0.5f}, {0, 1, 0}, {}, {}, {0, 1}, {}, 0, {}},
        {{-0.5f, -0.5f, -0.5f}, {0, -1, 0}, {}, {}, {1, 0}, {}, 0, {}},
        {{0.5f, -0.5f, -0.5f}, {0, -1, 0}, {}, {}, {0, 0}, {}, 0, {}},
        {{0.5f, -0.5f,  0.5f}, {0, -1, 0}, {}, {}, {0, 1}, {}, 0, {}},
        {{-0.5f, -0.5f,  0.5f}, {0, -1, 0}, {}, {}, {1, 1}, {}, 0, {}},
    };
    std::vector<uint32_t> indices = {
        0, 1, 2, 2, 3, 0,       
        4, 5, 6, 6, 7, 4,       
        8, 9, 10, 10, 11, 8,    
        12, 13, 14, 14, 15, 12, 
        16, 17, 18, 18, 19, 16, 
        20, 21, 22, 22, 23, 20  
    };
    auto mesh = createMesh(Primitive::Triangles, vertices, indices);
    mesh->setMaterial(material);
    
    // Create model
    auto model = createModel(world);
    model->addMesh(mesh);
    model->setPosition(Vec3(0.0f, 0.0f, 0.0f));

    //// Create light
    //auto light = createDirectionalLight(world);
    //light->setRotation(45.0f, 45.0f, 0.0f);
    //light->setColor(1.0f, 1.0f, 1.0f);
    //

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