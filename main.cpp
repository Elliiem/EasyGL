#include "EGL.h"

int main()
{
    EGL_Window win(1920,1080,"TEST");

    EGL_Shader shader("../shaders/basic_shader");
    shader.Bind();

    std::vector<EGL_Point> box{EGL_Point(-50,-50,0),EGL_Point(-50,50,0),EGL_Point(50,50,0),EGL_Point(50,-50,0)};
    std::vector<EGL_Point> box_small{EGL_Point(-25,-25,0),EGL_Point(-25,25,0),EGL_Point(25,25,0),EGL_Point(25,-25,0)};

    EGL_Mesh foo(&box);

    while(!win.ShouldQuit())
    {
        foo.Draw();
        foo.SetPos(win.input.mouse_pos.x, win.input.mouse_pos.y, 0);
        win.Update();
    }

    return 0;
}
