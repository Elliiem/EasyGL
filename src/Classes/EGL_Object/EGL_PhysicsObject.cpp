#include "EGL_PhysicsObject.h"

EGL_PhysicsObject::EGL_PhysicsObject(std::vector<EGL_Point>* points,void(*func)(EGL_Object*)) : EGL_Object(points,func){
}


EGL_PhysicsObject::EGL_PhysicsObject(std::vector<EGL_Point>* points) : EGL_Object(points){
}