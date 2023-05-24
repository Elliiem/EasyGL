#include "EGL.h"
int count = 0;

void mouse_func(EGL_PhysicsObject* obj, EGL_Window* win){
    obj->SetPos(win->input.mouse_pos.x,win->input.mouse_pos.y,0);
    if(obj->hits.size() != 0){
        fmt::print("Hit {}\n",count++);
    }
    obj->Rotate(0,0,0.001);
}

int main()
{
    EGL_Window win(1920,1080,"EGL TEST");
    EGL_Shader shader("../shaders/basic_shader");
    EGL_Render rend(&shader);
    EGL_Game game(&win,&rend);

    std::vector<EGL_Point> box{EGL_Point(-50,-50,0),EGL_Point(-50,50,0),EGL_Point(50,50,0),EGL_Point(50,-50,0)};
    std::vector<EGL_Point> box_small{EGL_Point(-25,-25,0),EGL_Point(-25,25,0),EGL_Point(25,25,0),EGL_Point(25,-25,0)};

    EGL_PhysicsObject* foo = game.AddPhysicsObject(&box,mouse_func);
    EGL_PhysicsObject* bar = game.AddPhysicsObject(&box);
    game.AddStaticObject(&box)->SetPos(600,600,0);

    foo->SetCol(1.0f,0.0f,1.0f,1.0f);

    win.Update();
    game.Update();

    while(!win.ShouldQuit())
    {
        game.Update();
    }

    return 0;
}
