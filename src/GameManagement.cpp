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


bool GameManagement::isValidDirection(int newDx, int newDy)
{
    if (currentDx + newDx == 0 && currentDy + newDy == 0) {
        return false;
    }
    return true;
}


void GameManagement::handleInput()
{
    Direction dir = input.getInput();


    if (dir.dx != 0 || dir.dy != 0) {

        if (isValidDirection(dir.dx, dir.dy)) {
            currentDx = dir.dx;
            currentDy = dir.dy;
            snake.setDirection(currentDx, currentDy);
        }

    }
}

bool GameManagement::checkFoodCollision()
{
    Position head = snake.getHeadPosition();
    Position foodPos = food.getFoodPosition();

    return (head.x == foodPos.x && head.y == foodPos.y);
}



bool GameManagement::checkWallCollision()
{
    return board.borderCollision(snake.getBodyPosition());
}



bool GameManagement::checkSelfCollision()
{
    return snake.checkSelfCollision();
}



void GameManagement::updateScore()
{
    score += 1;
}

void GameManagement::runGame()
{
    currentDx = 1;
    currentDy = 0;
    snake.setDirection(currentDx, currentDy);

    food.generateFood(snake.getBodyPosition());

    score = 0;

    state = Running;

    cout << "Game Started" << endl;
    cout << "Press any key to start" << endl;
    _getch();

    while (state == Running) {

        handleInput();

        bool willEatFood = checkFoodCollision();

        snake.snakeMove(willEatFood);

        if (willEatFood) {
            updateScore();
            food.generateFood(snake.getBodyPosition());
        }

        if (checkWallCollision()) {
            gameOver();
            break;
        }

        if (checkSelfCollision()) {
            gameOver();
            break;
        }

        system("cls");
        board.renderBoard(snake.getBodyPosition(), food.getFoodPosition(), score);

        Sleep(GAME_SPEED);
    }
}

void GameManagement::gameOver()
{
    state = GameOver;

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

        food.generateFood(snake.getBodyPosition());

        runGame();
    }
    else if (choice == 'Q' || choice == 'q')
    {
        cout << "Thanks for playing"<<endl;
    }
}


