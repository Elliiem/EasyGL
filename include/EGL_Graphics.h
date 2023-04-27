#ifndef EGL_GRAPHICS
#define EGL_GRAPHICS
// Low Level Graphics

#include "EGL_Structs.h"
#include <GL/glew.h>

#include <string>
#include <vector>

class EGL_Mesh{
    public:
    EGL_Mesh(EGL_Vertex* points, uint8_t num_points);
    EGL_Mesh(){}
    ~EGL_Mesh();

    void Draw();

    void Change(EGL_Vertex* points, uint8_t size);
    void Change();

    void SetPos(float x,float y,float z);
    void UpdateVertexPosition(EGL_Vector pos);

    EGL_Vector GetPos(){
        return pos;
    }

    
    protected:
    void Init_Mesh(EGL_Vertex* points, uint8_t num_points);
    enum
    {
        POSITION_VB,
        NUM_BUFFERS
    };

    GLuint vertex_array_obj;
    GLuint vertex_array_buffers[NUM_BUFFERS];
    uint8_t draw_count;
    EGL_Vertex* verticies;
    EGL_Vector pos;

};

class EGL_Shader{
    public:
    EGL_Shader(const std::string& file_name);
    ~EGL_Shader();

    void Bind();
    
    private:
    static const unsigned int NUM_SHADERS = 2;
    GLuint program;
    GLuint shaders[NUM_SHADERS];
};

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