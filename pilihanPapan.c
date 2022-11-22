#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "global.h"
#include "banner.h"
#include "pilihanPlayer.h"
#include "printPapan.h"

void pilihanPapan()
{
    
    system("cls");
    banner();
    printf("Pilih Jenis Papan\n");
    printf("1. Papan 3 x 3\n");
    printf("2. Papan 5 x 5\n");
    printf("3. Papan 7 x 7\n");
    printf("99. Kembali\n");
    printf("Masukan Pilihan Anda : ");
    scanf("%d", &pilihPapanLokal );
}

void cekPilihanPapan()
{
    switch (pilihPapanLokal)
    {
    case 1:
        printPapan33();
        break;
    
    default:
        printf("Belum ada\n");
        break;
    }
}