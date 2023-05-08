#include "EGL_Graphics.h"
#include "EGL_Physics.h"

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

void EGL_PhysicsObject::Update(){
    vel += acc;
    pos += vel;
    Rotate(rot_vel.x,rot_vel.y,rot_vel.z);
    Draw();
}

void HandleCollision(const EGL_Hitbox& other){
    
}