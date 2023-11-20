#ifndef WINAPP_H
#define WINAPP_H

#include <string>
#include <cstdint>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <map>

namespace SolarB{
    class WinApp
    {
    public:
        WinApp(uint16_t width, uint16_t height, const std::string& title);
        ~WinApp();
        
        bool init();
        bool initGlad();
        GLFWwindow* getWindow();
        bool getIsKeyDown(int key);

        void setKeyCallBack();
        bool processInput();
        void shutdown();
    

    private:
        // Used internally to update key states.  Called by the GLFW callback.
        void setIsKeyDown(int key, bool isDown);
        static void keyCallBack(GLFWwindow* window, int  key, int scancode, int action, int mods);
        /* data */
        // Map from monitored keyes to their pressed states
        
        uint16_t m_width;
        uint16_t m_height;
        std::string m_title;

        GLFWwindow* m_window{nullptr};
    };
}



#endif