#pragma once
#include <raylib.h>
#include <vector>

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
    int FindPaddlePosX() const {return PosX;}
    int FindPaddlePosY() const {return PosY;}
    int FindPaddleHeight() const {return Height;}
    int FindPaddleWidth() const {return Width;}
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
    Color DeadBrickColor;
    bool LifeStatus;

    public:
    Brick();
    Brick(int StartX, int StartY, bool AliveOrNot);
    ~Brick();
    void Draw();
    int FindBrickPosX() const {return PosX;}
    int FindBrickPosY() const {return PosY;}
    int FindBrickHeight() const {return Height;}
    int FindBrickWidth() const {return Width;}
    //yes those two functions where added to kill/spawn the bricks at the start of the game
    bool CheckIfAlive() {return LifeStatus;}; //true is alive, false is dead (i think)
    void SetLifeStatus(bool AliveOrNot) {LifeStatus = AliveOrNot;}
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
    void MoveBall(Paddle& paddle, std::vector<Brick> bricks);
    void Draw();;
};