#include "EGL_Graphics.h"
#include "EGL_Physics.h"

// Helpers
EGL_Vector ToVector(EGL_Point point){
    return EGL_Vector(point.x,point.y,point.z);
}

float Cross2d(EGL_Vector v1, EGL_Vector v2){
    return v1.x*v2.y - v1.y*v2.x;
}



EGL_Hitbox::EGL_Hitbox(std::vector<EGL_Point>* points) : EGL_Poly(points){
    
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
    float rs = Cross2d(r,s);
    // Now get the multipliers that get to the cutting point
    // are these more than 1 or less than 0 there is no intersection
    float t = Cross2d((q1-p1),s)/rs;
    float u = Cross2d((q1-p1),r)/rs;

    // now just looking at the values will get the result 
    // is rs not 0 and t and u are between 0 and 1 we have an interception
    // else not 
    if(rs != 0){
        if((0<=t && t<=1) && (0<=u && u<=1)){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}


bool EGL_Hitbox::PointInOther(EGL_Point point,EGL_Hitbox* other){
    int intersections = 0;
    for(int i=0;i<(other->points.size()-1);i++){
        if(CheckLineIntersect(ToVector(other->points.at(i))+other->pos,ToVector(other->points.at(i+1))+other->pos,ToVector(point)+pos)){
            intersections++;
        };
    }

    if(CheckLineIntersect(ToVector(other->points.at(0))+other->pos,ToVector(other->points.back())+other->pos,ToVector(point)+pos)){
        intersections++;
    };

    if(intersections%2 != 0){
        return true;
    } else {
        return false;
    }
}

void EGL_Hitbox::CheckCollision(EGL_Hitbox* other){
    std::vector<EGL_Vector> point_hits;
    for(int i=0;i<points.size();i++){
        if(PointInOther(points.at(i),other)){
            point_hits.push_back(ToVector(points.at(i))+pos);
        }
    }
    if(point_hits.size() != 0){
        hits.push_back(HitInfo(other,point_hits));
    }
}

void EGL_Hitbox::ClearHits(){
    hits.clear();
    hits.shrink_to_fit();
}