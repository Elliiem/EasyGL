#ifndef EGL_HITBOX
#define EGL_HITBOX

#include "EGL_Point.h"
#include "EGL_Poly.h"

#include <vector>

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
#endif