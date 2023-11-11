#include <iostream>

#include "win_app.h"

WinApp::WinApp(uint16_t width, uint16_t height, const std::string& title) :
    m_width{width}, m_height{height}, m_title{title}
{
}

WinApp::~WinApp()
{
}

bool WinApp::init(){
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
    // ************************************************************************************
    // Init callbacks to process inputs
    // ************************************************************************************
    glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
        std::cout << "GLFW Key Callback!\n";
    }
    );

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

bool WinApp::initGlad(){
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

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void WinApp::processInput()
{
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window, true);
}

void WinApp::shutdown(){
    glfwDestroyWindow(m_window);
    glfwTerminate();
}


GLFWwindow* WinApp::getWindow(){
    return m_window;
}