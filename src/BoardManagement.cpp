#include "BoardManagement.h"
#include<iostream>
using namespace std;



void BoardManagement::DrawHorizontalBorder()
{
    for(int i = 0; i < WIDTH + 2; i++)
        cout << "-";
       cout << endl;
}

char BoardManagement::RenderHelper(int x, int y, const std::list<Position>& snake, Position food)
{
    auto it = snake.begin();

    while (it != snake.end())
    {
        if (it->x == x && it->y == y)
        {
            return 'o';
        }

        ++it;
    }

    if (food.x == x && food.y == y)
    {
        return 'X';
    }

    return ' ';
}

void BoardManagement::RenderBoard(const list<Position>& snake, Position food, int score)
{
    DrawHorizontalBorder();

    for(int y = 0; y < HEIGHT; y++)
    {
        cout << "|";

        for(int x = 0; x < WIDTH; x++)
        {
            cout << RenderHelper(x, y, snake, food);
        }

        cout << "|" << endl;
    }

    DrawHorizontalBorder();

    cout << "Score: " << score << endl;
}

bool BoardManagement::BorderCollision(const std::list<Position>& snake)
{
    auto head = snake.begin();

    if (head->x < 0 || head->x >= WIDTH ||
        head->y < 0 || head->y >= HEIGHT)
    {
        return true;
    }

    return false;
}
