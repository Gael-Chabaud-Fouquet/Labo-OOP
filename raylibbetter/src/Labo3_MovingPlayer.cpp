#include "Labo3_MovingPlayerEntrypoint.h"
#include <raylib.h>

//color guide: https://c20.reclaimers.net/h1/engine/hard-coded-data/
//je m'arrete a "Multiplayer armor colors"<

MovingPlayer playerthatmoves;

void MovingPlayer::Draw() {
    int Width = 10;
    int Height = 10;
    int Velocity = 10;
    Color DVDColor = Color{255, 86, 185, 255};
    DrawRectangle(PosX, PosY, Width, Height, DVDColor);

    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        PosY -= Velocity;
        if (PosY < 10) {
            PosY = 300;
        }
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        PosX -= Velocity;
        if (PosX < 10) {
            PosX = 400;
        }
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        PosY += Velocity;
        if (PosY > 290) {
            PosY = 0;
        }
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        PosX += Velocity;
        if (PosX > 390) {
            PosX = 0;
        }
    }

}

int main(void){
    Color BackgroundColor = {255, 255, 255, 255};
    
    const int ScreenWidth = 400;
    const int ScreenHeight = 300;
    int FrameRate = 12;
    
    
    InitWindow(ScreenWidth, ScreenHeight, "Moving Player");
    SetTargetFPS(FrameRate);
    
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        playerthatmoves.Draw();
        ClearBackground(BackgroundColor);
        EndDrawing();
    }
    CloseWindow();
}