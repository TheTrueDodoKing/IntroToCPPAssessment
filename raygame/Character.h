#pragma once
#include "Actor.h"
#include "Vector2.h"
class Character :
    public Actor

{
public:
    Character::Character(const char* spritepath, );

    Vector2 Velocity
    {
        get{return _velocity; }
        set{ _}
    }

private:
    Vector2 _velocity;
    
};


