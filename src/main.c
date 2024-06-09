#include <raylib.h>
#include "game.h"
#include "constants.h"
#include "utils.h"
static Vector2 windowPos;



int main(void)
{

    Image wicon = LoadImage("../res/icon.png");
    
    // Initialization

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Planet Guard");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    InitGame();
    SetWindowIcon(wicon);
    UnloadImage(wicon);
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        
        // Draw
        BeginDrawing();

        ClearBackground(BLACK);

        UpdateGame();
        DrawGame();

        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}
