#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

#include "header.h"

void playgame(Game *game, bool *_kondisiPilihanPapan, bool *_kondisiPilihanPlayer, bool *_kondisiAfterGame, int _pilihanPlayer )
{
    Game tempgame;
    tempgame = *game;

    bool kondisiPilihanPapan = *_kondisiPilihanPapan;
    bool kondisiPilihanPlayer = *_kondisiPilihanPlayer; 
    bool kondisiAfterGame = *_kondisiAfterGame;
    
    bool kondisiPilihGiliranPertama = true;
    bool kondisiPemenang = false;
    bool kondisiGame = true;

    int baris;
    int kolom;
    int pemenang;


    do
    {
        // 0. PILIH SIAPA YANG PERTAMA
        if (kondisiPilihGiliranPertama == true)
        {
            pilihHalaman(20, &tempgame.pilihPertama); // Tampil halaman pilih giliran
            kondisiPilihGiliranPertama = false;
        }

        // 1. BERSIHKAN LAYAR
        system("cls");

        // 2. TAMPILKAN DASHBOARD KE LAYAR
        dashboard(tempgame.pemain1.namaPlayer, tempgame.pemain2.namaPlayer, tempgame.pilihPertama, tempgame.giliran, tempgame.pemain1.score, tempgame.pemain2.score, tempgame.id_game);

        // 3. TAMPILKAN PAPAN {JENIS PAPAN} KE LAYAR
        printPapan(tempgame.papan.jenisPapan, tempgame.papan.kotak);

        // 4. PILIH INDEX PAPAN
        pilihIndexPapan(_pilihanPlayer, tempgame.papan.jenisPapan, tempgame.giliran, tempgame.pilihPertama, tempgame.papan.kotak, &baris, &kolom);

        // 5. MARK INDEX YANG DI PILIH
        markIndex(tempgame.giliran, tempgame.pilihPertama, &tempgame.papan.kotak, baris, kolom);

        // 6. CEK PEMENANG
        cekKondisiPemenang(tempgame.papan.jenisPapan, tempgame.papan.kotak, &pemenang, &kondisiPemenang, tempgame.giliran, &tempgame.pemain1.score, &tempgame.pemain2.score);

        // 7. GANTI GILIRAN
        gantiGiliran(&tempgame.giliran, &tempgame.pilihPertama);

        // 8. TAMPILKAN PEMENANG
        if (kondisiPemenang == true)
        {
            system("cls");
            dashboard(tempgame.pemain1.namaPlayer, tempgame.pemain2.namaPlayer, tempgame.pilihPertama, tempgame.giliran, tempgame.pemain1.score, tempgame.pemain2.score, tempgame.id_game);
            printPapan(tempgame.papan.jenisPapan, tempgame.papan.kotak);
            do
            {
                tampilWinorDraw(tempgame.pemain1.namaPlayer, tempgame.pemain2.namaPlayer, pemenang, tempgame.giliran, tempgame.papan.jenisPapan);
                setelahCekMenang(tempgame, &kondisiGame, &kondisiPemenang, &kondisiPilihGiliranPertama, &kondisiPilihanPapan, &kondisiPilihanPlayer, &kondisiAfterGame);
            } while (kondisiAfterGame == true);
            kondisiAfterGame == true;
            resetAtributPlayGame(&pemenang, &tempgame.giliran, &tempgame.pilihPertama, &tempgame.papan.kotak, &kondisiPemenang);
        }

    } while (kondisiGame == true);

    *game = tempgame;

    *_kondisiPilihanPapan = kondisiPilihanPapan;
    *_kondisiPilihanPlayer =  kondisiPilihanPlayer;
    *_kondisiAfterGame = kondisiAfterGame;
    
}
