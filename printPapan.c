#include <stdio.h>

#include "global.h"

void printPapan33()
{
    printf("-----------------");
    for ( int i = 0; i < 3; i++ )
    {
        printf("%c %c %c\n", game[id].papan[i][0] , game[id].papan[i][1], game[id].papan[i][2]);
    }
    printf("-----------------");
}

void printPapan55()
{
    printf("-------------------------------");
    for ( int i = 0; i < 5; i++)
    {
        printf(" %c %c %c %c %c \n", game[id].papan[i][0],game[id].papan[i][1],game[id].papan[i][2],game[id].papan[i][3],game[id].papan[i][4]);
    }
    printf("-------------------------------");
}