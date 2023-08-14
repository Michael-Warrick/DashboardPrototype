#pragma once
#include "window.hpp"

class Application
{
public:
    Application();
    ~Application();

    void Run();
private:
    Window window;
};
