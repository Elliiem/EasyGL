#pragma once

#include <GL/glew.h>

#include <string>

class EGL_Shader{
    public:
    EGL_Shader(const std::string& file_name);
    ~EGL_Shader();

    void Bind();
    void SetCol(float r,float g,float b,float a);
    
    private:
    static const unsigned int NUM_SHADERS = 2;
    GLuint program;
    GLuint shaders[NUM_SHADERS];
    uint8_t col;
};
