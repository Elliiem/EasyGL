cmake_minimum_required(VERSION 3.5)

project(EGL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt REQUIRED)
include_directories(${fmt_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(EGL
main.cpp 
src/EGL_Window.cpp
src/EGL_Mesh.cpp
src/EGL_Shader.cpp
src/EGL_Func.cpp
src/EGL_Poly.cpp
src/EGL_Point.cpp
stb/stb_image.c
)

target_include_directories(EGL PUBLIC 
. 
stb
./include
)

target_link_libraries(EGL
fmt 
OpenGL 
GLEW
SDL2
)

install(TARGETS EGL
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
