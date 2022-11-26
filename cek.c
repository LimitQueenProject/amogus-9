#include "header.h"

#include <stdio.h>

int CekMenu( int _flagMenu )
{
    switch (_flagMenu)
    {
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    }
}

int CekPlayer( int _flagPlayer )
{
    switch (_flagPlayer)
    {
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 0:
        return 0;
        break;
    }
}

int CekLevel(int _flagLevel )
{
    switch (_flagLevel)
    {
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3 :
        return 3;
        break;
    case 0:
        return 0;
        break;
    }
}