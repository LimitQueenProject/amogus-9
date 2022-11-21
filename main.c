#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "global.h"
#include "Inisialisasi.h"
#include "inputNamaPlayer.h"
void printInisialisasi();
int main()
{
    
    Inisialisasi(id, giliran);
    inputNamaPlayer( 1, id);
    inputNamaPlayer( 2, id);
    printInisialisasi();

    return 0;
}




void printInisialisasi()
{
    printf("%d\n", game[id].game_id);
    printf("%d\n", game[id].score1);
    printf("%d\n", game[id].score2);
    printf("%s\n", game[id].papan);
    printf("%s\n", game[id].player1);
    printf("%s\n", game[id].player2);
    printf("%d\n", game[id].giliran);
    printf("%s\n", game[id].inisialisasi ? "true" : "false");
}