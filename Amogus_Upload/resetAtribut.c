#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "header.h"

void resetAtributPlayGame(int *_pemenang, int *_giliran, char (*_papan)[7][7])
{
    *_pemenang = -1;
    *_giliran = 1;

    strcpy((*_papan)[0], "       ");
    strcpy((*_papan)[1], "       ");
    strcpy((*_papan)[2], "       ");
    strcpy((*_papan)[3], "       ");
    strcpy((*_papan)[4], "       ");
    strcpy((*_papan)[5], "       ");
    strcpy((*_papan)[6], "       ");
}