#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <glad/gl.h>

class Shader {
public:
    Shader() = default;
    Shader(const std::string &vertexShaderPath,
           const std::string &fragmentShaderPath);
    ~Shader();

    void Use();

    Shader &operator=(const Shader &other);

private:
    std::vector<char> readFile(const std::string &filePath);
    void checkGLSLCompilationErrors(GLuint glslObject, const std::string &type);
    void createShaderProgram(std::string &vertexShaderPath,
                             std::string &fragmentShaderPath);

    std::string m_VertexShaderPath;
    std::string m_FragmentShaderPath;
    GLuint m_ID;
};