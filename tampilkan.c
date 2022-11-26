#include "header.h"

#include <stdio.h>
#include <windows.h>

void tampilanMenu()
{
    system("cls");
    banner1();
    koor(87,21);
    printf("MENU");
    koor(85,22);
    printf("Play Game");
    koor(85,23);
    printf("How to Play");
    koor(85,24);
    printf("About Us");
    koor(85,25);
    printf("Exit");
}

void tampilanPlayer()
{
    system("cls");
    banner1();
    koor(87,21);
    printf("CHOOSE PLAYER");
    koor(85,22);
    printf("1 Player");
    koor(85,23);
    printf("2 Player");
    koor(85,24);
    printf("Back");
}

void tingkatKesulitan()
{
    system("cls");
    banner1();
    koor(87,21);
    printf("LEVEL");
    koor(85,22);
    printf("Easy");
    koor(85,23);
    printf("Medium");
    koor(85,24);
    printf("Hard");
    koor(85,25);
    printf("Back");
}

void tampilanBoard()
{
    system("cls");
    banner1();
    koor(87,21);
    printf("BOARD");
    koor(85,22);
    printf("3x3");
    koor(85,23);
    printf("5x5");
    koor(85,24);
    printf("7x7");
    koor(85,25);
    printf("Back");
}

void tampilanHowToPlay()
{
    printf("Ini How To Play\n");
}
void tampilanAboutUs()
{
    printf("Ini About Us\n");
}