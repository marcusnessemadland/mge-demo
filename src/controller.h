#pragma once

#include <vulkan-renderer.h>

// Define entity
class Controller : public vr::Entity
{
    void mouseUpdate(const SDL_Update& update);
    void keyUpdate(const SDL_Update& _update);
    void keyDown(const SDL_Event& _event);

public:
    Controller(std::shared_ptr<vr::Window> _window);

    /// Create flying camera controller.
    ///
    /// @returns Shared controller.
    /// 
    friend std::shared_ptr<Controller> createController(std::shared_ptr<vr::World> _world, std::shared_ptr<vr::Window> _window, std::shared_ptr<vr::Camera> _camera);

protected:
    void update(double _dt) override;

private:
    std::shared_ptr<vr::Window> m_window;
    bool m_blockInput;
    vr::Vec3 m_moveInput;
    vr::Vec2 m_lookInput;
};