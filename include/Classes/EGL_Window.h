#pragma once

#include "EGL_Color.h"
#include "EGL_Input.h"
#include "EGL_Shader.h"

#include <string>
#include <SDL2/SDL.h>

// Window Handling
class EGL_Window{
    public:
    EGL_Window(int width,int height,std::string name);
    ~EGL_Window();

    EGL_Input input;

    public:
    void Update();
    bool ShouldQuit();
    void BindShader(EGL_Shader* new_shader);

    private:
    SDL_Event event;
    SDL_Window* SDL_win;
    SDL_GLContext gl_cont;
    EGL_Shader* current_shader;

    EGL_Color clear_col = EGL_Color(0,0,0,1);

    bool quit = 0;
    
    private:
    void HandleEvents();
    void SwapBuffers();
};

