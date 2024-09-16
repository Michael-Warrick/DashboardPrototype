#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <glad/gl.h>

class Shader
{
public:
    void Init(const std::string& vertexPath, const std::string& fragmentPath);
    void Use();
    void Delete();
private:
    std::vector<char> readFile(const std::string& filePath);
    void checkGLSLCompilationErrors(GLuint glslObject, const std::string& type);

    GLuint ID;
};