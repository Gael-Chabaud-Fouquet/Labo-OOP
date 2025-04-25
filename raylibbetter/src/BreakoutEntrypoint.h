#pragma once
#include <raylib.h>

class Paddle
{
    private:
    int PosX;
    int PosY;
    int Lenght;
    int Width;

    public:
    //Paddle(int Height, int Lenght, int PosX, int PosY);
    void Draw();
    void SetSize(int Width, int Lenght);
    void MovePaddle(int PosX);
};

class Ball
{
    private:
    int PosX;
    int PosY;
    int Lenght;
    int Height;

    public:
    //Ball(int Height, int Lenght, int PosX, int PosY);
    void Draw();
    void SetPositionBall();
};

class Brick
{
    private:
    int PosX;
    int PosY;
    int Lenght;
    int Width;
    bool IsAlive;

    public:
    //Brick(int Height, int Lenght, int PosX, int PosY, bool IsAlive);
    //~Brick();
    void Draw();
    void CheckIfAlive(bool IsAlive);
};