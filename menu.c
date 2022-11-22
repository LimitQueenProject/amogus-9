#include <stdio.h>
#include <stdlib.h>

#include "banner.h"
#include "global.h"
#include "pilihanPlayer.h"


void menu()
{
    system("cls");
    banner();
    printf("Menu\n");
    printf("1. Bermain\n");
    printf("2. Cara Bermain\n");
    printf("3. Tentang Kami\n");
    printf("Masukan Pilihan Anda : ");
    scanf("%d", &pilihanMenu);
}

void cekMenu()
{
    switch (pilihanMenu)
    {
    case 1:
        pilihanPlayer( );
        cekPilihanPlayer();
        break;
    
    default:
        printf("Belum ada\n");
        break;
    }
}