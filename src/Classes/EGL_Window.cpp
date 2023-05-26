#include "EGL.h"
#include "EGL_Window.h"

int EGL_WIN_HEIGHT;
int EGL_WIN_WIDTH;
float EGL_SWAP_INTERVAL = 0;

EGL_Window::EGL_Window(int width,int height,std::string name){
    EGL_WIN_HEIGHT = height;
    EGL_WIN_WIDTH = width;
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_win = SDL_CreateWindow(name.data(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_OPENGL);
    gl_cont = SDL_GL_CreateContext(SDL_win);

    GLenum status = glewInit();

    if(status != GLEW_OK){
        std::cerr << "Glew failed to Init" << std::endl;
    }

    SDL_GL_SetSwapInterval(0);
    input = EGL_Input(&event);
}

EGL_Window::~EGL_Window()
{
    SDL_GL_DeleteContext(gl_cont);
    SDL_DestroyWindow(SDL_win);
    SDL_Quit();
}

bool EGL_Window::ShouldQuit(){
    return quit;
}

void EGL_Window::SwapBuffers(){
    SDL_GL_SwapWindow(SDL_win);
}

void EGL_Window::Update(){
    SwapBuffers();
    input.Update();
    HandleEvents();

    if(input.IsPushed(SDLK_z) && input.IsPushed(SDLK_LCTRL)){
        quit = true;
    }
}

void EGL_Window::HandleEvents(){
    while (SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                quit = 1;
            break;
        }
        input.HandleInputs();
    }
}
