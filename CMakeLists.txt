cmake_minimum_required(VERSION 3.16)
project(DashboardPrototype VERSION 1.0.0)

# Setting C++ Version to 2020
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Creating glad library for OpenGL 4.1
add_subdirectory(Vendor/glad/cmake glad_cmake)
glad_add_library(glad_gl_core_41 REPRODUCIBLE API gl:core=4.1)

add_subdirectory(Vendor/glfw)

add_executable(${PROJECT_NAME}
    # Graphics
    Graphics/Renderer.cpp
    Graphics/Shader.cpp

    # Core
    Core/Application.cpp
    Core/Window.cpp
    Core/main.cpp
)

# Includes for first-party headers
target_include_directories(${PROJECT_NAME}
PUBLIC
    $<INSTALL_INTERFACE:${CMAKE_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
)

# Includes for third-party headers
target_include_directories(${PROJECT_NAME}
PRIVATE
    glfw
)

target_link_libraries(${PROJECT_NAME}
PUBLIC 
    glad_gl_core_41
    glfw
)

add_custom_target(copy_resources ALL
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${PROJECT_SOURCE_DIR}/Resources
  ${CMAKE_BINARY_DIR}/Bin/Resources
  COMMENT "Copying resources into binary directory"
)