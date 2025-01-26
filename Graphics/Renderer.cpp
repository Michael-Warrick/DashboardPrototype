#include "Renderer.hpp"

Renderer::Renderer(GLFWwindow *window) {
    m_Window = window;
    glfwSetWindowUserPointer(m_Window, this);
    glfwSetFramebufferSizeCallback(m_Window, framebufferResizeCallback);

    m_Camera = Graphics::Camera(glm::vec3(2.0f, 1.0f, 0.0f));

    m_HomeTileIndices = {// Left Column
                         0, 1, 2,

                         // Middle Column
                         3, 4, 5,

                         // Right Column
                         6, 7, 8};

    m_HomeTileOffsets = {
        // Left Column
        glm::vec3(-m_TileOffset, m_TileOffset, 0.0f),
        glm::vec3(-m_TileOffset, 0.0f, 0.0f),
        glm::vec3(-m_TileOffset, -m_TileOffset, 0.0f),

        // Middle Column
        glm::vec3(0.0f, (m_TileOffset / 2.0f), 0.0f),
        glm::vec3(-(m_TileOffset / m_TileWidth), -m_TileOffset, 0.0f),
        glm::vec3((m_TileOffset / m_TileWidth), -m_TileOffset, 0.0f),

        // Right Column
        glm::vec3(m_TileOffset, m_TileOffset, 0.0f),
        glm::vec3(m_TileOffset, 0.0f, 0.0f),
        glm::vec3(m_TileOffset, -m_TileOffset, 0.0f)};

    m_HomeTilePositions = {
        // Left Column
        glm::vec3(-(0.5 * m_TileWidth), m_TileHeight * 2.0f, -7.0f),
        glm::vec3(-(0.5 * m_TileWidth), m_TileHeight * 1.0f, -7.0f),
        glm::vec3(-(0.5 * m_TileWidth), m_TileHeight * 0.0f, -7.0f),

        // Middle Column
        glm::vec3(2.0f, m_TileHeight * 1.5f, -7.0f),
        glm::vec3(1.0f + (m_TileOffset / 2.0f), m_TileHeight * 0.0f, -7.0f),
        glm::vec3(3.0f - (m_TileOffset / 2.0f), m_TileHeight * 0.0f, -7.0f),

        // Right Column
        glm::vec3((3.5 * m_TileWidth) + (m_TileOffset / 2.0f),
                  m_TileHeight * 2.0f, -7.0f),
        glm::vec3((3.5 * m_TileWidth) + (m_TileOffset / 2.0f),
                  m_TileHeight * 1.0f, -7.0f),
        glm::vec3((3.5 * m_TileWidth) + (m_TileOffset / 2.0f),
                  m_TileHeight * 0.0f, -7.0f)};

    m_HomeTileScales = {// Left Column
                        glm::vec3(m_TileWidth, m_TileHeight, 1.0f),
                        glm::vec3(m_TileWidth, m_TileHeight, 1.0f),
                        glm::vec3(m_TileWidth, m_TileHeight, 1.0f),

                        // Middle Column
                        glm::vec3(3.0f * m_TileWidth,
                                  (m_TileHeight * 2.0) + m_TileOffset, 1.0f),
                        glm::vec3(1.5f * m_TileWidth - (m_TileOffset / 2.0f),
                                  m_TileHeight, 1.0f),
                        glm::vec3(1.5f * m_TileWidth - (m_TileOffset / 2.0f),
                                  m_TileHeight, 1.0f),

                        // Right Column
                        glm::vec3(m_TileWidth, m_TileHeight, 1.0f),
                        glm::vec3(m_TileWidth, m_TileHeight, 1.0f),
                        glm::vec3(m_TileWidth, m_TileHeight, 1.0f)};
}

Renderer::~Renderer() {}

void Renderer::Draw() { drawFrame(); }

void Renderer::drawFrame() {
    glClearColor(0.755f, 0.755f, 0.755f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawHomeTiles();
}

void Renderer::drawHomeTiles() {
    for (size_t i = 0; i < m_HomeTileIndices.size(); ++i) {
        m_Quad.Draw(
            m_HomeTilePositions[i] + m_HomeTileOffsets[i], m_HomeTileScales[i],
            0x289728FF,
            m_Camera.projectionMatrix(m_ViewportWidth, m_ViewportHeight),
            m_Camera.viewMatrix());
    }
}

void Renderer::handleFramebufferResize(int width, int height) {
    m_ViewportWidth = width;
    m_ViewportHeight = height;

    glViewport(0, 0, m_ViewportWidth, m_ViewportHeight);
}

void Renderer::framebufferResizeCallback(GLFWwindow *window, int width,
                                         int height) {
    // Retrieve `Renderer` instance from GLFW user pointer.
    Renderer *renderer =
        static_cast<Renderer *>(glfwGetWindowUserPointer(window));
    if (renderer) {
        // Forward request to non-static callback function
        renderer->handleFramebufferResize(width, height);
    }
}