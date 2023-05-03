#ifndef EGL_POLY
#define EGL_POLY

#include "EGL_Mesh.h"
#include "EGL_Point.h"
#include <vector>

// Top Level Graphics
class EGL_Poly : public EGL_Mesh{
    public:
    EGL_Poly(std::vector<EGL_Point>* points);
    EGL_Poly(){

    }

    ~EGL_Poly(){

    }

    void Rotate(float x,float y,float z);

    protected:
    std::vector<EGL_Point> points;

    private:
    EGL_Vertex* GetVerticiesVector();
};
#endif