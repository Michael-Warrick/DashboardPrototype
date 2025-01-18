#pragma once

#include <iostream>
#include <string>

#include <glad/gl.h>
#include "stb_image/stb_image.h"

namespace Graphics {
    class Texture {
    public:
        Texture() = default;
        explicit Texture(const std::string &texturePath);
        ~Texture();

        Texture(const Texture &other);                // Copy constructor
        Texture(Texture &&other) noexcept;            // Move constructor
        Texture &operator=(const Texture &other);     // Copy assignment
        Texture &operator=(Texture &&other) noexcept; // Move assignment

        void Bind(const GLenum &textureUnit);
    private:
        void createTexture(const std::string &texturePath);

        GLuint m_TextureID = 0;
        std::string m_TexturePath;

        int m_Width = 0;
        int m_Height = 0;
        int m_ChannelCount = 0;
        unsigned char *m_Data = nullptr;
    };
} // namespace Graphics