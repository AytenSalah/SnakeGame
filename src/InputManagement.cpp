#include "InputManagement.h"
#include <conio.h>

Direction InputManagement::getInput()
{
    if(_kbhit())
    {
        char key = _getch();
        switch(key)
        {
        case'A':
        case'a':
            return{-1,0};
        case'S':
        case's':
            return{0,1};
        case'D':
        case'd':
            return{1,0};
        case'W':
        case'w':
            return{0,-1};
        }
    }
    return{0,0};
}
