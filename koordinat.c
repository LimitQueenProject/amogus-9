#include <stdio.h>

#include "header.h"

void koor(int x, int y)
{
    HANDLE h;
    COORD c;
    c.X = x;
    c.Y = y;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h,c);
}

void printPanah( int _panx, int _pany )
{
    koor(_panx, _pany);setColor(3);printf("==>");setColor(7);koor(0,0);
}