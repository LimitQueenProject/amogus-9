#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "header.h"

void gantiGiliran(int *_giliran, int *_pilihPertama)
{
    *_giliran = *_giliran + 1;
    if (*_giliran % 2 == 0)
    {
        *_pilihPertama = 2;
    }
    else if (*_giliran % 2 == 1)
    {
        *_pilihPertama = 1;
    }
}

void resetAtributPlayGame(int *_pemenang, int *_giliran, int *_pilihPertama, char (*_papan)[7][7], bool *_kondisiPemenang)
{
    *_pemenang = 0;
    *_giliran = 1;
    *_pilihPertama = 1;
    *_kondisiPemenang = false;
    strcpy((*_papan)[0], "       ");
    strcpy((*_papan)[1], "       ");
    strcpy((*_papan)[2], "       ");
    strcpy((*_papan)[3], "       ");
    strcpy((*_papan)[4], "       ");
    strcpy((*_papan)[5], "       ");
    strcpy((*_papan)[6], "       ");
}

void setelahCekMenang(Game _game, bool *_kondisiGame, bool *_kondisiPemenang, bool *_kondisiPilihGiliranPertama, bool *_kondisiPilihanPapan, bool *_kondisiPilihanPlayer, bool *_kondisiAfterGame)
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
        *_kondisiGame = true;
        *_kondisiPilihGiliranPertama == false;
        *_kondisiAfterGame = false;
    }
    // swap turn
    else if (pany == 9)
    {
        *_kondisiPilihGiliranPertama == true;
        *_kondisiGame = false;
        *_kondisiAfterGame = false;
    }
    // save
    else if (pany == 11)
    {
        koor(panx,pany);
        printf("   ");
        saveData(_game);
        koor(50,29);printf("your data has been saved!");
        sleep(2);
        koor(50,29);printf("                         ");
        *_kondisiAfterGame = true;
    }
    // menu
    else if (pany == 13)
    {
        *_kondisiGame = false;
        *_kondisiPemenang = false;
        *_kondisiPilihanPapan = false;
        *_kondisiPilihanPlayer = false;
        *_kondisiAfterGame = false;
    }
    // back
    else if (pany == 15)
    {
        *_kondisiPemenang = false;
        *_kondisiGame = false;
        *_kondisiPilihanPapan = true;
        *_kondisiAfterGame = false;
    }
}




void cekKondisiPemenang(int _flag, char _papan[7][7], int *_pemenang, bool *_kondisiPemenang, int _giliran, int *_score1, int *_score2)
{
    // ATRIBUT PLAYER 1
    int vertikal1 = 0;
    int horizontal1 = 0;
    int diagonal11 = 0;
    int diagonal12 = 0;

    // ATRIBUT PLAYER 2
    int vertikal2 = 0;
    int horizontal2 = 0;
    int diagonal21 = 0;
    int diagonal22 = 0;

    // 1. CEK KONDISI MENANG PLAYER 1 VERTIKAL DAN HORIZONTAL
    for (int i = 0; i < _flag; i++)
    {
        for (int j = 0; j < _flag; j++)
        {

            if (_papan[j][i] == 'X')
            {
                vertikal1++; // kondisi menang vertikal player 1
            }
            if (_papan[i][j] == 'X')
            {
                horizontal1++; // kondisi menang vertikal player 1
            }
        }
        if (vertikal1 == _flag)
        {
            break;
        }
        if (horizontal1 == _flag)
        {
            break;
        }
        vertikal1 = 0;
        horizontal1 = 0;
    }
    // 2. CEK KONDISI MENANG PLAYER 1 DIAGONAL
    int k1 = 0;
    int l1 = _flag - 1;
    while (k1 < _flag && l1 >= 0)
    {
        if (_papan[k1][l1] == 'X')
        {
            diagonal11++; // kondisi menang diagonal 1 player 1
        }
        if (_papan[k1][k1] == 'X')
        {
            diagonal12++; // kondisi menang diagonal 2 player 1
        }
        k1++;
        l1--;
    }

    // 3. CEK KONDISI MENANG PLAYER 2 VERTIKAL DAN HORIZONTAL
    for (int i = 0; i < _flag; i++)
    {
        for (int j = 0; j < _flag; j++)
        {

            if (_papan[j][i] == 'O')
            {
                vertikal2++; // kondisi menang vertikal player 1
            }
            if (_papan[i][j] == 'O')
            {
                horizontal2++; // kondisi menang vertikal player 1
            }
        }
        if (vertikal2 == _flag)
        {
            break;
        }
        if (horizontal2 == _flag)
        {
            break;
        }
        vertikal2 = 0;
        horizontal2 = 0;
    }

    // 4. CEK KONDISI MENANG PLAYER 2 DIAGONAL
    int k2 = 0;
    int l2 = _flag - 1;
    while (k2 < _flag && l2 >= 0)
    {
        if (_papan[k2][l2] == 'O')
        {
            diagonal21++; // kondisi menang diagonal 1 player 1
        }
        if (_papan[k2][k2] == 'O')
        {
            diagonal22++; // kondisi menang diagonal 2 player 1
        }
        k2++;
        l2--;
    }

    // 5. EVALUASI HASIL PENGECEKAN
    if (_giliran >= (_flag * _flag))
    {
        *_pemenang = 3;
        *_kondisiPemenang = true;
        *_score1 = *_score1 + 1;
        *_score2 = *_score2 + 1;
    }
    else if (vertikal1 == _flag || horizontal1 == _flag || diagonal11 == _flag || diagonal12 == _flag)
    {
        *_pemenang = 1;
        *_score1 = *_score1 + 2;
        *_kondisiPemenang = true;
        if(*_score2!=0)
        {
        *_score2 = *_score2 - 1;
        }
    }
    else if (vertikal2 == _flag || horizontal2 == _flag || diagonal21 == _flag || diagonal22 == _flag)
    {
        *_pemenang = 2;
        *_score2 = *_score2 + 2;
        *_kondisiPemenang = true;
        if(*_score1!=0)
        {
        *_score1 = *_score1 - 1;
        }
    }
}



void markIndex(int _giliran, int _pilihPertama, char (*_papanKotak)[7][7], int _baris, int _kolom)
{
    if (_pilihPertama == 1)
    {
        if (_giliran % 2 == 1)
            (*_papanKotak)[_baris][_kolom] = 'X';
        else if (_giliran % 2 == 0)
            (*_papanKotak)[_baris][_kolom] = 'O';
    }
    else if (_pilihPertama == 2)
    {
        if (_giliran % 2 == 0)
            (*_papanKotak)[_baris][_kolom] = 'O';
        else if (_giliran % 2 == 1)
            (*_papanKotak)[_baris][_kolom] = 'X';
    }
}
