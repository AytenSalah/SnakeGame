#ifndef GAMEMANAGEMENT_H
#define GAMEMANAGEMENT_H

#include "Snake.h"
#include "Food.h"
#include "InputManagement.h"
#include "BoardManagement.h"

enum GameState {
    Running,
    GameOver,
    Paused
};

class GameManagement
{
private:
    Snake snake;
    Food food;
    InputManagement input;
    BoardManagement board;

    int score;
    GameState state;
    int currentDx, currentDy;

    int GAME_SPEED;
    void HandleInput();
    bool IsValidDirection(int newDx, int newDy);
    bool CheckFoodCollision();
    bool CheckWallCollision();
    bool CheckSelfCollision();

public:
    GameManagement();
    void RunGame();
    void GameOver();
    void UpdateScore();
};

#endif

