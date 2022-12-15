#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

#include "header.h"


void pilihIndexKomputer( int _jenisPapan, int *_baris, int *_kolom, char _papan[7][7] )
{
    int randomBaris;
    int randomKolom;
    bool validIndex = false ;

    do{
        // BUAT BIBIT ANGKA
        srand(time(0));
        // RANDOM BARIS DAN KOLOM
        randomBaris = rand() % _jenisPapan;
        randomKolom = rand() % _jenisPapan;
        // CEK KEVALIDAN INDEX 
        if ( _papan[randomBaris][randomKolom] == ' ' )
        {
            validIndex = true;
            *_baris = randomBaris;
            *_kolom = randomKolom;
        }
    }while(validIndex == false);
}




void pilihIndexPapan(int _flagIndex, int _jenisPapan, int _giliran, int _pilihPertama, char _papan[7][7], int *_baris, int *_kolom, bool *_valid)
{
    int count=0;
    const float detik = 10;
    time_t start, end;
    float waktu;
    start = time(NULL);
    *_valid=true;
    if (_flagIndex == 1)
    {
        if ( (_pilihPertama == 2 && _giliran % 2 == 1) || (_pilihPertama == 1 && _giliran % 2 == 0) )
        {
            int baris = *_baris;
            int kolom = *_kolom;
            // pilihIndexKomputer(_jenisPapan, &baris, &kolom, _papan);
            medium(_jenisPapan, &baris, &kolom, _papan);
            *_baris = baris;
            *_kolom = kolom;
        }
        else// if (_pilihPertama == 1)
        {
            int button=0;
            int panx;
            int pany;
            int cekValid = 0;
            if (_jenisPapan == 3)
            {
                koor(panx - 1, pany);
                printf(" ");
                panx = 54;
                pany = 7;
                do
                {
                        do
                        {
                            end = time(NULL);
                            waktu = end - start;
                            if(count%6000==0)
                            {
                                koor(61,2);printf("  ");
                                koor(61,2);printf("%.f",detik-waktu);
                            }
                            if(button!=0)
                            {
                                koor(panx, pany);
                                printf("1");
                                button=0;
                            }
                            if(button==0)
                            {
                                koor(0,0);
                            }
                            if(kbhit())
                            {
                            button = getch();
                            }
                            if (button == up || button == w || button == W)
                            {
                                switch (pany)
                                {
                                case 7:
                                    pany = 15;
                                    koor(panx, 7);
                                    printf(" ");
                                    break;
                                case 11:
                                    pany = 7;
                                    koor(panx, 11);
                                    printf(" ");
                                    break;
                                case 15:
                                    pany = 11;
                                    koor(panx, 15);
                                    printf(" ");
                                    break;
                                }
                            }
                            else if (button == down || button == s || button == S)
                            {
                                switch (pany)
                                {
                                case 7:
                                    pany = 11;
                                    koor(panx, 7);
                                    printf(" ");
                                    break;
                                case 11:
                                    pany = 15;
                                    koor(panx, 11);
                                    printf(" ");
                                    break;
                                case 15:
                                    pany = 7;
                                    koor(panx, 15);
                                    printf(" ");
                                    break;
                                }
                            }
                            else if (button == left || button == a || button == A)
                            {
                                switch (panx)
                                {
                                case 54:
                                    panx = 66;
                                    koor(54, pany);
                                    printf(" ");
                                    break;
                                case 60:
                                    panx = 54;
                                    koor(60, pany);
                                    printf(" ");
                                    break;
                                case 66:
                                    panx = 60;
                                    koor(66, pany);
                                    printf(" ");
                                    break;
                                }
                            }
                            else if (button == right || button == d || button == D)
                            {
                                switch (panx)
                                {
                                case 54:
                                    panx = 60;
                                    koor(54, pany);
                                    printf(" ");
                                    break;
                                case 60:
                                    panx = 66;
                                    koor(60, pany);
                                    printf(" ");
                                    break;
                                case 66:
                                    panx = 54;
                                    koor(66, pany);
                                    printf(" ");
                                    break;
                                }
                            }  
                            count++;  
                            sleep(0.1);
                            if(waktu==10)
                            {
                                *_valid=false;
                            }
                        } while (button != 13 && *_valid==true);

                            if (panx == 54 && pany == 7)
                            {
                                *_baris = 0;
                                *_kolom = 0;
                            }
                            else if (panx == 60 && pany == 7)
                            {
                                *_baris = 0;
                                *_kolom = 1;
                            }
                            else if (panx == 66 && pany == 7)
                            {
                                *_baris = 0;
                                *_kolom = 2;
                            }
                            else if (panx == 54 && pany == 11)
                            {
                                *_baris = 1;
                                *_kolom = 0;
                            }
                            else if (panx == 60 && pany == 11)
                            {
                                *_baris = 1;
                                *_kolom = 1;
                            }
                            else if (panx == 66 && pany == 11)
                            {
                                *_baris = 1;
                                *_kolom = 2;
                            }
                            else if (panx == 54 && pany == 15)
                            {
                                *_baris = 2;
                                *_kolom = 0;
                            }
                            else if (panx == 60 && pany == 15)
                            {
                                *_baris = 2;
                                *_kolom = 1;
                            }
                            else if (panx == 66 && pany == 15)
                            {
                                *_baris = 2;
                                *_kolom = 2;
                            }
                            if (_papan[*_baris][*_kolom] == ' ')
                            {
                                cekValid = 1;
                            }
                } while (cekValid == 0 && *_valid==true);
            }

            else if (_jenisPapan == 5)
            {
                koor(panx - 1, pany);
                printf(" ");
                panx = 48;
                pany = 7;
                do
                {
                    do
                    {
                        end = time(NULL);
                            waktu = end - start;
                            if(count%6000==0)
                            {
                                koor(61,2);printf("  ");
                                koor(61,2);printf("%.f",detik-waktu);
                            }
                            if(button!=0)
                            {
                                koor(panx, pany);
                                printf("1");
                                button=0;
                            }
                            if(button==0)
                            {
                                koor(0,0);
                            }
                            if(kbhit())
                            {
                            button = getch();
                            }
                        if (button == up || button == w || button == W)
                        {
                            switch (pany)
                            {
                            case 7:
                                pany = 23;
                                koor(panx, 7);
                                printf(" ");
                                break;
                            case 11:
                                pany = 7;
                                koor(panx, 11);
                                printf(" ");
                                break;
                            case 15:
                                pany = 11;
                                koor(panx, 15);
                                printf(" ");
                                break;
                            case 19:
                                pany = 15;
                                koor(panx, 19);
                                printf(" ");
                                break;
                            case 23:
                                pany = 19;
                                koor(panx, 23);
                                printf(" ");
                                break;
                            }
                        }
                        else if (button == down || button == s || button == S)
                        {
                            switch (pany)
                            {
                            case 7:
                                pany = 11;
                                koor(panx, 7);
                                printf(" ");
                                break;
                            case 11:
                                pany = 15;
                                koor(panx, 11);
                                printf(" ");
                                break;
                            case 15:
                                pany = 19;
                                koor(panx, 15);
                                printf(" ");
                                break;
                            case 19:
                                pany = 23;
                                koor(panx, 19);
                                printf(" ");
                                break;
                            case 23:
                                pany = 7;
                                koor(panx, 23);
                                printf(" ");
                                break;
                            }
                        }
                        else if (button == left || button == a || button == A)
                        {
                            switch (panx)
                            {
                            case 48:
                                panx = 72;
                                koor(48, pany);
                                printf(" ");
                                break;
                            case 54:
                                panx = 48;
                                koor(54, pany);
                                printf(" ");
                                break;
                            case 60:
                                panx = 54;
                                koor(60, pany);
                                printf(" ");
                                break;
                            case 66:
                                panx = 60;
                                koor(66, pany);
                                printf(" ");
                                break;
                            case 72:
                                panx = 66;
                                koor(72, pany);
                                printf(" ");
                                break;
                            }
                        }
                        else if (button == right || button == d || button == D)
                        {
                            switch (panx)
                            {
                            case 48:
                                panx = 54;
                                koor(48, pany);
                                printf(" ");
                                break;
                            case 54:
                                panx = 60;
                                koor(54, pany);
                                printf(" ");
                                break;
                            case 60:
                                panx = 66;
                                koor(60, pany);
                                printf(" ");
                                break;
                            case 66:
                                panx = 72;
                                koor(66, pany);
                                printf(" ");
                                break;
                            case 72:
                                panx = 48;
                                koor(72, pany);
                                printf(" ");
                                break;
                            }
                        }
                        count++;  
                        sleep(0.1);
                        if(waktu==10)
                        {
                            *_valid=false;
                        }
                        } while (button != 13 && *_valid==true);
                    // baris 1
                    if (panx == 48 && pany == 7)
                    {
                        *_baris = 0;
                        *_kolom = 0;
                    }
                    else if (panx == 54 && pany == 7)
                    {
                        *_baris = 0;
                        *_kolom = 1;
                    }
                    else if (panx == 60 && pany == 7)
                    {
                        *_baris = 0;
                        *_kolom = 2;
                    }
                    else if (panx == 66 && pany == 7)
                    {
                        *_baris = 0;
                        *_kolom = 3;
                    }
                    else if (panx == 72 && pany == 7)
                    {
                        *_baris = 0;
                        *_kolom = 4;
                    }
                    // baris 2
                    else if (panx == 48 && pany == 11)
                    {
                        *_baris = 1;
                        *_kolom = 0;
                    }
                    else if (panx == 54 && pany == 11)
                    {
                        *_baris = 1;
                        *_kolom = 1;
                    }
                    else if (panx == 60 && pany == 11)
                    {
                        *_baris = 1;
                        *_kolom = 2;
                    }
                    else if (panx == 66 && pany == 11)
                    {
                        *_baris = 1;
                        *_kolom = 3;
                    }
                    else if (panx == 72 && pany == 11)
                    {
                        *_baris = 1;
                        *_kolom = 4;
                    }
                    // baris3
                    else if (panx == 48 && pany == 15)
                    {
                        *_baris = 2;
                        *_kolom = 0;
                    }
                    else if (panx == 54 && pany == 15)
                    {
                        *_baris = 2;
                        *_kolom = 1;
                    }
                    else if (panx == 60 && pany == 15)
                    {
                        *_baris = 2;
                        *_kolom = 2;
                    }
                    else if (panx == 66 && pany == 15)
                    {
                        *_baris = 2;
                        *_kolom = 3;
                    }
                    else if (panx == 72 && pany == 15)
                    {
                        *_baris = 2;
                        *_kolom = 4;
                    }
                    // baris 4
                    else if (panx == 48 && pany == 19)
                    {
                        *_baris = 3;
                        *_kolom = 0;
                    }
                    else if (panx == 54 && pany == 19)
                    {
                        *_baris = 3;
                        *_kolom = 1;
                    }
                    else if (panx == 60 && pany == 19)
                    {
                        *_baris = 3;
                        *_kolom = 2;
                    }
                    else if (panx == 66 && pany == 19)
                    {
                        *_baris = 3;
                        *_kolom = 3;
                    }
                    else if (panx == 72 && pany == 19)
                    {
                        *_baris = 3;
                        *_kolom = 4;
                    }
                    // baris 5
                    else if (panx == 48 && pany == 23)
                    {
                        *_baris = 4;
                        *_kolom = 0;
                    }
                    else if (panx == 54 && pany == 23)
                    {
                        *_baris = 4;
                        *_kolom = 1;
                    }
                    else if (panx == 60 && pany == 23)
                    {
                        *_baris = 4;
                        *_kolom = 2;
                    }
                    else if (panx == 66 && pany == 23)
                    {
                        *_baris = 4;
                        *_kolom = 3;
                    }
                    else if (panx == 72 && pany == 23)
                    {
                        *_baris = 4;
                        *_kolom = 4;
                    }
                    if (_papan[*_baris][*_kolom] == ' ')
                    {
                        cekValid = 1;
                    }
                } while (cekValid == 0 && *_valid==true);
            }

            else if (_jenisPapan == 7)
            {
                koor(panx - 1, pany);
                printf(" ");
                panx = 42;
                pany = 7;
                {
                    do
                    {
                        end = time(NULL);
                            waktu = end - start;
                            if(count%6000==0)
                            {
                                koor(61,2);printf("  ");
                                koor(61,2);printf("%.f",detik-waktu);
                            }
                            if(button!=0)
                            {
                                koor(panx, pany);
                                printf("1");
                                button=0;
                            }
                            if(button==0)
                            {
                                koor(0,0);
                            }
                            if(kbhit())
                            {
                            button = getch();
                            }
                        if (button == up || button == w || button == W)
                        {
                            switch (pany)
                            {
                            case 7:
                                pany = 31;
                                koor(panx, 7);
                                printf(" ");
                                break;
                            case 11:
                                pany = 7;
                                koor(panx, 11);
                                printf(" ");
                                break;
                            case 15:
                                pany = 11;
                                koor(panx, 15);
                                printf(" ");
                                break;
                            case 19:
                                pany = 15;
                                koor(panx, 19);
                                printf(" ");
                                break;
                            case 23:
                                pany = 19;
                                koor(panx, 23);
                                printf(" ");
                                break;
                            case 27:
                                pany = 23;
                                koor(panx, 27);
                                printf(" ");
                                break;
                            case 31:
                                pany = 27;
                                koor(panx, 31);
                                printf(" ");
                                break;
                            }
                        }
                        else if (button == down || button == s || button == S)
                        {
                            switch (pany)
                            {
                            case 7:
                                pany = 11;
                                koor(panx, 7);
                                printf(" ");
                                break;
                            case 11:
                                pany = 15;
                                koor(panx, 11);
                                printf(" ");
                                break;
                            case 15:
                                pany = 19;
                                koor(panx, 15);
                                printf(" ");
                                break;
                            case 19:
                                pany = 23;
                                koor(panx, 19);
                                printf(" ");
                                break;
                            case 23:
                                pany = 27;
                                koor(panx, 23);
                                printf(" ");
                                break;
                            case 27:
                                pany = 31;
                                koor(panx, 27);
                                printf(" ");
                                break;
                            case 31:
                                pany = 7;
                                koor(panx, 31);
                                printf(" ");
                                break;
                            }
                        }
                        else if (button == left || button == a || button == A)
                        {
                            switch (panx)
                            {
                            case 42:
                                panx = 78;
                                koor(42, pany);
                                printf(" ");
                                break;
                            case 48:
                                panx = 42;
                                koor(48, pany);
                                printf(" ");
                                break;
                            case 54:
                                panx = 48;
                                koor(54, pany);
                                printf(" ");
                                break;
                            case 60:
                                panx = 54;
                                koor(60, pany);
                                printf(" ");
                                break;
                            case 66:
                                panx = 60;
                                koor(66, pany);
                                printf(" ");
                                break;
                            case 72:
                                panx = 66;
                                koor(72, pany);
                                printf(" ");
                                break;
                            case 78:
                                panx = 72;
                                koor(78, pany);
                                printf(" ");
                                break;
                            }
                        }
                        else if (button == right || button == d || button == D)
                        {
                            switch (panx)
                            {
                            case 42:
                                panx = 48;
                                koor(42, pany);
                                printf(" ");
                                break;
                            case 48:
                                panx = 54;
                                koor(48, pany);
                                printf(" ");
                                break;
                            case 54:
                                panx = 60;
                                koor(54, pany);
                                printf(" ");
                                break;
                            case 60:
                                panx = 66;
                                koor(60, pany);
                                printf(" ");
                                break;
                            case 66:
                                panx = 72;
                                koor(66, pany);
                                printf(" ");
                                break;
                            case 72:
                                panx = 78;
                                koor(72, pany);
                                printf(" ");
                                break;
                            case 78:
                                panx = 42;
                                koor(78, pany);
                                printf(" ");
                                break;
                            }
                        }
                        count++;  
                        sleep(0.1);
                        if(waktu==10)
                        {
                            *_valid=false;
                        }
                        } while (button != 13 && *_valid==true);
                    // baris 1
                    if (panx == 42 && pany == 7)
                    {
                        *_baris = 0;
                        *_kolom = 0;
                    }
                    else if (panx == 48 && pany == 7)
                    {
                        *_baris = 0;
                        *_kolom = 1;
                    }
                    else if (panx == 54 && pany == 7)
                    {
                        *_baris = 0;
                        *_kolom = 2;
                    }
                    else if (panx == 60 && pany == 7)
                    {
                        *_baris = 0;
                        *_kolom = 3;
                    }
                    else if (panx == 66 && pany == 7)
                    {
                        *_baris = 0;
                        *_kolom = 4;
                    }
                    else if (panx == 72 && pany == 7)
                    {
                        *_baris = 0;
                        *_kolom = 5;
                    }
                    else if (panx == 78 && pany == 7)
                    {
                        *_baris = 0;
                        *_kolom = 6;
                    }
                    // baris 2
                    else if (panx == 42 && pany == 11)
                    {
                        *_baris = 1;
                        *_kolom = 0;
                    }
                    else if (panx == 48 && pany == 11)
                    {
                        *_baris = 1;
                        *_kolom = 1;
                    }
                    else if (panx == 54 && pany == 11)
                    {
                        *_baris = 1;
                        *_kolom = 2;
                    }
                    else if (panx == 60 && pany == 11)
                    {
                        *_baris = 1;
                        *_kolom = 3;
                    }
                    else if (panx == 66 && pany == 11)
                    {
                        *_baris = 1;
                        *_kolom = 4;
                    }
                    else if (panx == 72 && pany == 11)
                    {
                        *_baris = 1;
                        *_kolom = 5;
                    }
                    else if (panx == 78 && pany == 11)
                    {
                        *_baris = 1;
                        *_kolom = 6;
                    }
                    // baris 3
                    else if (panx == 42 && pany == 15)
                    {
                        *_baris = 2;
                        *_kolom = 0;
                    }
                    else if (panx == 48 && pany == 15)
                    {
                        *_baris = 2;
                        *_kolom = 1;
                    }
                    else if (panx == 54 && pany == 15)
                    {
                        *_baris = 2;
                        *_kolom = 2;
                    }
                    else if (panx == 60 && pany == 15)
                    {
                        *_baris = 2;
                        *_kolom = 3;
                    }
                    else if (panx == 66 && pany == 15)
                    {
                        *_baris = 2;
                        *_kolom = 4;
                    }
                    else if (panx == 72 && pany == 15)
                    {
                        *_baris = 2;
                        *_kolom = 5;
                    }
                    else if (panx == 78 && pany == 15)
                    {
                        *_baris = 2;
                        *_kolom = 6;
                    }
                    // baris 4
                    else if (panx == 42 && pany == 19)
                    {
                        *_baris = 3;
                        *_kolom = 0;
                    }
                    else if (panx == 48 && pany == 19)
                    {
                        *_baris = 3;
                        *_kolom = 1;
                    }
                    else if (panx == 54 && pany == 19)
                    {
                        *_baris = 3;
                        *_kolom = 2;
                    }
                    else if (panx == 60 && pany == 19)
                    {
                        *_baris = 3;
                        *_kolom = 3;
                    }
                    else if (panx == 66 && pany == 19)
                    {
                        *_baris = 3;
                        *_kolom = 4;
                    }
                    else if (panx == 72 && pany == 19)
                    {
                        *_baris = 3;
                        *_kolom = 5;
                    }
                    else if (panx == 78 && pany == 19)
                    {
                        *_baris = 3;
                        *_kolom = 6;
                    }
                    // baris 5
                    else if (panx == 42 && pany == 23)
                    {
                        *_baris = 4;
                        *_kolom = 0;
                    }
                    else if (panx == 48 && pany == 23)
                    {
                        *_baris = 4;
                        *_kolom = 1;
                    }
                    else if (panx == 54 && pany == 23)
                    {
                        *_baris = 4;
                        *_kolom = 2;
                    }
                    else if (panx == 60 && pany == 23)
                    {
                        *_baris = 4;
                        *_kolom = 3;
                    }
                    else if (panx == 66 && pany == 23)
                    {
                        *_baris = 4;
                        *_kolom = 4;
                    }
                    else if (panx == 72 && pany == 23)
                    {
                        *_baris = 4;
                        *_kolom = 5;
                    }
                    else if (panx == 78 && pany == 23)
                    {
                        *_baris = 4;
                        *_kolom = 6;
                    }
                    // baris 6
                    else if (panx == 42 && pany == 27)
                    {
                        *_baris = 5;
                        *_kolom = 0;
                    }
                    else if (panx == 48 && pany == 27)
                    {
                        *_baris = 5;
                        *_kolom = 1;
                    }
                    else if (panx == 54 && pany == 27)
                    {
                        *_baris = 5;
                        *_kolom = 2;
                    }
                    else if (panx == 60 && pany == 27)
                    {
                        *_baris = 5;
                        *_kolom = 3;
                    }
                    else if (panx == 66 && pany == 27)
                    {
                        *_baris = 5;
                        *_kolom = 4;
                    }
                    else if (panx == 72 && pany == 27)
                    {
                        *_baris = 5;
                        *_kolom = 5;
                    }
                    else if (panx == 78 && pany == 27)
                    {
                        *_baris = 5;
                        *_kolom = 6;
                    }
                    // baris 7
                    else if (panx == 42 && pany == 31)
                    {
                        *_baris = 6;
                        *_kolom = 0;
                    }
                    else if (panx == 48 && pany == 31)
                    {
                        *_baris = 6;
                        *_kolom = 1;
                    }
                    else if (panx == 54 && pany == 31)
                    {
                        *_baris = 6;
                        *_kolom = 2;
                    }
                    else if (panx == 60 && pany == 31)
                    {
                        *_baris = 6;
                        *_kolom = 3;
                    }
                    else if (panx == 66 && pany == 31)
                    {
                        *_baris = 6;
                        *_kolom = 4;
                    }
                    else if (panx == 72 && pany == 31)
                    {
                        *_baris = 6;
                        *_kolom = 5;
                    }
                    else if (panx == 78 && pany == 31)
                    {
                        *_baris = 6;
                        *_kolom = 6;
                    }
                    if (_papan[*_baris][*_kolom] == ' ')
                    {
                        cekValid = 1;
                    }
                } while (cekValid == 0 && *_valid==true);
            }
        }
    }

    
    else if (_flagIndex == 2)
    {
        int button;
        int panx;
        int pany;
        int cekValid = 0;
        if (_jenisPapan == 3)
        {
            koor(panx - 1, pany);
            printf(" ");
            panx = 54;
            pany = 7;
            do
            {
                do
                {
                    end = time(NULL);
                    waktu = end - start;
                    if(count%6000==0)
                    {
                        koor(61,2);printf("  ");
                        koor(61,2);printf("%.f",detik-waktu);
                    }
                    if(button!=0)
                    {
                        koor(panx, pany);
                        if(_pilihPertama==1 && _giliran%2==1 || _pilihPertama==2 && _giliran%2==0)
                        {
                        printf("1");
                        }
                        else printf("2");
                        button=0;
                    }
                    if(button==0)
                    {
                        koor(0,0);
                    }
                    if(kbhit())
                    {
                    button = getch();
                    }
                    if (button == up || button == w || button == W)
                    {
                        switch (pany)
                        {
                        case 7:
                            pany = 15;
                            koor(panx, 7);
                            printf(" ");
                            break;
                        case 11:
                            pany = 7;
                            koor(panx, 11);
                            printf(" ");
                            break;
                        case 15:
                            pany = 11;
                            koor(panx, 15);
                            printf(" ");
                            break;
                        }
                    }
                    else if (button == down || button == s || button == S)
                    {
                        switch (pany)
                        {
                        case 7:
                            pany = 11;
                            koor(panx, 7);
                            printf(" ");
                            break;
                        case 11:
                            pany = 15;
                            koor(panx, 11);
                            printf(" ");
                            break;
                        case 15:
                            pany = 7;
                            koor(panx, 15);
                            printf(" ");
                            break;
                        }
                    }
                    else if (button == left || button == a || button == A)
                    {
                        switch (panx)
                        {
                        case 54:
                            panx = 66;
                            koor(54, pany);
                            printf(" ");
                            break;
                        case 60:
                            panx = 54;
                            koor(60, pany);
                            printf(" ");
                            break;
                        case 66:
                            panx = 60;
                            koor(66, pany);
                            printf(" ");
                            break;
                        }
                    }
                    else if (button == right || button == d || button == D)
                    {
                        switch (panx)
                        {
                        case 54:
                            panx = 60;
                            koor(54, pany);
                            printf(" ");
                            break;
                        case 60:
                            panx = 66;
                            koor(60, pany);
                            printf(" ");
                            break;
                        case 66:
                            panx = 54;
                            koor(66, pany);
                            printf(" ");
                            break;
                        }
                    }
                count++;  
                sleep(0.1);
                if(waktu==10)
                {
                    *_valid=false;
                }
                } while (button != 13 && *_valid==true);
                if (panx == 54 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 0;
                }
                else if (panx == 60 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 1;
                }
                else if (panx == 66 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 2;
                }
                else if (panx == 54 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 0;
                }
                else if (panx == 60 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 1;
                }
                else if (panx == 66 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 2;
                }
                else if (panx == 54 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 0;
                }
                else if (panx == 60 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 1;
                }
                else if (panx == 66 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 2;
                }
                if (_papan[*_baris][*_kolom] == ' ')
                {
                    cekValid = 1;
                }
            } while (cekValid==0 && *_valid==true);
        }

        else if (_jenisPapan == 5)
        {
            koor(panx - 1, pany);
            printf(" ");
            panx = 48;
            pany = 7;
            do
            {
                do
                {
                    end = time(NULL);
                    waktu = end - start;
                    if(count%6000==0)
                    {
                        koor(61,2);printf("  ");
                        koor(61,2);printf("%.f",detik-waktu);
                    }
                    if(button!=0)
                    {
                        koor(panx, pany);
                        if(_pilihPertama==1 && _giliran%2==1 || _pilihPertama==2 && _giliran%2==0)
                        {
                        printf("1");
                        }
                        else printf("2");
                        button=0;
                    }
                    if(button==0)
                    {
                        koor(0,0);
                    }
                    if(kbhit())
                    {
                    button = getch();
                    }
                    if (button == up || button == w || button == W)
                    {
                        switch (pany)
                        {
                        case 7:
                            pany = 23;
                            koor(panx, 7);
                            printf(" ");
                            break;
                        case 11:
                            pany = 7;
                            koor(panx, 11);
                            printf(" ");
                            break;
                        case 15:
                            pany = 11;
                            koor(panx, 15);
                            printf(" ");
                            break;
                        case 19:
                            pany = 15;
                            koor(panx, 19);
                            printf(" ");
                            break;
                        case 23:
                            pany = 19;
                            koor(panx, 23);
                            printf(" ");
                            break;
                        }
                    }
                    else if (button == down || button == s || button == S)
                    {
                        switch (pany)
                        {
                        case 7:
                            pany = 11;
                            koor(panx, 7);
                            printf(" ");
                            break;
                        case 11:
                            pany = 15;
                            koor(panx, 11);
                            printf(" ");
                            break;
                        case 15:
                            pany = 19;
                            koor(panx, 15);
                            printf(" ");
                            break;
                        case 19:
                            pany = 23;
                            koor(panx, 19);
                            printf(" ");
                            break;
                        case 23:
                            pany = 7;
                            koor(panx, 23);
                            printf(" ");
                            break;
                        }
                    }
                    else if (button == left || button == a || button == A)
                    {
                        switch (panx)
                        {
                        case 48:
                            panx = 72;
                            koor(48, pany);
                            printf(" ");
                            break;
                        case 54:
                            panx = 48;
                            koor(54, pany);
                            printf(" ");
                            break;
                        case 60:
                            panx = 54;
                            koor(60, pany);
                            printf(" ");
                            break;
                        case 66:
                            panx = 60;
                            koor(66, pany);
                            printf(" ");
                            break;
                        case 72:
                            panx = 66;
                            koor(72, pany);
                            printf(" ");
                            break;
                        }
                    }
                    else if (button == right || button == d || button == D)
                    {
                        switch (panx)
                        {
                        case 48:
                            panx = 54;
                            koor(48, pany);
                            printf(" ");
                            break;
                        case 54:
                            panx = 60;
                            koor(54, pany);
                            printf(" ");
                            break;
                        case 60:
                            panx = 66;
                            koor(60, pany);
                            printf(" ");
                            break;
                        case 66:
                            panx = 72;
                            koor(66, pany);
                            printf(" ");
                            break;
                        case 72:
                            panx = 48;
                            koor(72, pany);
                            printf(" ");
                            break;
                        }
                    }
                count++;  
                sleep(0.1);
                if(waktu==10)
                {
                    *_valid=false;
                }
                } while (button != 13);
                // baris 1
                if (panx == 48 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 0;
                }
                else if (panx == 54 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 1;
                }
                else if (panx == 60 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 2;
                }
                else if (panx == 66 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 3;
                }
                else if (panx == 72 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 4;
                }
                // baris 2
                else if (panx == 48 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 0;
                }
                else if (panx == 54 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 1;
                }
                else if (panx == 60 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 2;
                }
                else if (panx == 66 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 3;
                }
                else if (panx == 72 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 4;
                }
                // baris3
                else if (panx == 48 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 0;
                }
                else if (panx == 54 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 1;
                }
                else if (panx == 60 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 2;
                }
                else if (panx == 66 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 3;
                }
                else if (panx == 72 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 4;
                }
                // baris 4
                else if (panx == 48 && pany == 19)
                {
                    *_baris = 3;
                    *_kolom = 0;
                }
                else if (panx == 54 && pany == 19)
                {
                    *_baris = 3;
                    *_kolom = 1;
                }
                else if (panx == 60 && pany == 19)
                {
                    *_baris = 3;
                    *_kolom = 2;
                }
                else if (panx == 66 && pany == 19)
                {
                    *_baris = 3;
                    *_kolom = 3;
                }
                else if (panx == 72 && pany == 19)
                {
                    *_baris = 3;
                    *_kolom = 4;
                }
                // baris 5
                else if (panx == 48 && pany == 23)
                {
                    *_baris = 4;
                    *_kolom = 0;
                }
                else if (panx == 54 && pany == 23)
                {
                    *_baris = 4;
                    *_kolom = 1;
                }
                else if (panx == 60 && pany == 23)
                {
                    *_baris = 4;
                    *_kolom = 2;
                }
                else if (panx == 66 && pany == 23)
                {
                    *_baris = 4;
                    *_kolom = 3;
                }
                else if (panx == 72 && pany == 23)
                {
                    *_baris = 4;
                    *_kolom = 4;
                }
                if (_papan[*_baris][*_kolom] == ' ')
                {
                    cekValid = 1;
                }
            } while (cekValid==0 && *_valid==true);
        }

        else if (_jenisPapan == 7)
        {
            koor(panx - 1, pany);
            printf(" ");
            panx = 42;
            pany = 7;
            {
                do
                {
                    end = time(NULL);
                    waktu = end - start;
                    if(count%6000==0)
                    {
                        koor(61,2);printf("  ");
                        koor(61,2);printf("%.f",detik-waktu);
                    }
                    if(button!=0)
                    {
                        koor(panx, pany);
                        if(_pilihPertama==1 && _giliran%2==1 || _pilihPertama==2 && _giliran%2==0)
                        {
                        printf("1");
                        }
                        else printf("2");
                        button=0;
                    }
                    if(button==0)
                    {
                        koor(0,0);
                    }
                    if(kbhit())
                    {
                    button = getch();
                    }
                    if (button == up || button == w || button == W)
                    {
                        switch (pany)
                        {
                        case 7:
                            pany = 31;
                            koor(panx, 7);
                            printf(" ");
                            break;
                        case 11:
                            pany = 7;
                            koor(panx, 11);
                            printf(" ");
                            break;
                        case 15:
                            pany = 11;
                            koor(panx, 15);
                            printf(" ");
                            break;
                        case 19:
                            pany = 15;
                            koor(panx, 19);
                            printf(" ");
                            break;
                        case 23:
                            pany = 19;
                            koor(panx, 23);
                            printf(" ");
                            break;
                        case 27:
                            pany = 23;
                            koor(panx, 27);
                            printf(" ");
                            break;
                        case 31:
                            pany = 27;
                            koor(panx, 31);
                            printf(" ");
                            break;
                        }
                    }
                    else if (button == down || button == s || button == S)
                    {
                        switch (pany)
                        {
                        case 7:
                            pany = 11;
                            koor(panx, 7);
                            printf(" ");
                            break;
                        case 11:
                            pany = 15;
                            koor(panx, 11);
                            printf(" ");
                            break;
                        case 15:
                            pany = 19;
                            koor(panx, 15);
                            printf(" ");
                            break;
                        case 19:
                            pany = 23;
                            koor(panx, 19);
                            printf(" ");
                            break;
                        case 23:
                            pany = 27;
                            koor(panx, 23);
                            printf(" ");
                            break;
                        case 27:
                            pany = 31;
                            koor(panx, 27);
                            printf(" ");
                            break;
                        case 31:
                            pany = 7;
                            koor(panx, 31);
                            printf(" ");
                            break;
                        }
                    }
                    else if (button == left || button == a || button == A)
                    {
                        switch (panx)
                        {
                        case 42:
                            panx = 78;
                            koor(42, pany);
                            printf(" ");
                            break;
                        case 48:
                            panx = 42;
                            koor(48, pany);
                            printf(" ");
                            break;
                        case 54:
                            panx = 48;
                            koor(54, pany);
                            printf(" ");
                            break;
                        case 60:
                            panx = 54;
                            koor(60, pany);
                            printf(" ");
                            break;
                        case 66:
                            panx = 60;
                            koor(66, pany);
                            printf(" ");
                            break;
                        case 72:
                            panx = 66;
                            koor(72, pany);
                            printf(" ");
                            break;
                        case 78:
                            panx = 72;
                            koor(78, pany);
                            printf(" ");
                            break;
                        }
                    }
                    else if (button == right || button == d || button == D)
                    {
                        switch (panx)
                        {
                        case 42:
                            panx = 48;
                            koor(42, pany);
                            printf(" ");
                            break;
                        case 48:
                            panx = 54;
                            koor(48, pany);
                            printf(" ");
                            break;
                        case 54:
                            panx = 60;
                            koor(54, pany);
                            printf(" ");
                            break;
                        case 60:
                            panx = 66;
                            koor(60, pany);
                            printf(" ");
                            break;
                        case 66:
                            panx = 72;
                            koor(66, pany);
                            printf(" ");
                            break;
                        case 72:
                            panx = 78;
                            koor(72, pany);
                            printf(" ");
                            break;
                        case 78:
                            panx = 42;
                            koor(78, pany);
                            printf(" ");
                            break;
                        }
                    }
                count++;  
                sleep(0.1);
                if(waktu==10)
                {
                    *_valid=false;
                }
                } while (button != 13);
                // baris 1
                if (panx == 42 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 0;
                }
                else if (panx == 48 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 1;
                }
                else if (panx == 54 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 2;
                }
                else if (panx == 60 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 3;
                }
                else if (panx == 66 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 4;
                }
                else if (panx == 72 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 5;
                }
                else if (panx == 78 && pany == 7)
                {
                    *_baris = 0;
                    *_kolom = 6;
                }
                // baris 2
                else if (panx == 42 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 0;
                }
                else if (panx == 48 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 1;
                }
                else if (panx == 54 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 2;
                }
                else if (panx == 60 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 3;
                }
                else if (panx == 66 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 4;
                }
                else if (panx == 72 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 5;
                }
                else if (panx == 78 && pany == 11)
                {
                    *_baris = 1;
                    *_kolom = 6;
                }
                // baris 3
                else if (panx == 42 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 0;
                }
                else if (panx == 48 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 1;
                }
                else if (panx == 54 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 2;
                }
                else if (panx == 60 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 3;
                }
                else if (panx == 66 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 4;
                }
                else if (panx == 72 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 5;
                }
                else if (panx == 78 && pany == 15)
                {
                    *_baris = 2;
                    *_kolom = 6;
                }
                // baris 4
                else if (panx == 42 && pany == 19)
                {
                    *_baris = 3;
                    *_kolom = 0;
                }
                else if (panx == 48 && pany == 19)
                {
                    *_baris = 3;
                    *_kolom = 1;
                }
                else if (panx == 54 && pany == 19)
                {
                    *_baris = 3;
                    *_kolom = 2;
                }
                else if (panx == 60 && pany == 19)
                {
                    *_baris = 3;
                    *_kolom = 3;
                }
                else if (panx == 66 && pany == 19)
                {
                    *_baris = 3;
                    *_kolom = 4;
                }
                else if (panx == 72 && pany == 19)
                {
                    *_baris = 3;
                    *_kolom = 5;
                }
                else if (panx == 78 && pany == 19)
                {
                    *_baris = 3;
                    *_kolom = 6;
                }
                // baris 5
                else if (panx == 42 && pany == 23)
                {
                    *_baris = 4;
                    *_kolom = 0;
                }
                else if (panx == 48 && pany == 23)
                {
                    *_baris = 4;
                    *_kolom = 1;
                }
                else if (panx == 54 && pany == 23)
                {
                    *_baris = 4;
                    *_kolom = 2;
                }
                else if (panx == 60 && pany == 23)
                {
                    *_baris = 4;
                    *_kolom = 3;
                }
                else if (panx == 66 && pany == 23)
                {
                    *_baris = 4;
                    *_kolom = 4;
                }
                else if (panx == 72 && pany == 23)
                {
                    *_baris = 4;
                    *_kolom = 5;
                }
                else if (panx == 78 && pany == 23)
                {
                    *_baris = 4;
                    *_kolom = 6;
                }
                // baris 6
                else if (panx == 42 && pany == 27)
                {
                    *_baris = 5;
                    *_kolom = 0;
                }
                else if (panx == 48 && pany == 27)
                {
                    *_baris = 5;
                    *_kolom = 1;
                }
                else if (panx == 54 && pany == 27)
                {
                    *_baris = 5;
                    *_kolom = 2;
                }
                else if (panx == 60 && pany == 27)
                {
                    *_baris = 5;
                    *_kolom = 3;
                }
                else if (panx == 66 && pany == 27)
                {
                    *_baris = 5;
                    *_kolom = 4;
                }
                else if (panx == 72 && pany == 27)
                {
                    *_baris = 5;
                    *_kolom = 5;
                }
                else if (panx == 78 && pany == 27)
                {
                    *_baris = 5;
                    *_kolom = 6;
                }
                // baris 7
                else if (panx == 42 && pany == 31)
                {
                    *_baris = 6;
                    *_kolom = 0;
                }
                else if (panx == 48 && pany == 31)
                {
                    *_baris = 6;
                    *_kolom = 1;
                }
                else if (panx == 54 && pany == 31)
                {
                    *_baris = 6;
                    *_kolom = 2;
                }
                else if (panx == 60 && pany == 31)
                {
                    *_baris = 6;
                    *_kolom = 3;
                }
                else if (panx == 66 && pany == 31)
                {
                    *_baris = 6;
                    *_kolom = 4;
                }
                else if (panx == 72 && pany == 31)
                {
                    *_baris = 6;
                    *_kolom = 5;
                }
                else if (panx == 78 && pany == 31)
                {
                    *_baris = 6;
                    *_kolom = 6;
                }
                if (_papan[*_baris][*_kolom] == ' ')
                {
                    cekValid = 1;
                }
            
            } while (cekValid==0 && *_valid==true);
        }
    }
}