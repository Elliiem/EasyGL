#ifndef EGL_STRUCTS
#define EGL_STRUCTS

#include <glm/glm.hpp>

struct EGL_Vertex{
    EGL_Vertex(float X,float Y,float Z){
        pos = glm::vec3(X,Y,Z);
    }

    EGL_Vertex(glm::vec3 Vec){
        pos = Vec;
    }

    EGL_Vertex(EGL_Vertex* point){
        pos = point->pos;
    }
    
    EGL_Vertex(){

    }

    glm::vec3 pos;
};
struct EGL_Color{
    EGL_Color(float R, float G, float B, float A){
        r = R;
        g = G;
        b = B;
        a = A;
    }

    EGL_Color(){

    }

    float r;
    float g;
    float b;
    float a;
};
struct EGL_Vector{
    EGL_Vector(float x,float y,float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    EGL_Vector(){
        x = 0;
        y = 0;
        z = 0;
    }

    void operator+=(EGL_Vector other){
        x += other.x;
        y += other.y;
        z += other.z;
    }

    EGL_Vector operator-(EGL_Vector other){
        return EGL_Vector(x - other.x,y - other.y,z - other.z);       
    }
    EGL_Vector operator+(EGL_Vector other){
        return EGL_Vector(x + other.x,y + other.y,z + other.z);       
    }

    float x,y,z;
};
struct EGL_Point{
    // Initializers
    EGL_Point(EGL_Vector vec);
    EGL_Point(float x,float y,float z);
    EGL_Point();

    void RotateZ(float deg);
    void RotateX(float deg);
    void RotateY(float deg);
    
    float x,y,z;
    EGL_Vector vec;
    EGL_Vector rot;
};
#endif