#pragma once
#include <iostream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window();
    ~Window();

    GLFWwindow* GetPlatformWindow();

private:
    GLFWwindow* platformWindow;

    unsigned int width = 800;
    unsigned int height = 600;

    std::string title = "Simple OpenGL App";
};