#include <GL/glew.h>
#include <vector>
#include "EGL_Point.h"
#include "EGL_Func.h"
#include "EGL_Mesh.h"

EGL_Mesh::EGL_Mesh(std::vector<EGL_Point>* points){
    this->points = points;
    this->size = points->size();
    this->verticies = GetVerticiesVector();

    glGenVertexArrays(1,&vertex_array_obj);
    glBindVertexArray(vertex_array_obj);

    glGenBuffers(NUM_BUFFERS,vertex_array_buffers);
    glBindBuffer(GL_ARRAY_BUFFER,vertex_array_buffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER,size*sizeof(*verticies),verticies,GL_STREAM_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE,0,0);

    glBindVertexArray(0);
}

EGL_Mesh::~EGL_Mesh(){
    glDeleteVertexArrays(1, &vertex_array_obj);
}

void EGL_Mesh::Draw(){
    UpdateVertexPosition(this->pos);

    glBindVertexArray(vertex_array_obj);

    glDrawArrays(GL_POLYGON,0,size);

    glBindVertexArray(0);
}

void EGL_Mesh::Change(EGL_Vertex* verticies, uint8_t size){
    this->verticies = verticies;
    this->size = size;
    ChangeVerticies();
}

void EGL_Mesh::Change(){
    ChangeVerticies();
}

void EGL_Mesh::SetPos(float x,float y,float z){
    EGL_Vector tmp(x,y,z);
    UpdateVertexPosition(tmp);
    pos = tmp;
    ChangeVerticies();
}

void EGL_Mesh::SetPos(EGL_Vector pos){
    UpdateVertexPosition(pos);
    this->pos =  pos;
    ChangeVerticies();  
}

EGL_Vector EGL_Mesh::GetPos(){
    return pos;
}

void EGL_Mesh::UpdateVertexPosition(EGL_Vector pos){
    EGL_Vector position;
    for(int i=0;i<size;i++){
        position = EGL_UnclampCoordinates(verticies[i]);
        EGL_Vector new_position = (position-this->pos)+pos;
        verticies[i] = EGL_ClampCoordinates(new_position.x, new_position.y, new_position.z);
    }
}

void EGL_Mesh::Rotate(float x,float y,float z){
    for(int i=0;i<size;i++){
        points->at(i).RotateZ(z);
        points->at(i).RotateX(x);
        points->at(i).RotateY(y);
    }
    Change(GetVerticiesVector(),size);
}

EGL_Vertex* EGL_Mesh::GetVerticiesVector(){
    EGL_Vertex* verticies = new EGL_Vertex[points->size()];
    for(int i = 0; i<points->size();i++){
        verticies[i] = EGL_Vertex(EGL_ClampCoordinates(points->at(i).x+pos.x,points->at(i).y+pos.y,points->at(i).z+pos.z));
    }
    return verticies;
}

void EGL_Mesh::ChangeVerticies(){
    glBindVertexArray(vertex_array_obj);
    glBindBuffer(GL_ARRAY_BUFFER,vertex_array_buffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER,size*sizeof(*verticies),verticies,GL_STATIC_DRAW);
    glBindVertexArray(0);    
}