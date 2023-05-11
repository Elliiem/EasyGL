#pragma once

#include "EGL_Vertex.h"
#include "EGL_Vector.h"
#include <GL/glew.h>
#include <vector>

class EGL_Mesh{
    public:
    EGL_Mesh(std::vector<EGL_Point>* points);
    EGL_Mesh(){}
    ~EGL_Mesh();

    public:
    void Draw();
    void Change(EGL_Vertex* points, uint8_t size);
    void Change();
    void SetPos(float x,float y,float z);
    void SetPos(EGL_Vector pos);
    void Rotate(float x,float y,float z);
    EGL_Vector GetPos();

    protected:
    EGL_Vector pos;
    std::vector<EGL_Point>* points;
    private:
    EGL_Vertex* verticies;

    private:
    EGL_Vertex* GetVerticiesVector();
    void UpdateVertexPosition(EGL_Vector pos);
    void ChangeVerticies();

    private:
    enum{POSITION_VB,NUM_BUFFERS};

    GLuint vertex_array_obj;
    GLuint vertex_array_buffers[NUM_BUFFERS];

    protected:
    uint8_t size;
};
