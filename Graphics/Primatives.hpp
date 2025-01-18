#pragma once

#include <glad/gl.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.hpp"
#include "Texture.hpp"

namespace Graphics {
    namespace Primatives {
        /**
         * @class Quad
         * @brief A class to draw quads.
         *
         * @details This class is used to draw Quad objects either singularly or
         * with instancing techniques.
         */
        class Quad {
        public:
            /**
             * @brief Default Quad constructor.
             */
            Quad();

            /**
             * @brief Default Quad destructor.
             */
            ~Quad();

            /**
             * @brief Issues a single draw call to render a Quad.
             *
             * @details #Draw is used to draw a single Quad, used when
             * uniqueness and flexibility are requirements.
             */
            void Draw(glm::vec3 position, glm::mat4 projectionMatrix, glm::mat4 viewMatrix);

            /**
             * @brief Issues an instanced draw call to render an array of Quads.
             *
             * @details #DrawInstanced is used to draw multiple Quads using
             * instancing, where each Quad may share similar features.
             */
            void DrawInstanced();

        private:
            void createBuffers();

            GLuint m_QuadVAO; /**< ID pointing to Quad's OpenGL Vertex Array
                                 Object. */
            GLuint m_QuadVBO; /**< ID pointing to Quad's OpenGL Vertex Buffer
                                 Object. */
            GLuint m_QuadEBO; /**< ID pointing to Quad's OpenGL Element Buffer
                                 Object. */

            Shader m_QuadShader; /**< Quad's Shader object. */
            Texture m_QuadTexture; /**< Quad's Texture object. */

            glm::mat4 m_MVP;
        };
    } // namespace Primatives
} // namespace Graphics
