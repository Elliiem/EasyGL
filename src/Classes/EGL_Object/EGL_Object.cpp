#include <fmt/format.h>
#include "EGL_Object.h"
#include "EGL_Hitbox.h"

void default_func(EGL_Object* obj,EGL_Window* win){

}

EGL_Object::EGL_Object(std::vector<EGL_Point>* points,void(*func)(EGL_Object*,EGL_Window*)) : EGL_Mesh(points){
    this->func = func;
}

EGL_Object::EGL_Object(std::vector<EGL_Point>* points) : EGL_Mesh(points){
    func = default_func;
}

EGL_Object::~EGL_Object(){
}

void EGL_Object::SetPos(float x, float y, float z){
    EGL_Mesh::SetPos(x,y,z);
}

void EGL_Object::SetPos(EGL_Vector pos){
    EGL_Mesh::SetPos(pos);
}

void EGL_Object::Draw(EGL_Render* rend){
    rend->SetDrawCol(col);
    EGL_Mesh::Draw();
}

void EGL_Object::Rotate(float x,float y,float z){
    EGL_Mesh::Rotate(x,y,z);
}

void EGL_Object::Update(EGL_Window* win){
    func(this, win);
}

void EGL_Object::SetCol(EGL_Color col){
    this->col = col;
}

void EGL_Object::SetCol(float r, float g, float b, float a){
    col = EGL_Color(r,g,b,a);
}
