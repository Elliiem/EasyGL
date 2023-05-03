#include "EGL_Vector.h"

EGL_Vector::EGL_Vector(float x,float y,float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

EGL_Vector::EGL_Vector(){
    x = 0;
    y = 0;
    z = 0;
}

EGL_Vector EGL_Vector::Cross(const EGL_Vector& other){
    return EGL_Vector(y*other.z-z*other.y,z*other.x-x*other.z,x*other.y-y*other.x);
}

float EGL_Vector::Cross2d(const EGL_Vector& other){
    return x*other.y - y*other.x;
}

void EGL_Vector::operator+=(const EGL_Vector& other){
    x += other.x;
    y += other.y;
    z += other.z;
}

void EGL_Vector::operator-=(const EGL_Vector& other){
    x -= other.x;
    y -= other.y;
    z -= other.z;
}

EGL_Vector EGL_Vector::operator-(const EGL_Vector& other){
    return EGL_Vector(x - other.x,y - other.y,z - other.z);       
}

EGL_Vector EGL_Vector::operator+(const EGL_Vector& other){
    return EGL_Vector(x + other.x,y + other.y,z + other.z);       
}

float EGL_Vector::operator*(const EGL_Vector& other){
    return(x*other.x+y*other.y+z*other.z);
}

EGL_Vector EGL_Vector::operator*(float mult){
    return EGL_Vector(x*mult,y*mult,z*mult);
}

void EGL_Vector::operator*=(float mult){
    x *= mult;
    y *= mult;
    z *= mult;
}
