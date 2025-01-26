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
    void drawHomeTiles();

    void handleFramebufferResize(int width, int height);

    static void framebufferResizeCallback(GLFWwindow *window, int width,
                                          int height);

    Graphics::Primatives::Quad m_Quad;
    Graphics::Camera m_Camera;

    const float m_TileOffset = 0.025f;

    const float m_TileWidth = 1.33f;
    const float m_TileHeight = 1.0f;

    std::vector<uint16_t> m_HomeTileIndices;
    std::vector<glm::vec3> m_HomeTileOffsets;
    std::vector<glm::vec3> m_HomeTilePositions;
    std::vector<glm::vec3> m_HomeTileScales;

    uint32_t m_ViewportWidth = 1280;
    uint32_t m_ViewportHeight = 720;
};
