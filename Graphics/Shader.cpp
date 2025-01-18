#include "Shader.hpp"

Shader::Shader(const std::string &vertexShaderPath,
               const std::string &fragmentShaderPath) {
    m_VertexShaderPath = vertexShaderPath;
    m_FragmentShaderPath = fragmentShaderPath;

    createShaderProgram(m_VertexShaderPath, m_FragmentShaderPath);
}

Shader::~Shader() {
    if (m_ID != 0) {
        glDeleteProgram(m_ID);
    }
}

Shader &Shader::operator=(const Shader &other) {
    if (this != &other) {
        if (m_ID != 0) {
            glDeleteProgram(m_ID);
        }

        m_VertexShaderPath = other.m_VertexShaderPath;
        m_FragmentShaderPath = other.m_FragmentShaderPath;

        if (!m_VertexShaderPath.empty() && !m_FragmentShaderPath.empty()) {
            createShaderProgram(m_VertexShaderPath, m_FragmentShaderPath);
        }
    }
    return *this;
}

void Shader::Use() { glUseProgram(m_ID); }

void Shader::SetTextureID(const std::string &name, const GLuint &samplerLocation) const {
    glUniform1i(glGetUniformLocation(m_ID, name.c_str()), samplerLocation); 
}

void Shader::SetMat4(const std::string &name, const glm::mat4 &mat) {
    glUniformMatrix4fv(glGetUniformLocation(m_ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

std::vector<char> Shader::readFile(const std::string &filePath) {
    std::ifstream file(filePath, std::ios::ate | std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file!");
    }

    size_t fileSize = (size_t)file.tellg();
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);
    file.close();

    return buffer;
}

void Shader::checkGLSLCompilationErrors(GLuint glslObject,
                                        const std::string &type) {
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM") {
        glGetShaderiv(glslObject, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(glslObject, 1024, NULL, infoLog);
            std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type
                      << "\n"
                      << infoLog << std::endl;
        }
    } else {
        glGetProgramiv(glslObject, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(glslObject, 1024, NULL, infoLog);
            std::cerr << "ERROR::SHADER_PROGRAM_LINKING_ERROR of type: " << type
                      << "\n"
                      << infoLog << std::endl;
        }
    }
}

void Shader::createShaderProgram(std::string &vertexShaderPath,
                                 std::string &fragmentShaderPath) {
    std::vector<char> vertexCode = readFile(vertexShaderPath);
    std::vector<char> fragmentCode = readFile(fragmentShaderPath);

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

    m_ID = glCreateProgram();
    glAttachShader(m_ID, vertexShader);
    glAttachShader(m_ID, fragmentShader);
    glLinkProgram(m_ID);
    checkGLSLCompilationErrors(m_ID, "PROGRAM");

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}