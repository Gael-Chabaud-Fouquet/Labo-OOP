#include "BreakoutEntrypoint.h"
#include <raylib.h>

// my color guide: https://c20.reclaimers.net/h1/engine/hard-coded-data/



// void Paddle::SetPositionPaddle(int PosX, int PosY){
//     PosX = 10;
//     PosY = 20;
// };
// void Paddle::SetSize(int Width, int Lenght){
//     Width = 10;
//     Lenght = 20;
// };


Ball ball;
Paddle paddle;
Brick brick;

void Paddle::Draw() {
    int Width = 40;
    int Height = 10;
    int PosX = 180;
    int PosY = 270;
    Color PaddleColor = Color{255, 127, 0, 255};
    DrawRectangle(PosX, PosY, Width, Height, PaddleColor);
}

void Ball::Draw() {
    int Width = 10;
    int Height = 10;
    int PosX = 195;
    int PosY = 250;
    Color BallColor = Color{255, 86, 185, 255};
    DrawRectangle(PosX, PosY, Width, Height, BallColor);
}

void Brick::Draw() {
    int Width = 40;
    int Height = 20;
    int PosX = 5;
    int PosY = 5;
    Color BrickColor = Color{112, 126, 113, 255};
    DrawRectangle(PosX, PosY, Width, Height, BrickColor);
}

// void Paddle::MovePaddle(int PosX){
//     int PosX = PosX;
//     GetKeyPressed();
// }


int main(void){
    Color BackgroundColor = {255, 255, 255, 255};

    const int ScreenWidth = 400;
    const int ScreenHeight = 300;
    int FrameRate = 12;

    InitWindow(ScreenWidth, ScreenHeight, "Breakout");
    SetTargetFPS(FrameRate);

    while (!WindowShouldClose()) {
        BeginDrawing();
        paddle.Draw();
        ball.Draw();
        brick.Draw();
        ClearBackground(BackgroundColor);
        EndDrawing();
    }
    CloseWindow();
}