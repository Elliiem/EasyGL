#ifndef EGL_FUNC
#define EGL_FUNC

#include "EGL_Structs.h"

EGL_Vector EGL_UnclampCoordinates(EGL_Vertex vertex);
EGL_Vertex EGL_ClampCoordinates(float x,float y,float z);
EGL_Vector ToVector(EGL_Point point);

#endif