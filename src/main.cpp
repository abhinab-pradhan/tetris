#include <raylib.h>
#include "game.h"
#include "colors.h"

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

    Font font = LoadFontEx("Font/The Ink Prophecy.ttf",64,0,0);
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
        DrawTextEx(font,"Score",{350,15}, 24,2,WHITE);
        DrawRectangleRounded({320,55,170,60},0.3,6)
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}
