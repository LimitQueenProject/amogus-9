#include <stdio.h>
#include <string.h>

#include "header.h"

void inisialisasi(Game *_game, int *_jenisPapan, int _pilihanPapan, bool *_kondisiPilihGiliranPertama,  bool *_kondisiPemenang, bool *_kondisiGame )
{
    if ( _pilihanPapan == 1 )
        *_jenisPapan = 3;
    else if ( _pilihanPapan == 2 )
        *_jenisPapan = 5;
    else if ( _pilihanPapan == 3 )
        *_jenisPapan = 7;
    *_kondisiPilihGiliranPertama = true;
    *_kondisiPemenang = false;
    *_kondisiGame = true;

    _game->id_game = isiID();
    _game->giliran= 1;
    _game->pilihPertama = 1;

// sementara
    // strcpy(_game->pemain1.namaPlayer, "awoajgvc jhfncv snbc"); //true
    // strcpy(_game->pemain2.namaPlayer, "Aziz"); //false

// score
    _game->pemain1.score = 0;
    _game->pemain2.score = 0;

// Board
    _game->papan.jenisPapan = 3; // default
    
    strcpy(_game->papan.kotak[0], "       "); // 3 baris kosong
    strcpy(_game->papan.kotak[1], "       "); // 3 baris kosong
    strcpy(_game->papan.kotak[2], "       "); // 3 baris kosong
    strcpy(_game->papan.kotak[3], "       "); // 3 baris kosong
    strcpy(_game->papan.kotak[4], "       "); // 3 baris kosong
    strcpy(_game->papan.kotak[5], "       "); // 3 baris kosong
    strcpy(_game->papan.kotak[6], "       "); // 3 baris kosong
}



// 1. Inisilasiasi
// void inisialisasi( Game *_game, int _id )
// {
// }



void scanNama( int _flagInputNama, char (*_namaPlayer)[100])
{
 scanf(" %[^\n]", (*_namaPlayer));
}
