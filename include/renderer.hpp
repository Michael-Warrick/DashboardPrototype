#pragma once

#include <iostream>
#include <glad/gl.h>

#include "shader.hpp"

class Renderer
{
public:
    void Init();
    void Draw();
    void CleanUp();

private:
    void createBuffers();
    void drawFrame();

    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;

    Shader shader;
};