#include "EGL.h"

EGL_PhysicsObject::EGL_PhysicsObject(std::vector<EGL_Point> points){
    this->points = points;
    this->box = EGL_Hitbox(points);
}

void EGL_PhysicsObject::Update(){
    box.pos = this->pos;
    this->Draw();
}


// Kreispendel