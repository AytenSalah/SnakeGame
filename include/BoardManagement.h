#ifndef BOARDMANAGEMENT_H
#define BOARDMANAGEMENT_H
#include<list>
#include"Snake.h"
class BoardManagement
{
private:
    const int WIDTH = 20;
    const int HEIGHT = 10;
    void DrawHorizontalBorder();
    char RenderHelper(int x, int y, const std::list<Position>& snake, Position food);
public:
        void RenderBoard(const std::list<Position>& snake, Position food, int score);
        bool BorderCollision(const std::list<Position>& snake);
        int GetWidth() { return WIDTH; }
        int GetHeight() { return HEIGHT; }
};


#endif // BOARDMANAGEMENT_H
