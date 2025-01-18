#include "Application.hpp"

Application::Application() : m_Renderer(m_Window.GetPlatformWindow()) {
}

void Application::Run() {
    while (m_Window.IsOpen()) {
        // Poll for window events (resize, DPI change...)
        m_Window.PollEvents();

        // Render
        m_Renderer.Draw();

        // Double buffering, show new framebuffer
        m_Window.SwapBuffers();
    }
}