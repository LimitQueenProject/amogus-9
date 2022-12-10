// #include <stdio.h>
// #include <windows.h>
// #include <stdbool.h>

// #include "header.h"

// int main()
// {
//     // Deklarasi Variabel
//     // 1. Deklarasi Variabel Komponen Penyusun Game
//     Game game;
//     // 0
//     const int menu = 0;
//     // 1
//     const int newgame = 1;
//     // 1.1
//     const int _1player = 1;
//     // 1.2
//     const int _2player = 2;
//     // 1.3
//     const int pilihpapan = 11;
//     // 1.3.1
//     const int papan3x3 = 3;
//     // 1.3.2
//     const int papan5x5 = 5;
//     // 1.3.3
//     const int papan7x7 = 7;

//     // 1.4
//     const int pilihpertama = 111;
//     // 1.4.1
//     const int player1_pertama = 1;
//     // 1.4.2
//     const int player2_pertama = 2;


//     // 2
//     const int loadgame = 2;
//     // 3
//     const int highscore = 3;
//     // 4
//     const int howtoplay = 4;
//     // 5
//     const int aboutus = 5;
//     // -1
//     const int keluar = -1;


    
//     // 2. Deklarasi Variabel Kondisi-Kondisi Halaman
//     bool kondisiHalaman = true;
//     int halaman = 0;
//     int pilihan = 0;
//     bool maingame = false;


//     // Algoritma
//     // 1. Pengaturan ukuran console dengan lebar 1000 dan tinggi 600 {source: https://www.codeincodeblock.com/2011/03/move-console-windows-using-codeblock.html}
//     HWND hWnd = GetConsoleWindowNT();
//     MoveWindow(hWnd, 180, 50, 1000, 600, TRUE);

//     // 2. Menampilkan Loading Game Agar Keren
//     loading();

//     do{
        
//         switch (halaman){
            
//             case menu:
//                 pilihHalaman(menu, &pilihan);
//                 if ( pilihan == newgame ){
//                     halaman = newgame;
//                 }
//                 else if ( pilihan == loadgame ){
//                     halaman = loadgame;
//                 }
//                 else if ( pilihan == highscore ){
//                     halaman = highscore;
//                 }
//                 else if ( pilihan == howtoplay ){
//                     halaman = howtoplay;
//                 }
//                 else if ( pilihan == aboutus ){
//                     halaman = aboutus;
//                 }
//                 else if ( pilihan == keluar ){
//                     kondisiHalaman = false;
//                 }
//             break;

//             case newgame:
//                 // PILIH JENIS PLAYER
//                 pilihHalaman(newgame, &pilihan);
//                 if( pilihan == _1player ){
//                     game.jenisPermainanPlayer = _1player;
//                     halaman = pilihpapan;
//                 }
//                 else if( pilihan == _2player ){
//                     game.jenisPermainanPlayer = _2player;
//                     halaman = pilihpapan;
//                 }
//                 else if( pilihan == keluar ){
//                     halaman = menu;
//                 }
//             break;

//             case pilihpapan:
//                 // PILIH JENIS PAPAN
//                 pilihHalaman(pilihpapan, &pilihan);
//                 if ( pilihan == papan3x3 ){
//                     game.papan.jenisPapan = papan3x3;
//                     halaman = pilihpertama;
//                 }
//                 else if ( pilihan == papan5x5 ){
//                     game.papan.jenisPapan = papan5x5;
//                     halaman = pilihpertama;
//                 }
//                 else if ( pilihan == papan7x7 ){
//                     game.papan.jenisPapan = papan7x7;
//                     halaman = pilihpertama;
//                 }
//                 else if ( pilihan == keluar ){
//                     halaman = newgame;
//                 }
//             break;
            
//             case pilihpertama:
//                 // PILIH JENIS PAPAN
//                 pilihHalaman(pilihpertama, &pilihan);
//                 if ( pilihan == papan3x3 ){
//                     game.papan.jenisPapan = papan3x3;
//                     maingame = true;
//                 }
//                 else if ( pilihan == papan5x5 ){
//                     game.papan.jenisPapan = papan5x5;
//                     maingame = true;
//                 }
//                 else if ( pilihan == papan7x7 ){
//                     game.papan.jenisPapan = papan7x7;
//                     maingame = true;
//                 }
//             break;
//         }
        
//         while( maingame == true ){
//             // modul isi nama
//             // playgame(&game);
//         }
//     }while(kondisiHalaman == true);



//     return 0;
// }

// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <windows.h>
// // #include <string.h>
// // #include <stdbool.h>

// // #include "header.h"

// // int main()
// // {
// //     Game game;

// //     // DEKLARASI HALAMAN
// //     int pilihanMenu;
// //     int pilihanPlayer;
// //     int pilihanPapan;

// //     bool kondisiPilihanMenu = true;
// //     bool kondisiPilihanPlayer = true;
// //     bool kondisiPilihanPapan = true;
// //     bool kondisiAfterGame = true;



// //     HWND hWnd = GetConsoleWindowNT();
// //     MoveWindow(hWnd, 180, 50, 1000, 600, TRUE);

// //     loading();
// //     menu:
// //     if ( kondisiPilihanMenu )
// //     {
// //         pilihHalaman(0, &pilihanMenu);
// //         kondisiPilihanMenu = false;
// //         goto menu;
// //     }
// //     else if ( kondisiPilihanPlayer )
// //     {
// //         pilihHalaman(1, &game.jenisPermainanPlayer);
// //         kondisiPilihanPlayer = false;
// //         goto menu;
// //     }
// //     else if ( kondisiPilihanPapan )
// //     {
// //         pilihHalaman(11, &game.papan.jenisPapan);
// //         kondisiPilihanPapan = false;
// //     }

// //     playgame( &game, &kondisiPilihanPapan, &kondisiPilihanPlayer, &kondisiAfterGame, game.jenisPermainanPlayer);

// //     return 0;
// // }