#pragma once

#include "EGL_Hitbox.h"

class EGL_Object : public EGL_Mesh{
    public:
    EGL_Object(std::vector<EGL_Point>* points);
    ~EGL_Object(){
        delete box;
    }

    EGL_Hitbox* box;


    // Drawing Stuff
    void Draw();
    void Draw(float x, float y, float z);
    void Rotate(float x,float y,float z);
    void SetPos(float x,float y,float z);
    void SetPos(EGL_Vector pos);
    

    // Physics Stuff
    void Update();

    EGL_Vector GetVel(){
        return pos-last_pos;
    }

    std::vector<EGL_Vector> CheckColision(EGL_Object* other);

    EGL_Vector last_pos;
    EGL_Vector acceleration;
};
