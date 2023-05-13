#include "EGL_Game.h"

EGL_Game::EGL_Game(EGL_Window* win){
    this->win = win;
}

EGL_Game::~EGL_Game(){
    for(int i=0;i<physics_objects.size();i++){
        delete physics_objects.at(i);
    }

    for(int i=0;i<static_objects.size();i++){
        delete static_objects.at(i);
    }
}


EGL_Object* EGL_Game::AddPhysicsObject(std::vector<EGL_Point>* points, void(*func)(EGL_Object*)){
    physics_objects.emplace_back(new EGL_Object(points,func));
    return physics_objects.back();
}

EGL_Object* EGL_Game::AddStaticObject(std::vector<EGL_Point>* points, void(*func)(EGL_Object*)){
    static_objects.emplace_back(new EGL_Object(points,func));
    return static_objects.back();
}

void EGL_Game::DeleteObject(EGL_Object* obj){
    bool found = false;
    for(int i=0;i<physics_objects.size();i++){
        if(physics_objects.at(i) == obj){
            found = true;
            physics_objects.erase(physics_objects.begin()+i);
            delete obj;
            return;
        }
    }
    for(int i=0;i<static_objects.size();i++){
        if(static_objects.at(i) == obj){
            found = true;
            static_objects.erase(static_objects.begin() + i);
            delete obj;
            return;
        }
    }

    std::cerr << "\033[31;1mEGL_Game::DeleteObject Couldnt find Object!\033[0m\n";
}

void EGL_Game::Update(){
    for(int i=0;i<physics_objects.size();i++){
        physics_objects.at(i)->Update();
        physics_objects.at(i)->Draw();
    }
    for(int i=0;i<static_objects.size();i++){
        static_objects.at(i)->func(static_objects.at(i));
        static_objects.at(i)->Draw();
    }
}