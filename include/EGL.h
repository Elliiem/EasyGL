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

struct EGL_Point{
    EGL_Point(glm::vec3 Vec){
        vec = Vec;
        x = Vec.x;
        y = Vec.y;
        z = Vec.z;
    }

    EGL_Point(float X,float Y,float Z){
        x = X;
        y = Y;
        z = Z;
    }

    EGL_Point(){
        x = 0;
        y = 0;
        z = 0;
    }

    EGL_Point operator+(EGL_Point Other){
        return EGL_Point(x+Other.x,y+Other.y,z+Other.z);
    }
    EGL_Point operator-(EGL_Point Other){
        return EGL_Point(x-Other.x,y-Other.y,z-Other.z);
    }

    glm::vec3 vec;
    float x;
    float y;
    float z;
};

struct EGL_Deg{
    EGL_Deg(){
        val = 0;
    }
    EGL_Deg(float Deg){
        val = Deg;
    }
    
    float operator+(float Deg){
        float tval = val;
        float times = ((tval+Deg)/360);
        tval = 360*(times-int(times));
        return abs(round(tval*1000)/1000);
    }

    void operator+=(float Deg){
        float times = ((val+Deg)/360);
        val = 360*(times-int(times));
        val = abs(round(val*1000)/1000);
    }

    float operator-(float Deg){
        float times;
        float tval;
        tval = val-Deg;
        if(tval >= 0){
            times = tval/360;
            tval = 360*(times-int(times));
        }
        else{
            times = abs(tval/360);
            tval = 360*(1-(times-int(times)));
        }
        if(tval == 360)
            return 0.0;
        return abs(round(tval*1000)/1000);
    }

    void operator-=(float Deg){
        float times;
        val -= Deg;
        if(val >= 0){
            times = val/360;
            val = 360*(times-int(times));
        }
        else{
            times = abs(val/360);
            val = 360*(1-(times-int(times)));
        }
        if(val == 360)
            val = 0;
        else
            val = abs(round(val*1000)/1000);
    }

    float val;
};

struct EGL_Polar{
    EGL_Polar(float x,float y,float z);
    
    EGL_Point Carthesian();

    float lx;
    float ly;
    float lz;
    EGL_Deg dx;
    EGL_Deg dy;
    EGL_Deg dz;
    EGL_Point pos;
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


// EGL ClampCoords
EGL_Vertex EGL_ClampCoords(EGL_Window* win,float x,float y,float z);




#endif