#include "EGL.h"

struct Point{
    Point(float A,float B){
        a = A;
    }
    float a;
    float b;
};

float ToRadians(float d){
    return d*0.017453292519943295;
}

float ToDegrees(float r){
    return r*57.29577951308232;
}

int GetQuadrant(float a, float b){
    if(a>=0 && b >= 0)
        return 0;
    if(a<0 && b>=0)
        return 1;
    if(a<0 && b<0)
        return 2;
    if(a>=0 && b<0)
        return 3;
    return -1;
}

int GetQuadrantP(float Deg){
    if(Deg<=90)
        return 0;
    else if(Deg <= 180)
        return 1;
    else if(Deg <= 270)
        return 2;
    else if(Deg < 360)
        return 3;
    else
        return -1;
}

float GetDeg(float A,float B){
    float deg;
    int q = GetQuadrant(A,B);
    A = abs(A);
    B = abs(B);
    switch (q)
    {
    case 0:
        deg = ToDegrees(atan(B/A));
        break;
    case 1:
        deg = 180-ToDegrees(atan(B/A)) + 90;      
        break;
    case 2:
        deg = ToDegrees(atan(B/A)) + 180;      
        break;
    case 3:
        deg = ToDegrees(atan(B/A)) + 270;
        break;
    case -1:
        deg = 0;
        break;
    }
    return deg;
}

Point ToKarthesian(float Deg,float Len){
    int q = GetQuadrantP(Deg);
    float a,b;
    switch (q)
    {
    case 1:
        Deg -= 90;
        break;
    case 2:
        Deg -= 180;
        break;
    case 3:
        Deg -= 270;
        break;
    case -1:
        return Point(0,0);
        break;    
    }
    a = cos(ToDegrees(Deg))*Len;
    b = sin(ToDegrees(Deg))*Len;
    return Point(a,b);

}


EGL_Polar::EGL_Polar(float X,float Y,float Z){
    lx = sqrt(pow(Z,1)+pow(Y,1));
    dx = GetDeg(Z,Y);
    ly = sqrt(pow(X,1)+pow(Z,1));
    dy = GetDeg(X,Z);
    lz = sqrt(pow(X,1)+pow(Y,1));
    dz = GetDeg(X,Y);
}