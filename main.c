#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "banner.h"
#include "menu.h"
#include "pilihanPlayer.h"

int main()
{
    menu( &pilihanMenu );
    cekMenu();
    printf("Jenis Player : %d\n", game[id].jenisPlayer);
    printf("Kondisi Papan 1 : %d\n", game[id].papan1);
    printf("Kondisi Papan 2 : %d\n", game[id].papan2);
    printf("Kondisi Papan 3 : %d\n", game[id].papan3);
    return 0;
}