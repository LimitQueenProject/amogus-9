#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "header.h"

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
    while (fread(&_game, sizeof(Game), 1, file))
    {
        printf("\nData Ditemukan\n");
        printf("ID Game : %d\n", _game.id_game);
        printf("%s VS %s\n", _game.pemain1.namaPlayer, _game.pemain2.namaPlayer);
        printf("Score %s\t: %d\n", _game.pemain1.namaPlayer, _game.pemain1.score);
        printf("Score %s\t: %d\n", _game.pemain2.namaPlayer, _game.pemain2.score);
        printf("Jenis Papan : %dx%d\n", _game.papan.jenisPapan, _game.papan.jenisPapan);
        if (_game.pilihPertama == 1)
            printf("Giliran Pertama : %s\n", _game.pemain1.namaPlayer);
        else
            printf("Giliran Pertama : %s\n", _game.pemain2.namaPlayer);
    }

    fclose(file);
}

void loadGame(Game *game, bool *_kondisiLoadgame)
{
    int _id;

    FILE *file1;
    Game tempGame;

    bool kondisiDitemukan = false;
    bool kondisiCariLagi = false;

    do{
        file1 = fopen("data.dat","rb");
            tampilkanData();

            printf("\nMasukan id yang akan di load : ");
            scanf("%d", &_id);

            while(fread(&tempGame, sizeof(Game),1,file1))
            {
                if ( tempGame.id_game == _id )
                {
                    printf("\nData Bisa Di Load\n");
                    printf("ID Game : %d\n", tempGame.id_game);
                    printf("%s VS %s\n", tempGame.pemain1.namaPlayer, tempGame.pemain2.namaPlayer);
                    printf("Score %s\t: %d\n", tempGame.pemain1.namaPlayer, tempGame.pemain1.score);
                    printf("Score %s\t: %d\n", tempGame.pemain2.namaPlayer, tempGame.pemain2.score);
                    printf("Jenis Papan : %dx%d\n", tempGame.papan.jenisPapan, tempGame.papan.jenisPapan);
                    if (tempGame.pilihPertama == 1){
                        printf("Giliran Pertama : %s\n", tempGame.pemain1.namaPlayer);
                    }
                    else{
                        printf("Giliran Pertama : %s\n", tempGame.pemain2.namaPlayer);
                    }
                    printf("\nLoad Permainan ? Tekan Enter Jika Ya");
                    int b = getch();
                    if (b==13)
                    {
                        *_kondisiLoadgame = true;
                        *game = tempGame;
                    }
                    kondisiDitemukan = true;
                }
            }
            if( kondisiDitemukan == true ){
                kondisiCariLagi = false;
            }
            else if( kondisiDitemukan == false ){
                printf("\nData Tidak Ditemukan");
                printf("\nTekan Tombol Enter Untuk Mencari Data lain...");
                int b = getch();
                if( b == 13 ){ 
                    kondisiCariLagi = true;
                }
            }
        fclose(file1);
    }while(kondisiCariLagi == true);

}

void saveData(Game _game)
{
    FILE *file1, *file2;
    Game tempGame;
    int id = _game.id_game;

    file1 = fopen("data.dat", "ab");
    fwrite(&_game, sizeof(Game), 1, file1);
    fclose(file1);

    file1 = fopen("data.dat", "rb");
    file2 = fopen("tempData.dat", "ab");

    while (fread(&tempGame, sizeof(Game), 1, file1))
    {
        if (tempGame.id_game != id)
        {
            fwrite(&tempGame, sizeof(Game), 1, file2);
        }
    }
    fwrite(&_game, sizeof(Game), 1, file2);

    fclose(file1);
    fclose(file2);
    remove("data.dat");
    rename("tempData.dat", "data.dat");
}