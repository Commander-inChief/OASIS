#include "Game.h"

bool checkCollision(const Dinosaur& dino, const Obstacle obstacles[], int obstacleCount)
{
	Rectangle dinoRect = GetDinosaurRect(dino);
	for (int i = 0; i < obstacleCount; ++i)
	{
		if (obstacles[i].active)
		{
			Rectangle obstacleRect = GetObstacleRect(obstacles[i]);
			if (CheckCollisionRecs(dinoRect, obstacleRect)) {
				return true; 
			}
		}
		return false; 
	}
}

// Note: This code will only compile when Othman has added the active field and GetObstacleRect() function to Obstacle.h
// I only used these parameters pending Othman's changes to the Obstacle struct. 
// Once he has added the active field and GetObstacleRect() function, this code will compile successfully.
// But if he uses a different name for the active field or GetObstacleRect() function, I will need to change the code accordingly.



void updateGame(GameState& state, const Dinosaur& dino, const Obstacle obstacles[], int obstacleCount)
{
	if (state == GameState::PLAYING) 
	{
		if (checkCollision(dino, obstacles, obstacleCount))
		{
			state = GameState::GAME_OVER; 
		}
	}
}

void resetGame(GameState& state, Dinosaur& dino, Obstacle obstacles[], int obstacleCount)
{
	ResetDinosaur(dino); 

	state = GameState::PLAYING; 
}

