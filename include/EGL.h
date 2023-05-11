#pragma once

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <fmt/format.h>

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

#include "EGL_Structs.h"
#include "EGL_Window.h"
#include "EGL_Func.h"
#include "EGL_Physics.h"
#include "EGL_Graphics.h"

// Globals
extern int EGL_WIN_HEIGHT;
extern int EGL_WIN_WIDTH;
extern float EGL_SWAP_INTERVAL;