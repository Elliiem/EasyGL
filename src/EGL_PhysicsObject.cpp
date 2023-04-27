#include "EGL.h"

EGL_PhysicsObject::EGL_PhysicsObject(std::vector<EGL_Point>* points) : EGL_Poly(points){
    box = new EGL_Hitbox(points);
}

void EGL_PhysicsObject::Draw(float x,float y,float z){
    SetPos(x,y,z);
    EGL_Mesh::Draw();
    box->SetPos(pos.x,pos.y,pos.z);
}

void EGL_PhysicsObject::Draw(){
    EGL_Mesh::Draw();
}

void EGL_PhysicsObject::Rotate(float x,float y,float z){
    EGL_Poly::Rotate(x,y,z);
    box->Rotate(x,y,z);
}

void EGL_PhysicsObject::SetPos(float x,float y,float z){
    EGL_Mesh::SetPos(x,y,z);
    box->SetPos(x,y,z);
}