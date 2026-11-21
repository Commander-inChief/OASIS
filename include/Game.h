#pragma once
#include "Dinosaur.h"
#include "Obstacle.h"

enum class GameState { // The different states of the game
	MENU,
	PLAYING,
	GAME_OVER
};

bool checkCollision(const Dinosaur& dino, const Obstacle obstacles[], int obstacleCount); 
void updateGame(GameState& state, const Dinosaur& dino, const Obstacle obstacles[], int obstacleCount); 
void resetGame(GameState& state, Dinosaur& dino, Obstacle obstacles[], int obstacleCount); 