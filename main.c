/* Bermain Game TicTacToe
I.S.    : Diketahui data yang dibutuhkan pada file header
F.F.    : Bermain game tictactoe dengan happy
Author  : Farhan, Azhar, Roy
Versi   : v.1
Tanggal : 25/11/2022
*/
#include "header.h"

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>

int main()
{
    int id=0;
    int i;
    int pilihanMenu;
    bool statusMenu = true; // kondisi perulangan tetap dijalankan
    bool statusPlayer = true; // kondisi perulangan tetap dijalankan
    bool statusLevel = true; // kondisi perulangan tetap dijalankan
    char index[2];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            game[id].papan.kotak[i][j]=' ';
        }
    }
    
    // Seting Layar menjadi full screen
    system("mode 800");

    // 1. Laman Inisialisasi Pada Game
    /*
        Mengisi
        jenisPlayer
        jenisPapan
        scorePlayer1
        scorePlayer2
        scoreComputer
    */

    // Looping Halaman Menu
    do
    {
        pilihanMenu = panah(1); /*  fungsi panah itu sebagai tampilan segala jenis pemilihan player, papan, level, menu  */

        switch (pilihanMenu){
            // jika memilih Play Game maka case 1
            case 1 : 
                do
                {
                    statusPlayer = true;
                    game[id].jenisPlayer = panah(2); 
                    
                        switch (game[id].jenisPlayer)
                        {
                            // jika memilih jenis player 1
                            case 1 :
                                do
                                {
                                    statusLevel = true;
                                    game[id].com.tingkatKesulitan = panah(21);

                                    switch (game[id].com.tingkatKesulitan)
                                    {
                                        case 1 :
                                            game[id].papan.jenisPapan = panah(22);
                                            if ( game[id].papan.jenisPapan == 0)
                                                statusLevel = true;
                                            else {
                                                statusPlayer = false;
                                                statusLevel = false;
                                            }
                                            break;
                                        case 2 : 
                                            game[id].papan.jenisPapan = panah(22);
                                            if( game[id].papan.jenisPapan == 0)
                                                statusLevel = true;
                                            else {
                                                statusPlayer = false;
                                                statusLevel = false;
                                            }
                                            break;
                                        case 3 : 
                                            game[id].papan.jenisPapan = panah(22);
                                            if( game[id].papan.jenisPapan == 0)
                                                statusLevel = true;
                                            else {
                                                statusPlayer = false;
                                                statusLevel = false;
                                            }
                                            break;
                                        case 0 :
                                            statusLevel = false;
                                            break;
                                    }
                                }while (statusLevel);
                                break;
                            case 2 :
                                game[id].papan.jenisPapan = panah(22);
                                if( game[id].papan.jenisPapan == 0)
                                        statusPlayer = true;
                                else 
                                    statusPlayer = false;
                                break;
                            case 0 :
                                statusPlayer = false;
                                break;
                        }
                }while (statusPlayer);
                break;
            case 2 : 
                tampilanHowToPlay();
                int button1;
                do
                {
                    button1 = getch();
                }while ( button1 != 13 );
                break;

            case 3 : 
                tampilanAboutUs();
                int button2;
                do
                {
                    button2 = getch();
                } while ( button2 != 13 );
                break;

            case 0 : 
                statusMenu = false;
                break;
        } 

    if ( game[id].jenisPlayer == 2 && game[id].papan.jenisPapan == 1 )
    {
        int a =0;
        while ( a < 2 )
        {
            system("cls");
            DisplayPapan3x3(id);
            PilihIndex(index);
            if ( index == "A1" )
                game[id].papan.kotak[0][0] = 'X';
        }



        int i;
        scanf("%d",&i);
    }





    }while ( statusMenu );
    return 0;
}