#include "game.h"
#include <iostream>
#include <glad/glad.h>


Game::Game(/* args */)
{
}

Game::~Game()
{
}

void Game::start(){
    m_window = new WinApp(1600, 900, "Rafael");

    if(!m_window->init()){
        std::cout << "Failed to initialize glfw" << std::endl;
    }
    if (!m_window->initGlad())
    {
        std::cout << "GLAD init failed!";
    }

    m_renderer.init();
    //renderer.shaders("resources/shader/shader.vs", "resources/shader/shader.fs");
    // Make a quad with two triangles
 
    // Load texture
    m_renderer.loadTexture("resources/textures/container.jpg");
    m_renderer.use();   
    glUniform1i(glGetUniformLocation(m_renderer.m_ID, "texture1"), 0);
}

void Game::run(){
    while (!glfwWindowShouldClose(m_window->getWindow()))
    {
        // input
        // -----
        glfwPollEvents();
        m_window->processInput();

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