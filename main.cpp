#include "EGL.h"

EGL_Window win(1920,1000,"TEST");

int main()
{
    EGL_Shader shader("/home/elliem/cpp/EGL/shaders/basic_shader");
    shader.Bind();

    std::vector<EGL_Point> points{EGL_Point(0,50,0),EGL_Point(50,-50,0),EGL_Point(0,-30,0),EGL_Point(-50,-50,0)};

    std::vector<EGL_Point> box1_points{EGL_Point(0,0,0),EGL_Point(0,100,0),EGL_Point(100,100,0),EGL_Point(100,0,0)};
    std::vector<EGL_Point> box2_points{EGL_Point(-5,-25,0),EGL_Point(-5,25,0),EGL_Point(5,25,0),EGL_Point(5,-25,0)};

    EGL_PhysicsObject box1(&box1_points);
    EGL_PhysicsObject box2(&box2_points);
    win.SetClearCol(0.1,0.32,0.5,1);
    //23, 83, 133

    while(!win.ShouldQuit())
    {
        box1.Draw();
        box2.Rotate(0,0,1);
        box2.Draw(win.mouse.x,win.mouse.y,0);

        box2.box->CheckCollision(box1.box);
        if(box2.box->hits.size() != 0){
            win.SetClearCol(1,1,1,1);
        } else {
            win.SetClearCol(0.1,0.32,0.5,1);
        }
        box2.box->ClearHits();

        win.Update();
    }

    return 0;
}


