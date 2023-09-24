#ifndef WINAPP_H
#define WINAPP_H

#include <string>
#include <cstdint>
#include <GLFW/glfw3.h>

class WinApp
{
public:
    WinApp(uint16_t width, uint16_t height, const std::string& title);
    ~WinApp();
    
    bool init();

    GLFWwindow* getWindow();

private:
    /* data */
    uint16_t width_;
    uint16_t height_;
    std::string title_;

    GLFWwindow* window_{nullptr};
};




#endif