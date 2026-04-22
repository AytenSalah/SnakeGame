#ifndef SNAKE_H
#define SNAKE_H
#include<list>

struct Position
{
  int x;
  int y;
};

class Snake
{
private:
    int dx,dy;
    std::list<Position> body;
public:
        Snake();
        Position getHeadPosition();
        std::list<Position> getBodyPosition();
        void setDirection(int newDx, int newDy);
        void snakeMove(bool eaten);
        bool checkSelfCollision();


};

#endif // SNAKE_H
