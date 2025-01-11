#pragma once
#include <iostream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "Graphics/Renderer.hpp"

class Window {
public:
    Window();
    ~Window();

    void PollEvents();
    void SwapBuffers();

    GLFWwindow *GetPlatformWindow();
    bool IsOpen();

private:
    GLFWwindow *m_Window = nullptr;

    uint16_t m_Width = 1280;
    uint16_t m_Height = 720;

    std::string m_Title = "DashboardPrototype Alpha Version 1.0.0 | macOS "
                          "(Apple Silicon) - OpenGL 4.1";
};