#include "EGL.h"

EGL_Poly::EGL_Poly(EGL_Window* Win, std::vector<EGL_Point> points){
    this->points = points;
    win = Win;
    std::vector<EGL_Vertex> vertV;
    
    for(int i = 0; i<points.size();i++)
    {
        vertV.push_back(EGL_ClampCoords(win,points.at(i).x,points.at(i).y,points.at(i).z));
    }

    mesh = new EGL_Mesh(vertV.data(),3);
}

EGL_Poly::~EGL_Poly(){
    delete mesh;
}

void EGL_Poly::Draw(int x,int y,int z){
    pos = EGL_Vector(x,y,z);
    ChangeVerts();
    mesh->Draw();
}

void EGL_Poly::Draw(){
    mesh->Draw();
}

void EGL_Poly::ChangeVerts(){
    std::vector<EGL_Vertex> vertV;
            
    for(int i = 0; i<points.size();i++)
    {
        vertV.push_back(EGL_ClampCoords(win,pos.x+points.at(i).x,pos.y+points.at(i).y,pos.z+points.at(i).z));
    }

    mesh->Change(vertV.data(),vertV.size());   
}

void EGL_Poly::Change(std::vector<EGL_Point> points){
    this->points = points;
    ChangeVerts();
}

void EGL_Poly::Change(){
    ChangeVerts();
}

void EGL_Poly::Rotate(float x,float y,float z){
    for(int i=0;i<points.size();i++){
        points.at(i).RotateZ(z);
        points.at(i).RotateX(x);
        points.at(i).RotateY(y);
    }
    Change();
}