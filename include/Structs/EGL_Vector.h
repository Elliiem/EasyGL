#ifndef EGL_VECTOR
#define EGL_VECTOR

// Mathematical Vector
struct EGL_Vector{
    EGL_Vector(float x,float y,float z);
    EGL_Vector();


    float x,y,z;

    // returns the Cross product of this and other
    EGL_Vector Cross(const EGL_Vector& other);

    // returns the scalar 2d Cross product of the two Vectors x and y
    float Cross2d(const EGL_Vector& other);

    // Adds other's x,y and z to x,y and z
    void operator+=(const EGL_Vector& other);

    // adds other's x,y and z to x,y and z and returns a
    // Vector with these new values
    EGL_Vector operator+(const EGL_Vector& other);

    // Subtracts other's x,y and z from x,y and z
    void operator-=(const EGL_Vector& other);

    // substracts other's x,y and z from x,y and z and returns a
    // Vector with these new values
    EGL_Vector operator-(const EGL_Vector& other);

    // Multiplies the Vector and returns the dot product
    float operator*(const EGL_Vector& other);

    // Multiplies x,y and z by the given number and returns a new 
    // Vector with the reslts
    EGL_Vector operator*(float mult);

    // Multiplies x,y and z by the given number
    void operator*=(float mult);
};
#endif