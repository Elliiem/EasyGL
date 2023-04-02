#include "EGL.h"

int main()
{
    EGL_Window win(1920,1080,"TEST");

    EGL_Shader shader("/home/elliem/cpp/EGL/shaders/basic_shader");

    std::vector<EGL_Point> points{EGL_Point(0,0,0),EGL_Point(50,50,0),EGL_Point(100,0,0)};
    std::vector<EGL_Point> points2{EGL_Point(0,1080,0),EGL_Point(1000,500,0),EGL_Point(1920,1080,0)};
    EGL_Poly poly(&win,points);
    EGL_Poly poly2(&win,points2);

    shader.Bind();

    poly2.Change(points);
    poly.Change(points2);

    EGL_Point foo(-1,1,0);
    foo.RotateZ(1);

    while(!win.quit)
    {
        win.Clear();

        poly.Draw();
        points.at(0).RotateZ(-1);
        points.at(1).RotateZ(-1);
        points.at(2).RotateZ(-1);
        poly2.Change(points);
        poly2.Draw(100,100,0);

        win.Update();
    }

    SDL_DestroyWindow(win.SDL_win);
    SDL_Quit();
    return 0;
}


