#include "EGL.h"

EGL_Window win(1920,1080,"TEST");

int main()
{
    EGL_Shader shader("/home/elliem/cpp/EGL/shaders/basic_shader");
    shader.Bind();

    std::vector<EGL_Point> points{EGL_Point(0,50,0),EGL_Point(50,-50,0),EGL_Point(0,-30,0),EGL_Point(-50,-50,0)};

    std::vector<EGL_Point> box1_points{EGL_Point(0,0,0),EGL_Point(0,100,0),EGL_Point(100,100,0),EGL_Point(100,0,0)};
    std::vector<EGL_Point> box2_points{EGL_Point(-15,-15,0),EGL_Point(-15,15,0),EGL_Point(15,15,0),EGL_Point(15,-15,0)};

    EGL_Hitbox box1(&box1_points);
    EGL_Hitbox box2(&box2_points);

    box1.Draw(880,500,0);

    win.SetClearCol(0.1,0.32,0.5,1);
    //23, 83, 133

    while(!win.ShouldQuit())
    {
        box1.Draw();
        box2.Rotate(0,0,1);
        box2.Draw(win.mouse.x,win.mouse.y,0);

        box2.CheckCollision(&box1);
        if(box2.hits.size() != 0){
            for(int i=0;i<box2.hits.at(0).hit_points.size();i++){
                fmt::print("{} {} {} \n",box2.hits.at(0).hit_points.at(i).x,box2.hits.at(0).hit_points.at(i).y,box2.hits.at(0).hit_points.at(i).z);
            }
            fmt::print("\n");
        }
        box2.ClearHits();

        win.Update();
    }

    return 0;
}


