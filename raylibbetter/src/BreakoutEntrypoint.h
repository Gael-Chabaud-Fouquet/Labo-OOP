#pragma once
#include <raylib.h>

class Paddle
{
    private:
    int PosX;
    int PosY;
    int Width;
    int Height;
    int Velocity;
    Color PaddleColor;

    public:
    Paddle(int StartX, int StartY);
    void Draw();
    void MovePaddle();
};

class Brick
{
    private:
    int PosX;
    int PosY;
    int Width;
    int Height;
    Color BrickColor;
    bool IsAlive;

    public:
    Brick();
    Brick(int StartX, int StartY, bool AliveOrNot);
    ~Brick();
    void Draw();
    void CheckIfAlive(bool IsAlive);
};

class Ball
{
    private:
    int PosX;
    int PosY;
    int Width;
    int Height;
    int VelocityX;
    int VelocityY;
    Color BallColor;

    public:
    Ball(int StartX, int StartY);
    void MoveBall();
    void Draw();
    Brick GetBrick();
    Paddle GetPaddle();
};


// class GameObject {
// }