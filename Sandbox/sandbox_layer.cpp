#include "sandbox_layer.h"

#include <iostream>
namespace Sandbox{
    void SandboxLayer::init()
    {
        std::cout << " Sandbox Layer Init\n";
    }
    void SandboxLayer::update()
    {
        //SolarB::drawQuad();
    }
    void SandboxLayer::render()
    {
    }
    void SandboxLayer::shutdown()
    {
    }
}