#include <fmt/format.h>
#include "EGL_Object.h"
#include "EGL_Hitbox.h"

EGL_Object::EGL_Object(std::vector<EGL_Point>* points,void(*func)(EGL_Object*)) : EGL_Mesh(points){
    box = new EGL_Hitbox(points);
    this->func = func;
}

EGL_Object::~EGL_Object(){
    delete box;
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
    func(this);
    SetPos(pos+GetVel()+acceleration);
    acceleration = {};
}

EGL_Vector EGL_Object::GetVel(){
    return pos-last_pos;
}

std::vector<EGL_Vector> EGL_Object::CheckColision(EGL_Object* other){
    return box->CheckCollision(other->box);
}

void EGL_Object::SetVel(EGL_Vector vel){
    last_pos = pos-vel;
}

void EGL_Object::SetVel(float x,float y,float z){
    EGL_Vector vel(x,y,z);
    last_pos = pos-vel;
}

void EGL_Object::AddVel(EGL_Vector add){
    last_pos -= add;
}