#include "EGL.h"

int EGL_WIN_HEIGHT;
int EGL_WIN_WIDTH;

EGL_Window::EGL_Window(int width, int height, std::string name)
{
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

    if(status != GLEW_OK)
    {
        std::cerr << "Glew failed to Init" << std::endl;
    }

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

void EGL_Window::SwapBuffers()
{
    SDL_GL_SwapWindow(SDL_win);
}


void EGL_Window::Clear()
{
    glClearColor(clear_col.r,clear_col.g,clear_col.b,clear_col.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void EGL_Window::SetClearCol(float R,float G,float B,float A)
{
    clear_col = EGL_Color(R,G,B,A);
}

void EGL_Window::SetClearCol(EGL_Color col){
    clear_col = col;
}


void EGL_Window::Update()
{
    SwapBuffers();
    HandleEvents();

    if(keyboard[SDLK_z] && keyboard[SDLK_LCTRL]){
        quit = true;
    }

    Clear();
}


void EGL_Window::HandleEvents()
{
    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case(SDL_QUIT):
                quit = 1;
            break;
        }
        HandleKey();
        HandleMouse();
    }
}

void EGL_Window::HandleMouse(){
    switch(event.type){
        case(SDL_MOUSEMOTION):
            mouse.x = event.motion.x;
            mouse.y = event.motion.y;
        break;
    }
}

void EGL_Window::HandleKey(){
    switch(event.type){
        case(SDL_KEYUP):    
            try{
                keyboard.at(event.key.keysym.sym) = false;
            }
            catch (const std::exception&){
                keyboard.insert({event.key.keysym.sym,false});
            }
        break;
        case(SDL_KEYDOWN):
            try{
                keyboard.at(event.key.keysym.sym) = true;
            }
            catch (const std::exception&){
                keyboard.insert({event.key.keysym.sym,true});
            }
        break;
    }
}
