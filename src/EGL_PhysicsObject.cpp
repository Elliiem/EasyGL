#include "EGL.h"

EGL_PhysicsObject::EGL_PhysicsObject(std::vector<EGL_Point>* points){
    Init_Poly(points);
}

void EGL_PhysicsObject::Update(){
    this->Draw();
}