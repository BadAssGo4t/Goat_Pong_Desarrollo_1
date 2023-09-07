#include "Game.h"


namespace Game
{
    Button::newButton sngPLayer;
    Button::newButton multPlayer;

    static Image game_back;
    Texture2D gameBackground;



    static Vector2 mousePoint;

    void InitGame() // Init
    {
        curScreen.width = 1200;
        curScreen.height = 900;

        game_back = LoadImage("../Resources/Images/bk.png");
        ImageResize(&game_back, curScreen.width / 2, curScreen.height / 2);
        gameBackground = LoadTextureFromImage(game_back); // background

    }

    void UpdateGame()
    {
        DrawGame();

    }

    void DrawGame() {

        BeginDrawing();



        EndDrawing();
    }

    void UnloadGame()
    {
        std::cout << "Game Unloaded." << '\n';
    }
}
