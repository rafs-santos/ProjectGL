#ifndef SANDBOX_LAYER_H
#define SANDBOX_LAYER_H

#include <layer/layer.h>

namespace Sandbox{
    class SandboxLayer : public SolarB::Layer
    {
    
    public:
        SandboxLayer() : Layer("SandboxLayer") {}
        
        void init() override;
        void update() override;
        void render() override;
        void shutdown() override;
    private:

    };
}
#endif