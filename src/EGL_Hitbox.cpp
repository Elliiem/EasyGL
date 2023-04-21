#include "EGL.h"

// Helpers
EGL_Vector ToVector(EGL_Point point){
    return EGL_Vector(point.x,point.y,point.z);
}

float Cross2d(EGL_Vector v1, EGL_Vector v2){
    return v1.x*v2.y - v1.y*v2.x;
}

// Checks if the line from p1 to the largest x intersects the q1q2 Vector 
bool CheckLineIntersect(EGL_Vector q1,EGL_Vector q2, EGL_Vector p1){
    // Find the point p2
    EGL_Vector p2 = p1;
    // Check if q1 or q2 have a larger x, and set p2's x to one larger
    if(q1.x > q2.x){
        p2.x = q1.x + 1;
    } else {
        p2.x = q2.x + 1;
    }

    // Calculate the Vectors between p1 and p2, and q1 and q2
    EGL_Vector s = q2 - q1;
    EGL_Vector r = p2 - p1;

    // Get the cross product of r and s this
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

// Checks if a given point is inside the bounds of the Hitbox, other
bool CheckIfInPoly(EGL_Vector point, EGL_Hitbox* checking, EGL_Hitbox* other){
    int count = 0; //number of intersections

    // Go through every line on the polygon ...
    for(int i=0;i<other->points.size()-1;i++){
        // ... and Check if the points line intersects 
        if(CheckLineIntersect(other->points.at(i)+other->pos,other->points.at(i+1)+other->pos,point+checking->pos)){
            // if so iterate count
            count++;
        };
    }
    // and do the same to the line between the last and first point
    if(CheckLineIntersect(other->points.at(0)+other->pos,other->points.back()+other->pos,point+checking->pos)){
        count++;
    }

    // Check if count is even or odd
    // Return true if odd, else false
    if(count%2!=0){
        return true;
    } else {
        return false;
    }
}


EGL_Hitbox::EGL_Hitbox(std::vector<EGL_Vector> points){
    this->points = points;
}

EGL_Hitbox::EGL_Hitbox(std::vector<EGL_Point> points){
    std::vector<EGL_Vector> vector;

    for(int i=0;i<points.size();i++){
        vector.push_back(ToVector(points.at(i)));
    }

    this->points = vector;
}


void EGL_Hitbox::CheckCollision(EGL_Hitbox* other){
    std::vector<EGL_Vector> hits;

    for(int i=0;i<points.size();i++){
        if(CheckIfInPoly(points.at(i),this,other)){
            hits.push_back(points.at(i)+pos);
        }
    }

    this->hits = hits;
    if(hits.size() == 0){
        this->other = other;
    }
}

void EGL_Hitbox::UpdateHitbox(std::vector<EGL_Point> points){
    std::vector<EGL_Vector> vector;

    for(int i=0;i<points.size();i++){
        vector.push_back(ToVector(points.at(i)));
    }

    this->points = vector;
}