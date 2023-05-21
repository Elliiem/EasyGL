#pragma once

#include "EGL_Object.h"


class EGL_PhysicsObject : public EGL_Object{
    public:
    EGL_PhysicsObject(std::vector<EGL_Point>* points,void(*func)(EGL_PhysicsObject*));
    EGL_PhysicsObject(std::vector<EGL_Point>* points);
    ~EGL_PhysicsObject();

    struct HitInfo{
        HitInfo(EGL_Object* other, std::vector<EGL_Vector> hit_points,std::vector<EGL_Hitbox*> box = {}){
            this->other = other;
            this->hit_points = hit_points;
            this->box = box;
        }

        std::vector<EGL_Hitbox*> box;
        EGL_Object* other;
        std::vector<EGL_Vector> hit_points;
    };

    EGL_Hitbox* box;
    std::vector<HitInfo> hits;
    void (*func)(EGL_PhysicsObject*);

    public:
    void Draw();
    void Draw(float x, float y, float z);
    void SetPos(float x,float y,float z);
    void SetPos(EGL_Vector pos);
    void Rotate(float x,float y,float z);    

    void Move(float x,float y,float z);
    void Move(EGL_Vector pos);
    
    void SetVel(float x,float y,float z);
    void SetVel(EGL_Vector vel);
    void AddVel(float x,float y,float z);
    void AddVel(EGL_Vector add);
    void Accelerate(float x,float y,float z);
    void Accelerate(EGL_Vector acc);
    EGL_Vector GetVel();

    std::vector<EGL_Vector> CheckColision(EGL_PhysicsObject* other);

    void Update();

    private:
    EGL_Vector last_pos;
    EGL_Vector acceleration;
};