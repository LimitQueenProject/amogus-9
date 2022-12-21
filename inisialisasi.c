#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include "header.h"

int isiID()
{
    bool kosong = false;
    int id_sementara = 1;
    // BUKA FILE
    FILE *file;
    file = fopen("id.dat", "rb");
    // CEK FILE JIKA KOSONG
    if ( file == NULL )
    {
        kosong = true;
    }
    // TUTUP FILE SETELAH DIBUKA
    fclose(file);
    // JIKA DATA MASIH KOSONG MAKA ISI DATA DENGAN ANGKA DEFAULT 1
    if ( kosong )
    {
        file = fopen("id.dat", "wb");
        fwrite(&id_sementara, sizeof(int), 1, file);
    // TUTUP FILE SETELAH DIBUKA
        fclose(file);
    }
    // JIKA DATA SUDAH TERISI MAKA AMBIL NILAI ID TERAKHIR DAN TAMBAHKAN 1
    else if ( !kosong )
    {
        
        file = fopen("id.dat", "rb");
        fread(&id_sementara, sizeof(int), 1, file);
        fclose(file);
        id_sementara++;
        file = fopen("id.dat", "wb");
        fwrite(&id_sementara, sizeof(int), 1, file);
        fclose(file);
    } 
    return id_sementara;
} 



int namaYangSama(char _namaPlayer[20]){
    FILE *file1;
    file1 = fopen("data.dat", "rb");

    Game tempGame;

    while(fread(&tempGame, sizeof(Game), 1, file1)){
        if( strcmp(_namaPlayer, tempGame.pemain1.namaPlayer) == 0  || strcmp(_namaPlayer, tempGame.pemain2.namaPlayer)==0 ){
            fclose(file1);
            return 1;
        }
    }
    
    fclose(file1);
    return 0;
}



void inisialisasi( Game *game, int *_pemenang )
{
// NAMA
    inputNama(game->jenisPermainanPlayer, &game->pemain1.namaPlayer, &game->pemain2.namaPlayer );

// game
    game->id_game = isiID();
    game->giliran = 1;
    *_pemenang = -1;


// score
    game->pemain1.score = 0;
    game->pemain2.score = 0;

// Board    
    strcpy(game->papan.kotak[0], "       "); // 7 baris kosong
    strcpy(game->papan.kotak[1], "       "); // 7 baris kosong
    strcpy(game->papan.kotak[2], "       "); // 7 baris kosong
    strcpy(game->papan.kotak[3], "       "); // 7 baris kosong
    strcpy(game->papan.kotak[4], "       "); // 7 baris kosong
    strcpy(game->papan.kotak[5], "       "); // 7 baris kosong
    strcpy(game->papan.kotak[6], "       "); // 7 baris kosong

// Inisialisasi
    game->kondisiInisialisasi = false;
}

void scanNama( char (*_namaPlayer)[20])
{
 scanf(" %[^\n]", (*_namaPlayer));
}