#include "window.hpp"

Window::Window()
{
    glfwInit();

    // Using most supported version by default (4.1)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    platformWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (platformWindow == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(platformWindow);

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
    glfwTerminate();
}

GLFWwindow* Window::GetPlatformWindow() 
{
    return platformWindow;
}