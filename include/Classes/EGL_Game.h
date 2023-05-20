#pragma once

#include "EGL_Window.h"
#include "EGL_Object.h"

#include <vector>
#include <iostream>

class EGL_Game{
    public:
    EGL_Game(EGL_Window* win);
    ~EGL_Game();

    std::vector<EGL_Object*> physics_objects;
    std::vector<EGL_Object*> static_objects;

    EGL_Window* win;

    public:
    EGL_Object* AddPhysicsObject(std::vector<EGL_Point>* points, void(*func)(EGL_Object*));
    EGL_Object* AddStaticObject(std::vector<EGL_Point>* points, void(*func)(EGL_Object*));
    EGL_Object* AddPhysicsObject(std::vector<EGL_Point>* points);
    EGL_Object* AddStaticObject(std::vector<EGL_Point>* points);
    void DeleteObject(EGL_Object* obj);
    void Update();
    void UpdateCollisions();
};