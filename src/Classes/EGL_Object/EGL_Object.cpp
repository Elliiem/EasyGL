#include <fmt/format.h>
#include "EGL_Object.h"
#include "EGL_Hitbox.h"

void default_func(EGL_Object* obj){

}

EGL_Object::EGL_Object(std::vector<EGL_Point>* points,void(*func)(EGL_Object*)) : EGL_Mesh(points){
    this->func = func;
}

EGL_Object::EGL_Object(std::vector<EGL_Point>* points) : EGL_Mesh(points){
    func = default_func;
}

EGL_Object::~EGL_Object(){
}

void EGL_Object::Draw(float x,float y,float z){
    SetPos(x,y,z);
    EGL_Mesh::Draw();
}

void EGL_Object::SetPos(float x, float y, float z){
    EGL_Mesh::SetPos(x,y,z);
}

void EGL_Object::SetPos(EGL_Vector pos){
    EGL_Mesh::SetPos(pos);
}

void EGL_Object::Draw(){
    EGL_Mesh::Draw();
}

void EGL_Object::Rotate(float x,float y,float z){
    EGL_Mesh::Rotate(x,y,z);
}

void EGL_Object::Update(){
    func(this);
}
