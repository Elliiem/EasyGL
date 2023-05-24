#include "EGL_Graphics.h"
#include "EGL_Hitbox.h"

// Helpers
EGL_Vector ToVector(EGL_Point point){
    return EGL_Vector(point.x,point.y,point.z);
}

bool CheckIntersect(float rs,float t,float u){
    if((0<=t && t<=1) && (0<=u && u<=1) && rs != 0) return true;
    else return false;
}
// Helpers

EGL_Hitbox::EGL_Hitbox(std::vector<EGL_Point>* points) : EGL_Mesh(points){ 
}

bool EGL_Hitbox::LineIntersect(EGL_Vector q1,EGL_Vector q2, EGL_Vector p1){
    EGL_Vector p2 = p1;

    if(q1.x > q2.x) p2.x = q1.x + 1;
    else p2.x = q2.x + 1;

    if(q1.z<p1.z-0.1 || q1.z>p1.z+0.1) return false;

    EGL_Vector s = q2 - q1;
    EGL_Vector r = p2 - p1;
    float rs = EGL_Vector::Cross2d(r, s);
    float t = EGL_Vector::Cross2d(q1-p1, s)/rs;
    float u = EGL_Vector::Cross2d(q1-p1, r)/rs;
    
    return CheckIntersect(rs,t,u);
}

bool EGL_Hitbox::LineIntersect(EGL_Vector q1, EGL_Vector q2, EGL_Vector p1, EGL_Vector p2){
    if(q1.z<p1.z-0.1 || q1.z>p1.z+0.1) return false;

    EGL_Vector s = q2 - q1;
    EGL_Vector r = p2 - p1;
    float rs = EGL_Vector::Cross2d(r, s);
    float t = EGL_Vector::Cross2d(q1-p1, s)/rs;
    float u = EGL_Vector::Cross2d(q1-p1, r)/rs;
    
    return CheckIntersect(rs,t,u);
}

std::vector<EGL_Vector> EGL_Hitbox::CheckCollision(EGL_Hitbox* other){
    std::vector<EGL_Vector> point_hits;
    int intersections = 0;

    for(int ai=0; ai<points->size(); ai++){
        for(int bi=0; bi<other->points->size()-1;bi++){
            if(LineIntersect(other->points->at(bi)+other->pos, other->points->at(bi+1)+other->pos, points->at(ai)+pos)){
                intersections++;
            }
        }
        if(LineIntersect(other->points->back()+other->pos, other->points->at(0)+other->pos, points->at(ai)+pos)){
            intersections++;
        }        

        if(intersections%2 != 0) point_hits.push_back(ToVector(points->at(ai)));

        intersections = 0;
    }

    return point_hits;
}

bool EGL_Hitbox::CheckPoint(EGL_Vector point){
    int intersections = 0;
    
    for(int i=0;i<points->size()-1;i++){
        if(LineIntersect(points->at(i)+pos,points->at(i+1)+pos,point)) intersections++;
    }
    if(LineIntersect(points->at(0)+pos,points->back()+pos,point)) intersections++;

    if(intersections%2 != 0) return true;
    else return false;
}
