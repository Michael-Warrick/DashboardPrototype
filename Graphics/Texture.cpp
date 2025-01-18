#include "Texture.hpp"

Graphics::Texture::Texture(const std::string &texturePath) {
    createTexture(texturePath);
}

Graphics::Texture::~Texture() {
    if (m_TextureID != 0) {
        glDeleteTextures(1, &m_TextureID);
    }
}

Graphics::Texture::Texture(const Texture &other)
    : m_TextureID(0), m_TexturePath(other.m_TexturePath) {
    if (!m_TexturePath.empty()) {
        createTexture(m_TexturePath); // Recreate the texture
    }
}

Graphics::Texture::Texture(Texture &&other) noexcept
    : m_TextureID(other.m_TextureID),
      m_TexturePath(std::move(other.m_TexturePath)) {
    other.m_TextureID = 0; // Nullify the moved-from object
}

Graphics::Texture &Graphics::Texture::operator=(const Texture &other) {
    if (this != &other) { // Self-assignment check
        // Clean up the current texture
        if (m_TextureID != 0) {
            glDeleteTextures(1, &m_TextureID);
            m_TextureID = 0; // Reset to avoid dangling references
        }

        // Copy the texture path from the other object
        m_TexturePath = other.m_TexturePath;

        // Recreate the texture if the other texture has a valid path
        if (!m_TexturePath.empty()) {
            createTexture(m_TexturePath);
        } else {
            m_TextureID = 0; // Ensure no texture ID is assigned
        }
    }
    return *this;
}

Graphics::Texture &Graphics::Texture::operator=(Texture &&other) noexcept {
    if (this != &other) {
        // Cleanup existing resources
        if (m_TextureID != 0) {
            glDeleteTextures(1, &m_TextureID);
        }

        // Steal resources from other
        m_TextureID = other.m_TextureID;
        m_TexturePath = std::move(other.m_TexturePath);

        // Nullify the moved-from object
        other.m_TextureID = 0;
    }
    return *this;
}

void Graphics::Texture::Bind(const GLenum &textureUnit) { 
    glActiveTexture(textureUnit);
    glBindTexture(GL_TEXTURE_2D, m_TextureID);
}

void Graphics::Texture::createTexture(const std::string &texturePath) {
    if (m_TextureID != 0) {
        glDeleteTextures(1, &m_TextureID);
        m_TextureID = 0;
    }

    m_TexturePath = texturePath;

    // Generate and bind a texture to the texture ID
    glGenTextures(1, &m_TextureID);

    glBindTexture(GL_TEXTURE_2D, m_TextureID);

    // Set texture wrapping settings
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Set texture filtering settings
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_set_flip_vertically_on_load(true);
    // Load and create texture and generate mipmaps
    m_Data = stbi_load(m_TexturePath.c_str(), &m_Width, &m_Height,
                       &m_ChannelCount, 0);
    if (m_Data) {
        GLenum format = (m_ChannelCount == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, m_Width, m_Height, 0, format,
                     GL_UNSIGNED_BYTE, m_Data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cerr << "Error: Failed to load texture!\n";
    }

    // Free no longer needed image resources
    stbi_image_free(m_Data);
}