#include "application.hpp"

void Application::Run()
{
    while (window.IsOpen())
    {
        window.Present();

        glfwSwapBuffers(window.GetPlatformWindow());
        glfwPollEvents();
    }
}