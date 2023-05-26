#pragma once

#include "EGL_Object.h"


class EGL_PhysicsObject : public EGL_Object{
    public:
    EGL_PhysicsObject(std::vector<EGL_Point>* points,void(*func)(EGL_PhysicsObject*,EGL_Window*),std::string id);
    EGL_PhysicsObject(std::vector<EGL_Point>* points,std::string id);
    ~EGL_PhysicsObject();

    struct HitInfo{
        HitInfo(EGL_PhysicsObject* other, std::vector<EGL_Vector> hit_points,std::vector<EGL_Hitbox*> box = {}){
            this->other = other;
            this->hit_points = hit_points;
            this->box = box;
        }

        std::vector<EGL_Hitbox*> box;
        EGL_PhysicsObject* other;
        std::vector<EGL_Vector> hit_points;
    };

    EGL_Hitbox* box;
    std::vector<HitInfo> hits;
    void (*func)(EGL_PhysicsObject*,EGL_Window*);

    public:
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

    std::vector<EGL_Vector> Collide(EGL_PhysicsObject* other);
    HitInfo* FindHit(std::string id);

    void Update(EGL_Window* win);

    EGL_PhysicsObject* AddChild(std::vector<EGL_Point>* points,void(*func)(EGL_PhysicsObject*,EGL_Window*),std::string id);
    void RemoveChild(EGL_PhysicsObject* obj);

    private:
    EGL_Vector last_pos;
    EGL_Vector acceleration;
    std::vector<EGL_PhysicsObject*> children;
};