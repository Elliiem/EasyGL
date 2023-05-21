#pragma once

#include "EGL_Hitbox.h"

class EGL_Object : public EGL_Mesh{
    public:
    EGL_Object(std::vector<EGL_Point>* points,void(*func)(EGL_Object*));
    EGL_Object(std::vector<EGL_Point>* points);
    ~EGL_Object();

    void (*func)(EGL_Object*);

    void Draw();
    void Draw(float x,float y,float z);
    void SetPos(float x,float y,float z);
    void SetPos(EGL_Vector pos);
    void Rotate(float x,float y,float z);    
    
    void Update();

    private:
    std::vector<EGL_Object*> children;
};