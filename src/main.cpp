#include <raylib.h>
#include "game.h"

double lastUpdateTime=0;

bool eventTrigger(double interval){
    double currentTime=GetTime();
    if(currentTime-lastUpdateTime>= interval){
        lastUpdateTime=currentTime;
        return true;
    }
    return false;
}
int main() 
{
    Color darkBlue={44,44,127,255};
    InitWindow(500,620,"raylib tetris");
    SetTargetFPS(60);
    Game game=Game();

    //block.Move(4,3);

    while(WindowShouldClose() ==false){
        game.handleInput();
        if(eventTrigger(0.2)){
            game.moveBlockDown();
        }
        //game.moveBlockDown();
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}
