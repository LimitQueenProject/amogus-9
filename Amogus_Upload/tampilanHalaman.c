#include <stdio.h>
#include <unistd.h>
#include <windows.h>

#include "header.h"



void tampilanMenu()
{
    // 1. Bersihkan Layar
    system("cls");

    // 2. Tampilkan Banner 2
    banner2();
    
    // 3. PRINT Pilihan Menu
    koor(59,13); printf("%c%c%c%c%c%c%c%c",218, 196, 196, 196, 196, 196, 196, 191);        
    koor(59,14); printf("%c MENU %c",179, 179 );                                
    koor(59,15); printf("%c%c%c%c%c%c%c%c",192, 196, 196, 196, 196, 196, 196, 217);                
    koor(55,17); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);       
    koor(55,18); printf("%c   New Game   %c", 179, 179);
    koor(55,19); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180);            
    koor(55,20); printf("%c  Load Game   %c", 179, 179);
    koor(55,21); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180);            
    koor(55,22); printf("%c  Highscore   %c", 179, 179);
    koor(55,23); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180);
    koor(55,24); printf("%c  How to Play %c", 179, 179);
    koor(55,25); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180);
    koor(55,26); printf("%c   About Us   %c", 179, 179);
    koor(55,27); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180);
    koor(55,28); printf("%c     Exit     %c", 179, 179);
    koor(55,29); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    
}

void tampilanPlayer()
{
    // 1. Bersihkan Layar
    system("cls");

    // 2. Tampilkan Banner 2
    banner2();

    // 3. PRINT Pilihan Player
    koor(54,13);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    koor(54,14);printf("%c               %c",179,179);
    koor(54,15);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    koor(52,17);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    koor(52,18);printf("%c                   %c",179,179);
    koor(52,19);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,180);
    koor(52,20);printf("%c                   %c",179,179);
    koor(52,21);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,180);
    koor(52,22);printf("%c                   %c",179,179);
    koor(52,23);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    koor(56,14);
    printf("CHOOSE PLAYER");
    koor(58,18);
    printf("1 Player");
    koor(58,20);
    printf("2 Player");
    koor(60,22);
    printf("Back");
}

void tampilanBoard()
{
    // 1. Bersihkan Layar
    system("cls");

    // 2. Tampilkan Banner 2
    banner2();

    // 3. PRINT PILIHAN PAPAN
    koor(56,13); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,191);
    koor(56,14); printf("%c           %c",179,179);
    koor(56,15); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,217);
    koor(52,17); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    koor(52,18); printf("%c                   %c",179,179);
    koor(52,19); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,180);
    koor(52,20); printf("%c                   %c",179,179);
    koor(52,21); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,180);
    koor(52,22); printf("%c                   %c",179,179);
    koor(52,23); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,180);
    koor(52,24); printf("%c                   %c",179,179);
    koor(52,25); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    koor(60,14); printf("BOARD");
    koor(61,18); printf("3x3");
    koor(61,20); printf("5x5");
    koor(61,22); printf("7x7");
    koor(60,24); printf("Back");
}

void tampilanHowToPlay()
{
    int button;
    // 1. Bersihkan Layar
    system("cls");

    // 2. Tampilkan Banner 2
    banner2();

    // 3. PRINT Tampilan Cara Bermain
    koor(52,12); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);            
    koor(52,13); printf("%c How to Play  %c", 179, 179);
    koor(52,14); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);

    koor(27,16); printf("1. The game starts using board sizes, namely 3x3, 5x5, and 7x7");
    koor(27,17); printf("2. There are 2 players who can play, which can be against fellow players");
    koor(30,18); printf("or against the computer");
    koor(27,19); printf("3. Player 1 uses the X mark and player 2 uses the O mark");
    koor(27,20); printf("4. Choose a box to be filled in by the player, provided that");
    koor(30,21); printf("the player cannot choose a box that has already been selected");
    koor(27,22); printf("5. The first player to succeed in making a line with his mark");
    koor(30,23); printf("be it horizontal, vertical or diagonal then declared the winner");
    koor(27,24); printf("6. If none of the players succeed in making a line, then the ");
    koor(30,25); printf("game is considered a draw");
    
    koor(2,33);  printf("press any key to back...");
	button = getch();
}

void tampilanAboutUs()
{
    int button;
    // 1. Bersihkan Layar
    system("cls");

    // 2. Tampilkan Banner 2
    banner2();

    // 3. PRINT Tampilan Tentang Kami
    koor(52,12); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    koor(52,13); printf("%c   About Us   %c", 179, 179);
    koor(52,14); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);

    koor(46,16); printf("1. Farhan Muhammad yasin");
    koor(49,17); printf("NIM = 221524008");
    koor(49,18); printf("Instagram = @f._.myers");
    koor(46,20); printf("2. Muhammad Azharuddin Hamid");
    koor(49,21); printf("NIM = 221524018");
    koor(49,22); printf("Instagram = @muhammadazhar9_");
    koor(46,24); printf("3. Roy Aziz Barera");
    koor(49,25); printf("NIM = 221524030");
    koor(49,26); printf("Instagram = @royazizbarera_");
    koor(41,28); printf("Institusi = Polikteknik Negeri Bandung");
    
    koor(2,33);  printf("press any key to back...");
	button = getch();
}

void tampilanPilihPertama ()
{
    // 1. Bersihkan Layar
    system("cls");

    // 2. Tampilkan Banner 2
    banner2();

    // 3. PRINT Tampilan Siapa yang Bermain Pertama
    koor(47,12); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    koor(47,13); printf("%c SIAPA YANG BERMAIN PERTAMA %c",179,179);
    koor(47,14); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    
    koor(52,16); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    koor(52,17); printf("%c                   %c",179,179);
    koor(52,18); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,180);
    koor(52,19); printf("%c                   %c",179,179);
    koor(52,20); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    koor(58,17); printf("Player 1");
    koor(58,19); printf("Player 2");
}

void tampilSetelahBermain()
{
	koor(94,7);  printf("Play Again");
	koor(94,9);  printf("Choose Board");
	koor(94,11); printf("Save");
	koor(94,13); printf("Back to Menu");
	koor(94,15); printf("Ganti Giliran");
}


void tampilWinorDraw(char _namaPlayer1[100], char _namaPlayer2[100], int _pemenang, int _giliran, int _jenisPapan)
{
    //kondisi menang
    if (_pemenang == 1 || _pemenang == 2){
        koor(10,11); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201, 205, 187, 201, 205, 187, 201, 187, 201, 201, 205, 187, 203, 205, 187, 201, 205, 187, 201, 203, 187, 201, 205, 187);
        koor(10,12); printf("%c  %c %c%c%c%c%c %c%c%c%c%c%c%c %c %c%c%c", 186, 186, 186, 186, 186, 186, 186, 203, 204, 203, 188, 204, 205, 185, 186, 200, 205, 187);
        koor(10,13); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c %c %c%c%c",  200, 205, 188, 200, 205, 188, 200, 200, 188, 200, 205, 188, 202, 200, 205, 202, 202, 202, 200, 205, 188);
        //kondisi jika player 1 menang
        if (_pemenang == 1){
            koor(20,15); printf("%s !!!", _namaPlayer1);
        //kondisi jika player 2 menang
        }else if (_pemenang == 2){
            koor(20,15); printf("%s !!!", _namaPlayer2);
        }
    }
    //kondisi draw atau seri
    else {
        koor(15,11); printf("%c%c%c%c%c%c%c%c%c%c %c", 201, 203, 187, 203, 205, 187, 201, 205, 187, 203, 203);
        koor(15,12); printf(" %c%c%c%c%c%c%c%c%c%c%c", 186, 186, 204, 203, 188, 204, 205, 185, 186, 186, 186);
        koor(15,13); printf("%c%c%c%c%c%c%c %c%c%c%c", 205, 202, 188, 202, 200, 205, 202, 202, 200, 202, 188);
        koor(15,15); printf("%s VS %s", _namaPlayer1, _namaPlayer2);
        }
}


void inputNama( int _jenisPermainanPlayer, char (*_namaPlayer1)[20], char (*_namaPlayer2)[20])
{
    int valid = 0;
    // Nama Player
    if ( _jenisPermainanPlayer == 1 )
    {
        do{
            // Bersihkan Layar
            system("cls");

            // Tampilkan Banner 2
            banner2();

            koor(45,17); printf("Masukan nama anda : ");
            scanNama(&*_namaPlayer1);
            if ( strlen(*_namaPlayer1) <= 20 ){
                valid = 1;
            }
            else{
                koor(43,19); printf("Nama anda terlalu panjang silahkan input ulang");
                sleep(2);
            }
        }while(valid == 0);
        strcpy(*_namaPlayer2, "Computer");
    }
    else if ( _jenisPermainanPlayer == 2 )
    {
        do{
            // Bersihkan Layar
            system("cls");

            // Tampilkan Banner 2
            banner2();

            koor(45,17); printf("Masukan nama player 1 : ");
            scanNama(&*_namaPlayer1);
            if ( strlen(*_namaPlayer1) <= 20 ){
                valid = 1;
            }
            else{
                koor(43,19); printf("Nama anda terlalu panjang silahkan input ulang\n");
                sleep(2);
            }
        }while(valid == 0);
        valid = 0;
        
        do{
            // Bersihkan Layar
            system("cls");

            // Tampilkan Banner 2
            banner2();
            
            koor(45,17); printf("Masukan nama player 2 : ");
            scanNama(&*_namaPlayer2);
            if ( strlen(*_namaPlayer2) <= 20 ){
                valid = 1;
            }
            else{
                koor(43,17); printf("Nama anda terlalu panjang silahkan input ulang\n");
                sleep(2);
            }
        }while(valid == 0);
    }
}

void scanNama( char (*_namaPlayer)[20])
{
 scanf(" %[^\n]", (*_namaPlayer));
}
