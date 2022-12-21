#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

#include "header.h"

void playGame(Game *game, int *_pemenang)
{
    Game tempgame;
    tempgame = *game;
    int pemenang = *_pemenang;

    Index indexPlayGame;

    bool valid;

    // 1. BERSIHKAN LAYAR
    system("cls");

    do
    {

        // // 2. TAMPILKAN DASHBOARD KE LAYAR
        dashboard(tempgame.pemain1.namaPlayer, tempgame.pemain2.namaPlayer, tempgame.pilihPertama, tempgame.giliran, tempgame.pemain1.score, tempgame.pemain2.score, tempgame.id_game);

        // // 3. TAMPILKAN PAPAN {JENIS PAPAN} KE LAYAR
        printPapan(tempgame.papan.jenisPapan, tempgame.papan.kotak);

        // // 4. PILIH INDEX PAPAN
        valid=false;
        pilihIndexPapan(tempgame.jenisPermainanPlayer, tempgame.papan.jenisPapan, tempgame.giliran, tempgame.pilihPertama, tempgame.papan.kotak, &indexPlayGame, &valid);

        // // 5. MARK INDEX YANG DI 
        if(valid==true)
        markIndex(tempgame.giliran, tempgame.pilihPertama, &tempgame.papan.kotak, indexPlayGame.baris, indexPlayGame.kolom);

        // // 6. CEK PEMENANG

        pemenang = cekPemenang(tempgame.papan.jenisPapan, tempgame.papan.kotak);

        // // 7. TAMBAHKAN SCORE PEMENANG JIKA ADA
        if ( pemenang == 1 ){
            tempgame.pemain1.score++;
        }
        else if ( pemenang == 2 ){
            tempgame.pemain2.score++;
        }

        // // 8. GANTI GILIRAN
        tempgame.giliran++;

    } while (pemenang == -1 && tempgame.giliran <= tempgame.papan.jenisPapan*tempgame.papan.jenisPapan);
        
        // 1. BERSIHKAN LAYAR
        system("cls");

        // // 2. TAMPILKAN DASHBOARD KE LAYAR
        dashboard(tempgame.pemain1.namaPlayer, tempgame.pemain2.namaPlayer, tempgame.pilihPertama, tempgame.giliran, tempgame.pemain1.score, tempgame.pemain2.score, tempgame.id_game);

        // // 3. TAMPILKAN PAPAN {JENIS PAPAN} KE LAYAR
        printPapan(tempgame.papan.jenisPapan, tempgame.papan.kotak);

    *game = tempgame;
    *_pemenang = pemenang;
    
}
