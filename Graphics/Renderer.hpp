#pragma once

#include <iostream>

#include <glad/gl.h>

#include "Shader.hpp"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void Draw();

private:
    void createBuffers();
    void drawFrame();

    unsigned int m_QuadVBO;
    unsigned int m_QuadVAO;
    unsigned int m_QuadEBO;

    Shader m_QuadShader;
};