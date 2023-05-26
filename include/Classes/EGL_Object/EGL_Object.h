#pragma once

#include "EGL_Hitbox.h"
#include "EGL_Window.h"
#include "EGL_Mesh.h"
#include "EGL_Render.h"
#include "EGL_Vector.h"

#include <vector>
#include <string>
#include <iostream>

class EGL_Object : public EGL_Mesh{
    public:
    EGL_Object(std::vector<EGL_Point>* points,void(*func)(EGL_Object*,EGL_Window*),std::string id);
    EGL_Object(std::vector<EGL_Point>* points,std::string id);
    ~EGL_Object();
    
    std::string id;

    void (*func)(EGL_Object*,EGL_Window*);

    void Draw(EGL_Render* win);
    void SetPos(float x,float y,float z);
    void SetPos(EGL_Vector pos);
    void Rotate(float x,float y,float z);    
    
    void Update(EGL_Window* win);

    EGL_Object* AddChild(std::vector<EGL_Point>* points,void(*func)(EGL_Object*,EGL_Window*),std::string id);
    void RemoveChild(EGL_Object* obj);


    private:
    std::vector<EGL_Object*> children;
};