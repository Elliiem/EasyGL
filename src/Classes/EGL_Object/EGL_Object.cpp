#include <fmt/format.h>
#include "EGL_Object.h"
#include "EGL_Hitbox.h"

void default_func(EGL_Object* obj){

}

EGL_Object::EGL_Object(std::vector<EGL_Point>* points,void(*func)(EGL_Object*),bool isphysics) : EGL_Mesh(points){
    box = new EGL_Hitbox(points);
    this->func = func;
    this->isphysics = isphysics;
}

EGL_Object::EGL_Object(std::vector<EGL_Point>* points,bool isphysics) : EGL_Mesh(points){
    box = new EGL_Hitbox(points);
    func = default_func;
    this->isphysics = isphysics;
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
    EGL_Mesh::SetPos(x,y,z);
    box->SetPos(x,y,z);
    if(isphysics){
        last_pos = pos;
    }
}

void EGL_Object::SetPos(EGL_Vector pos){
    EGL_Mesh::SetPos(pos);
    box->SetPos(pos);
    if(isphysics){
        last_pos = this->pos;
    }
}

void EGL_Object::Update(){
    func(this);
    if(isphysics){
        SetPos(pos+GetVel()+acceleration);
        acceleration = {};
    }
    ClearHits();
}

EGL_Vector EGL_Object::GetVel(){
    return pos-last_pos;
}

std::vector<EGL_Vector> EGL_Object::CheckColision(EGL_Object* other){
    std::vector<EGL_Vector> hit_points = box->CheckCollision(other->box);
    if(hit_points.size() != 0){
        hits.emplace_back(HitInfo(other,hit_points));
    }
    return hit_points;
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

void EGL_Object::Accelerate(EGL_Vector acc){
    acceleration += acc;
}

void EGL_Object::Move(EGL_Vector pos){
    EGL_Vector vel = GetVel();
    SetPos(pos);
    SetVel(vel);
}

void EGL_Object::Move(float x,float y, float z){
    EGL_Vector vel = GetVel();
    SetPos(x,y,z);
    SetVel(vel);
}

void EGL_Object::ClearHits(){
    hits.clear();
    hits.shrink_to_fit();
}