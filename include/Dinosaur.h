#pragma once
#include "raylib.h"

struct Dinosaur {
    Vector2 position;    // x and y on the screen
    float velocity;      // up/down speed
    Texture2D texture;   // dino image
    bool isJumping;      // true when in the air
    float groundY;       // where the ground is
};

void InitDinosaur(Dinosaur &dino, float startX, float groundY);
void UpdateDinosaur(Dinosaur &dino);
void DrawDinosaur(const Dinosaur &dino);
void UnloadDinosaur(Dinosaur &dino);
Rectangle GetDinosaurRect(const Dinosaur &dino);
