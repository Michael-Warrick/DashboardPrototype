#pragma once

#include <iostream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "Primatives.hpp"
#include "Camera.hpp"

class Renderer {
public:
    Renderer() = default;
    Renderer(GLFWwindow *window);
    ~Renderer();

    void Draw();

private:
    GLFWwindow *m_Window = nullptr;
    void drawFrame();

    void handleFramebufferResize(int width, int height);

    static void framebufferResizeCallback(GLFWwindow *window, int width,
                                          int height);

    Graphics::Primatives::Quad m_Quad;
    Graphics::Camera m_Camera;

    uint32_t m_ViewportWidth = 1280;
    uint32_t m_ViewportHeight = 720;
};
