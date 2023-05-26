#include "EGL_Input.h"

EGL_Input::EGL_Input(SDL_Event* event){
    this->event = event;
}

bool EGL_Input::IsPressed(int key){
    try{return !last_keyboard.at(key) && keyboard.at(key);}
    catch(std::exception&){return false;}
}

bool EGL_Input::IsPushed(int key){
    try{return keyboard.at(key);}
    catch(std::exception&){
        return false;
    }
}

void EGL_Input::HandleInputs()
{
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

void EGL_Input::Update(){
    last_keyboard = keyboard;
}

void EGL_Input::KeyUp(){
    try{
        keyboard.at(event->key.keysym.sym) = false;
    } catch (const std::exception&){
        keyboard.insert({event->key.keysym.sym,false});
    }
}

void EGL_Input::KeyDown(){
    try{
        keyboard.at(event->key.keysym.sym) = true;
    } catch (const std::exception&){
        keyboard.insert({event->key.keysym.sym,true});
    }
}

void EGL_Input::MouseMovement(){
    mouse_pos.x = event->motion.x;
    mouse_pos.y = event->motion.y;
}