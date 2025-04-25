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
    void MovePaddle();
};

class Ball
{
    private:
    int PosX;
    int PosY;
    int Lenght;
    int Height;

    public:
    void Draw();
    void MoveBall();
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
    // Brick(int PosX, int PosY, bool IsAlive);
    // ~Brick();
    void Draw();
    void CheckIfAlive(bool IsAlive);
};

// class GameObject {
// }