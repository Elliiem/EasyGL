#pragma once

#include "EGL_Hitbox.h"
#include "EGL_Window.h"
#include "EGL_Render.h"

class EGL_Object : public EGL_Mesh{
    public:
    EGL_Object(std::vector<EGL_Point>* points,void(*func)(EGL_Object*,EGL_Window*));
    EGL_Object(std::vector<EGL_Point>* points);
    ~EGL_Object();

    void (*func)(EGL_Object*,EGL_Window*);

    void Draw(EGL_Render* win);
    void SetPos(float x,float y,float z);
    void SetPos(EGL_Vector pos);
    void Rotate(float x,float y,float z);    
    
    void Update(EGL_Window* win);

    void SetCol(EGL_Color col);
    void SetCol(float r,float g,float b,float a);

    private:
    EGL_Color col = EGL_Color(0.25f,0.25f,0.25f,1.0f);
    std::vector<EGL_Object*> children;
};