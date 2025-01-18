#include "Renderer.hpp"

Renderer::Renderer(GLFWwindow *window) {
    m_Window = window;
    glfwSetWindowUserPointer(m_Window, this);
    glfwSetFramebufferSizeCallback(m_Window, framebufferResizeCallback);

    m_Camera = Graphics::Camera(glm::vec3(0.0f, 0.0f, 0.0f));
}

Renderer::~Renderer() {}

void Renderer::Draw() { drawFrame(); }

void Renderer::drawFrame() {
    glClearColor(0.755f, 0.755f, 0.755f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    float offset = 0.2f;

    m_Quad.Draw(glm::vec3(-1.0f - offset, -1.0f - offset, -5.0f),
                m_Camera.projectionMatrix(m_ViewportWidth, m_ViewportHeight),
                m_Camera.viewMatrix());

    m_Quad.Draw(glm::vec3(0.0f, -1.0f - offset, -5.0f),
                m_Camera.projectionMatrix(m_ViewportWidth, m_ViewportHeight),
                m_Camera.viewMatrix());

    m_Quad.Draw(glm::vec3(1.0f + offset, -1.0f - offset, -5.0f),
                m_Camera.projectionMatrix(m_ViewportWidth, m_ViewportHeight),
                m_Camera.viewMatrix());

    m_Quad.Draw(glm::vec3(-1.0f - offset, 0.0f, -5.0f),
                m_Camera.projectionMatrix(m_ViewportWidth, m_ViewportHeight),
                m_Camera.viewMatrix());

    m_Quad.Draw(glm::vec3(0.0f, 0.0f, -5.0f),
                m_Camera.projectionMatrix(m_ViewportWidth, m_ViewportHeight),
                m_Camera.viewMatrix());

    m_Quad.Draw(glm::vec3(1.0f + offset, 0.0f, -5.0f),
                m_Camera.projectionMatrix(m_ViewportWidth, m_ViewportHeight),
                m_Camera.viewMatrix());

    m_Quad.Draw(glm::vec3(-1.0f - offset, 1.0f + offset, -5.0f),
                m_Camera.projectionMatrix(m_ViewportWidth, m_ViewportHeight),
                m_Camera.viewMatrix());

    m_Quad.Draw(glm::vec3(0.0f, 1.0f + offset, -5.0f),
                m_Camera.projectionMatrix(m_ViewportWidth, m_ViewportHeight),
                m_Camera.viewMatrix());

    m_Quad.Draw(glm::vec3(1.0f + offset, 1.0f + offset, -5.0f),
                m_Camera.projectionMatrix(m_ViewportWidth, m_ViewportHeight),
                m_Camera.viewMatrix());
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