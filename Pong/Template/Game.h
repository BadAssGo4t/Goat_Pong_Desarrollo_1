#pragma once

#include "ScreenManager.h"
#include "Player.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

#define PLAYER_MAX_LIFE         5

namespace Game
{


	void InitGame();
	void UpdateGame();
	void DrawGame();
	void UnloadGame();
}