#ifndef BOARDMANAGEMENT_H
#define BOARDMANAGEMENT_H
#include<list>
#include"Snake.h"
class BoardManagement
{
private:
    const int WIDTH = 20;
    const int HEIGHT = 10;
    void drawHorizontalBorder();
    char renderHelper(int x, int y, const std::list<Position>& snake, Position food);
public:
        void renderBoard(const std::list<Position>& snake, Position food, int score);
        bool borderCollision(const std::list<Position>& snake);
        int getWidth() { return WIDTH; }
        int getHeight() { return HEIGHT; }
};


#endif // BOARDMANAGEMENT_H
