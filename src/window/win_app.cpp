#include "win_app.h"

#include <iostream>

WinApp::WinApp(uint16_t width, uint16_t height, const std::string& title) :
    width_{width}, height_{height}, title_{title}
{

}

WinApp::~WinApp()
{
}

bool WinApp::init(){
     // glfw: initialize and configure
    // ------------------------------
    if(!glfwInit()){
        std::cout << "GLFW init failed!\n";
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // glfw window creation
    // --------------------
    window_ = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);
    if (window_ == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

        
    glfwMakeContextCurrent(window_);


    return true;
}   

GLFWwindow* WinApp::getWindow(){
    return window_;
}