#ifndef EGL_WINDOW
#define EGL_WINDOW

#include "EGL_Color.h"
#include "EGL_Input.h"
#include <string>
#include <map>
#include <SDL2/SDL.h>

// Window Handling
class EGL_Window{
    public:
    EGL_Window(int width, int height, std::string name);
    ~EGL_Window();

    EGL_Input input;

    void Update();
    void Clear();

    bool ShouldQuit();

    void SetClearCol(float R,float G,float B,float A);
    void SetClearCol(EGL_Color col);

    private:
    SDL_Event event;

    SDL_Window* SDL_win;
    SDL_GLContext gl_cont;

    EGL_Color clear_col = EGL_Color(0,0,0,1);


    bool quit = 0;

    void HandleEvents();

    void SwapBuffers();
};
#endif
