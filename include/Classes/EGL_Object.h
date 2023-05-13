#pragma once

#include "EGL_Hitbox.h"

class EGL_Object : public EGL_Mesh{
    public:
    EGL_Object(std::vector<EGL_Point>* points,void(*func)(EGL_Object*));
    ~EGL_Object();

    EGL_Hitbox* box;
    void (*func)(EGL_Object*);


    // Drawing Stuff

    void Draw();
    void Draw(float x, float y, float z);
    void Rotate(float x,float y,float z);
    void SetPos(float x,float y,float z);
    void SetPos(EGL_Vector pos);
    

    // Physics Stuff
    void Update();

    EGL_Vector GetVel();
    void SetVel(EGL_Vector vel);
    void AddVel(EGL_Vector add);

    std::vector<EGL_Vector> CheckColision(EGL_Object* other);

    EGL_Vector last_pos;
    EGL_Vector acceleration;
};
