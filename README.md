# SimpleOpenGLApp
A very simple no-installation or package manager necessary cross-platform OpenGL 4.1 starter project.

## About
This project is perfect for those wanting to start out learning modern OpenGL while remaining cross-platform. Unfortunately, macOS only supports OpenGL up to version 4.1 so developers miss out on nice-haves such as compute shaders however when just starting out this is more than enough to learn the basics even including geometry shaders and tessalation shaders too. The project is CMake based making use of git submodules and CMake's subdirectory feature to provide a simpler, more compartimentalised project.

## Setup
To get started with this project, all that needs to be done is to clone the repository as shown below and you can move onto the next step.
```shell
$ git clone --recursive https://github.com/Michael-Warrick/SimpleOpenGLApp.git
```

## Building
In order to build the project, after having cloned it locally, either use an IDE with CMake capabilities, the CMake GUI App or enter these commands into your shell of choice.
```shell
$ cd SimpleOpenGLApp
```
```shell
$ mkdir build
```
```shell
$ cd build
```
```shell
$ cmake ..
```

## Resources
- CMake Docs: https://cmake.org/documentation/
- LearnOpenGL.com: https://learnopengl.com/