#include "controller.h"

using namespace vr;

void Controller::mouseUpdate(const SDL_Update& update)
{
    // Look up/down and right/left
    m_lookInput = Vec2(update.mouse.xrel, update.mouse.yrel) * -1.0f;
}

void Controller::keyUpdate(const SDL_Update& _update)
{
    // Move forward/backward
    m_moveInput.z = (_update.keyboard.down[SDL_SCANCODE_W]) ? -1.0f :
                  (_update.keyboard.down[SDL_SCANCODE_S]) ?  1.0f : 0.0f;

    // Move right/left
    m_moveInput.x = (_update.keyboard.down[SDL_SCANCODE_A]) ? -1.0f :
                  (_update.keyboard.down[SDL_SCANCODE_D]) ?  1.0f : 0.0f;

    // Move up/down
    m_moveInput.y = (_update.keyboard.down[SDL_SCANCODE_E]) ?  1.0f :
                  (_update.keyboard.down[SDL_SCANCODE_Q]) ? -1.0f : 0.0f;
}

void Controller::keyDown(const SDL_Event& _event)
{
    // Block/unblock input and lock/unlock cursor
    if (_event.key.key == SDLK_F1)
    {
        m_blockInput = !m_blockInput;
        m_window->setCursorLock(!m_blockInput);
        m_window->setCursorPos(m_window->getWidth() / 2, m_window->getHeight() / 2);
    }
}

Controller::Controller(std::shared_ptr<Window> _window)
    : m_window(_window), m_blockInput(false)
{
    // Begin locking cursor
    m_window->setCursorLock(true);

    // Register update callbacks
    _window->registerUpdate(SDL_UPDATE_MOUSE, [this](const SDL_Update& update)
    {
        this->mouseUpdate(update);
    });

    _window->registerUpdate(SDL_UPDATE_KEYBOARD, [this](const SDL_Update& update)
    {
        this->keyUpdate(update);
    });

    // Register event callbacks
    _window->registerEvent(SDL_EVENT_KEY_DOWN, [this](const SDL_Event& event)
    {
        this->keyDown(event);
    });
}

void Controller::update(double _dt)
{
    // Update camera fly movement
    if (!m_blockInput)
    {
        if (std::shared_ptr<CameraFlyComponent> component = getComponent<CameraFlyComponent>())
        {
            // Call component API
            component->setMoveInput(normalize(m_moveInput));
            component->setLookInput(m_lookInput);
        }
    }
}

std::shared_ptr<Controller> createController(std::shared_ptr<vr::World> _world, std::shared_ptr<vr::Window> _window, std::shared_ptr<vr::Camera> _camera)
{
    // Create entity
    auto controller = vr::createEntity<Controller>(_world, _window);

    // Add components
    controller->addComponent<CameraFlyComponent>(_camera);

    return controller;
}
