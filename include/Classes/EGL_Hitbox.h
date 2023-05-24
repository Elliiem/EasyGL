#pragma once

#include "EGL_Point.h"
#include "EGL_Mesh.h"
#include <vector>

class EGL_Hitbox : public EGL_Mesh{
    public:
    EGL_Hitbox(std::vector<EGL_Point>* points);
    EGL_Hitbox(){

    }

    // Returns all points from this Hitbox that are in other, in a vector
    std::vector<EGL_Vector> CheckCollision(EGL_Hitbox* other);
    
    // Checks if point is in this Hitbox 
    bool CheckPoint(EGL_Vector point);

    private:
    // Checks if the line q and p are intersecting
    // Is p2 not given p gets treated as a "ray" in the positive x
    bool LineIntersect(EGL_Vector q1,EGL_Vector q2, EGL_Vector p1);
    bool LineIntersect(EGL_Vector q1,EGL_Vector q2, EGL_Vector p1,EGL_Vector p2);
};
