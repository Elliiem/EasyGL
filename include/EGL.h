#ifndef EGL
#define EGL

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <fmt/format.h>

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

//Structs
struct EGL_Vertex{
    EGL_Vertex(float X,float Y,float Z){
        pos = glm::vec3(X,Y,Z);
    }

    EGL_Vertex(glm::vec3 Vec){
        pos = Vec;
    }

    EGL_Vertex(EGL_Vertex* point){
        pos = point->pos;
    }

    glm::vec3 pos;
};

struct EGL_Color{
    EGL_Color(float R, float G, float B, float A){
        r = R;
        g = G;
        b = B;
        a = A;
    }

    EGL_Color(){

    }

    float r;
    float g;
    float b;
    float a;
};

struct EGL_Vector{
    EGL_Vector(float x,float y,float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    EGL_Vector(){
        x = 0;
        y = 0;
        z = 0;
    }

    float x,y,z;
};

struct EGL_Point{
    // Initializers
    EGL_Point(EGL_Vector vec);
    EGL_Point(float x,float y,float z);
    EGL_Point();

    void RotateZ(float deg);
    void RotateX(float deg);
    void RotateY(float deg);
    
    float x,y,z;
    protected:
    EGL_Vector vec;
    EGL_Vector rot;
};

// EGL Window
class EGL_Window{
    public:
    EGL_Window(int width, int height, std::string name);
    ~EGL_Window();

    SDL_Window* SDL_win;
    SDL_GLContext gl_cont;

    bool quit = 0;

    void SwapBuffers();
    void Update();
    void Clear();
    void SetClearCol(float R,float G,float B,float A);
    void SetClearCol(EGL_Color col);

    private:
    EGL_Color clear_col = EGL_Color(0,0,0,1);
    SDL_Event event;

    void HandleEvents();
};

// EGL Mesh
class EGL_Mesh{
    public:
    EGL_Mesh(EGL_Vertex* points, uint8_t num_points = 3);
    EGL_Mesh(){

    }
    ~EGL_Mesh();

    void Draw();
    void Change(EGL_Vertex* points, uint8_t size);

    enum
    {
        POSITION_VB,
        NUM_BUFFERS
    };

    //private:
    GLuint vertex_array_obj;
    GLuint vertex_array_buffers[NUM_BUFFERS];
    uint8_t draw_count;

};

// EGL Shader
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

// EGL Poly
class EGL_Poly{
    public:
    EGL_Poly(EGL_Window* win, std::vector<EGL_Point> Points);
    EGL_Poly(){

    }
    ~EGL_Poly();

    void Draw();
    void Draw(int x,int y,int z);
    void Change(std::vector<EGL_Point> Points);
    void Change();

    private:
    
    void ChangeVerts();

    std::vector<EGL_Point> points;
    EGL_Mesh* mesh;
    EGL_Window* win;
    EGL_Point pos;
};

class EGL_Obj{
    public:
    EGL_Obj(EGL_Poly poly);

    EGL_Vector pos;
    private:
    EGL_Poly poly;

};



// EGL ClampCoords
EGL_Vertex EGL_ClampCoords(EGL_Window* win,float x,float y,float z);




#endif