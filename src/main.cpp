#include <raylib.h>
#include "game.h"
int main() 
{
    Color darkBlue={44,44,127,255};
    InitWindow(300,600,"raylib tetris");
    SetTargetFPS(60);
    Game game=Game();

    //block.Move(4,3);

    while(WindowShouldClose() ==false){
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}
