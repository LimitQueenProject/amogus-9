#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "banner.h"
#include "global.h"
#include "menu.h"
#include "pilihan.h"
#include "pilihanPlayer.h"
#include "pilihanPapan.h"

void pilihanPapan()
{
    
    system("cls");
    banner();
    printf("Pilih Jenis Papan\n");
    printf("1. Papan 3 x 3\n");
    printf("2. Papan 5 x 5\n");
    printf("3. Papan 7 x 7\n");
    printf("99. Kembali\n");
    pilihan(&pilihPapanGlobal);
    // printf("Masukan Pilihan Anda : ");
    // scanf("%d", &pilihPapanGlobal );
}

void cekPilihanPapan()
{
    switch (pilihPapanGlobal)
    {
    case 1:
        game[id].papan1 = true;
        break;
    case 2:
        game[id].papan2 = true;
        break;
    case 3:
        game[id].papan3 = true;
        break;
    case 99:
        bermain();
        break;
    default:
        game[id].papan1 = true;
        break;
    }
}