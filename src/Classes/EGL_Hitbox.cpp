#include "EGL_Graphics.h"
#include "EGL_Hitbox.h"

// Helpers
EGL_Vector ToVector(EGL_Point point){
    return EGL_Vector(point.x,point.y,point.z);
}

float Cross2d(EGL_Vector v1, EGL_Vector v2){
    return v1.x*v2.y - v1.y*v2.x;
}



EGL_Hitbox::EGL_Hitbox(std::vector<EGL_Point>* points) : EGL_Mesh(points){
    
}

// Checks if the line from p1 to the largest x intersects the q1q2 Vector 
bool EGL_Hitbox::CheckLineIntersect(EGL_Vector q1,EGL_Vector q2, EGL_Vector p1){
    // Find the point p2
    EGL_Vector p2 = p1;
    // Check if q1 or q2 have a larger x, and set p2's x to one larger
    if(q1.x > q2.x){
        p2.x = q1.x + 1;
    } else {
        p2.x = q2.x + 1;
    }

    if(q1.z != p1.z){
        if(q1.z<p1.z-0.1 || q1.z>p1.z+0.1){
            return false;
        }
    }

    // Calculate the Vectors between p1 and p2, and q1 and q2
    EGL_Vector s = q2 - q1;
    EGL_Vector r = p2 - p1;

    // Get the cross product of r and s
    // is the result 0, then the vectors are parralel
    float rs = EGL_Vector::Cross2d(r, s);
    // Now get the multipliers that get to the cutting point
    // are these more than 1 or less than 0 there is no intersection
    float t = EGL_Vector::Cross2d(q1-p1, s)/rs;
    float u = EGL_Vector::Cross2d(q1-p1, r)/rs;
    

    // now just looking at the values will get the result 
    // is rs not 0 and t and u are between 0 and 1 we have an interception
    // else not 
    if(rs != 0){
        if((0<=t && t<=1) && (0<=u && u<=1)){
            return true;
        }
    }

    return false;
}

std::vector<EGL_Vector> EGL_Hitbox::CheckCollision(EGL_Hitbox* other){
    std::vector<EGL_Vector> point_hits;
    int intersections = 0;

    // Going over each point in this Hitbox
    for(int ai=0; ai<points->size(); ai++){
        for(int bi=0; bi<other->points->size();bi++){
            if(bi == other->points->size() - 1){
                if(CheckLineIntersect(ToVector(other->points->back())+other->pos, ToVector(other->points->at(0))+other->pos, ToVector(points->at(ai))+pos)){
                    intersections++;
                }                    
            } else {
                if(CheckLineIntersect(ToVector(other->points->at(bi))+other->pos, ToVector(other->points->at(bi+1))+other->pos, ToVector(points->at(ai))+pos)){
                    intersections++;
                }
            }
        }
        if(intersections%2 != 0){
            point_hits.push_back(ToVector(points->at(ai)));
        }

        intersections = 0;
    }

    return point_hits;
}