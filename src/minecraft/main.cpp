#include "../engine/glf.h"

#include <iostream>

int main()
{
    engine::Application::Config config;
    config.width = 720;
    config.height = 720;
    config.title = "OpenGL Minecraft";

    engine::Application app;
    if (!app.Initialize(config))
    {
        std::cout << "Application initialization failed." << std::endl;
        std::exit(-1);
    }

    app.Start();

    return 0;
}