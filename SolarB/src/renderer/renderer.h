#ifndef Renderer_H
#define Renderer_H

#include <iostream>
#include <vector>
#include <unordered_map>

namespace SolarB{
    class Renderer
    {
    public:
        unsigned int m_ID;
        std::vector<unsigned int> m_textureID;
        static void init();
        static void drawQuad();
        // copy shader from learnopengl code
        static void shaders(const char* , const char* , const char* );

        void use();
        void quadData();
        void loadTexture(const char* texturePath);
       
        void bindTexture();

        const std::vector<unsigned int>& getTextureIDs() const {
            return m_textureID;
        }
    private:
        static void checkCompileErrors(unsigned int shader, std::string type);
        
        std::unordered_map<std::string, unsigned int> m_shaders;  // Map shader names to their IDs

        unsigned int VBO, VAO, EBO;
    };
}

#endif