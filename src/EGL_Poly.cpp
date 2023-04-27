#include "EGL.h"

EGL_Poly::EGL_Poly(std::vector<EGL_Point>* points){
    this->points = *points;
    Init_Mesh(GetVerticiesVector(),points->size());
}

EGL_Vertex* EGL_Poly::GetVerticiesVector(){
    EGL_Vertex* verticies = new EGL_Vertex[points.size()];
    for(int i = 0; i<points.size();i++){
        verticies[i] = EGL_Vertex(EGL_ClampCoordinates(points.at(i).x+pos.x,points.at(i).y+pos.y,points.at(i).z+pos.z));
    }
    return verticies;
}

void EGL_Poly::Rotate(float x,float y,float z){
    for(int i=0;i<draw_count;i++){
        points.at(i).RotateZ(z);
        points.at(i).RotateX(x);
        points.at(i).RotateY(y);
    }
    Change(GetVerticiesVector(),draw_count);
}