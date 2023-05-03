#ifndef EGL_PHYSICSOBJECT
#define EGL_PHYSICSOBJECT

#include "EGL_Hitbox.h"

class EGL_PhysicsObject : public EGL_Poly{
    public:
    EGL_PhysicsObject(std::vector<EGL_Point>* points);
    ~EGL_PhysicsObject(){
        delete box;
    }
    EGL_Hitbox* box;

    void Draw();
    void Draw(float x, float y, float z);
    void Rotate(float x,float y,float z);
    void SetPos(float x,float y,float z);
    
    void Update();
};


#endif