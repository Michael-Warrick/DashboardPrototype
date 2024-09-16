cmake_minimum_required(VERSION 3.25.3)
project(Xbox-360-Dashboard VERSION 0.0.1 LANGUAGES CXX)

# Setting C++ Version to 2020
set(CMAKE_CXX_STANDARD 20)

# Including libraries as subdirectories
add_subdirectory(vendor/cmake-glad2)
add_subdirectory(vendor/glfw)

add_executable(${PROJECT_NAME} 
    # Headers
    ${CMAKE_SOURCE_DIR}/include/application.hpp
    ${CMAKE_SOURCE_DIR}/include/window.hpp
    ${CMAKE_SOURCE_DIR}/include/renderer.hpp
    ${CMAKE_SOURCE_DIR}/include/shader.hpp

    # Sources
    ${CMAKE_SOURCE_DIR}/src/main.cpp

    ${CMAKE_SOURCE_DIR}/src/application.cpp
    ${CMAKE_SOURCE_DIR}/src/window.cpp
    ${CMAKE_SOURCE_DIR}/src/renderer.cpp
    ${CMAKE_SOURCE_DIR}/src/shader.cpp
)

# Including added libraries
target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    cmake-glad2
    glfw
)

target_link_libraries(${PROJECT_NAME}
    cmake-glad2
    glfw
)