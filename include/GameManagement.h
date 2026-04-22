#ifndef GAMEMANAGEMENT_H
#define GAMEMANAGEMENT_H

#include "Snake.h"
#include "Food.h"
#include "InputManagement.h"
#include "BoardManagement.h"

enum GameState {
    Running,
    GameOver
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

    const int GAME_SPEED = 200;

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

