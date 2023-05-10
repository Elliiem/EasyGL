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

void EGL_Vector::Print() const{
    fmt::print("{} {} {}\n",x,y,z);
}

EGL_Vector EGL_Vector::Cross(const EGL_Vector& a,const EGL_Vector& b){
    return EGL_Vector(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

float EGL_Vector::Cross2d(const EGL_Vector& a,const EGL_Vector& b){
    return a.x*b.y - a.y*b.x;
}

float EGL_Vector::Len() const{
    return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}

float EGL_Vector::DegreeBetween(const EGL_Vector& a,const EGL_Vector& b){
    return acos((a*b) / (a.Len()*b.Len()))*57.29577951308232;
}

float EGL_Vector::Projection(const EGL_Vector& a,const EGL_Vector& b){
    return (a*b)/(b.Len());
}

EGL_Vector EGL_Vector::Unit() const{
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

EGL_Vector EGL_Vector::operator-(const EGL_Vector& other) const{
    return EGL_Vector(x - other.x,y - other.y,z - other.z);       
}

EGL_Vector EGL_Vector::operator+(const EGL_Vector& other) const{
    return EGL_Vector(x + other.x,y + other.y,z + other.z);       
}

float EGL_Vector::operator*(const EGL_Vector& other) const{
    return(x*other.x+y*other.y+z*other.z);
}

EGL_Vector EGL_Vector::operator*(float mult) const{
    return EGL_Vector(x*mult,y*mult,z*mult);
}

void EGL_Vector::operator*=(float mult){
    x *= mult;
    y *= mult;
    z *= mult;
}

EGL_Vector EGL_Vector::operator/(float div) const{
    return EGL_Vector(x/div,y/div,z/div);
}

void EGL_Vector::operator/=(float div){
    x /= div;
    y /= div;
    z /= div;
}

bool EGL_Vector::operator==(const EGL_Vector& other) const{
    if(x == other.x && y == other.y && z == other.z){
        return true;
    } else {
        return false;
    }
}

EGL_Vector EGL_Vector::operator-() const{
    return EGL_Vector(-x,-y,-z);
}