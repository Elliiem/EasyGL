#ifndef EGL_POINT
#define EGL_POINT

// Rotatable Point (around the origin)
struct EGL_Point{
    EGL_Point(EGL_Vector vec);
    EGL_Point(float x,float y,float z);
    EGL_Point();

    // Current Coordinates
    float x,y,z;
    // Initial Coordinates
    EGL_Vector vec;
    // Current Rotation
    EGL_Vector rot;

    void RotateZ(float deg);
    void RotateX(float deg);
    void RotateY(float deg);
};
#endif