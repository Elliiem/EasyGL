#include "EGL.h"


//Rz
// cos() −sin() 0
// sin()  cos() 0
//  0      0    1
//Rx
// 1   0      0
// 0 cos() -sin()
// 0 sin()  cos()
//Ry
// cos()  0 sin()
//   0    1   0
// -sin() 0 cos()

float Rad(float deg){
  return deg * 0.017453293;
}

float Deg(float rad){
  return rad * 57.29577951;
}


//Initializers
EGL_Point::EGL_Point(glm::vec3 vec){
  this->vec = vec;
  x = vec.x;
  y = vec.y;
  z = vec.z; 
}

EGL_Point::EGL_Point(float x,float y,float z){
  vec = glm::vec3(x,y,z);
  this->x = x;
  this->y = y;
  this->z = z;
}

EGL_Point::EGL_Point(){
  x = 0;
  y = 0;
  z = 0;
  vec = glm::vec3(0,0,0);
}

//Operators
EGL_Point EGL_Point::operator+(EGL_Point other){
  return EGL_Point(x+other.x,y+other.y,z+other.z);
}

EGL_Point EGL_Point::operator-(EGL_Point other){
  return EGL_Point(x-other.x,y-other.y,z-other.z);
}


void EGL_Point::RotateZ(float deg){
  x = (x*cos(Rad(deg)))-(y*sin(Rad(deg)));
  y = (x*sin(Rad(deg)))+(y*cos(Rad(deg)));
  vec = glm::vec3(x,y,z);
  fmt::print("{} {} {}\n",x,y,z);
}