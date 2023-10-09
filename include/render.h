#ifndef RENDER_H
#define RENDER_H

#include <iostream>

class Render
{
public:
    unsigned int m_ID;
    void init();
    // copy shader from learnopengl code
    void shaders(const char* vertexPath, const char* fragmentPath);

    void use();
   
private:
    void checkCompileErrors(unsigned int shader, std::string type);
};




#endif