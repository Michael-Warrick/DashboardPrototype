#pragma once
#include "Graphics/Renderer.hpp"
#include "Window.hpp"

class Application {
public:
    Application();
    ~Application() = default;
    
    void Run();

private:
    Window m_Window;
    Renderer m_Renderer;
};