#include <stdio.h>
#include <windows.h>

#include "header.h"

void PilihIndex(char _mark[])
{
    printf("%s, Masukan Pilihan Anda : ");
    scanf(" %s", _mark);
}










void playGame (int _flagGame)
{
    system("cls");
    if ( _flagGame == 111 )    
        printf("ini main 111\n");
    else if ( _flagGame == 112 )    
        printf("ini main 112\n");
}