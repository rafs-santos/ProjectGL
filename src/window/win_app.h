#ifndef WINAPP_H
#define WINAPP_H

#include <string>
#include <cstdint>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class WinApp
{
public:
    WinApp(uint16_t width, uint16_t height, const std::string& title);
    ~WinApp();
    
    bool init();
    bool initGlad();
    GLFWwindow* getWindow();
    void processInput();
    void shutdown();
  

private:
    /* data */
    uint16_t m_width;
    uint16_t m_height;
    std::string m_title;

    GLFWwindow* m_window{nullptr};
};




#endif