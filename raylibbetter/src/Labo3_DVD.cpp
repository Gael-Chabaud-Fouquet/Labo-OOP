#include "Labo3_DVDEntrypoint.h"
#include <raylib.h>

DVDCube::DVDCube(int startX, int startY)
    : PosX(startX), PosY(startY), Width(25), Height(25), VelocityX(400), VelocityY(150), DVDColor(Color{255, 86, 185, 255}) {}

void DVDCube::Draw() {
    DrawRectangle(PosX, PosY, Width, Height, DVDColor);
}

void DVDCube::Move() {
    PosX += VelocityX * GetFrameTime();
    PosY += VelocityY * GetFrameTime();

    if (PosY + Height > GetScreenHeight() || PosY < 0) {
        VelocityY *= -1;
    }
    if (PosX + Width > GetScreenWidth() || PosX < 0) {
        VelocityX *= -1;
    }
}

int main(void) {
    Color BackgroundColor = {255, 255, 255, 255};

    const int ScreenWidth = 1000;
    const int ScreenHeight = 600;
    int FrameRate = 120;

    InitWindow(ScreenWidth, ScreenHeight, "DVD Cube");
    SetTargetFPS(FrameRate);

    DVDCube dvd(50, 50);

    while (!WindowShouldClose()) {
        BeginDrawing();
        dvd.Move();
        dvd.Draw();
        ClearBackground(BackgroundColor);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}