#pragma once

#include "EGL_Object.h"

class EGL_PhysicsObject : public EGL_Object{
    EGL_PhysicsObject(std::vector<EGL_Point>* points,void(*func)(EGL_Object*));
    EGL_PhysicsObject(std::vector<EGL_Point>* points);
    ~EGL_PhysicsObject();
};