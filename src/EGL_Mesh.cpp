#include "EGL.h"

EGL_Mesh::EGL_Mesh(EGL_Vertex* verticies, uint8_t num_points){
    draw_count = num_points;
    this->verticies = verticies;

    glGenVertexArrays(1,&vertex_array_obj);
    glBindVertexArray(vertex_array_obj);

    glGenBuffers(NUM_BUFFERS,vertex_array_buffers);
    glBindBuffer(GL_ARRAY_BUFFER,vertex_array_buffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER,num_points*sizeof(*verticies),verticies,GL_STREAM_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE,0,0);

    glBindVertexArray(0);
}

EGL_Mesh::~EGL_Mesh(){
    glDeleteVertexArrays(1, &vertex_array_obj);
}

void EGL_Mesh::Init_Mesh(EGL_Vertex* verticies, uint8_t num_points){
    draw_count = num_points;
    this->verticies = verticies;

    glGenVertexArrays(1,&vertex_array_obj);
    glBindVertexArray(vertex_array_obj);

    glGenBuffers(NUM_BUFFERS,vertex_array_buffers);
    glBindBuffer(GL_ARRAY_BUFFER,vertex_array_buffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER,num_points*sizeof(*verticies),verticies,GL_STREAM_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE,0,0);

    glBindVertexArray(0);
}


void EGL_Mesh::UpdateVertexPosition(EGL_Vector pos){
    EGL_Vector position;
    for(int i=0;i<draw_count;i++){
        position = EGL_UnclampCoordinates(verticies[i]);
        verticies[i] = EGL_ClampCoordinates((position.x-this->pos.x)+pos.x,(position.y-this->pos.y)+pos.y,(position.z-this->pos.z)+pos.z);
    }
}


void EGL_Mesh::Draw(){
    UpdateVertexPosition(this->pos);
    
    glBindVertexArray(vertex_array_obj);

    glDrawArrays(GL_POLYGON,0,draw_count);

    glBindVertexArray(0);
}

void EGL_Mesh::Change(EGL_Vertex* verticies, uint8_t size)
{
    this->verticies = verticies;
    draw_count = size;
    glBindVertexArray(vertex_array_obj);
    glBindBuffer(GL_ARRAY_BUFFER,vertex_array_buffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER,draw_count*sizeof(*verticies),verticies,GL_STATIC_DRAW);
    glBindVertexArray(0);    
}

void EGL_Mesh::Change(){
    glBindVertexArray(vertex_array_obj);
    glBindBuffer(GL_ARRAY_BUFFER,vertex_array_buffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER,draw_count*sizeof(*verticies),verticies,GL_STATIC_DRAW);
    glBindVertexArray(0);    
}

void EGL_Mesh::SetPos(float x,float y,float z){
    EGL_Vector tmp(x,y,z);
    UpdateVertexPosition(tmp);
    pos = tmp;
    Change();
}