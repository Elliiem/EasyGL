#include "EGL.h"

int main()
{
    EGL_Window win(1920,1080,"TEST");

    EGL_Shader shader("../shaders/basic_shader");
    shader.Bind();

    std::vector<EGL_Point> box{EGL_Point(-50,-50,0),EGL_Point(-50,50,0),EGL_Point(50,50,0),EGL_Point(50,-50,0)};
    std::vector<EGL_Point> box_small{EGL_Point(-25,-25,0),EGL_Point(-25,25,0),EGL_Point(25,25,0),EGL_Point(25,-25,0)};

    EGL_Hitbox foo(&box_small);
    EGL_Hitbox bar(&box);
    bar.SetPos(100,100,0);

    while(!win.ShouldQuit())
    {
        foo.SetPos(win.input.mouse_pos.x,win.input.mouse_pos.y,0);
        foo.Draw();
        bar.Draw();
        win.Update();
    }

    return 0;
}
