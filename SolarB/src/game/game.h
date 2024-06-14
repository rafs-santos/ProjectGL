#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window/win_app.h"
#include "renderer/renderer.h"
#include "layer/layer.h"

#include <vector>
#include <memory>

namespace SolarB{
    class Game
    {
    public:
        Game(const std::string name);
        // ~Game();

        static void keyCallBack(GLFWwindow* window, int  key, int scancode, int action, int mods);
        void keyUpdate();
        void start();
        void run();
        void shutDown();

        void addLayer(Layer* layer);
    private:
        std::string m_name{};
        bool m_running = false;
        // Try to understand when use pointer and when not use 
        WinApp* m_window{nullptr};
        Renderer m_renderer;

        std::vector<Layer*> m_layers;
    };

    std::unique_ptr<Game> createGame();
}
#endif

