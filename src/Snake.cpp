#include"Snake.h"

Snake::Snake()
{
    body.push_back({10,5});
    body.push_back({10,6});
    body.push_back({10,7});
    dx=1;
    dy=0;
}

Position Snake::GetHeadPosition()
{
    return body.front();
}

std::list<Position> Snake::GetBodyPosition() {
    return body;
}

void Snake::SetDirection(int newDx, int newDy) {
    dx = newDx;
    dy = newDy;
}

void Snake::SnakeMove(bool eaten)
{
        Position head = body.front();
        Position newHead;
        newHead.x=head.x+dx;
        newHead.y=head.y+dy;
    if (newHead.x < 0)
        newHead.x = 19;   

    if (newHead.x >= 20)
        newHead.x = 0;
    if (newHead.y < 0)
        newHead.y = 9;   

    if (newHead.y >= 10)
        newHead.y = 0;
        body.insert(body.begin(),newHead);

        if(!eaten)
        {
           body.pop_back();
        }
}

