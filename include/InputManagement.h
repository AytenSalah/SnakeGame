#ifndef INPUTMANAGEMENT_H
#define INPUTMANAGEMENT_H

struct Direction
{
    int dx;
    int dy;
};

class InputManagement
{
public:
        Direction GetInput();
        char GetKey();


};

#endif // INPUTMANAGEMENT_H
