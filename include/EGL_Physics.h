#ifndef EGL_PHYSICS
#define EGL_PHYSICS

#include <vector>
#include "EGL_Structs.h"
#include "EGL_Graphics.h"

// Physics Engine
    /*
    Hitboxes
        Collision Detection
            optimally sht like CheckCollision(EGL_Hitbox) and returns a struct with the hit info
    Collision Handling
        Calculate New Velocities
        Calculate New RotForces in z
    Velocity/Acceleration
        Gravity
        Forces (like Thrusters)
    Rotational Forces
        only realistic in z
        other directions just a bit of rotation on collision
        and let them slowly go back to 0
    Drawing -> U know
        Handle Poly
    */

// Top Level Physics Engine
// Should only need to tell every Physics Object to Check for Collisions with Objects nearby




class EGL_Physics{

};

class EGL_Hitbox : public EGL_Poly{
    public:
    EGL_Hitbox(std::vector<EGL_Point>* points);
    EGL_Hitbox(){

    }

    struct HitInfo{
        HitInfo(EGL_Hitbox* other,std::vector<EGL_Vector> hit_points){
            this->hit_points = hit_points;
            this->other = other;
        }
        std::vector<EGL_Vector> hit_points ;
        EGL_Hitbox* other;
    };

    void CheckCollision(EGL_Hitbox* other);
    void UpdateHitbox(std::vector<EGL_Point>* points);
    void ClearHits();

    std::vector<HitInfo> hits;

    private:
    bool CheckLineIntersect(EGL_Vector q1,EGL_Vector q2, EGL_Vector p1);
    bool PointInOther(EGL_Point point,EGL_Hitbox* other);
};

class EGL_PhysicsObject : public EGL_Poly{
    public:
    EGL_PhysicsObject(std::vector<EGL_Point>* points);
    ~EGL_PhysicsObject(){
        delete box;
    }
    EGL_Hitbox* box;

    void Draw();
    void Draw(float x, float y, float z);
    void Rotate(float x,float y,float z);
    void SetPos(float x,float y,float z);
    
    void Update();
};

#endif