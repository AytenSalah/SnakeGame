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
        Position GetHeadPosition();
        std::list<Position> GetBodyPosition();
        void SetDirection(int newDx, int newDy);
        void SnakeMove(bool eaten);
        bool CheckSelfCollision();


};

#endif // SNAKE_H
