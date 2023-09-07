#include "Unloader.h"

namespace Unloader
{
	void UnloadMenu()
	{
		std::cout << "MENU UNLOADER EXECUTED" << '\n';
		Menu::UnloadMenu();
		Options::UnloadOptions();
		CreditsNmsp::UnloadCredits();
		Instructions::UnloadInstructions();
		std::cout << "MENU UNLOADER FINISHED" << '\n';
	}

	void UnloadGame()
	{
		std::cout << "GAME UNLOADER EXECUTED" << '\n';
		Game::UnloadGame();
		GameMode::UnloadGameMode();
		std::cout << "GAME UNLOADER FINISHED" << '\n';
	}

	void UnloadAll()
	{
		std::cout << "GLOBAL UNLOADER EXECUTED" << '\n';
		Game::UnloadGame();
		GameMode::UnloadGameMode();
		Menu::UnloadMenu();
		Options::UnloadOptions();
		CreditsNmsp::UnloadCredits();
		Instructions::UnloadInstructions();
		std::cout << "GLOBAL UNLOADER FINISHED" << '\n';
	}
}
