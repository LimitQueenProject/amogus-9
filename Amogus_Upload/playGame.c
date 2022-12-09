#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

#include "header.h"

void playgame(Game *game)
{
    Game tempgame;
    tempgame = *game;

    int baris;
    int kolom;

    do
    {
        // 0. PILIH SIAPA YANG PERTAMA
        // if (kondisiPilihGiliranPertama == true)
        // {
        //     pilihHalaman(111, &tempgame.pilihPertama); // Tampil halaman pilih giliran
        //     kondisiPilihGiliranPertama = false;
        // }
        // 1. BERSIHKAN LAYAR
        system("cls");

        // // 2. TAMPILKAN DASHBOARD KE LAYAR
        dashboard(tempgame.pemain1.namaPlayer, tempgame.pemain2.namaPlayer, tempgame.pilihPertama, tempgame.giliran, tempgame.pemain1.score, tempgame.pemain2.score, tempgame.id_game);

        // // 3. TAMPILKAN PAPAN {JENIS PAPAN} KE LAYAR
        printPapan(tempgame.papan.jenisPapan, tempgame.papan.kotak);

        // // 4. PILIH INDEX PAPAN
        pilihIndexPapan(tempgame.jenisPermainanPlayer, tempgame.papan.jenisPapan, tempgame.giliran, tempgame.pilihPertama, tempgame.papan.kotak, &baris, &kolom);

        // // 5. MARK INDEX YANG DI PILIH
        markIndex(tempgame.giliran, tempgame.pilihPertama, &tempgame.papan.kotak, baris, kolom);

        // // 6. CEK PEMENANG
        // cekKondisiPemenang(tempgame.papan.jenisPapan, tempgame.papan.kotak, &pemenang, &kondisiPemenang, tempgame.giliran, &tempgame.pemain1.score, &tempgame.pemain2.score);
        tempgame.pemenang = cekPemenang(tempgame.papan.jenisPapan, tempgame.papan.kotak);
        // printf("Pemenang : %d", tempgame.pemenang);
        // int o = getch();

        if ( tempgame.pemenang == 1 ){
            tempgame.pemain1.score++;
        }
        else if ( tempgame.pemenang == 2 ){
            tempgame.pemain2.score++;
        }

        // // 7. GANTI GILIRAN
        tempgame.giliran++;

        // // 8. TAMPILKAN PEMENANG
        // if (kondisiPemenang == true)
        // {
        //     system("cls");
        //     dashboard(tempgame.pemain1.namaPlayer, tempgame.pemain2.namaPlayer, tempgame.pilihPertama, tempgame.giliran, tempgame.pemain1.score, tempgame.pemain2.score, tempgame.id_game);
        //     printPapan(tempgame.papan.jenisPapan, tempgame.papan.kotak);
        //     do
        //     {
                // tampilWinorDraw(tempgame.pemain1.namaPlayer, tempgame.pemain2.namaPlayer, pemenang, tempgame.giliran, tempgame.papan.jenisPapan);
                // setelahCekMenang(tempgame, &kondisiGame, &kondisiPemenang, &kondisiPilihGiliranPertama, &kondisiPilihanPapan, &kondisiPilihanPlayer, &kondisiAfterGame);
        //     } while (kondisiAfterGame == true);
        //     kondisiAfterGame == true;
            // resetAtributPlayGame(&pemenang, &tempgame.giliran, &tempgame.pilihPertama, &tempgame.papan.kotak, &kondisiPemenang);
        // }

    } while (tempgame.pemenang == -1 && tempgame.giliran <= tempgame.papan.jenisPapan*tempgame.papan.jenisPapan);

    *game = tempgame;
    
}
