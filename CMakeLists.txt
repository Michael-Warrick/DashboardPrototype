cmake_minimum_required(VERSION 3.25.3)
project(SimpleOpenGLApp VERSION 0.0.1 LANGUAGES CXX)

# Setting C++ Version to 2020
set(CMAKE_CXX_STANDARD 20)

# Including libraries as subdirectories
add_subdirectory(vendor/cmake-glad2)
add_subdirectory(vendor/glfw)

add_executable(${PROJECT_NAME} 
    src/main.cpp
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

target_compile_options(${PROJECT_NAME} PRIVATE -g)