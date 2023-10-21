#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stb_image.h>
#include "window/win_app.h"
#include "renderer/renderer.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // Init and create a windows
    WinApp win_app{1600, 900, "Rafael"};
    if(!win_app.init()){
        std::cout << "Failed to initialize glfw" << std::endl;
        return -1;
    }
    if (!win_app.initGlad())
    {
        std::cout << "GLAD init failed!";
        return -1;
    }

    Renderer renderer;
    renderer.init();
    //renderer.shaders("resources/shader/shader.vs", "resources/shader/shader.fs");
    // Make a quad with two triangles
 
    // Load texture
    renderer.loadTexture("resources/textures/container.jpg");
    renderer.use();   
    glUniform1i(glGetUniformLocation(renderer.m_ID, "texture1"), 0);
    //ourShader.setInt("texture2", 1);
    // render loop
    // -----------
    while (!glfwWindowShouldClose(win_app.getWindow()))
    {
        // input
        // -----
        processInput(win_app.getWindow());

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // bind textures on corresponding texture units
        //glActiveTexture(GL_TEXTURE0);
        //glBindTexture(GL_TEXTURE_2D, renderer.m_textureID[0]);
        renderer.bindTexture();
        //renderer.bindTexture();
        // render the triangle
        renderer.use();

        renderer.drawQuad();


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(win_app.getWindow());
        glfwPollEvents();
    }
    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}