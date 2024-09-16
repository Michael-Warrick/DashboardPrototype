#include "shader.hpp"

void Shader::Init(const std::string &vertexPath, const std::string &fragmentPath)
{
    std::vector<char> vertexCode = readFile(vertexPath);
    std::vector<char> fragmentCode = readFile(fragmentPath);

    // Ensure null-termination
    vertexCode.push_back('\0');
    fragmentCode.push_back('\0');

    const char *vertexShaderCode = vertexCode.data();
    const char *fragmentShaderCode = fragmentCode.data();

    GLuint vertexShader;
    GLuint fragmentShader;
    GLint success;

    GLchar infoLog[512];

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
    glCompileShader(vertexShader);
    checkGLSLCompilationErrors(vertexShader, "VERTEX");

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderCode, NULL);
    glCompileShader(fragmentShader);
    checkGLSLCompilationErrors(fragmentShader, "FRAGMENT");

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);
    checkGLSLCompilationErrors(ID, "PROGRAM");

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Use()
{
    glUseProgram(ID);
}

void Shader::Delete()
{
    glDeleteProgram(ID);
}

std::vector<char> Shader::readFile(const std::string &filePath)
{
    std::ifstream file(filePath, std::ios::ate | std::ios::binary);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file!");
    }

    size_t fileSize = (size_t)file.tellg();
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);
    file.close();

    return buffer;
}

void Shader::checkGLSLCompilationErrors(GLuint glslObject, const std::string &type)
{
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(glslObject, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(glslObject, 1024, NULL, infoLog);
            std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n"
                      << infoLog << std::endl;
        }
    }
    else
    {
        glGetProgramiv(glslObject, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(glslObject, 1024, NULL, infoLog);
            std::cerr << "ERROR::SHADER_PROGRAM_LINKING_ERROR of type: " << type << "\n"
                      << infoLog << std::endl;
        }
    }
}