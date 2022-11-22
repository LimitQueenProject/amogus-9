#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "banner.h"
#include "menu.h"
#include "playGame.h"

int main()
{
    menu( &pilihanMenu );
    cekMenu();
    
    printf("Jenis Player : %d\n", game[id].jenisPlayer);
    printf("Jenis Papan  : %d\n", game[id].jenisPapan);

    cekPlayGame();

    return 0;
}