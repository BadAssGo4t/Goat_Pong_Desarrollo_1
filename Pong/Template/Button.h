#pragma once

#include "ScreenManager.h"

namespace Button
{
    struct   newButton
    {
        Texture2D Texture;
        float FrameHeight;
        Rectangle SourceRec;
        Rectangle Bounds;
        int State;
        bool Action;
    };
}
