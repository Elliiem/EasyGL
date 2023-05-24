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

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")

add_executable(EGL
main.cpp 
src/Classes/EGL_Window.cpp
src/Classes/EGL_Mesh.cpp
src/Classes/EGL_Shader.cpp
src/EGL_Func.cpp
src/Structs/EGL_Point.cpp
src/Classes/EGL_Hitbox.cpp
src/Classes/EGL_Object/EGL_Object.cpp
src/Classes/EGL_Object/EGL_PhysicsObject.cpp
src/Structs/EGL_Vector.cpp
src/Classes/EGL_Input.cpp
src/Classes/EGL_Game.cpp
src/Classes/EGL_Render.cpp
)

target_include_directories(EGL PUBLIC  
./include
./include/Classes
./include/Structs
./include/Classes/EGL_Object
)

target_link_libraries(EGL
fmt 
OpenGL 
GLEW
SDL2
)

install(TARGETS EGL
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
