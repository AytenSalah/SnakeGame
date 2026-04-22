#include "Food.h"
#include <cstdlib>
#include <ctime>


Food::Food()
{
    srand(time(0));
    food={0,0};
}

bool Food::IsOnSnake(int x, int y, const std::list<Position>& snake)
{
    auto it = snake.begin();

    while (it != snake.end())
    {
        if (it->x == x && it->y == y)
        {
            return true;
        }

        ++it;
    }

    return false;
}

void Food::GenerateFood(const std::list<Position>& snake) {
    int x, y;
    do {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
    } while (IsOnSnake(x, y, snake));

    food = {x, y};
}

Position Food::GetFoodPosition()
{
    return food;
}
