#include "EGL.h"

EGL_Vertex EGL_ClampCoords(EGL_Window* win,float x,float y,float z){
    int win_height;
    int win_width;

    SDL_GetWindowSize(win->SDL_win,&win_width,&win_height); 
    
    float xf = x / ((float)win_width/2);
    float yf = -(y / ((float)win_height/2));

    return EGL_Vertex(xf-1,yf+1,z);
}
