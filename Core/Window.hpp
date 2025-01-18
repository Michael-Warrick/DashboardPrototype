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

#if defined(__APPLE__) || defined(__MACH__)
#ifdef __arm64__
    std::string m_PlatformName = "macOS (Apple Silicon) 64-bit";
#elif defined(__x86_64__)
    std::string m_PlatformName = "macOS (Intel) 64-bit";
#endif
#elif defined(_WIN64)
    std::string m_PlatformName = "Windows 64-bit";
#elif defined(__linux__)
    std::string m_PlatformName = "Linux 64-bit";
#endif

    std::string m_Title = "DashboardPrototype Alpha Version 1.0.0 | " + m_PlatformName + " - OpenGL 4.1";
};