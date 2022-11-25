#include "header.h"

#include <stdio.h>
#include <windows.h>

void tampilanMenu()
{
    system("cls");
    banner1();
    koor(75,21);
    printf("MENU");
    koor(74,22);
    printf("Play Game");
    koor(74,23);
    printf("How to Play");
    koor(74,24);
    printf("About Us");
}

void tampilanPlayer()
{
    system("cls");
    banner1();
    koor(75,21);
    printf("CHOOSE PLAYER");
    koor(74,22);
    printf("1 Player");
    koor(74,23);
    printf("2 Player");
    koor(74,24);
    printf("Back");
}