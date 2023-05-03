#ifndef EGL_PHYSICS
#define EGL_PHYSICS

#include "EGL_Hitbox.h"
#include "EGL_PhysicsObject.h"

// Physics Engine
    /*
    Hitboxes
        Collision Detection
            optimally sht like CheckCollision(EGL_Hitbox) and returns a struct with the hit info
    Collision Handling
        Calculate New Velocities
        Calculate New RotForces in z
    Velocity/Acceleration
        Gravity
        Forces (like Thrusters)
    Rotational Forces
        only realistic in z
        other directions just a bit of rotation on collision
        and let them slowly go back to 0
    Drawing -> U know
        Handle Poly
    */

// Top Level Physics Engine
// Should only need to tell every Physics Object to Check for Collisions with Objects nearby
#endif