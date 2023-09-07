#pragma once
#include "Game.h"

namespace Ball
{
    struct NewBall {
        Vector2 position;
        Vector2 speed;
        int radius;
        bool active;
    };
}