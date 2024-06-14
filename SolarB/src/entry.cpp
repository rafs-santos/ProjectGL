
#include "game/game.h"

int main()
{   
    std::cout << "Entry Point file\n";

    auto game = SolarB::createGame();
    
    game->start();
    game->run();
    game->shutDown();

    return 0;
}