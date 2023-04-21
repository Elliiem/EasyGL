#include "EGL.h"

EGL_Vertex EGL_ClampCoords(float x,float y,float z){
    float xf = x / ((float)EGL_WIN_WIDTH/2);
    float yf = -(y / ((float)EGL_WIN_HEIGHT/2));

    return EGL_Vertex(xf-1,yf+1,z);
}
