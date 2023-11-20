#include "Game.h"
#include <iostream>



SolarB::Game::Game(/* args */)
{
}

SolarB::Game::~Game()
{
}

void SolarB::Game::start(){
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
    m_renderer.loadTexture("./resources/textures/container.jpg");
    m_renderer.use();   
    glUniform1i(glGetUniformLocation(m_renderer.m_ID, "texture1"), 0);


    for(auto layer : m_layers){
        layer->init();
    }

}

void SolarB::Game::run(){

    // Start SolarB::Game
    m_running = true;
    while (m_running)
    {
        // input
        // -----
        glfwPollEvents();
        m_running = m_window->processInput();
        
        for(auto layer : m_layers){
            layer->update();
        }

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // bind textures on corresponding texture units
        m_renderer.bindTexture();
        //renderer.bindTexture();
        // render the triangle
        m_renderer.use();

        //m_renderer.drawQuad();


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(m_window->getWindow());
    }
}

void SolarB::Game::shutDown(){
    for(auto layer : m_layers){
        layer->shutdown();
        delete layer;
    }
    m_window->shutdown();

}

void SolarB::Game::addLayer(Layer *layer)
{
    m_layers.emplace_back(layer);
}

void SolarB::Game::keyUpdate(){
    std::cout << "entrei\n";
}

void SolarB::Game::keyCallBack(GLFWwindow* window, int  key, int scancode, int action, int mods){
    std::cout << "GLFW Key Callback!\n";
    SolarB::Game* game = static_cast<SolarB::Game*>(glfwGetWindowUserPointer(window));
    if(game){
        game->keyUpdate();
    }
}