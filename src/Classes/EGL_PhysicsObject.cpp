#include "EGL_Graphics.h"
#include "EGL_Physics.h"
#include <fmt/format.h>

EGL_Object::EGL_Object(std::vector<EGL_Point>* points) : EGL_Poly(points){
    box = new EGL_Hitbox(points);
}

void EGL_Object::Draw(float x,float y,float z){
    SetPos(x,y,z);
    EGL_Mesh::Draw();
    box->SetPos(pos.x,pos.y,pos.z);
}

void EGL_Object::Draw(){
    EGL_Mesh::Draw();
}

void EGL_Object::Rotate(float x,float y,float z){
    EGL_Poly::Rotate(x,y,z);
    box->Rotate(x,y,z);
}

void EGL_Object::SetPos(float x,float y,float z){
    EGL_Mesh::SetPos(x,y,z);
    box->SetPos(x,y,z);
}