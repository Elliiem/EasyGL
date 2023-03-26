#include "EGL.h"

EGL_Mesh::EGL_Mesh(EGL_Vertex* points, uint8_t num_points){
    draw_count = num_points;

    glGenVertexArrays(1,&vertex_array_obj);
    glBindVertexArray(vertex_array_obj);

    glGenBuffers(NUM_BUFFERS,vertex_array_buffers);
    glBindBuffer(GL_ARRAY_BUFFER,vertex_array_buffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER,num_points*sizeof(*points),points,GL_STREAM_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE,0,0);

    glBindVertexArray(0);
}

EGL_Mesh::~EGL_Mesh(){
    glDeleteVertexArrays(1, &vertex_array_obj);
}

void EGL_Mesh::Draw(){
    glBindVertexArray(vertex_array_obj);

    glDrawArrays(GL_POLYGON,0,draw_count);

    glBindVertexArray(0);
}

void EGL_Mesh::Change(EGL_Vertex* points, uint8_t size)
{
    draw_count = size;
    glBindVertexArray(vertex_array_obj);
    glBindBuffer(GL_ARRAY_BUFFER,vertex_array_buffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER,draw_count*sizeof(*points),points,GL_STATIC_DRAW);
    glBindVertexArray(0);    
}