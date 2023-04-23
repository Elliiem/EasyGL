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
#include <map>

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
    
    EGL_Vertex(){

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

    void operator+=(EGL_Vector other){
        x += other.x;
        y += other.y;
        z += other.z;
    }

    EGL_Vector operator-(EGL_Vector other){
        return EGL_Vector(x - other.x,y - other.y,z - other.z);       
    }
    EGL_Vector operator+(EGL_Vector other){
        return EGL_Vector(x + other.x,y + other.y,z + other.z);       
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
    EGL_Vector vec;
    EGL_Vector rot;
};

// Globals
extern int EGL_WIN_HEIGHT;
extern int EGL_WIN_WIDTH;

// Window Handling
class EGL_Window{
    public:
    EGL_Window(int width, int height, std::string name);
    ~EGL_Window();

    void Update();
    void SwapBuffers();
    void Clear();

    bool ShouldQuit();

    void SetClearCol(float R,float G,float B,float A);
    void SetClearCol(EGL_Color col);

    /*This will be replaced by a input class*/
    void HandleEvents();
    void HandleKey();
    void HandleMouse();
    
    
    // Input Storage, All will be under one class!
    // Keyboard Inputs stored on a map 
    // whether a key is pressed or not is mapped to the key in the SDL Keycode
    /*Later there will be a class for storing and Handling all Mouse Inputs*/
    std::map<int,bool> keyboard;
    // Mouse Inputs currently are only the position of the mouse
    /*Later there will be a class for storing and Handling all Mouse Inputs*/
    EGL_Vector mouse;

    private:
    SDL_Event event;

    SDL_Window* SDL_win;
        EGL_Color clear_col = EGL_Color(0,0,0,1);
    SDL_GLContext gl_cont;

    bool quit = 0;
};

// Low Level Graphics
class EGL_Mesh{
    public:
    EGL_Mesh(EGL_Vertex* points, uint8_t num_points);
    EGL_Mesh(){

    }
    ~EGL_Mesh();

    void Draw();
    void Draw(float x,float y,float z);

    void Change(EGL_Vertex* points, uint8_t size);
    void Change();

    void UpdateVertexPosition(EGL_Vector pos);

    EGL_Vector pos;

    protected:
    void Init_Mesh(EGL_Vertex* verticies, uint8_t num_points);

    enum
    {
        POSITION_VB,
        NUM_BUFFERS
    };

    GLuint vertex_array_obj;
    GLuint vertex_array_buffers[NUM_BUFFERS];
    uint8_t draw_count;
    EGL_Vertex* verticies;

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
    void Init_Poly(std::vector<EGL_Point>* points);
    std::vector<EGL_Point> points;

    private:
    EGL_Vertex* GetVerticiesVector();
};


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

    bool CheckLineIntersect(EGL_Vector q1,EGL_Vector q2, EGL_Vector p1);
    bool PointInOther(EGL_Point point,EGL_Hitbox* other);
    void CheckCollision(EGL_Hitbox* other);
    void UpdateHitbox(std::vector<EGL_Point>* points);
    void ClearHits();

    std::vector<HitInfo> hits;
};

class EGL_PhysicsObject : public EGL_Poly{
    public:
    EGL_PhysicsObject(std::vector<EGL_Point>* points);

    void Update();
};

//EGL Helper Functions
EGL_Vector EGL_UnclampCoordinates(EGL_Vertex vertex);
EGL_Vertex EGL_ClampCoordinates(float x,float y,float z);
EGL_Vector ToVector(EGL_Point point);
#endif