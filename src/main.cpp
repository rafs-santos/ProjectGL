#include <iostream>

//#include <stb_image.h>
//#include "window/win_app.h"
//#include "renderer/renderer.h"

#include "game/game.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    Game game;

    game.start();
    game.run();
    game.shutDown();

    return 0;
}