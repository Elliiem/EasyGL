#include "EGL.h"

//Helpers
float Rad(float deg){
  return deg * 0.017453293;
}

float Deg(float rad){
  return rad * 57.29577951;
}


//Initializers
EGL_Point::EGL_Point(EGL_Vector vec){
  this->vec = vec;
  x = vec.x;
  y = vec.y;
  z = vec.z;
}

EGL_Point::EGL_Point(float x,float y,float z){
  vec = EGL_Vector(x,y,z);
  this->x = x;
  this->y = y;
  this->z = z;
}

EGL_Point::EGL_Point(){
  x = 0;
  y = 0;
  z = 0;
  vec = EGL_Vector(0,0,0);
}


/*
-----------# Rz #----------
▛  cos()  -sin()     0    ▜ 
▌  sin()   cos()     0    ▐  
▙    0       0       1    ▟ 
-----------# Rx #----------
▛    1       0       0    ▜
▌    0     cos()  -sin()  ▐
▙    0     sin()   cos()  ▟
-----------# Ry #----------
▛  cos()     0     sin()  ▜
▌    0       1       0    ▐
▙ -sin()     0     cos()  ▟ 
*/

void EGL_Point::RotateZ(float deg){
  rot.z += deg;
  if(rot.z>=360){
    rot.z = rot.z-360;
  }
  else if(rot.z<0){
    rot.z = rot.z+360;
  }
  x = (vec.x*cos(Rad(rot.z)))-(vec.y*sin(Rad(rot.z)));
  y = (vec.x*sin(Rad(rot.z)))+(vec.y*cos(Rad(rot.z)));
}

void EGL_Point::RotateX(float deg){
  rot.x += deg;
  if(rot.x>=360){
    rot.x = rot.x-360;
  }
  else if(rot.x<0){
    rot.x = rot.x+360;
  }
  y = (vec.y*cos(Rad(rot.x)))-(vec.z*sin(Rad(rot.x)));
  z = (vec.y*sin(Rad(rot.x)))+(vec.z*cos(Rad(rot.x)));
}

void EGL_Point::RotateY(float deg){
  rot.y += deg;
  if(rot.y>=360){
    rot.y = rot.y-360;
  }
  else if(rot.y<0){
    rot.y = rot.y+360;
  }
  x = (vec.x*cos(Rad(rot.y)))+(vec.z*sin(Rad(rot.y)));
  z = (vec.x*(-sin(Rad(rot.y))))+(vec.z*cos(Rad(rot.y)));
}