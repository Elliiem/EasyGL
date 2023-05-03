#ifndef EGL_WINDOW
#define EGL_WINDOW

#include "EGL_Structs.h"
#include <string>
#include <map>
#include <SDL2/SDL.h>

// Window Handling
class EGL_Window{
    public:
    EGL_Window(int width, int height, std::string name);
    ~EGL_Window();

    // Input Storage, All will be under one class!
    // Keyboard Inputs stored on a map 
    // whether a key is pressed or not is mapped to the key in the SDL Keycode
    /*Later there will be a class for storing and Handling all Mouse Inputs*/
    std::map<int,bool> keyboard;
    // Mouse Inputs currently are only the position of the mouse
    /*Later there will be a class for storing and Handling all Mouse Inputs*/
    EGL_Vector mouse;

    void Update();
    void Clear();

    bool ShouldQuit();

    void SetClearCol(float R,float G,float B,float A);
    void SetClearCol(EGL_Color col);

    private:
    SDL_Event event;

    SDL_Window* SDL_win;
    EGL_Color clear_col = EGL_Color(0,0,0,1);
    SDL_GLContext gl_cont;

    bool quit = 0;

    /*This will be replaced by a input class*/
    void HandleEvents();
    void HandleKey();
    void HandleMouse();
    void SwapBuffers();
};
#endif
