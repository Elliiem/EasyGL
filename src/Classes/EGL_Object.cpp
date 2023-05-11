#include <fmt/format.h>
#include "EGL_Object.h"
#include "EGL_Hitbox.h"

EGL_Object::EGL_Object(std::vector<EGL_Point>* points) : EGL_Mesh(points){
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
    EGL_Mesh::Rotate(x,y,z);
    box->Rotate(x,y,z);
}

void EGL_Object::SetPos(float x,float y,float z){
    last_pos = this->pos;
    EGL_Mesh::SetPos(x,y,z);
    box->SetPos(x,y,z);
}

void EGL_Object::SetPos(EGL_Vector pos){
    last_pos = this->pos;
    EGL_Mesh::SetPos(pos);
    box->SetPos(pos);
}

void EGL_Object::Update(){
    SetPos(pos+GetVel()+acceleration);
    acceleration = {};
    EGL_Mesh::Draw();
    fmt::print("Somethins!");
}

std::vector<EGL_Vector> EGL_Object::CheckColision(EGL_Object* other){
    return box->CheckCollision(other->box);
}