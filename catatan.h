/* 
A. Algoritma Yang Dibutuhkan pada main UI
    1. Menampilkan Loading Memasuki Game;
    2. Menampilkan Halaman Menu;
        a. New Game;
        b. Load Game;
        c. How To Play;
        d. About Us;
    3. Menampilkan Halaman New Game
        a. vs Computer
        b. vs Friend
        c. back
    4. Menampilkan Halaman vs Computer
        a. Easy
        b. Medium
        c. Hard
        d. back
    5. Menampilkan Halaman vs Friend, Easy, Medium, Hard
        a. Board Type 3x3
        b. Board Type 5x5
        c. Board Type 7x7
        d. back
    6. Menampilkan Halaman How To Play
        "Berisi cara bermain tictactoe"
        a. back
    7. Menampilkan Halaman About Us
        "Berisi tentang developer"
        a. back

B. Modul Yang Dibutuhkan Dalam Main
    1. MasukanPilihanInisialisasi()
        berguna untuk 


    // 2. Kondisi Setelah Menu
    if ( pilihanMenu == 1 )
        game[id].jenisPlayer =  panah(2);
    else if ( pilihanMenu == 2 )
        tampilanHowToPlay();        
    else if ( pilihanMenu == 3 )
        tampilanAboutUs();
    else if ( pilihanMenu == 0)
        statusMenu = true; 

    // 3. Kondisi Setelah Player
    if ( game[id].jenisPlayer == 1 )
        game[id].com.tingkatKesulitan = panah(21);
    
    // 4. Kondisi Setelah menentukan 2 Player atau menentukan level 
    else if ( game[id].jenisPlayer == 2 || game[id].com.tingkatKesulitan == 1 || game[id].com.tingkatKesulitan == 2 || game[id].com.tingkatKesulitan == 3)
        game[id].papan.jenisPapan = panah(22);

    else if ( game[id].jenisPlayer == 0 )
        pilihanMenu = panah(1);
    
    scanf("%d", &i);


*/

/* Bermain Game TicTacToe
I.S.    : Diketahui data yang dibutuhkan pada file header
F.F.    : Bermain game tictactoe dengan happy
Author  : Farhan, Azhar, Roy
Versi   : v.1
Tanggal : 25/11/2022
*/
/*
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
    bool statusMenu = true;
    bool statusPlayer = true;
    bool statusLevel = true;
    
    // Seting Layar menjadi full screen
    system("mode 800");

    // 1. Halaman awal
    do
    {
        pilihanMenu = panah(1);

        switch (pilihanMenu){
            case 1 : 
                do
                {
                    statusPlayer = true;
                    game[id].jenisPlayer = panah(2);
                        switch (game[id].jenisPlayer)
                        {
                            case 1 :
                                do
                                {
                                statusLevel = true;
                                game[id].com.tingkatKesulitan = panah(21);
                                switch (game[id].com.tingkatKesulitan)
                                {
                                    case 1 :
                                        game[id].papan.jenisPapan = panah(22);
                                        statusPlayer = false;
                                        statusLevel = false;
                                        break;
                                    case 2 : 
                                        game[id].papan.jenisPapan = panah(22);
                                        statusPlayer = false;
                                        statusLevel = false;
                                        break;
                                    case 3 : 
                                        game[id].papan.jenisPapan = panah(22);
                                        statusPlayer = false;
                                        statusLevel = false;
                                        break;
                                    case 0 :
                                        statusLevel = false;
                                        statusPlayer = true;
                                        break;
                                }
                                }while (statusLevel);
                                break;
                            case 2 :
                                game[id].papan.jenisPapan = panah(22);
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
                } while ( button1 != 13 );
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

    if ( game[id].jenisPlayer == 1 && game[id].com.tingkatKesulitan == 1 && game[id].papan.jenisPapan == 1 )
    {
        playGame(111);
        int i;
        scanf("%d",&i);
        statusMenu = false;
    }
    else if ( game[id].jenisPlayer == 1 && game[id].com.tingkatKesulitan == 1 && game[id].papan.jenisPapan == 2 )
    {
        playGame(112);
    }




    }while ( statusMenu );
    return 0;
}
*/