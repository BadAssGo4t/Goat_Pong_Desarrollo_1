#include "Credits.h"

namespace CreditsNmsp
{
    Button::newButton returnBttn;

    Texture2D backgroundCred;
    Texture2D logoTex;

    static Vector2 mousePoint; 
    static Image creditsImg;
    static Image logo;

    int amountOfCredits = 0;


    void InitCredits() // Init
    {
        amountOfCredits = 3;
        curScreen.width = 600;
        curScreen.height = 800;

        creditsImg = LoadImage("../Resources/Credits/CreditsGray.png");
        ImageResize(&creditsImg, curScreen.width, curScreen.height);

        logo = LoadImage("../Resources/Images/SymBlack.png");
        ImageResize(&logo, 50, 50);

        backgroundCred = LoadTextureFromImage(creditsImg);

        logoTex = LoadTextureFromImage(logo);

        returnBttn.Texture = LoadTexture("../Resources/Button/Return.png");
        returnBttn.FrameHeight = (float)returnBttn.Texture.height / NUM_FRAMES;
        returnBttn.SourceRec = { 0, 0, (float)returnBttn.Texture.width, returnBttn.FrameHeight };

        // Define button bounds on screen
        returnBttn.Bounds = { curScreen.width - returnBttn.Texture.width * 3 / 2.0f, curScreen.height - returnBttn.Texture.height * 3 / NUM_FRAMES / 2.0f, (float)returnBttn.Texture.width, returnBttn.FrameHeight };
        returnBttn.State = 0;  // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
        returnBttn.Action = false;

    }

    void UpdateCredits()
    {
        DrawCredits();

        mousePoint = GetMousePosition();

        if (CheckCollisionPointRec(mousePoint, returnBttn.Bounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) returnBttn.State = 2;
            else returnBttn.State = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) returnBttn.Action = true;
        }
        else returnBttn.State = 0;

        if (returnBttn.Action)
        {
            std::cout << "boton Credits precionado" << "\n";
            returnBttn.Action = false;
            ScreenManagerNam::Screens = ScreenManagerNam::Menu;
        }
    }

    void DrawCredits() {
        BeginDrawing();

        ClearBackground(GetColor(0x052c46ff));

        DrawTexture(backgroundCred, 0, 0, WHITE);
        DrawTexture(logoTex, 0 + logoTex.width, curScreen.height - logoTex.height*2, WHITE);

        DrawTextureRec(returnBttn.Texture, returnBttn.SourceRec, Vector2{ returnBttn.Bounds.x, returnBttn.Bounds.y }, WHITE);

        EndDrawing();
    }

    void UnloadCredits()
    {
        UnloadTexture(returnBttn.Texture);
        UnloadTexture(backgroundCred);
        UnloadImage(creditsImg);
        std::cout << "Credits Unloaded." << '\n';
    }
}
