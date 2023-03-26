#include "EGL.h"

EGL_Poly::EGL_Poly(EGL_Window* Win, std::vector<EGL_Point> Points){
    points = Points;
    win = Win;
    std::vector<EGL_Vertex> vertV;
    
    for(int i = 0; i<Points.size();i++)
    {
        vertV.push_back(EGL_ClampCoords(win,Points.at(i).x,Points.at(i).y,Points.at(i).z));
    }

    mesh = new EGL_Mesh(vertV.data(),3);
}

EGL_Poly::~EGL_Poly(){
    delete mesh;
}

void EGL_Poly::Draw(int x,int y,int z){
    pos = EGL_Point(x,y,z);
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

void EGL_Poly::Change(std::vector<EGL_Point> Points){
    points = Points;
    ChangeVerts();
}

void EGL_Poly::Change(){
    ChangeVerts();
}