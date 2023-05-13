#pragma once

#include "EGL_Color.h"
#include "EGL_Input.h"
#include "EGL_Object.h"

#include <string>
#include <SDL2/SDL.h>

// Window Handling
class EGL_Window{
    public:
    EGL_Window(int width, int height, std::string name);
    ~EGL_Window();

    EGL_Input input;

    std::vector<EGL_Object*> physics_objects;
    std::vector<EGL_Object*> static_objects;

    public:
    void Update();
    void Clear();
    bool ShouldQuit();
    void SetClearCol(float R,float G,float B,float A);
    void SetClearCol(EGL_Color col);
    EGL_Object* AddPhysicsObject(std::vector<EGL_Point>* points);
    EGL_Object* AddStaticObject(std::vector<EGL_Point>* points);

    private:
    SDL_Event event;

    private:
    SDL_Window* SDL_win;
    SDL_GLContext gl_cont;

    EGL_Color clear_col = EGL_Color(0,0,0,1);

    bool quit = 0;
    
    private:
    void HandleEvents();
    void SwapBuffers();
};

