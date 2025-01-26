#include "Primatives.hpp"

Graphics::Primatives::Quad::Quad() {
    m_QuadShader = Shader("./Resources/Shaders/Quad.vert.glsl",
                          "./Resources/Shaders/Quad.frag.glsl");
    createBuffers();
    m_QuadTexture = Texture("./Resources/Images/Textures/DefaultTexture.png");
    m_QuadShader.Use();
    m_QuadShader.SetTextureID("imageTexture", 0);
}

Graphics::Primatives::Quad::~Quad() {
    glDeleteVertexArrays(1, &m_QuadVAO);
    glDeleteBuffers(1, &m_QuadVBO);
    glDeleteBuffers(1, &m_QuadEBO);
}

void Graphics::Primatives::Quad::Draw(glm::vec3 position, glm::vec3 scale,
                                      uint32_t hexColor,
                                      glm::mat4 projectionMatrix,
                                      glm::mat4 viewMatrix) {
    m_QuadTexture.Bind(GL_TEXTURE0);
    m_QuadShader.Use();

    glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
    model = glm::scale(model, scale);

    m_MVP = projectionMatrix * viewMatrix * model;
    // Set MVP
    m_QuadShader.SetMat4("mvp", m_MVP);
    m_QuadShader.SetHexColor("quadColor", hexColor);

    glBindVertexArray(m_QuadVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Graphics::Primatives::Quad::DrawInstanced() {}

void Graphics::Primatives::Quad::createBuffers() {
    float vertices[] = {
        // Positions        // Colors         // Texture coordinates
        0.5f,  0.5f,  0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // top right
        0.5f,  -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f  // top left
    };

    unsigned int indices[] = {
        0, 1, 3, // First triangle
        1, 2, 3  // Second triangle
    };

    // Generate VAO, VBO and EBO
    glGenVertexArrays(1, &m_QuadVAO);
    glGenBuffers(1, &m_QuadVBO);
    glGenBuffers(1, &m_QuadEBO);

    // Bind VAO
    glBindVertexArray(m_QuadVAO);

    // Bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_QuadVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Bind EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_QuadEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
                 GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                          (void *)0);
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                          (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Texture attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                          (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // // Unbind VBO and then VAO
    // glBindBuffer(GL_ARRAY_BUFFER, 0);
    // glBindVertexArray(0);
}