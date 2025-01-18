#pragma once

#include <cstdint>
#include <cmath>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Graphics {
    class Camera {
    public:
        enum class Movement {
            eForward,
            eBackward,
            eLeft,
            eRight
        };

        Camera() = default;
        Camera(glm::vec3 position);
        ~Camera() = default;

        void ProcessKeyboard(Movement direction, float deltaTime);
        void ProcessMouseMovement(float offsetX, float offsetY);

        glm::mat4 viewMatrix();
        glm::mat4 projectionMatrix(uint32_t viewportWidth, uint32_t viewportHeight);
    private:
        void updateCameraVectors();
        
        glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 m_Front = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 m_Up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 m_Right;
        glm::vec3 m_WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
        
        float m_Yaw = -90.0f;
        float m_Pitch = 0.0f;

        float m_MovementSpeed = 2.5f;
        float m_MouseSensitivity = 0.1f;
        float m_FOV = 45.0f;
    };
} // namespace Graphics
