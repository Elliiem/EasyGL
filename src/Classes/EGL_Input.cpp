#include "EGL_Input.h"

EGL_Input::EGL_Input(SDL_Event* event){
    this->event = event;
}

void EGL_Input::Handle(){
    switch(event->type){
        case SDL_KEYDOWN:
            KeyDown();
        break;
        case SDL_KEYUP:
            KeyUp();
        break;
        case SDL_MOUSEMOTION:
            MouseMovement();
        break;
    };
}

void EGL_Input::KeyUp(){
    try{
        keyboard.at(event->key.keysym.sym) = false;
    }
    catch (const std::exception&){
        keyboard.insert({event->key.keysym.sym,false});
    }
}

void EGL_Input::KeyDown(){
    try{
        keyboard.at(event->key.keysym.sym) = true;
    }
    catch (const std::exception&){
        keyboard.insert({event->key.keysym.sym,true});
    }
}

void EGL_Input::MouseMovement(){
    mouse_pos.x = event->motion.x;
    mouse_pos.y = event->motion.y;
}