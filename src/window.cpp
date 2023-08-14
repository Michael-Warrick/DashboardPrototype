#include "window.hpp"

Window::Window()
{
    glfwInit();

    // Using most supported version by default (4.1)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0)
    {
        std::cerr << "Failed to initialize OpenGL context" << std::endl;
        glfwTerminate();
    }

    glViewport(0, 0, width, height);
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::Present()
{
    glfwSwapBuffers(window);

    // Render
    glClearColor(0.2f, 0.4f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwPollEvents();
}

GLFWwindow* Window::GetPlatformWindow() 
{
    return window;
}

bool Window::IsOpen()
{
    return !glfwWindowShouldClose(window);
}