#pragma once

#include <vector>
#include "EGL_Object.h"

class EGL_Physics{
    public:
    std::vector<EGL_Object> objects;

    void UpdatePhysics();
    
    EGL_Object* AddObject(std::vector<EGL_Point>* points);

};