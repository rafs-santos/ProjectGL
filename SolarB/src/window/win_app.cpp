#include <iostream>

#include "win_app.h"
#include "game/game.h"

std::map<int, bool> keys {
        {GLFW_KEY_SPACE , false},
        {GLFW_KEY_W     , false},
        {GLFW_KEY_A     , false}
    };

SolarB::WinApp::WinApp(uint16_t width, uint16_t height, const std::string& title) :
    m_width{width}, m_height{height}, m_title{title}
{
}

SolarB::WinApp::~WinApp()
{
}

void SolarB::WinApp::keyCallBack(GLFWwindow* window, int  key, int scancode, int action, int mods){
    std::map<int,bool>::iterator it = keys.find(key);
    if (it != keys.end()) {
        keys[key] = action == GLFW_PRESS;
    }
}

bool SolarB::WinApp::init(){
    // glfw: initialize and configure
    // ************************************************************************************
    if(!glfwInit()){
        std::cout << "GLFW init failed!\n";
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // ************************************************************************************
    // glfw window creation
    // ************************************************************************************
    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }    
    glfwMakeContextCurrent(m_window);
    
    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GLFW_TRUE);
    
    // ************************************************************************************
    // Init callbacks to process inputs
    // ************************************************************************************
    //glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
    //    std::cout << "GLFW Key Callback!\n";
    //    // call my function to handle callback
    //    Game::keyUpdate();
    //}
    //);

    glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
    {
        std::cout << "GLFW Mouse Callback!\n";
    });

    glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height){
        glViewport(0, 0, width, height);
    }
    );

    return true;
}   

bool SolarB::WinApp::initGlad(){
    // init Renderer
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD!\n";
        return false;
    }
    std::cout << "GLAD init successful!\n";
    return true;
  }

bool SolarB::WinApp::getIsKeyDown(int key) {
    bool result = false;
    std::map<int,bool>::iterator it = keys.find(key);
    if (it != keys.end()) {
        result = keys[key];
    }
    return result;
}
void SolarB::WinApp::setIsKeyDown(int key, bool isDown){
    std::map<int,bool>::iterator it = keys.find(key);
    if (it != keys.end()) {
        keys[key] = isDown;
    }
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
bool SolarB::WinApp::processInput()
{
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(m_window))
        return false;
    return true;
}

void SolarB::WinApp::shutdown(){
    glfwDestroyWindow(m_window);
    glfwTerminate();
}


GLFWwindow* SolarB::WinApp::getWindow(){
    return m_window;
}

void setKeyCallBack(){
    
}