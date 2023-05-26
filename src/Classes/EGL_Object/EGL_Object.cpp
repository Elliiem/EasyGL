#include "EGL_Object.h"

void no_op(EGL_Object* obj,EGL_Window* win){}

EGL_Object::EGL_Object(std::vector<EGL_Point>* points,void(*func)(EGL_Object*,EGL_Window*),std::string id) : EGL_Mesh(points){
    this->func = func;
    this->id = id;
}

EGL_Object::EGL_Object(std::vector<EGL_Point>* points,std::string id) : EGL_Mesh(points){
    func = no_op;
    this->id = id;
}

EGL_Object::~EGL_Object(){
    for(int i=0;i<children.size();i++){
        delete children.at(i);
    }
}

void EGL_Object::SetPos(float x, float y, float z){
    EGL_Mesh::SetPos(x,y,z);
}

void EGL_Object::SetPos(EGL_Vector pos){
    EGL_Mesh::SetPos(pos);
}

void EGL_Object::Draw(EGL_Render* rend){
    EGL_Mesh::Draw(rend);
    for(int i=0;i<children.size();i++){
        children.at(i)->Draw(rend);
    }
}

void EGL_Object::Rotate(float x,float y,float z){
    EGL_Mesh::Rotate(x,y,z);
}

void EGL_Object::Update(EGL_Window* win){
    func(this, win);
}

EGL_Object* EGL_Object::AddChild(std::vector<EGL_Point>* points,void (*func)(EGL_Object*,EGL_Window*),std::string id){
    children.emplace_back(new EGL_Object(points,func,id));
    return children.back();
}

void EGL_Object::RemoveChild(EGL_Object* obj){
    for(int i=0;i<children.size();i++){
        if(children.at(i) == obj){
            children.erase(children.begin()+i);
            delete obj;
            return;
        }
    }
    std::cerr << "\033[31;1mEGL_Object::RemoveChild Couldnt find Child!\033[0m\n";
}
