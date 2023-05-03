#ifndef EGL_MESH
#define EGL_MESH

#include "EGL_Vertex.h"
#include "EGL_Vector.h"
#include <GL/glew.h>

class EGL_Mesh{
    public:
    EGL_Mesh(EGL_Vertex* points, uint8_t num_points);
    EGL_Mesh(){}
    ~EGL_Mesh();

    
    void Draw();

    void Change(EGL_Vertex* points, uint8_t size);
    void Change();

    void UpdateVertexPosition(EGL_Vector pos);

    void SetPos(float x,float y,float z);
    EGL_Vector GetPos();


    protected:
    uint8_t draw_count;
    EGL_Vector pos;
    
    void Init_Mesh(EGL_Vertex* points, uint8_t num_points);
    

    private:
    enum
    {
        POSITION_VB,
        NUM_BUFFERS
    };

    GLuint vertex_array_obj;
    GLuint vertex_array_buffers[NUM_BUFFERS];
    EGL_Vertex* verticies;

};
#endif