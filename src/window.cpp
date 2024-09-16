#include "window.hpp"

Window::Window()
{
    glfwInit();

    // Using most supported version by default (4.1)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

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

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    renderer.Init();
}

Window::~Window()
{
    renderer.CleanUp();
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::Present()
{
    renderer.Draw();
}

GLFWwindow *Window::GetPlatformWindow()
{
    return window;
}

bool Window::IsOpen()
{
    return !glfwWindowShouldClose(window);
}

void Window::framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}