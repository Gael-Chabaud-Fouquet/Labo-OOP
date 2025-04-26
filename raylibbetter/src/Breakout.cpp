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

void Paddle::MovePaddle() {
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        PosX -= Velocity;
        if (PosX < 0) {
            PosX = 0;
        }
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        PosX += Velocity;
        if (PosX > 370) {
            PosX = 370;
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
bool CheckCollision(Ball rec1, Paddle rec2) {
    return CheckCollision(rec1, rec2);
}

int main(void){
    Color BackgroundColor = {255, 255, 255, 255};
    
    const int ScreenWidth = 410;
    const int ScreenHeight = 300;
    int FrameRate = 60;
    
    InitWindow(ScreenWidth, ScreenHeight, "Breakout");
    SetTargetFPS(FrameRate);
    
    Paddle paddle(185, 270);
    Ball ball(50, 50);
    //highest line
    Brick brick1(5, 5, true);
    Brick brick2(50, 5, true);
    Brick brick3(95, 5, true);
    Brick brick4(140, 5, true);
    Brick brick5(185, 5, true);
    Brick brick6(230, 5, true);
    Brick brick7(275, 5, true);
    Brick brick8(320, 5, true);
    Brick brick9(365, 5, true);
    //second highest
    Brick brick1a(5, 30, true);
    Brick brick2a(50, 30, true);
    Brick brick3a(95, 30, true);
    Brick brick4a(140, 30, true);
    Brick brick5a(185, 30, true);
    Brick brick6a(230, 30, true);
    Brick brick7a(275, 30, true);
    Brick brick8a(320, 30, true);
    Brick brick9a(365, 30, true);
    //anotherline
    Brick brick1b(5, 55, true);
    Brick brick2b(50, 55, true);
    Brick brick3b(95, 55, true);
    Brick brick4b(140, 55, true);
    Brick brick5b(185, 55, true);
    Brick brick6b(230, 55, true);
    Brick brick7b(275, 55, true);
    Brick brick8b(320, 55, true);
    Brick brick9b(365, 55, true);
    
    //bool CollisionBetweenBallAndPaddle = CheckCollision(ball, paddle)

    while (!WindowShouldClose()) {
        BeginDrawing();
        paddle.Draw();
        paddle.MovePaddle();
        ball.Draw();
        ball.MoveBall();
        //first line
        brick1.Draw();
        brick2.Draw();
        brick3.Draw();
        brick4.Draw();
        brick5.Draw();
        brick6.Draw();
        brick7.Draw();
        brick8.Draw();
        brick9.Draw();
        //second line
        brick1a.Draw();
        brick2a.Draw();
        brick3a.Draw();
        brick4a.Draw();
        brick5a.Draw();
        brick6a.Draw();
        brick7a.Draw();
        brick8a.Draw();
        brick9a.Draw();
        //third line
        brick1b.Draw();
        brick2b.Draw();
        brick3b.Draw();
        brick4b.Draw();
        brick5b.Draw();
        brick6b.Draw();
        brick7b.Draw();
        brick8b.Draw();
        brick9b.Draw();

        
        ClearBackground(BackgroundColor);
        EndDrawing();
    }
    CloseWindow();
}