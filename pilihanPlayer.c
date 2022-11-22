#include <stdio.h>
#include <stdlib.h>

#include "banner.h"
#include "global.h"
#include "menu.h"
#include "printPapan.h"

void pilihanPlayer( )
{
    system("cls");
    banner();
    printf("Pilih Jenis Player\n");
    printf("1. 1 Player (P vs Komputer)\n");
    printf("2. 2 Player (P vs P)\n");
    printf("99. Kembali\n");
    printf("Masukan Pilihan Anda : ");
    scanf("%d", &game[id].jenisPlayer );
}
void cekPilihanPlayer()
{
    switch (game[id].jenisPlayer)
    {
    // case 1:
    //     pilihanPlayer( );
    //     cekPilihanPlayer();
    //     break;
    case 2:
        pilihanPapan();
        break;
    case 99:
        menu();
        cekMenu();
        break;
    default:
        printf("Belum ada\n");
        printf("Silahkan pilih yang lain\n");
        pilihanPlayer();
        cekPilihanPlayer();
        break;
    }    
}