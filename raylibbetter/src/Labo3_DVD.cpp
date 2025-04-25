#include "Labo3_DVDEntrypoint.h"
#include <raylib.h>

//color guide: https://c20.reclaimers.net/h1/engine/hard-coded-data/
//je m'arrete a "Multiplayer armor colors"

DVDCube dvd;

void DVDCube::Draw(){
    int PosX;
    int PosY;
    int Width = 10;
    int Height = 10;
    Color DVDColor = Color{255, 86, 185, 255};
    DrawRectangle(PosX, PosY, Width, Height, DVDColor);
}
void DVDCube::Move(){
    int VelocityX = 30;
    int VelocityY = 10;
    
    
    PosX +=VelocityX;// * GetFrameTime();
    PosY += VelocityY;// * GetFrameTime();



if (PosY > 300 || PosY < 0) {
    VelocityY *= -1;
}
if (PosX > 400 || PosX < 0) {
    VelocityX *= -1;
}
}

int main(void){
    Color BackgroundColor = {255, 255, 255, 255};

    const int ScreenWidth = 400;
    const int ScreenHeight = 300;
    int FrameRate = 100;

    InitWindow(ScreenWidth, ScreenHeight, "DVD Cube");
    SetTargetFPS(FrameRate);

    while (!WindowShouldClose()) {
        BeginDrawing();
        dvd.Move();
        dvd.Draw();
        ClearBackground(BackgroundColor);
        EndDrawing();
    }
    CloseWindow();
}