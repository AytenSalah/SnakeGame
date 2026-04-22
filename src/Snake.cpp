#include"Snake.h"

Snake::Snake()
{
    body.push_back({10,5});
    body.push_back({10,6});
    body.push_back({10,7});
    dx=1;
    dy=0;
}

Position Snake::getHeadPosition()
{
    return body.front();
}

std::list<Position> Snake::getBodyPosition() {
    return body;
}

void Snake::setDirection(int newDx, int newDy) {
    dx = newDx;
    dy = newDy;
}

void Snake::snakeMove(bool eaten)
{
        Position head = body.front();
        Position newHead;
        newHead.x=head.x+dx;
        newHead.y=head.y+dy;
        body.insert(body.begin(),newHead);

        if(!eaten)
        {
           body.pop_back();
        }
}

bool Snake::checkSelfCollision()
{
    Position head = body.front();

    auto it = body.begin();
    ++it; 

    while (it != body.end())
    {
        if (head.x == it->x && head.y == it->y)
            return true;

        ++it;
    }

    return false;
}
