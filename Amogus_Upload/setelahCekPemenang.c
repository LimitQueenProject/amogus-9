#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "header.h"


// void setelahCekMenang(Game _game, bool *_kondisiGame, bool *_kondisiPemenang, bool *_kondisiPilihGiliranPertama, bool *_kondisiPilihanPapan, bool *_kondisiPilihanPlayer, bool *_kondisiAfterGame)
void setelahCekMenang(Game _game, int *_halaman, bool *_maingame, bool *_kondisiSetelahMenang, bool *_kondisiGantiGiliran, bool *_kondisiInisialisasi)
{
    int button;
    int panx = 89;
    int pany = 7;
    tampilSetelahBermain();
    do
    {
        koor(panx, pany);
        printPanah(panx, pany);
        button = getch();
        if (button == down || button == s || button == S)
        {
            switch (pany)
            {
            case 7:
                pany = 9;
                koor(panx, 7);
                printf("   ");
                break;
            case 9:
                pany = 11;
                koor(panx, 9);
                printf("   ");
                break;
            case 11:
                pany = 13;
                koor(panx, 11);
                printf("   ");
                break;
            case 13:
                pany = 15;
                koor(panx, 13);
                printf("   ");
                break;
            case 15:
                pany = 7;
                koor(panx, 15);
                printf("   ");
                break;
            }
        }
        else if (button == up || button == w || button == W)
        {
            switch (pany)
            {
            case 7:
                pany = 15;
                koor(panx, 7);
                printf("   ");
                break;
            case 9:
                pany = 7;
                koor(panx, 9);
                printf("   ");
                break;
            case 11:
                pany = 9;
                koor(panx, 11);
                printf("   ");
                break;
            case 13:
                pany = 11;
                koor(panx, 13);
                printf("   ");
                break;
            case 15:
                pany = 13;
                koor(panx, 15);
                printf("   ");
                break;
            }
        }
    } while (button != 13);
    // play again
    if (pany == 7)
    {
        *_maingame = true;
        *_kondisiSetelahMenang = false;
    }
    // ganti papan
    else if (pany == 9)
    {
        *_maingame = false;
        *_halaman = 11;
        *_kondisiSetelahMenang = false;
    }
    // save
    else if (pany == 11)
    {
        resetAtributPlayGame(&_game.pemenang, &_game.giliran, &_game.papan.kotak);
        saveData(_game);
        *_kondisiSetelahMenang = true;
    }
    // menu
    else if (pany == 13)
    {
        *_maingame = false;
        *_halaman = 0;
        *_kondisiSetelahMenang = false;
        *_kondisiInisialisasi = true;
    }
    // ganti giliran
    else if (pany == 15)
    {
        *_kondisiGantiGiliran = true;
    }
}
