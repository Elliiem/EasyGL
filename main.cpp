#include "EGL.h"

void std_func(EGL_Object* obj){
    EGL_Vector pos = obj->GetPos();
    if(pos.x <= 0 || pos.x >= 1920){
        EGL_Vector current = obj->GetVel();
        obj->SetVel(-current.x,current.y,current.z);
    }else if(pos.y <= 0 || pos.y >= EGL_WIN_HEIGHT){
        EGL_Vector current = obj->GetVel();
        obj->SetVel(current.x,-current.y,current.z);
    }
}

int main()
{
    EGL_Window win(1920,1080,"TEST");

    EGL_Game game(&win);

    EGL_Shader shader("../shaders/basic_shader");
    shader.Bind();

    std::vector<EGL_Point> box{EGL_Point(-50,-50,0),EGL_Point(-50,50,0),EGL_Point(50,50,0),EGL_Point(50,-50,0)};
    std::vector<EGL_Point> box_small{EGL_Point(-25,-25,0),EGL_Point(-25,25,0),EGL_Point(25,25,0),EGL_Point(25,-25,0)};


    EGL_Object* foo = game.AddPhysicsObject(&box, std_func);
    foo->SetPos(500,800,0);
    foo->SetVel(EGL_Vector(1,1,0));

    while(!win.ShouldQuit())
    {
        game.Update();
        win.Update();
    }

    return 0;
}
