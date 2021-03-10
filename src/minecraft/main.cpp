#include "../engine/glf.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "game.h"

int main()
{
    Game* game = new Game();

    engine::Application application;
	application.InitializeWindow(720, 720, "OpenGL Window");
    application.AddUpdatable(game);
    application.Start();

    return 0;
}