#include "EGL.h"

EGL_Vertex EGL_ClampCoordinates(float x,float y,float z){
    float xf = x / ((float)EGL_WIN_WIDTH/2);
    float yf = -(y / ((float)EGL_WIN_HEIGHT/2));

    return EGL_Vertex(xf-1,yf+1,z);
}

EGL_Vector EGL_UnclampCoordinates(EGL_Vertex vertex){
    float xr = ((vertex.pos.x+1)*0.5)*EGL_WIN_WIDTH;
    float yr = ((-vertex.pos.y+1)*0.5)*EGL_WIN_HEIGHT;
    return EGL_Vector(xr,yr,vertex.pos.z);
}