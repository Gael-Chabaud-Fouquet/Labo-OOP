#include <raylib.h>
#include "Labo3_MaisonEntrypoint.h"

//color guide: https://c20.reclaimers.net/h1/engine/hard-coded-data/
//je m'arrete a "Multiplayer armor colors"


Wall wall;
Sun sun;
Sky sky;
Ground ground;
Roof roof;
Walkway walkway;
Door door;


void Roof::Draw() { //bon bah toit rectangle, flemme de chercher les vecteurs pour un triangle
    int Width = 250;
    int Height = 10;
    int PosX = 160;
    int PosY = 270;
    Color RoofColor = Color{157, 11, 14, 255}; //maroon
    DrawRectangle(PosX, PosY, Width, Height, RoofColor);
}

void Walkway::Draw() {
    int Width = 40;
    int Height = 200;
    int PosX = 200;
    int PosY = 400;
    Color WalkwayColor = Color{112, 126, 113, 255}; //gray
    DrawRectangle(PosX, PosY, Width, Height, WalkwayColor);
}

void Door::Draw() {
    int Width = 30;
    int Height = 50;
    int PosX = 205;
    int PosY = 350;
    Color DoorColor = Color{30, 204, 145, 255}; //teal
    DrawRectangle(PosX, PosY, Width, Height, DoorColor);
}

void Wall::Draw() {
    int Width = 230;
    int Height = 120;
    int PosX = 170;
    int PosY = 280;
    Color WallColor = Color{198, 156, 108, 255}; //tan
    DrawRectangle(PosX, PosY, Width, Height, WallColor);
}

void Sun::Draw() {
    int Rayon = 60;
    int PosX = 770;
    int PosY = 30;
    Color SunColor = Color{255, 255, 1, 255}; //yellow
    DrawCircle(PosX, PosY, Rayon, SunColor);
}

void Sky::Draw() {
    int Width = 800;
    int Height = 400;
    int PosX = 0;
    int PosY = 0;
    Color SkyColor = Color{100, 147, 237, 255}; //cobalt
    DrawRectangle(PosX, PosY, Width, Height, SkyColor);
}

void Ground::Draw() {
    int Width = 800;
    int Height = 200;
    int PosX = 0;
    int PosY = 400;
    Color GroundColor = Color{0, 100, 1, 255}; //sage
    DrawRectangle(PosX, PosY, Width, Height, GroundColor);
}


int main(void){
    Color BackgroundColor = {255, 255, 255, 255};

    const int ScreenWidth = 800;
    const int ScreenHeight = 600;
    int FrameRate = 12;

    InitWindow(ScreenWidth, ScreenHeight, "Maison");
    SetTargetFPS(FrameRate);

    while (!WindowShouldClose()) {
        BeginDrawing();
        sky.Draw();
        ground.Draw();
        sun.Draw();
        wall.Draw();
        door.Draw();
        walkway.Draw();
        roof.Draw();

        ClearBackground(BackgroundColor);
        EndDrawing();
    }
    CloseWindow();
}