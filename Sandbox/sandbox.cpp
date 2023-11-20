#include <iostream>


#include "game/game.h"
#include "sandbox_layer.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{   
    std::cout << "sandbox_layer\n";
    SolarB::Game game;
    game.addLayer(new Sandbox::SandboxLayer{});

    game.start();
    game.run();
    game.shutDown();

    return 0;
}