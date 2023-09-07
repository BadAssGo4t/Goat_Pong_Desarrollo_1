#include "ScreenManager.h"

namespace ScreenManagerNam
{
	
	static void Change();

	GameScreen Screens;

	int ScreenManager()
	{
		SetTargetFPS(60);
		curScreen.width = 600;
		curScreen.height = 800;

		InitWindow(curScreen.width, curScreen.height, "Pong");

		Menu::InitMenu();
		CreditsNmsp::InitCredits();
		Game::InitGame();

		//Gameplay::UpdateGame();


		while (!WindowShouldClose())
		{
			Change();
		}

		CloseWindow();
		Unloader::UnloadAll();
		return 0;
	} // SCreen MANAGER



  static void Change() 
  {
	switch (Screens)
	{

	  case Menu: {
			Menu::UpdateMenu();
	  } break;

	  
	  case Instructions: {
			Instructions::UpdateInstructions();
	  } break;

	  case Credits: {
		  CreditsNmsp::UpdateCredits();
	  } break;

	  case GameMode: {
		  GameMode::UpdateGameMode();
	  } break;

	  case Game: {
		  Game::UpdateGame();
	  } break;
	  
	}

  } // CHANGE END 
}