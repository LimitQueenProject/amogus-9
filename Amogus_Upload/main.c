#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#include "header.h"

int main()
{
    // Deklarasi Variabel
    // 1. Deklarasi Variabel Komponen Penyusun Game
    Game game;
    // int pemenang = -1;
    // 0
    #define menu 0
    // 1
    #define newgame 1
    // 1.1
    #define _1player 1
    // 1.2
    #define _2player 2
    // 1.3
    #define pilihpapan 11
    // 1.3.1
    #define papan3x3 3
    // 1.3.2
    #define papan5x5 5
    // 1.3.3
    #define papan7x7 7

    // 1.4
    #define pilihpertama 111
    // 1.4.1
    #define player1_pertama 1
    // 1.4.2
    #define player2_pertama 2


    // 2
    #define loadgame 2
    // 3
    #define highscore 3
    // 4
    #define howtoplay 4
    // 5
    #define aboutus 5
    // -1
    #define keluar -1


    
    // 2. Deklarasi Variabel Kondisi-Kondisi Halaman
    bool kondisiHalaman = true;
    int halaman = 0;
    int pilihan = 0;
    bool maingame = false;
    bool kondisiInisialisasi = false;
    bool kondisiLoadgame = false;
    bool kondisiSetelahMenang = false;
    bool kondisiGantiGiliran = true;


    // Algoritma
    // 1. Pengaturan ukuran console dengan lebar 1000 dan tinggi 600 {source: https://www.codeincodeblock.com/2011/03/move-console-windows-using-codeblock.html}
    HWND hWnd = GetConsoleWindowNT();
    MoveWindow(hWnd, 180, 50, 1000, 600, TRUE);

    // 2. Menampilkan Loading Game Agar Keren
    // loading();

    do{
        
        switch (halaman){
            
            case menu:
                pilihHalaman(menu, &pilihan);
                if ( pilihan == newgame ){
                    halaman = newgame;
                }
                else if ( pilihan == loadgame ){
                    loadGame( &game, &kondisiLoadgame );
                    if ( kondisiLoadgame == true ){
                        maingame = true;
                        game.kondisiInisialisasi = false;
                    }

                }
                else if ( pilihan == highscore ){
                    halaman = highscore;
                }
                else if ( pilihan == howtoplay ){
                    halaman = howtoplay;
                }
                else if ( pilihan == aboutus ){
                    halaman = aboutus;
                }
                else if ( pilihan == keluar ){
                    kondisiHalaman = false;
                }
            break;

            case newgame:
                // PILIH JENIS PLAYER
                pilihHalaman(newgame, &pilihan);
                if( pilihan == _1player ){
                    game.jenisPermainanPlayer = _1player;
                    halaman = pilihpapan;
                }
                else if( pilihan == _2player ){
                    game.jenisPermainanPlayer = _2player;
                    halaman = pilihpapan;
                }
                else if( pilihan == keluar ){
                    halaman = menu;
                }
            break;

            case pilihpapan:
                // PILIH JENIS PAPAN
                pilihHalaman(pilihpapan, &pilihan);
                if ( pilihan == papan3x3 ){
                    game.papan.jenisPapan = papan3x3;
                    maingame = true;
                }
                else if ( pilihan == papan5x5 ){
                    game.papan.jenisPapan = papan5x5;
                    maingame = true;
                }
                else if ( pilihan == papan7x7 ){
                    game.papan.jenisPapan = papan7x7;
                    maingame = true;
                }
                else if ( pilihan == keluar ){
                    halaman = newgame;
                }
            break;
        }
        

        while( maingame == true ){
            if ( game.kondisiInisialisasi == true ){
                inisialisasi(&game);
            }
            if ( kondisiGantiGiliran == true ){
                pilihHalaman(pilihpertama, &game.pilihPertama); 
                kondisiGantiGiliran = false;
            }
            
            playgame(&game);
            system("cls");
            dashboard(game.pemain1.namaPlayer, game.pemain2.namaPlayer, game.pilihPertama, game.giliran, game.pemain1.score, game.pemain2.score, game.id_game);
            printPapan(game.papan.jenisPapan, game.papan.kotak);
            tampilWinorDraw(game.pemain1.namaPlayer, game.pemain2.namaPlayer, game.pemenang, game.giliran, game.papan.jenisPapan);
            do{
                setelahCekMenang(game, &halaman, &maingame, &kondisiSetelahMenang, &kondisiGantiGiliran, &game.kondisiInisialisasi);
            }while(kondisiSetelahMenang == true );

            resetAtributPlayGame(&game.pemenang, &game.giliran, &game.papan.kotak);
        }

    }while(kondisiHalaman == true);



    return 0;
}