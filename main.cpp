#include "EGL.h"

EGL_Window win(1920,1080,"TEST");

int main()
{
    EGL_Shader shader("/home/elliem/cpp/EGL/shaders/basic_shader");
    shader.Bind();

    std::vector<EGL_Point> points{EGL_Point(0,50,0),EGL_Point(50,-50,0),EGL_Point(0,-30,0),EGL_Point(-50,-50,0)};
    EGL_PhysicsObject foo(points);
    EGL_PhysicsObject bar(points);
    foo.pos = EGL_Vector(1000,500,0);
    while(!win.quit)
    {
        win.Clear();
        
        //foo.Update();
        //bar.Draw();
        bar.pos = win.mouse;
        
        //foo.box.CheckCollision(&bar.box);
        //bar.box.CheckCollision(&foo.box);
        if(foo.box.hits.size()!=0 || bar.box.hits.size()!=0){
            win.SetClearCol(1,1,1,1);
        } else {
            win.SetClearCol(0,0,0,1);
        }


        win.Update();
    }

    SDL_DestroyWindow(win.SDL_win);
    SDL_Quit();
    return 0;
}


