#pragma once
#include <iostream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "renderer.hpp"

class Window
{
public:
    Window();
    ~Window();

    void Present();
    GLFWwindow* GetPlatformWindow();
    bool IsOpen();

private:
    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
    
    GLFWwindow* window = nullptr;

    uint16_t width = 1280;
    uint16_t height = 720;

    std::string title = "Xbox 360 Dashboard";

    Renderer renderer;
};