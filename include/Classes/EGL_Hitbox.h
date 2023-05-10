#pragma once

#include "EGL_Point.h"
#include "EGL_Poly.h"

#include <vector>

class EGL_Hitbox : public EGL_Poly{
    public:
    EGL_Hitbox(std::vector<EGL_Point>* points);
    EGL_Hitbox(){

    }

    std::vector<EGL_Vector> CheckCollision(EGL_Hitbox* other);

    private:
    bool CheckLineIntersect(EGL_Vector q1,EGL_Vector q2, EGL_Vector p1);
};
