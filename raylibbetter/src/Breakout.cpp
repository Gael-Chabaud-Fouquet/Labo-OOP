#include "BreakoutEntrypoint.h"
#include <raylib.h>
#include <vector>
#include <algorithm>

// my color guide: https://c20.reclaimers.net/h1/engine/hard-coded-data/
//je m'arrete a "Multiplayer armor colors"

Ball::Ball(int StartX, int StartY) : PosX(StartX), PosY(StartY), Width(10), Height(10), VelocityX(100), VelocityY(100), BallColor(Color{255, 86, 185, 255}) {}

Brick::Brick(int StartX, int StartY, bool AliveOrNot) : PosX(StartX), PosY(StartY), Width(40), Height(20), LifeStatus(true), BrickColor(Color{112, 126, 113, 255}) {}
Brick::~Brick() {};

Paddle::Paddle(int StartX, int StartY) : PosX(StartX), PosY(StartY), Width(40), Height(10), Velocity(10), PaddleColor(Color{255, 127, 0, 255}) {}

std::vector<Brick> bricks;

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

void Ball::MoveBall(Paddle& paddle, std::vector<Brick> bricks){
    
    PosX += VelocityX * GetFrameTime();
    PosY += VelocityY * GetFrameTime();
    
    if (PosX < paddle.FindPaddlePosX() + paddle.FindPaddleWidth() && PosX + Width > paddle.FindPaddlePosX() && PosY < paddle.FindPaddlePosY() + paddle.FindPaddleHeight() && PosY + Height > paddle.FindPaddlePosY()) {
        VelocityY *= -1;
    }
    
    for (Brick& brick : bricks) {
        if (brick.CheckIfAlive() && PosX < brick.FindBrickPosX() + brick.FindBrickWidth() && PosX + Width > brick.FindBrickPosX() && PosY < brick.FindBrickPosY() + brick.FindBrickHeight() && PosY + Height > brick.FindBrickPosY()) {
            VelocityY *= -1;
            brick.SetLifeStatus(false);
        }
    }

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
    
    const int ScreenWidth = 410;
    const int ScreenHeight = 300;
    
    int FrameRate = 60;
    
    InitWindow(ScreenWidth, ScreenHeight, "Breakout");
    SetTargetFPS(FrameRate);
    
    Paddle paddle(185, 270);
    Ball ball(180, 260);
    
    //i searched online, it saved a 29 lines of this:
    //Brick brick"num""letter"(Posx, PosY, true);
    //and also this:
    //brick"num""letter".Draw();
    //i would have used brick1 to brick9, brick1a to brick9a and brick1b to brick9b
    //just look at an old commit to see what i mean. the message of this commit should be something like "Added more bricks and resized the screen to make it evenly"
    
    int AxisSpaceBetweenEachBricksX = 45;
    int AxisSpaceBetweenEachBricksY = 25;
    int TheOffsetFromTheScreenEdgeThatIsUsedToMakeTheBrickPlacementSymetrical = 5;
    int HowManyBrickAreInASingleRow = 9;
    
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < HowManyBrickAreInASingleRow; ++column) {
            int PositionOfBrickX = 5 + column * AxisSpaceBetweenEachBricksX;
            int PositionOfBrickY = TheOffsetFromTheScreenEdgeThatIsUsedToMakeTheBrickPlacementSymetrical + row * AxisSpaceBetweenEachBricksY;
            bool LifeStatus;
            bricks.push_back(Brick(PositionOfBrickX, PositionOfBrickY, LifeStatus));
        }
    }
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        paddle.Draw();
        paddle.MovePaddle();
        ball.Draw();
        ball.MoveBall(paddle, bricks);
        bricks.erase(remove_if(bricks.begin(), bricks.end(), [](Brick& brick) {return !brick.CheckIfAlive();}), bricks.end());      //je n'en peus plus. pourquoi les briques ne veulent pas disparaitre? selon mes recherches, ca devrait marcher
        //https://stackoverflow.com/questions/22729906/stdremove-if-not-working-properly selon ça, sa devrait marcher (je pense)
        for (Brick& brick : bricks) {
            brick.Draw();
        }
        ClearBackground(BackgroundColor);
        EndDrawing();
    }
    CloseWindow();
}