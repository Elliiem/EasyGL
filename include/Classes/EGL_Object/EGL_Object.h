#pragma once

#include "EGL_Hitbox.h"

class EGL_Object : public EGL_Mesh{
    struct HitInfo{
    HitInfo(EGL_Object* other, std::vector<EGL_Vector> hit_points){
        this->other = other;
        this->hit_points = hit_points;
    }

    EGL_Object* other;
    std::vector<EGL_Vector> hit_points;
    };

    public:
    EGL_Object(std::vector<EGL_Point>* points,void(*func)(EGL_Object*),bool isphysics = false);
    EGL_Object(std::vector<EGL_Point>* points,bool isphysics = false);
    ~EGL_Object();

    void (*func)(EGL_Object*);
    std::vector<HitInfo> hits;


    // Drawing Stuff

    void Draw();
    void Draw(float x, float y, float z);
    void SetPos(float x,float y,float z);
    void SetPos(EGL_Vector pos);
    void Rotate(float x,float y,float z);    

    // Physics Stuff
    
    void Update();
    void Move(EGL_Vector pos);
    void Move(float x,float y,float z);
    
    void SetVel(EGL_Vector vel);
    void SetVel(float x,float y,float z);
    void AddVel(EGL_Vector add);
    void Accelerate(EGL_Vector acc);

    EGL_Vector GetVel();

    std::vector<EGL_Vector> CheckColision(EGL_Object* other);

    private:
    void ClearHits();

    private:
    EGL_Vector last_pos;
    EGL_Vector acceleration;
    EGL_Hitbox* box;
    bool isphysics = false;
};