#include "BreakoutEntrypoint.h"
#include <raylib.h>

// my color guide: https://c20.reclaimers.net/h1/engine/hard-coded-data/
//je m'arrete a "Multiplayer armor colors"

Ball::Ball(int StartX, int StartY) : PosX(StartX), PosY(StartY), Width(10), Height(10), VelocityX(200), VelocityY(100), BallColor(Color{255, 86, 185, 255}) {}
Brick::Brick(int StartX, int StartY, bool AliveOrNot) : PosX(StartX), PosY(StartY), Width(40), Height(20), BrickColor(Color{112, 126, 113, 255}) {}
Paddle::Paddle(int StartX, int StartY) : PosX(StartX), PosY(StartY), Width(40), Height(10), Velocity(10), PaddleColor(Color{255, 127, 0, 255}) {}
Brick::~Brick() {};

void Paddle::Draw() {
    DrawRectangle(PosX, PosY, Width, Height, PaddleColor);
    
}

Brick Ball::GetBrick() {
    return Brick{PosX, PosY, true};
}

Paddle Ball::GetPaddle() {
    return Paddle{PosX, PosY};
}

void Paddle::MovePaddle() {
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
    DrawRectangle(PosX, PosY, Width, Height, BallColor);
}

void Ball::MoveBall(){
    PosX += VelocityX * GetFrameTime();
    PosY += VelocityY * GetFrameTime();
    
    if (PosY + Height > GetScreenHeight() || PosY < 0) {
        VelocityY *= -1;
    }
    if (PosX + Width > GetScreenWidth() || PosX < 0) {
        VelocityX *= -1;
    }
}

void Brick::Draw() {
    DrawRectangle(PosX, PosY, Width, Height, BrickColor);
}

int main(void){
    Color BackgroundColor = {255, 255, 255, 255};
    
    const int ScreenWidth = 400;
    const int ScreenHeight = 300;
    int FrameRate = 60;
    
    InitWindow(ScreenWidth, ScreenHeight, "Breakout");
    SetTargetFPS(FrameRate);
    
    Paddle paddle(50, 270);
    Ball ball(50, 50);
    Brick brick(5, 5, true);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        paddle.Draw();
        paddle.MovePaddle();
        ball.Draw();
        ball.MoveBall();
        brick.Draw();
        ClearBackground(BackgroundColor);
        EndDrawing();
    }
    CloseWindow();
}