#ifndef FOOD_H
#define FOOD_H
#include"Snake.h"
#include <list>

class Food
{
private:
    Position food;
    const int WIDTH = 20;
    const int HEIGHT = 10;
    bool isOnSnake(int x, int y, const std::list<Position>& snake);

public:
    Food();
    void generateFood(const std::list<Position>& snake);
    Position getFoodPosition();
};

#endif

