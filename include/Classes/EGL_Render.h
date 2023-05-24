#pragma once

#include "EGL_Shader.h"
#include "EGL_Color.h"

class EGL_Render{
    public:
    EGL_Render(EGL_Shader* shader);

    void SetClearCol(float r,float g,float b,float a);
    void SetClearCol(EGL_Color col);
    void SetDrawCol(float r,float g,float b,float a);
    void SetDrawCol(EGL_Color col);

    void Clear();
    void Update();

    void BindShader();
    void BindShader(EGL_Shader* new_shader);

    private:
    EGL_Shader* shader;
};