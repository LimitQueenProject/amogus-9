#include <stdio.h>

#include "global.h"
#include "playGame.h"
#include "printPapan.h"

void cekPlayGame()
{   
    if ( game[id].jenisPlayer == 1 && game[id].jenisPapan == 1 )
    {
        playGame1_1();
    }
    else if ( game[id].jenisPlayer == 1 && game[id].jenisPapan == 2 )
    {
        playGame1_2();
    }
    else if ( game[id].jenisPlayer == 1 && game[id].jenisPapan == 3 )
    {
        playGame1_3();
    }
    else if ( game[id].jenisPlayer == 2 && game[id].jenisPapan == 1 )
    {
        playGame2_1();
    }
    else if ( game[id].jenisPlayer == 2 && game[id].jenisPapan == 2 )
    {
        playGame2_2();
    }
    else if ( game[id].jenisPlayer == 2 && game[id].jenisPapan == 3 )
    {
        playGame2_3();
    }
}

void playGame1_1()
{
    printPapan33();
}

void playGame1_2()
{
    printf("Belum Ada Game Nya\n");
}

void playGame1_3()
{
    printf("Belum Ada Game Nya\n");
}

void playGame2_1()
{
    printPapan33();
}

void playGame2_2()
{
    printf("Belum Ada Game Nya\n");
}

void playGame2_3()
{
    printf("Belum Ada Game Nya\n");
}