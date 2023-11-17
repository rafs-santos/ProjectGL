#include "game.h"
#include <iostream>



Game::Game(/* args */)
{
}

Game::~Game()
{
}

void Game::start(){
    // Maybe create my callback before call this
    
    m_window = new WinApp(1600, 900, "Rafael");

    if(!m_window->init()){
        std::cout << "Failed to initialize glfw" << std::endl;
    }
    if (!m_window->initGlad())
    {
        std::cout << "GLAD init failed!";
    }
    glfwSetKeyCallback(m_window->getWindow(), keyCallBack);
    glfwSetWindowUserPointer(m_window->getWindow(), this);
    m_renderer.init();
    //renderer.shaders("resources/shader/shader.vs", "resources/shader/shader.fs");
    // Make a quad with two triangles
 
    // Load texture
    m_renderer.loadTexture("resources/textures/container.jpg");
    m_renderer.use();   
    glUniform1i(glGetUniformLocation(m_renderer.m_ID, "texture1"), 0);
}

void Game::run(){

    // Start game
    m_running = true;
    while (m_running)
    {
        // input
        // -----
        glfwPollEvents();
        m_running = m_window->processInput();
        //if(m_window->getIsKeyDown(GLFW_KEY_SPACE))
        //    std::cout << "Detected Key\n";
        
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // bind textures on corresponding texture units
        m_renderer.bindTexture();
        //renderer.bindTexture();
        // render the triangle
        m_renderer.use();

        m_renderer.drawQuad();


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(m_window->getWindow());
    }
}

void Game::shutDown(){
    m_window->shutdown();
}

void Game::keyUpdate(){
    std::cout << "entrei\n";
}

void Game::keyCallBack(GLFWwindow* window, int  key, int scancode, int action, int mods){
    std::cout << "GLFW Key Callback!\n";
    Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));
    if(game){
        game->keyUpdate();
    }
}