#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "header.h"

int cekNamaDuplikat( int _awal, char listNamaValid[10000][20], char _namaPlayer[20] ){
        for( int b = 0; b <= _awal; b++ ){
            if( strcmp(_namaPlayer, listNamaValid[b])==0 ){
                return 1;
            }
        }
        return 0;
}

void highScore()
{   
    // DEKLARASI
    typedef struct{
        char namaPlayer[20];
        int score;
    }DATA;

    FILE *file1;
    DATA data[10000];
    DATA dataTampil[10000];
    DATA tempData;
    Game tempGame;
    char listNamaValid[10000][20];

    // 1. CEK JUMLAH DATA YANG TERSIMPAN
    file1 = fopen("data.dat","rb");
    if (file1 == NULL){
        system("cls");
        banner2();

        printf("\n\tData is empty");
        printf("\n\tPress any button to back");
        
        fclose(file1);
        int butt = getch();
    }
    else{
        // 2. SALIN NAMA DAN SCORE DARI TIAP TIAP PEMAIN
        int i = 0;
        while (fread(&tempGame, sizeof(Game), 1, file1))
        {
            strcpy(data[i].namaPlayer, tempGame.pemain1.namaPlayer);
            data[i].score = tempGame.pemain1.score;
            strcpy(data[i+1].namaPlayer, tempGame.pemain2.namaPlayer);
            data[i+1].score = tempGame.pemain2.score;
            i+=2;
        }
        fclose(file1);     

        // SATUKAN POINT NAMA YANG SAMA
        int awal = 0;
        for(int k = 0; k < i; k++){
            if( cekNamaDuplikat(awal,listNamaValid,data[k].namaPlayer) == 0 ){
                strcpy(listNamaValid[awal], data[k].namaPlayer);
                awal++;
            }
        }

        // JUMLAHKAN SCORE PADA NAMA YANG SAMA
        int cnt = 0;
        bool ada = false;
        for( int j = 0; j < awal; j++ ){
            for( int k = 0; k < i; k++ ){
                if( strcmp(listNamaValid[j], data[k].namaPlayer)==0 ){
                    strcpy(dataTampil[cnt].namaPlayer, data[k].namaPlayer);
                    dataTampil[cnt].score += data[k].score;
                    ada = true;
                }
            }
            if(ada == true)
            cnt++;
            ada = false;                
        }



        // URUTKAN DATA DARI YANG PALING BESAR KE TERKECIL
        for ( int j = 0; j < cnt; j++ ){
            for ( int k = 0; k < cnt-1; k++ )
            {
                if( dataTampil[k].score < dataTampil[k+1].score )
                {
                    tempData = dataTampil[k];
                    dataTampil[k] = dataTampil[k+1];
                    dataTampil[k+1] = tempData;
                }
            }
        }
        
        // BATASI DATA YANG AKAN DI TAMPILKAN MAKSIMAL 10 DATA PLAYER TERMASUK KOMPUTER
        if(cnt>10)
        {
            cnt=10;
        }

        system("cls");
        
        // TAMPILKAN DATA YANG SUDAH DI AMBIL DARI FILE

        for (int j = 0; j < cnt; j++)
        {
            tampilHighScore(dataTampil[j].namaPlayer, dataTampil[j].score, j, cnt);
        }
        int p = getch();    

    }
}


void tampilkanData(int *_IDPilihanPlayer, bool *_lanjut)
{
    int count=0;
    int urutan;
    int IDPilihanPlayer;
    int daftarID[10000];
    bool lanjut=true;
    int max_id;
    FILE *file;
    Game _game;

    // BUKA FILE DATA.DAT MODE READ
    file = fopen("data.dat", "rb");
    system("cls");

    // TAMPILKAN BANNER
    banner2();
    koor(3,12);

    // BACA DATA DAN L
    while (fread(&_game, sizeof(Game), 1, file))
    {
        if(count==1){
            koor(3,12);
        }
        printf("\n\tID Game : %d\n", _game.id_game);
        printf("\t%s VS %s\n", _game.pemain1.namaPlayer, _game.pemain2.namaPlayer);
        printf("\tScore %s\t: %d\n", _game.pemain1.namaPlayer, _game.pemain1.score);
        printf("\tScore %s\t: %d\n", _game.pemain2.namaPlayer, _game.pemain2.score);
        printf("\tBoard Type : %dx%d\n", _game.papan.jenisPapan, _game.papan.jenisPapan);
        if (_game.pilihPertama == 1)
            printf("\t%s is go first\n", _game.pemain1.namaPlayer);
        else
            printf("\t%s is go first\n", _game.pemain2.namaPlayer);

        
        daftarID[count]=_game.id_game;

        // Menghitung berapa banyak data
        count++;
    }

    koor(2,12); printf("List of Data");
    koor(90,12); printf("Press Esc to back to the menu");


    panahLoadGame(count, daftarID, &lanjut, &IDPilihanPlayer);
    *_IDPilihanPlayer = IDPilihanPlayer;
    *_lanjut = lanjut;

    fclose(file);
}



void loadGame(Game *game, bool *_kondisiLoadgame)
{
    int _id;

    bool cari = true;

    FILE *file1;
    Game tempGame;

    bool kondisiDitemukan = false;
    bool kondisiCariLagi = false;

    do{
        file1 = fopen("data.dat","rb");

        if ( file1 == NULL ){
            system("cls");
            banner2();
            printf("\n\tData is empty");
            printf("\n\tPress Any Button to back to the menu");
            int butt;
            butt = getch();
        }
        else{
            // tampilkan data yang tersimpan di file data.dat
            tampilkanData(&_id, &cari);

            if(cari==true){
            while(fread(&tempGame, sizeof(Game),1,file1)){
                if ( tempGame.id_game == _id ){
                    system("cls");
                    banner2();
                    printf("\n\n\n\tSucces to found the data\n");
                    printf("\tID Game : %d\n", tempGame.id_game);
                    printf("\t%s VS %s\n", tempGame.pemain1.namaPlayer, tempGame.pemain2.namaPlayer);
                    printf("\tScore %s\t: %d\n", tempGame.pemain1.namaPlayer, tempGame.pemain1.score);
                    printf("\tScore %s\t: %d\n", tempGame.pemain2.namaPlayer, tempGame.pemain2.score);
                    printf("\tBoard Type : %dx%d\n", tempGame.papan.jenisPapan, tempGame.papan.jenisPapan);

                    if (tempGame.pilihPertama == 1){
                        printf("\t%s is go first\n", tempGame.pemain1.namaPlayer);
                    }
                    else{
                        printf("\t%s is go first\n", tempGame.pemain2.namaPlayer);
                    }

                    printf("\n\n\tLoad game ?\n\tPress Enter to load");
                    koor(90,28); printf("Press Esc to back to menu");
                    int b = getch();
                    if (b==13){
                        *_kondisiLoadgame = true;
                        *game = tempGame;
                    }
                    else if (b==27){
                        kondisiCariLagi = false;
                    }
                    kondisiDitemukan = true;
                }
            }
            if( kondisiDitemukan == true )
            {
                kondisiCariLagi = false;
            }
            else if( kondisiDitemukan == false ){
                system("cls");
                banner2();
                printf("\n\n\tData not found");
                printf("\n\tPress Enter to search another id...");
                koor(90,28); printf("Press Esc to back to the menu");
                int b = getch();

                if( b == 13 )
                { 
                    kondisiCariLagi = true;
                }
                else if(b == 27)
                {
                    kondisiCariLagi = false;
                } 
            }
        
        fclose(file1);
    }else {fclose(file1);
    kondisiCariLagi = false;}
    }
    }while(kondisiCariLagi == true);
}



void saveData(Game _game)
{  
    FILE *file1, *file2;
    Game tempGame;
    int id = _game.id_game;

    // BUKA FILE DATA.DAT MODE REWIND
    file1 = fopen("data.dat", "ab");
    // TAMBAHKAN DATA TERBARU KE BARIS PALING BAWAH
    fwrite(&_game, sizeof(Game), 1, file1);
    // TUTUP FILE1
    fclose(file1);

    // BUKA DILE DATA.DAT MODE READ
    file1 = fopen("data.dat", "rb");
    // BUKA DILE TEMPDATA.DAT MODE APPEND
    file2 = fopen("tempData.dat", "ab");

    // BACA DAN MASUKAN DATA YANG ADA PADA FILE SATU PERSATU KECUALI ID YANG AKAN DI SAVE PADA FILE DATA.DAT
    while (fread(&tempGame, sizeof(Game), 1, file1))
    {
        if (tempGame.id_game != id)
        {
            // MASUKAN DATA KECUALI DATA YANG SAMA DENGAN ID GAME YANG AKAN DISIMPAN
            fwrite(&tempGame, sizeof(Game), 1, file2);
        }
    }
    // SIMPAN DATA TERBARU KE BARIS PALING BAWAH PADA TEMPDATA.DAT
    fwrite(&_game, sizeof(Game), 1, file2);
    koor(55,28);
    printf("\n\tYour data has been saved\n");
    sleep(2);
    koor(55,28);
    printf("\n\t                         \n");

    // TUTUP FILE DATA.DAT DAN TEMPDATA.DAT
    fclose(file1);
    fclose(file2);

    // HAPUS DATA.DAT
    remove("data.dat");
    
    // UBAH NAMA TEMPDATA.DAT MENJADI DATA.DAT
    rename("tempData.dat", "data.dat");
}