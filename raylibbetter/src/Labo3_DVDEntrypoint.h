#pragma once
#include <raylib.h>

class DVDCube
{
    private:
    int PosX;
    int PosY;
    int Lenght;
    int Width;

    public:
    void Draw();
    void Move();
};