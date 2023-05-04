#ifndef EGL_INPUT
#define EGL_INPUT

#include "EGL_Vector.h"

#include <SDL2/SDL.h>

#include <map>

class EGL_Input{
    public:
    EGL_Input(SDL_Event* event);
    EGL_Input(){};

    std::map<int,bool>keyboard;
    EGL_Vector mouse_pos;

    void Handle();

    private:
    SDL_Event* event;

    void KeyUp();
    void KeyDown();
    void MouseMovement();
};



#endif