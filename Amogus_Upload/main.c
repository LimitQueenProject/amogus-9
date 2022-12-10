#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#include "header.h"

int main()
{
    // Deklarasi Variabel
    // 1. Deklarasi Variabel Komponen Penyusun Game
    Game game;

    #define menu 0
    #define newgame 1
    #define _1player 1
    #define _2player 2
    #define pilihpapan 11
    #define papan3x3 3
    #define papan5x5 5
    #define papan7x7 7
    #define pilihpertama 111
    #define player1_pertama 1
    #define player2_pertama 2
    #define loadgame 2
    #define highscore 3
    #define howtoplay 4
    #define aboutus 5
    #define keluar -1

    bool kondisiHalaman = true;
    int halaman = 0;
    int pilihan = 0;
    bool maingame = false;
    bool kondisiInisialisasi = false;
    bool kondisiLoadgame = false;
    bool kondisiSetelahMenang = false;
    bool kondisiGantiGiliran = true;
    int pemenang;

    // Algoritma
    // 1. Pengaturan ukuran console dengan lebar 1000 dan tinggi 600 {source: https://www.codeincodeblock.com/2011/03/move-console-windows-using-codeblock.html}
    HWND hWnd = GetConsoleWindowNT();
    MoveWindow(hWnd, 180, 50, 1000, 600, TRUE);

    // 2. Menampilkan Loading Game Agar Keren
    loading();

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
                        kondisiLoadgame = false;
                    }
                }
                else if ( pilihan == highscore ){
                    highScore();
                }
                else if ( pilihan == howtoplay ){
                    tampilanHowToPlay();
                }
                else if ( pilihan == aboutus ){
                    tampilanAboutUs();
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
                inisialisasi(&game, &pemenang);
            }
            if ( kondisiGantiGiliran == true ){
                pilihHalaman(pilihpertama, &game.pilihPertama); 
                kondisiGantiGiliran = false;
            }
            
            playgame(&game, &pemenang);
            do{
                tampilWinorDraw(game.pemain1.namaPlayer, game.pemain2.namaPlayer, pemenang, game.giliran, game.papan.jenisPapan);
                setelahCekMenang(game, &pemenang, &halaman, &maingame, &kondisiSetelahMenang, &kondisiGantiGiliran, &game.kondisiInisialisasi);
            }while(kondisiSetelahMenang == true );

            resetAtributPlayGame(&pemenang, &game.giliran, &game.papan.kotak);
        }

    }while(kondisiHalaman == true);



    return 0;
}