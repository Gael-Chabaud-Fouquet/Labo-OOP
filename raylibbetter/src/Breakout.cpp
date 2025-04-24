#include "BreakoutEntrypoint.h"
#include <raylib.h>

// my color guide: https://c20.reclaimers.net/h1/engine/hard-coded-data/



void Paddle::Draw() {
    int Width = 10;
    int Lenght = 20;
    int PosX = 10;
    int PosY = 20;
    Color PaddleColor = Color{255, 127, 0, 255};
    DrawRectangle(Width, Lenght, PosX, PosY, PaddleColor);
}



int main(void){
    Color BackgroundColor = {0, 0, 0, 255};

    const int ScreenWidth = 400;
    const int ScreenHeight = 300;
    int FrameRate = 12;

    InitWindow(ScreenWidth, ScreenHeight, "Breakout");
    SetTargetFPS(FrameRate);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BackgroundColor);
        EndDrawing();
    }
    CloseWindow();
}