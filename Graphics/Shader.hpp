#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public:
    Shader() = default;
    Shader(const std::string &vertexShaderPath,
           const std::string &fragmentShaderPath);
    ~Shader();

    Shader &operator=(const Shader &other);

    void Use();
    void SetTextureID(const std::string &name, const GLuint &samplerLocation) const;
    void SetMat4(const std::string &name, const glm::mat4 &mat);

private:
    std::vector<char> readFile(const std::string &filePath);
    void checkGLSLCompilationErrors(GLuint glslObject, const std::string &type);
    void createShaderProgram(std::string &vertexShaderPath,
                             std::string &fragmentShaderPath);

    std::string m_VertexShaderPath;
    std::string m_FragmentShaderPath;
    GLuint m_ID;
};