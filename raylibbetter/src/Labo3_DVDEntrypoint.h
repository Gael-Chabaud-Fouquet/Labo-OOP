#pragma once
#include <raylib.h>

// class DVDCube
// {
//     private:
//     int PosX;
//     int PosY;
//     int Lenght;
//     int Width;

//     public:
//     DVDCube(int startX, int startY) {int PosX(startX); int PosY(startY);}
//     void Draw();
//     void Move();
// };

class DVDCube {
    private:
        int PosX;
        int PosY;
        int Width;
        int Height;
        int VelocityX;
        int VelocityY;
        Color DVDColor;
        public:
        DVDCube(int StartX, int StartY);
        void Move();
        void Draw();
    };