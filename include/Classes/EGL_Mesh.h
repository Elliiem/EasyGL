#pragma once

#include "EGL_Vertex.h"
#include "EGL_Vector.h"
#include "EGL_Point.h"
#include "EGL_Render.h"
#include "EGL_Color.h"

#include <GL/glew.h>
#include <vector>

class EGL_Mesh{
    public:
    EGL_Mesh(std::vector<EGL_Point>* points);
    EGL_Mesh(){}
    ~EGL_Mesh();

    public:
    void Draw(EGL_Render* rend);
    void Change(EGL_Vertex* points, uint8_t size);
    void Change();

    void Rotate(float x,float y,float z);

    void SetPos(float x,float y,float z);
    void SetPos(EGL_Vector pos);
    EGL_Vector GetPos();

    void SetCol(EGL_Color col);
    void SetCol(float r,float g,float b,float a);

    protected:
    EGL_Vector pos;
    std::vector<EGL_Point>* points;

    private:
    EGL_Vertex* verticies;
    EGL_Color col = EGL_Color(0.25f,0.25f,0.25f,1.0f);
    enum{POSITION_VB,NUM_BUFFERS};
    GLuint vertex_array_obj;
    GLuint vertex_array_buffers[NUM_BUFFERS];
    uint8_t size;

    EGL_Vertex* GetVerticies();
    void UpdateVertexPosition(EGL_Vector pos);
    void BindVerticies();
};
