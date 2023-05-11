#include "EGL_Physics.h"

EGL_Object* EGL_Physics::AddObject(std::vector<EGL_Point>* points){
    objects.push_back(EGL_Object(points));
    return &objects.at(objects.size()-1);
}

void EGL_Physics::UpdatePhysics(){
    for(int i=0;i<objects.size();i++){
        objects.at(i).Update();
    }
}
