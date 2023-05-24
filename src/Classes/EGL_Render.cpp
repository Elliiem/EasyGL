#include "EGL_Render.h"

EGL_Render::EGL_Render(EGL_Shader* shader){
    this->shader = shader;
    BindShader();
}

void EGL_Render::SetClearCol(float r, float g, float b, float a){
    glClearColor(r,g,b,a);
}

void EGL_Render::SetClearCol(EGL_Color col){
    glClearColor(col.r,col.g,col.b,col.a);
}

void EGL_Render::SetDrawCol(float r, float g, float b, float a){
    shader->SetCol(r,g,b,a);
}

void EGL_Render::SetDrawCol(EGL_Color col){
    shader->SetCol(col.r,col.g,col.b,col.a);
}

void EGL_Render::Clear(){
    glClear(GL_COLOR_BUFFER_BIT);
}

void EGL_Render::Update(){
    Clear();
}

void EGL_Render::BindShader(){
    shader->Bind();
}

void EGL_Render::BindShader(EGL_Shader *new_shader)
{
    shader = new_shader;
    shader->Bind();
}
