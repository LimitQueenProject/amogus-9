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
    // Pengaturan ukuran console dengan lebar 1000 dan tinggi 600 
    HWND hWnd = GetConsoleWindowNT();
    MoveWindow(hWnd, 180, 50, 1000, 600, TRUE);

    // Menampilkan Loading Game 
    loading();

    do{
        // Cek halaman apa
        switch (halaman){
            // Halaman Menu
            case menu:
                // Pilih halaman
                pilihHalaman(menu, &pilihan);

                // Jika pilih new game
                if ( pilihan == newgame ){
                    halaman = newgame;
                }
                
                // Jika pilih load game
                else if ( pilihan == loadgame ){
                    loadGame( &game, &kondisiLoadgame );
                    if ( kondisiLoadgame == true ){
                        maingame = true;
                        game.kondisiInisialisasi = false;
                        kondisiLoadgame = false;
                    }
                }
                
                // Jika pilih highscore
                else if ( pilihan == highscore ){
                    highScore();
                }
                
                // Jika pilih How to Play
                else if ( pilihan == howtoplay ){
                    tampilanHowToPlay();
                }
                
                // Jika pilih About Us
                else if ( pilihan == aboutus ){
                    tampilanAboutUs();
                }
                
                // Jika pilih Exit
                else if ( pilihan == keluar ){
                    kondisiHalaman = false;
                }
            break;

            // Pilih berapa player
            case newgame:
                // PILIH JENIS PLAYER
                pilihHalaman(newgame, &pilihan);
                
                // Jika pilih 1 player
                if( pilihan == _1player ){
                    game.jenisPermainanPlayer = _1player;
                    halaman = pilihpapan;
                }
                
                // Jika pilih 2 player
                else if( pilihan == _2player ){
                    game.jenisPermainanPlayer = _2player;
                    halaman = pilihpapan;
                }
                
                // Jika pilih kembali ke halaman menu
                else if( pilihan == keluar ){
                    halaman = menu;
                }
            break;

            //  Pilih papan
            case pilihpapan:
                // PILIH JENIS PAPAN
                pilihHalaman(pilihpapan, &pilihan);
                
                // Jika pilih papan 3x3
                if ( pilihan == papan3x3 ){
                    game.papan.jenisPapan = papan3x3;
                    maingame = true;
                }

                // Jika pilih papan 5x5
                else if ( pilihan == papan5x5 ){
                    game.papan.jenisPapan = papan5x5;
                    maingame = true;
                }

                // Jika pilih papan 7x7
                else if ( pilihan == papan7x7 ){
                    game.papan.jenisPapan = papan7x7;
                    maingame = true;
                }

                // Jika pilih kembali ke pilih berapa pemain
                else if ( pilihan == keluar ){
                    halaman = newgame;
                }
            break;
        }
        
        
        // Permainan 
        while( maingame == true ){
            // Inisialisasi sebelum bermain (dipakai sekali diawal game)
            if ( game.kondisiInisialisasi == true ){
                inisialisasi(&game, &pemenang);
            }

            // Jika opsi ganti giliran aktif
            if ( kondisiGantiGiliran == true ){
                pilihHalaman(pilihpertama, &game.pilihPertama); 
                kondisiGantiGiliran = false;
            }
            
            // Permainan dimulai
            playGame(&game, &pemenang);
            // Permainan selesai

            // Menampilkan ucapan selamat kepada pemenang atau draw
            tampilWinorDraw(game.pemain1.namaPlayer, game.pemain2.namaPlayer, pemenang, game.giliran, game.papan.jenisPapan);
            
            // Menu setelah bermain
            do{
                setelahCekMenang(game, &pemenang, &halaman, &maingame, &kondisiSetelahMenang, &kondisiGantiGiliran, &game.kondisiInisialisasi);
            }while(kondisiSetelahMenang == true );

            // Mereset seluruh atribut permainan sebelumnya
            resetAtributPlayGame(&pemenang, &game.giliran, &game.papan.kotak);
        }

    }while(kondisiHalaman == true);



    return 0;
}