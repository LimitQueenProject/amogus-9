#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>
#include <unistd.h>

#include "header.h"

void highscore()
{
    Game _temp;
    // Game _game[1000];
    typedef struct
    {
        char nama[100];
        int score;
    }dataHighscore;
    
    dataHighscore data[1000];

    int i = 0;
    
    FILE *file;

    file = fopen("data.dat", "rb");

    while( fread(&_temp, sizeof(Game), 1, file) )
    {
        if ( strcmp(_temp.pemain2.namaPlayer, "Computer") == 0 )
        {
            strcpy(data[i].nama, _temp.pemain1.namaPlayer);
            data[i].score = _temp.pemain1.score;
        }
        i++;
    }
    fclose(file);
    system("cls");
    for ( int j = 0; j < i; j++ )
    {
        printf("\n%d. %s\t : %d\n", j+1, data[j].nama, data[j].score );
    }
    printf("Tekan Tombol Apapun Untuk Kembali...");
    int z = getch();
}



void tampilkanData()
{
    int max_id;
    FILE *file;
    Game _game;

    // MEMBACA ID TERBESAR SAAT INI
    // file = fopen("id.dat", "rb");
    // fread(&max_id, sizeof(int), 1, file);
    // fclose(file);
     
    file = fopen("data.dat", "rb");
    while(fread(&_game, sizeof(Game), 1, file))
    {
        printf("Data Ditemukan\n");
        printf("ID Game : %d\n", _game.id_game);
        printf("%s VS %s\n", _game.pemain1.namaPlayer, _game.pemain2.namaPlayer);
        printf("Score %s\t: %d\n", _game.pemain1.namaPlayer ,_game.pemain1.score);
        printf("Score %s\t: %d\n", _game.pemain2.namaPlayer ,_game.pemain2.score);
        printf("Jenis Papan : %dx%d\n",_game.papan.jenisPapan ,_game.papan.jenisPapan);
        if ( _game.pilihPertama == 1 )    
            printf("Giliran Pertama : %s\n",_game.pemain1.namaPlayer);
        else
            printf("Giliran Pertama : %s\n",_game.pemain2.namaPlayer);
    }

    fclose(file);
}


// void saveData( Game _game )
// {
//     FILE *file;
//     FILE *filetemp;

//     int flag = 0;

//     int id = _game.id_game;

//     // Simpan Data Terbaru ke penyimpanan sementara (tempData.dat)
//     filetemp = fopen( "tempData.dat", "wb" );
//     // Cek apakah file bisa dibuka 
//     if ( filetemp == NULL ) // jika tidak bisa dibuka
//     {
//         printf("Gagal Menyimpan Game\n");
//         int b = getch();
//     }
//     else // jika bisa dibuka maka copy datanya ke file temp
//     {
//         fwrite(&_game, sizeof(Game), 1, filetemp);
//         flag = 1;
//     }
//     fclose(filetemp);

// // Setelah itu coba mengganti data yang ada di data.dat sesuai id digant menjadi data yang ada di temp
//     if ( flag == 1 ){
//     filetemp = fopen("tempData.dat", "rb");
//     file = fopen("data.dat", "ab");

//         while( fread( &_game, sizeof(Game) , 1 , filetemp ) )
//         {
//                 fwrite( &_game, sizeof(Game), 1, file );
//         }
//     fclose(file);
//     fclose(filetemp);
//     }
//     else
//     {
//         printf("Anjir gagal copy");
//         int b = getch();
//     }

// }

void saveData( Game _game )
{
    FILE *file1, *file2;
    Game tempGame;
    int id = _game.id_game;

    file1 = fopen("data.dat", "ab");
    fwrite(&_game, sizeof(Game), 1, file1);
    fclose(file1);

    file1 = fopen("data.dat", "rb+");
    file2 = fopen("tempData.dat", "ab+");

    while( fread(&tempGame, sizeof(Game), 1, file1) )
    {
        if ( tempGame.id_game != id )
        {
            fwrite(&tempGame, sizeof(Game), 1, file2);
        }
    }
    fwrite(&_game, sizeof(Game), 1, file2);

    fclose(file1);
    fclose(file2);
    remove("data.dat");
    rename("tempData.dat","data.dat");
}


// void readData( Game _game )
void loadGame( Game *game )
{
    int id;
    Game _game;
    FILE *file;
    
    // 1. Tampilkan Data Yang Bisa Di Load    
    tampilkanData();
    
    // 2. Cek Data Bisa Di Buka Apa Tidak 
    file = fopen("data.dat", "rb");
    if ( file == NULL )
    {
        system("cls");
        printf("Gagal membaca data\n");
        printf("Halaman akan tertutup dalam 3 detik\n");
        sleep(1);
        system("cls");
        printf("Gagal membaca data\n");
        printf("Halaman akan tertutup dalam 2 detik\n");
        sleep(1);
        system("cls");
        printf("Gagal membaca data\n");
        printf("Halaman akan tertutup dalam 1 detik\n");
        sleep(1);
        system("cls");
    }
    // 3. Jika bisa dibuka maka Load Data
    else
    {
    // 4. Deklarasikan Variabel Yang Dibutuhkan untuk Load Data
        bool kondisiData;
    
    // 5. Algoritma
        CariData:  // Label
        // Buat kondisi data bisa dicari kembali
        kondisiData = true;
        // Masukan Pilihan Data Yang Ingin dicari berdasarkan id Game
        printf("\nCari berdasarkan id data : ");
        scanf(" %d", &id);

    // 6. Cek Apakah data tersebut ada atau tidak
        while( fread(&_game, sizeof(_game), 1, file) > 0 && kondisiData )
        {
            // Jika data ditemukan
            if ( _game.id_game == id )
            {
                // Tampilkan Data Yang sudah Ditemukan
                system("cls");
                banner2();
                printf("\n\nData Ditemukan\n");
                printf("ID Game : %d\n", _game.id_game);
                printf("%s VS %s\n", _game.pemain1.namaPlayer, _game.pemain2.namaPlayer);
                printf("Score %s : %d\n", _game.pemain1.namaPlayer ,_game.pemain1.score);
                printf("Score %s : %d\n", _game.pemain2.namaPlayer ,_game.pemain2.score);
                printf("Jenis Papan : %dx%d\n",_game.papan.jenisPapan ,_game.papan.jenisPapan);
                if ( _game.pilihPertama == 1 )    
                    printf("Giliran Pertama : %s\n",_game.pemain1.namaPlayer);
                else
                    printf("Giliran Pertama : %s\n",_game.pemain2.namaPlayer);

                // Tanya apakah Data diatas sudah sesuai dengan load game yang di inginkan
                printf("\n\nAfaakah Data yang Ini Banh ? [Tekan Enter Jika Iya]");
                int b = getch();
                printf("\nYakin ? [ Tekan Enter Jika Yakin ]");
                if ( b == 13 )  // jika user menekan tombol enter maka masukan data yang dipilih kedalam permainan
                {
                    kondisiData = false;
                    *game = _game;
                }
            }
        }
        // Jika data tidak ditemukan maka tanya ulang
        if ( kondisiData )
        {
            printf("\n\nData Tidak Ditemukan\n");
            printf("Tekan Tombol Enter untuk mencari data lain");
            int enter = getch();
            if ( enter == 13 )
                goto CariData;
        }
    }
    fclose(file);
}



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


void jumlahData()
{
    Game _game;
    FILE *file;
    file = fopen("data.dat", "rb");

    fseek(file,0,SEEK_END);
    
    int n = ftell(file)/sizeof(Game);
    printf("\nJumlah Data : %d ", n);
    fclose(file);
}