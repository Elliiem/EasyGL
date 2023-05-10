#ifndef EGL_PHYSICSOBJECT
#define EGL_PHYSICSOBJECT

#include "EGL_Hitbox.h"

class EGL_Object : public EGL_Poly{
    public:
    EGL_Object(std::vector<EGL_Point>* points);
    ~EGL_Object(){
        delete box;
    }

    EGL_Hitbox* box;


    // Drawing Stuff
    void Draw();
    void Draw(float x, float y, float z);
    void Rotate(float x,float y,float z);
    void SetPos(float x,float y,float z);
    

    // Physics Stuff
    void Update();

    EGL_Vector last_pos;
    EGL_Vector acceleration
};


#endif