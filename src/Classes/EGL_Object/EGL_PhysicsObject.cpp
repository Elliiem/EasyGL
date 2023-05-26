#include "EGL_PhysicsObject.h"

void no_op(EGL_PhysicsObject* obj,EGL_Window* win){}

EGL_PhysicsObject::EGL_PhysicsObject(std::vector<EGL_Point>* points,void(*func)(EGL_PhysicsObject*,EGL_Window*),std::string id) : EGL_Object(points,id){
    this->box = new EGL_Hitbox(points);
    this->func = func;
}


EGL_PhysicsObject::EGL_PhysicsObject(std::vector<EGL_Point>* points,std::string id) : EGL_Object(points,id){
    this->box = new EGL_Hitbox(points);
    this->func = no_op;
}

EGL_PhysicsObject::~EGL_PhysicsObject(){
    delete box;
}

void EGL_PhysicsObject::SetPos(float x,float y,float z){
    EGL_Mesh::SetPos(x,y,z);
    box->SetPos(x,y,z);
    last_pos = pos;
}

void EGL_PhysicsObject::SetPos(EGL_Vector pos){
    EGL_Mesh::SetPos(pos);
    box->SetPos(pos);
    last_pos = pos;
}

void EGL_PhysicsObject::Rotate(float x,float y,float z){
    EGL_Mesh::Rotate(x,y,z);
    box->Rotate(x,y,z);
}

void EGL_PhysicsObject::Move(float x,float y,float z){
    EGL_Vector vel = GetVel();
    EGL_Mesh::SetPos(x,y,z);
    box->SetPos(x,y,z);
    SetVel(vel);
}

void EGL_PhysicsObject::Move(EGL_Vector pos){
    EGL_Vector vel = GetVel();
    EGL_Mesh::SetPos(pos);
    box->SetPos(pos);
    SetVel(vel);
}

void EGL_PhysicsObject::SetVel(float x,float y,float z){
    last_pos = pos - EGL_Vector(x,y,z);
}   

void EGL_PhysicsObject::SetVel(EGL_Vector vel){
    last_pos = pos - vel;
}

void EGL_PhysicsObject::AddVel(float x,float y,float z){
    last_pos -= EGL_Vector(x,y,z);
}

void EGL_PhysicsObject::AddVel(EGL_Vector add){
    last_pos -= add;
}

void EGL_PhysicsObject::Accelerate(float x, float y, float z){
    acceleration += EGL_Vector(x,y,z);
}

void EGL_PhysicsObject::Accelerate(EGL_Vector acc){
    acceleration += acc;
}

EGL_Vector EGL_PhysicsObject::GetVel(){
    return pos - last_pos;
}

std::vector<EGL_Vector> EGL_PhysicsObject::Collide(EGL_PhysicsObject *other){
    std::vector<EGL_Vector> col = box->CheckCollision(other->box);
    if(col.size() != 0){
        hits.emplace_back(HitInfo(other,col));
    }
    return col;
}

EGL_PhysicsObject::HitInfo* EGL_PhysicsObject::FindHit(std::string id){
    for(int i=0;i<hits.size();i++){
        if(hits.at(i).other->id == id) return &hits.at(i);
    }
    return nullptr;
}

void EGL_PhysicsObject::Update(EGL_Window* win){
    func(this,win);

    EGL_Vector vel = GetVel();
    last_pos = pos;
    SetPos(pos+acceleration+vel);

    hits.clear();
    hits.shrink_to_fit();
}

EGL_PhysicsObject *EGL_PhysicsObject::AddChild(std::vector<EGL_Point> *points, void (*func)(EGL_PhysicsObject *, EGL_Window *), std::string id){
    children.emplace_back(new EGL_PhysicsObject(points,func,id));
    return children.back();
}

void EGL_PhysicsObject::RemoveChild(EGL_PhysicsObject *obj){
    for(int i=0;i<children.size();i++){
        if(children.at(i) == obj){
            children.erase(children.begin()+i);
            delete obj;
            return;
        }
    }
    std::cerr << "\033[31;1mEGL_PhysicsObject::RemoveChild Couldnt find Child!\033[0m\n";
}
