/*
 * Copyright 2025 Marcus Nesse Madland. All rights reserved.
 * License: https://github.com/marcusnessemadland/mge/blob/main/LICENSE
 */

#pragma once

#include <mge.h>

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