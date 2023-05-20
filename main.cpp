#include "EGL.h"
EGL_Window win(1920,1080,"EGL TEST");
EGL_Game game(&win);

int count = 0;

void mouse_func(EGL_Object* obj){
    obj->SetPos(win.input.mouse_pos.x,win.input.mouse_pos.y,0);
    if(obj->hits.size() != 0){
        fmt::print("Hit {}\n",count++);
    }
}

int main()
{
    EGL_Shader shader("../shaders/basic_shader");
    shader.Bind();

    std::vector<EGL_Point> box{EGL_Point(-50,-50,0),EGL_Point(-50,50,0),EGL_Point(50,50,0),EGL_Point(50,-50,0)};
    std::vector<EGL_Point> box_small{EGL_Point(-25,-25,0),EGL_Point(-25,25,0),EGL_Point(25,25,0),EGL_Point(25,-25,0)};


    EGL_Object* foo = game.AddPhysicsObject(&box,mouse_func);
    EGL_Object* bar = game.AddPhysicsObject(&box);
    game.AddStaticObject(&box)->SetPos(500,500,0);
    win.Update();
    game.Update();

    while(!win.ShouldQuit())
    {
        game.Update();
        win.Update();
    }

    return 0;
}
