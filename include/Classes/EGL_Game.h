#pragma once

#include "EGL_Window.h"
#include "EGL_Object.h"
#include "EGL_PhysicsObject.h"

#include <vector>
#include <iostream>

class EGL_Game{
    public:
    EGL_Game(EGL_Window* win,EGL_Render* rend);
    ~EGL_Game();

    std::vector<EGL_PhysicsObject*> physics_objects;
    std::vector<EGL_Object*> static_objects;

    EGL_Window* win;
    EGL_Render* rend;

    public:
    EGL_PhysicsObject* AddPhysicsObject(std::vector<EGL_Point>* points,void(*func)(EGL_PhysicsObject*,EGL_Window*),std::string id);
    EGL_Object* AddStaticObject(std::vector<EGL_Point>* points,void(*func)(EGL_Object*,EGL_Window*),std::string id);
    EGL_PhysicsObject* AddPhysicsObject(std::vector<EGL_Point>* points,std::string id);
    EGL_Object* AddStaticObject(std::vector<EGL_Point>* points,std::string id);
    
    void DeleteObject(EGL_Object* obj);
    void Update();
    void UpdateCollisions();
    void ChangeScene(std::vector<EGL_PhysicsObject*> physics_obj, std::vector<EGL_Object*> static_obj);
};