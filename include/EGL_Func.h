#pragma once

#include "EGL_Vector.h"
#include "EGL_Vertex.h"

EGL_Vector EGL_UnclampCoordinates(EGL_Vertex vertex);
EGL_Vertex EGL_ClampCoordinates(float x,float y,float z);
EGL_Vector ToVector(EGL_Point point);
