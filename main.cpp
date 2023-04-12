#include "EGL.h"

int main()
{
    EGL_Window win(1920,1080,"TEST");

    EGL_Shader shader("/home/elliem/cpp/EGL/shaders/basic_shader");

    std::vector<EGL_Point> points{EGL_Point(-10,-10,0),EGL_Point(10,-10,0),EGL_Point(10,10,0),EGL_Point(-10,10,0)};
    std::vector<EGL_Point> points2{EGL_Point(0,1080,0),EGL_Point(1000,500,0),EGL_Point(1920,1080,0)};
    EGL_Poly poly(&win,points);
    EGL_Poly poly2(&win,points2);

    shader.Bind();

    poly2.Change(points);
    poly.Change(points2);

    while(!win.quit)
    {
        win.Clear();
        poly.Draw();
        poly2.Rotate(0,0,0.1);
        poly2.Draw(100,100,0);
        win.Update();
    }

    SDL_DestroyWindow(win.SDL_win);
    SDL_Quit();
    return 0;
}


