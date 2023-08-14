#include "application.hpp"

Application::Application()
{
}

Application::~Application()
{
}

void Application::Run() 
{
    while(window.IsOpen())
    {
        window.Present();
    }
}