#pragma once
#include "Game.h"

namespace Player
{
    // players
    struct NewPlayer {
        Rectangle plyRec;
        Vector2 position;
        Vector2 size;
        bool active;
        int life;
    };
}