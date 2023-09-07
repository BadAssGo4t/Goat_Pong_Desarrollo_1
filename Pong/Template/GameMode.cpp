#include "GameMode.h"

namespace GameMode
{
    Button::newButton sngPLayer;
    Button::newButton multPlayer;
    float multPlayerHeight = 0.0f;
    float sngPLayerHeight = 0.0f;
    //static Image game_back;
    //Texture2D gameBackground;

    bool thisScreen = false; 

    static Vector2 mousePoint;

    void InitGameMode() // Init
    {
        curScreen.width = 1200;
        curScreen.height = 900;

        InitWindow(curScreen.width, curScreen.height, "Pong");
        /*
                game_back = LoadImage("../Resources/Images/bk.png");
        ImageResize(&game_back, curScreen.width / 2, curScreen.height / 2);
        gameBackground = LoadTextureFromImage(game_back); // background

        */

        // playBttn Button
        sngPLayer.Texture = LoadTexture("../Resources/Button/play-Bttn.png");
        sngPLayer.FrameHeight = (float)sngPLayer.Texture.height / NUM_FRAMES;
        sngPLayer.SourceRec = { 0, 0, (float)sngPLayer.Texture.width, sngPLayer.FrameHeight };

        // Define button bounds on screen
        sngPLayer.Bounds = { curScreen.width / 2.0f - sngPLayer.Texture.width, curScreen.height / 2.0f - sngPLayer.Texture.height * 3 / NUM_FRAMES / 2.0f, (float)sngPLayer.Texture.width, sngPLayer.FrameHeight };
        sngPLayer.State = 0;  // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
        sngPLayer.Action = false;
        sngPLayerHeight = curScreen.height / 2.0f - sngPLayer.Texture.height * 3 / NUM_FRAMES / 2.0f;

        // playBttn Button
        multPlayer.Texture = LoadTexture("../Resources/Button/play-Bttn.png");
        multPlayer.FrameHeight = (float)multPlayer.Texture.height / NUM_FRAMES;
        multPlayer.SourceRec = { 0, 0, (float)multPlayer.Texture.width, multPlayer.FrameHeight };

        // Define button bounds on screen
        multPlayer.Bounds = { curScreen.width / 2.0f - multPlayer.Texture.width, curScreen.height / 2.0f + multPlayer.Texture.height * 2 / NUM_FRAMES / 2.0f, (float)multPlayer.Texture.width, multPlayer.FrameHeight };
        multPlayer.State = 0;  // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
        multPlayer.Action = false;
        multPlayerHeight = curScreen.height / 2.0f + multPlayer.Texture.height * 2 / NUM_FRAMES / 2.0f;


    }


    void UpdateGameMode()
    {

        mousePoint = GetMousePosition();

        DrawGameMode();

        if (CheckCollisionPointRec(mousePoint, sngPLayer.Bounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) sngPLayer.State = 2;
            else sngPLayer.State = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) sngPLayer.Action = true;
        }
        else sngPLayer.State = 0;

        if (CheckCollisionPointRec(mousePoint, multPlayer.Bounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) multPlayer.State = 2;
            else multPlayer.State = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) multPlayer.Action = true;
        }
        else multPlayer.State = 0;

        if (sngPLayer.Action)
        {
            std::cout << "boton instructionsBttn precionado" << "\n";
            sngPLayer.Action = false;
        }

        if (multPlayer.Action)
        {
            std::cout << "boton playBttn precionado" << "\n";
            multPlayer.Action = false;
        }

        sngPLayer.SourceRec.y = sngPLayer.State * sngPLayer.FrameHeight;
        multPlayer.SourceRec.y = multPlayer.State * multPlayer.FrameHeight;

    }

    void DrawGameMode() {

        BeginDrawing();

        ClearBackground(GRAY);

        DrawTextureRec(sngPLayer.Texture, sngPLayer.SourceRec, Vector2{ sngPLayer.Bounds.x, sngPLayer.Bounds.y }, WHITE);
        DrawTextureRec(multPlayer.Texture, multPlayer.SourceRec, Vector2{ multPlayer.Bounds.x, multPlayer.Bounds.y }, WHITE);

        EndDrawing();
    }

    void UnloadGameMode()
    {
        UnloadTexture(sngPLayer.Texture);
        UnloadTexture(multPlayer.Texture);
        std::cout << "GameMode Unloaded." << '\n';
    }
}
