#include "window/win_app.h"
#include "renderer/renderer.h"
class Game
{

public:
    Game(/* args */);
    ~Game();

    void start();
    void run();
    void shutDown();
private:
    bool m_running = false;
    // Try to understand when use pointer and when not use 
    WinApp* m_window{nullptr};
    Renderer m_renderer;
};



