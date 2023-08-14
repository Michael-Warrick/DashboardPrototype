#include "application.hpp"

Application::Application()
{
    window = Window();
}

Application::~Application()
{
    glfwTerminate();
}

void Application::Run() 
{
    while(!glfwWindowShouldClose(window.GetPlatformWindow()))
    {
        glfwPollEvents();

        // Render
        glClearColor(0.2f, 0.4f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window.GetPlatformWindow());
    }
}