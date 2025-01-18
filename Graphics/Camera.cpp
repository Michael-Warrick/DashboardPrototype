#include "Camera.hpp"

Graphics::Camera::Camera(glm::vec3 position) {
    m_Position = position;

    updateCameraVectors();
}

void Graphics::Camera::ProcessKeyboard(Movement direction, float deltaTime) {
    float velocity = m_MovementSpeed * deltaTime;

    if (direction == Movement::eForward) {
        m_Position += m_Front * velocity;
    }
    if (direction == Movement::eBackward) {
        m_Position -= m_Front * velocity;
    }
    if (direction == Movement::eLeft) {
        m_Position -= m_Right * velocity;
    }
    if (direction == Movement::eRight) {
        m_Position += m_Right * velocity;
    }
}

void Graphics::Camera::ProcessMouseMovement(float offsetX, float offsetY) {
    offsetX *= m_MouseSensitivity;
    offsetY *= m_MouseSensitivity;

    m_Yaw += offsetX;
    m_Yaw += offsetY;

    if (m_Pitch > 90.0f) {
        m_Pitch = 90.0f;
    }
    if (m_Pitch < -90.0f) {
        m_Pitch = -90.0f;
    }

    updateCameraVectors();
}

glm::mat4 Graphics::Camera::viewMatrix() {
    return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

glm::mat4 Graphics::Camera::projectionMatrix(uint32_t viewportWidth,
                                             uint32_t viewportHeight) {
    return glm::perspective(glm::radians(m_FOV),
                            static_cast<float>(viewportWidth) /
                                static_cast<float>(viewportHeight),
                            0.1f, 100.0f);
}

void Graphics::Camera::updateCameraVectors() {
    // Calculate new front vector
    glm::vec3 front;
    front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    front.y = sin(glm::radians(m_Pitch));
    front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));

    m_Front = front;

    // Recalculate Right and Up vectors too
    // Normalising vectors as the more you look up or down,
    // their lengths get closer to 0, resulting in slower
    // movement.
    m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
    m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}