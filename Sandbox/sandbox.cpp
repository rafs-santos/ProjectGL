#include <iostream>
#include <memory>

#include "game/game.h"
#include "sandbox_layer.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

class SandboxGame : public SolarB::Game
{
public:
    SandboxGame(const std::string& name) : Game(name) {
        addLayer(new Sandbox::SandboxLayer{});
    }
    ~SandboxGame();

private:
    /* data */

};

std::unique_ptr<SolarB::Game> SolarB::createGame(){
    return std::make_unique<SandboxGame>("SandBox");
}
// int main()
// {   
//     std::cout << "sandbox_layer\n";
//     SolarB::Game game;
//     game.addLayer(new Sandbox::SandboxLayer{});

//     game.start();
//     game.run();
//     game.shutDown();

//     return 0;
// }