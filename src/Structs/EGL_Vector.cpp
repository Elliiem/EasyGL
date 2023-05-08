#include "EGL_Vector.h"
#include <fmt/format.h>

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

float EGL_Vector::Len(){
    return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}

float EGL_Vector::DegreeBetween(EGL_Vector& other){
    return acos((*this*other) / (Len()*other.Len()))*57.29577951308232;
}

float EGL_Vector::Projection(EGL_Vector& other){
    return (*this*other)/(other.Len());
}

EGL_Vector EGL_Vector::Unit(){
    return *this/Len();
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

EGL_Vector EGL_Vector::operator/(float div){
    return EGL_Vector(x/div,y/div,z/div);
}

void EGL_Vector::operator/=(float div){
    x /= div;
    y /= div;
    z /= div;
}

bool EGL_Vector::operator==(const EGL_Vector& other){
    if(x == other.x && y == other.y && z == other.z){
        return true;
    } else {
        return false;
    }
}
