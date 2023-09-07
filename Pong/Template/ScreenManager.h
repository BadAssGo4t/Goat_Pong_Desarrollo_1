#pragma once

#include <iostream>
#include "raylib.h"

#include "Menu.h"
#include "Options.h"
#include "Instructions.h"
#include "Credits.h"

#include "GameMode.h"
#include "Game.h"

#include "Button.h"
#include "Unloader.h"

struct   Screen
{
    int width;
    int height;
};

static Screen curScreen;


namespace ScreenManagerNam
{
	enum GameScreen
	{
		Menu = 0,
		Game,
		GameMode,
		Instructions,
		Credits,
		End
	};
	extern GameScreen Screens;

	int ScreenManager();
}