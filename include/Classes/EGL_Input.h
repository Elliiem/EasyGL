#pragma once 

#include "EGL_Vector.h"

#include <SDL2/SDL.h>

#include <map>

class EGL_Input{
    public:
    EGL_Input(SDL_Event* event);
    EGL_Input(){};

    EGL_Vector mouse_pos;

    bool IsPressed(int key);
    bool IsPushed(int key);


    void HandleInputs();
    void Update();

    private:
    SDL_Event* event;
    std::map<int,bool>keyboard;
    std::map<int,bool>last_keyboard;

    void KeyUp();
    void KeyDown();
    void MouseMovement();
};
