#include "BreakoutEntrypoint.h"
#include <raylib.h>

// my color guide: https://c20.reclaimers.net/h1/engine/hard-coded-data/
//je m'arrete a "Multiplayer armor colors"

Ball ball;
Paddle paddle;
Brick brick;

void Paddle::Draw() {
    int Width = 40;
    int Height = 10;
    int PosY = 270;
    Color PaddleColor = Color{255, 127, 0, 255};
    DrawRectangle(PosX, PosY, Width, Height, PaddleColor);
    
}

void Paddle::MovePaddle() {
    int Velocity = 10;
    int Width = 40;
    int Height = 10;
    int PosY = 270;
    Color PaddleColor = Color{255, 127, 0, 255};
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        PosX -= Velocity;
        if (PosX < 0) {
            PosX = 0;
        }
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        PosX += Velocity;
        if (PosX > 360) {
            PosX = 360;
        }
    }

}

void Ball::Draw() {
    int Width = 10;
    int Height = 10;
    int PosX = 195;
    int PosY = 250;
    Color BallColor = Color{255, 86, 185, 255};
    DrawRectangle(PosX, PosY, Width, Height, BallColor);
}

// void Ball::MoveBall(){
//}

// Brick::Brick(int PosX, int PosY, bool IsAlive){
//     PosX += 50;
//     PosY += 30;
//     IsAlive = true;
// }

void Brick::Draw() {
    int Width = 40;
    int Height = 20;
    int PosX = 5;
    int PosY = 5;
    Color BrickColor = Color{112, 126, 113, 255};
    DrawRectangle(PosX, PosY, Width, Height, BrickColor);
}

int main(void){
    Color BackgroundColor = {255, 255, 255, 255};

    const int ScreenWidth = 400;
    const int ScreenHeight = 300;
    int FrameRate = 12;

    InitWindow(ScreenWidth, ScreenHeight, "Breakout");
    SetTargetFPS(FrameRate);
    while (!WindowShouldClose()) {
        paddle.MovePaddle();
        BeginDrawing();
        paddle.Draw();
        ball.Draw();
        brick.Draw();
        ClearBackground(BackgroundColor);
        EndDrawing();
    }
    CloseWindow();
}