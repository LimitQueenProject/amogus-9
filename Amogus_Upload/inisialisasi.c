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

    FILE *file;
    file = fopen("id.dat", "rb");
    if ( file == NULL )
    {
        // printf("Kosong");
        // int i = getch();
        kosong = true;
    }
    fclose(file);
    if ( kosong )
    {
        file = fopen("id.dat", "wb");
        fwrite(&id_sementara, sizeof(int), 1, file);
        fclose(file);
    }
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


// void inisialisasi( char (*_namaPlayer1)[20], char (*_namaPlayer2)[20], int *_id, int *_giliran, int *_score1, int *_score2, char (*_kotak)[7][7], int _jenisPlayer )
void inisialisasi( Game *game, int *_pemenang )
{
    
    // int valid = 0;
    // // Nama Player
    // if ( game->jenisPermainanPlayer == 1 )
    // {
    //     do{
    //         system("cls");
    //         printf("\nMasukan nama anda : ");
    //         scanf(" %[^\n]", game->pemain1.namaPlayer);
    //         if ( strlen(game->pemain1.namaPlayer) <= 20 ){
    //             valid = 1;
    //         }
    //         else{
    //             printf("Nama anda terlalu panjang silahkan input ulang\n");
    //             sleep(2);
    //         }
    //     }while(valid == 0);
    //     strcpy(game->pemain2.namaPlayer, "Computer");
    // }
    // else if ( game->jenisPermainanPlayer == 2 )
    // {
    //     do{
    //         system("cls");
    //         printf("\nMasukan nama player 1 : ");
    //         scanf(" %[^\n]", game->pemain1.namaPlayer);
    //         if ( strlen(game->pemain1.namaPlayer) <= 20 ){
    //             valid = 1;
    //         }
    //         else{
    //             printf("Nama anda terlalu panjang silahkan input ulang\n");
    //             sleep(2);
    //         }
    //     }while(valid == 0);
    //     valid = 0;
    //     do{
    //         system("cls");
    //         printf("\nMasukan nama player 2 : ");
    //         scanf(" %[^\n]", game->pemain2.namaPlayer);
    //         if ( strlen(game->pemain2.namaPlayer) <= 20 ){
    //             valid = 1;
    //         }
    //         else{
    //             printf("Nama anda terlalu panjang silahkan input ulang\n");
    //             sleep(2);
    //         }
    //     }while(valid == 0);
    // }

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
// void inisialisasi( char (*_namaPlayer1)[20], char (*_namaPlayer2)[20], int *_id, int *_giliran, int *_score1, int *_score2, char (*_kotak)[7][7], int _jenisPlayer )
// {
    
//     int valid = 0;
//     // Nama Player
//     if ( _jenisPlayer == 1 )
//     {
//         do{
//             system("cls");
//             printf("\nMasukan nama anda : ");
//             scanf(" %[^\n]", *_namaPlayer1);
//             if ( strlen(*_namaPlayer1) <= 20 ){
//                 valid = 1;
//             }
//             else{
//                 printf("Nama anda terlalu panjang silahkan input ulang\n");
//                 sleep(2);
//             }
//         }while(valid == 0);
//         strcpy(*_namaPlayer2, "Computer");
//     }
//     else if ( _jenisPlayer == 2 )
//     {
//         do{
//             system("cls");
//             printf("\nMasukan nama player 1 : ");
//             scanf(" %[^\n]", *_namaPlayer1);
//             if ( strlen(*_namaPlayer1) <= 20 ){
//                 valid = 1;
//             }
//             else{
//                 printf("Nama anda terlalu panjang silahkan input ulang\n");
//                 sleep(2);
//             }
//         }while(valid == 0);
//         valid = 0;
//         do{
//             system("cls");
//             printf("\nMasukan nama player 2 : ");
//             scanf(" %[^\n]", *_namaPlayer2);
//             if ( strlen(*_namaPlayer2) <= 20 ){
//                 valid = 1;
//             }
//             else{
//                 printf("Nama anda terlalu panjang silahkan input ulang\n");
//                 sleep(2);
//             }
//         }while(valid == 0);
//     }

// // game
//     *_id = isiID();
//     *_giliran= 1;


// // score
//     *_score1 = 0;
//     *_score2 = 0;

// // Board    
//     strcpy(*_kotak[0], "       "); // 7 baris kosong
//     strcpy(*_kotak[1], "       "); // 7 baris kosong
//     strcpy(*_kotak[2], "       "); // 7 baris kosong
//     strcpy(*_kotak[3], "       "); // 7 baris kosong
//     strcpy(*_kotak[4], "       "); // 7 baris kosong
//     strcpy(*_kotak[5], "       "); // 7 baris kosong
//     strcpy(*_kotak[6], "       "); // 7 baris kosong
// }