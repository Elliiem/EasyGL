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

    EGL_Vector vel;
    EGL_Vector rot_vel;
    EGL_Vector acc;


    void Draw();
    void Draw(float x, float y, float z);
    void Rotate(float x,float y,float z);
    void SetPos(float x,float y,float z);
    
    void Update();
    
    private:
    void Deccelerate();
    void HandleCollision(const EGL_Hitbox& other);
};


#endif