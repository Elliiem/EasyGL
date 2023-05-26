#include "EGL_Game.h"

EGL_Game::EGL_Game(EGL_Window* win,EGL_Render* rend){
    this->win = win;
    this->rend = rend;
}

EGL_Game::~EGL_Game(){
    for(int i=0;i<physics_objects.size();i++){
        delete physics_objects.at(i);
    }

    for(int i=0;i<static_objects.size();i++){
        delete static_objects.at(i);
    }
}


EGL_PhysicsObject* EGL_Game::AddPhysicsObject(std::vector<EGL_Point>* points,void(*func)(EGL_PhysicsObject*,EGL_Window*),std::string id){
    physics_objects.emplace_back(new EGL_PhysicsObject(points,func,id));
    return physics_objects.back();
}

EGL_Object* EGL_Game::AddStaticObject(std::vector<EGL_Point>* points, void(*func)(EGL_Object*,EGL_Window*),std::string id){
    static_objects.emplace_back(new EGL_Object(points,func,id));
    return static_objects.back();
}

EGL_PhysicsObject* EGL_Game::AddPhysicsObject(std::vector<EGL_Point>* points,std::string id){
    physics_objects.emplace_back(new EGL_PhysicsObject(points,id));
    return physics_objects.back();
}

EGL_Object* EGL_Game::AddStaticObject(std::vector<EGL_Point>* points,std::string id){
    static_objects.emplace_back(new EGL_Object(points,id));
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
    UpdateCollisions();
    for(int i=0;i<physics_objects.size();i++){
        physics_objects.at(i)->Update(win);
        physics_objects.at(i)->Draw(rend);
    }
    for(int i=0;i<static_objects.size();i++){
        static_objects.at(i)->Update(win);
        static_objects.at(i)->Draw(rend);
    }

    win->Update();
    rend->Update();
}

void EGL_Game::UpdateCollisions(){
    for(int i=0;i<physics_objects.size();i++){
        for(int ii=0;ii<physics_objects.size();ii++){
            if(physics_objects.at(i) != physics_objects.at(ii)){
                physics_objects.at(i)->Collide(physics_objects.at(ii));
            }
        }
    }
}

void EGL_Game::ChangeScene(std::vector<EGL_PhysicsObject*> physics_obj, std::vector<EGL_Object*> static_obj){
    physics_objects = physics_obj;
    static_objects = static_obj;
}
