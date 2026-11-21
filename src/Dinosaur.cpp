#include "Dinosaur.h"

void InitDinosaur(Dinosaur &dino, float startX, float groundY)
{
    dino.texture = LoadTexture("resources/dino.png");
    dino.groundY = groundY;
    dino.position.x = startX;
    dino.position.y = groundY - dino.texture.height;
    dino.velocity = 0;
    dino.isJumping = false;
}

void UpdateDinosaur(Dinosaur &dino)
{
    if (IsKeyPressed(KEY_SPACE) && !dino.isJumping)
   {
     dino.velocity = -600;
     dino.isJumping = true;
   }
    dino.velocity += 1500 * GetFrameTime();
    dino.position.y += dino.velocity * GetFrameTime();
    if (dino.position.y >= dino.groundY - dino.texture.height)
    {
      dino.position.y = dino.groundY - dino.texture.height;
      dino.velocity = 0;
      dino.isJumping = false;
   }
}

void DrawDinosaur(const Dinosaur &dino)
{
    DrawTexture(dino.texture, (int)dino.position.x, (int)dino.position.y, WHITE);
}

void UnloadDinosaur(Dinosaur &dino)
{
    UnloadTexture(dino.texture);
}

Rectangle GetDinosaurRect(const Dinosaur &dino)
{
    return { dino.position.x, dino.position.y,
             (float)dino.texture.width, (float)dino.texture.height };
}

void ResetDinosaur(Dinosaur &dino)
{
    dino.position.y = dino.groundY - dino.texture.height;
    dino.velocity = 0;
    dino.isJumping = false;
}
