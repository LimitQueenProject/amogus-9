#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>



void medium( int _jenisPapan, int *_baris, int *_kolom, char _papan[7][7] )
{
    typedef struct{
        int baris;
        int kolom;
        bool indexValid;
    }Index;

    Index index[9];

    index[0].baris = *_baris;
    index[0].kolom = *_kolom;

    index[1].baris = index[0].baris - 1;
    index[1].kolom = index[0].kolom - 1;

    index[2].baris = index[0].baris - 1;
    index[2].kolom = index[0].kolom - 0;
    
    index[3].baris = index[0].baris - 1;
    index[3].kolom = index[0].kolom + 1;

    index[4].baris = index[0].baris + 0;
    index[4].kolom = index[0].kolom + 1;

    index[5].baris = index[0].baris + 1;
    index[5].kolom = index[0].kolom + 1;
    
    index[6].baris = index[0].baris + 1;
    index[6].kolom = index[0].kolom + 0;

    index[7].baris = index[0].baris + 1;
    index[7].kolom = index[0].kolom - 1;

    index[8].baris = index[0].baris + 0;
    index[8].kolom = index[0].kolom - 1;

    int j[8];
    int k = -1;
    int i = 0;
    for( i = 1; i <= 8; i++ )
    {
        if( index[i].baris >= 0 && index[i].kolom >= 0 && _papan[index[i].baris][index[i].kolom] == ' '){
            index[i].indexValid = true;
            k++;
            j[k] = i;
        }
        else{
            index[i].indexValid = false;
        }
    }

    if ( k == -1 ){
        srand(time(0));
        i = rand() % (j[k]-j[0]) + j[0];
        
        *_baris = index[i].baris;
        *_kolom = index[i].kolom;
    }else{
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
}