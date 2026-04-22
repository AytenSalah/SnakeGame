#include "GameManagement.h"
#include<conio.h>
#include<iostream>
#include<windows.h>
using namespace std;

GameManagement::GameManagement()
{
    score = 0;
    state = Running;
    currentDx = 1;
    currentDy = 0;
}


bool GameManagement::IsValidDirection(int newDx, int newDy)
{
    if (currentDx + newDx == 0 && currentDy + newDy == 0) {
        return false;
    }
    return true;
}


void GameManagement::HandleInput()
{
    Direction dir = input.GetInput();


    if (dir.dx != 0 || dir.dy != 0) {

        if (IsValidDirection(dir.dx, dir.dy)) {
            currentDx = dir.dx;
            currentDy = dir.dy;
            snake.SetDirection(currentDx, currentDy);
        }

    }
}

bool GameManagement::CheckFoodCollision()
{
    Position head = snake.GetHeadPosition();
    Position foodPos = food.GetFoodPosition();

    return (head.x == foodPos.x && head.y == foodPos.y);
}


bool GameManagement::CheckSelfCollision()
{
    return snake.CheckSelfCollision();
}



void GameManagement::UpdateScore()
{
    score += 1;
}

void GameManagement::RunGame()
{
    currentDx = 1;
    currentDy = 0;
    snake.SetDirection(currentDx, currentDy);

    food.GenerateFood(snake.GetBodyPosition());

    score = 0;

    state = Running;

    cout << "Game Started" << endl;
    cout << "Press any key to start" << endl;
    _getch();

    while (state == Running) {

        HandleInput();

        bool WillEatFood = CheckFoodCollision();

        snake.SnakeMove(WillEatFood);

        if (WillEatFood) {
            UpdateScore();
            food.GenerateFood(snake.GetBodyPosition());
            if(GAME_SPEED > 50 )
            {GAME_SPEED = GAME_SPEED -25;}
        }

        if (CheckSelfCollision()) {
            GameOver();
            break;
        }

        system("cls");
        board.RenderBoard(snake.GetBodyPosition(), food.GetFoodPosition(), score);

        Sleep(GAME_SPEED);
    }
}

void GameManagement::GameOver()
{
    state = GameState::GameOver;

    system("cls");

    cout << "GAME OVER!"<<endl;
    cout << "Final Score: " << score << endl;
    cout << "Press R to Restart or Q to Quit: ";

    char choice = _getch();

    if (choice == 'R' || choice == 'r')
    {

        snake = Snake();
        score = 0;
        state = Running;
        currentDx = 1;
        currentDy = 0;

        food.GenerateFood(snake.GetBodyPosition());

        RunGame();
    }
    else if (choice == 'Q' || choice == 'q')
    {
        cout << "Thanks for playing"<<endl;
    }
}


