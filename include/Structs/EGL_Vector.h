#pragma once

#include <cmath>
#include <fmt/format.h>

// Mathematical Vector
struct EGL_Vector{
    EGL_Vector(float x,float y,float z);
    EGL_Vector();


    float x,y,z;

    void Print() const;

    // returns the lenght of this Vector
    float Len() const;

    // returns the degree between this Vector and the given Vector
    static float DegreeBetween(const EGL_Vector& a,const EGL_Vector& b);

    // returns the projection on another Vector
    static float Projection(const EGL_Vector& a,const EGL_Vector& b);

    // returns the Unit Vector of this Vector
    EGL_Vector Unit() const;

    // returns the Cross product of this and other
    static EGL_Vector Cross(const EGL_Vector& a,const EGL_Vector& b);

    // returns the scalar 2d Cross product of the two Vectors x and y
    static float Cross2d(const EGL_Vector& a,const EGL_Vector& b);

    // Adds other's x,y and z to x,y and z
    void operator+=(const EGL_Vector& other);

    // adds other's x,y and z to x,y and z and returns a
    // Vector with these new values
    EGL_Vector operator+(const EGL_Vector& other) const;

    // Subtracts other's x,y and z from x,y and z
    void operator-=(const EGL_Vector& other);

    // substracts other's x,y and z from x,y and z and returns a
    // Vector with these new values
    EGL_Vector operator-(const EGL_Vector& other) const;

    // Multiplies the Vector and returns the dot product
    float operator*(const EGL_Vector& other) const;

    // Multiplies x,y and z by the given number and returns a new 
    // Vector with the reslts
    EGL_Vector operator*(float mult) const;

    // Multiplies x,y and z by the given number
    void operator*=(float mult);

    // Divides x,y and z by the given number and returns a new 
    // Vector with the reslts
    EGL_Vector operator/(float div) const;

    // Divides x,y and z by the given number
    void operator/=(float div);

    // Compares this Vector to the given one
    bool operator==(const EGL_Vector& other) const;

    EGL_Vector operator-() const;
};