#ifndef EGL_VERTEX
#define EGL_VERTEX

#include <glm/glm.hpp>

// Vertex for OpenGL
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
#endif