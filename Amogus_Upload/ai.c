#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>



void pilihIndexKomputer( int _jenisPapan, int *_baris, int *_kolom, char _papan[7][7] )
{
    typedef struct{
        int baris;
        int kolom;
        bool indexValid;
    }Index;

    Index index[9];
    int i = 0;
    bool random = false;

    // MASUKAN INDEX TERAKHIR PADA ARRAY 0
    
    index[0].baris = *_baris;
    index[0].kolom = *_kolom;

    // MASUKAN BARIS DAN KOLOM KOTAK DISEKITA INDEX TERAKHIR YANG DIMASUKAN

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

    // CEK BARIS DAN KOLOM BERADA PADA INDEX YANG DIIZINKAN

    for( i = 1; i <= 8; i++ ){
        
        if( index[i].baris >= 0 && index[i].kolom >= 0 && index[i].baris < _jenisPapan && index[i].kolom < _jenisPapan){
            index[i].indexValid = true;
        }
    }

    // CEK INDEX YANG MEMILILKI TANDA X DIBELAKANG INDEX BARIS TERAKHIR YANG DIPILIH PLAYER 1

    for( i = 1; i <= 8; i++ ){
        if( index[i].indexValid == true && _papan[index[i].baris][index[i].kolom] == 'X' ){
            index[i].indexValid = true;
        }
        else{
            index[i].indexValid = false;
        }
    }

    // MASUKAN BARIS DAN KOLOM YANG SESUAI

    if( index[1].indexValid == true && _papan[index[1].baris][index[1].kolom] == 'X' && _papan[index[5].baris][index[5].kolom] == ' ' ){
        *_baris = index[5].baris;
        *_kolom = index[5].kolom;
    }
    else if( index[2].indexValid == true && _papan[index[2].baris][index[2].kolom] == 'X' && _papan[index[6].baris][index[6].kolom] == ' ' ){
        *_baris = index[6].baris;
        *_kolom = index[6].kolom;
    }
    else if( index[3].indexValid == true && _papan[index[3].baris][index[3].kolom] == 'X' && _papan[index[7].baris][index[7].kolom] == ' ' ){
        *_baris = index[7].baris;
        *_kolom = index[7].kolom;
    }
    else if( index[4].indexValid == true && _papan[index[4].baris][index[4].kolom] == 'X' && _papan[index[8].baris][index[8].kolom] == ' ' ){
        *_baris = index[8].baris;
        *_kolom = index[8].kolom;
    }
    else if( index[5].indexValid == true && _papan[index[5].baris][index[5].kolom] == 'X' && _papan[index[1].baris][index[1].kolom] == ' ' ){
        *_baris = index[1].baris;
        *_kolom = index[1].kolom;
    }
    else if( index[6].indexValid == true && _papan[index[6].baris][index[6].kolom] == 'X' && _papan[index[2].baris][index[2].kolom] == ' ' ){
        *_baris = index[2].baris;
        *_kolom = index[2].kolom;
    }
    else if( index[7].indexValid == true && _papan[index[7].baris][index[7].kolom] == 'X' && _papan[index[3].baris][index[1].kolom] == ' ' ){
        *_baris = index[3].baris;
        *_kolom = index[3].kolom;
    }
    else if( index[8].indexValid == true && _papan[index[8].baris][index[8].kolom] == 'X' && _papan[index[4].baris][index[4].kolom] == ' ' ){
        *_baris = index[4].baris;
        *_kolom = index[4].kolom;
    }
    // JIKA SEKITAR BARIS DAN KOLOM PEMAIN 1 BELUM TERISI X MAKA ISI YANG MEMILIKI RUANG YANG BISA DIISI DISEKITARNYA
    else{
        for( i = 1; i <= 8; i++ ){
            if( index[i].baris >= 0 && index[i].kolom >= 0 &&
                index[i].baris < _jenisPapan && index[i].kolom < _jenisPapan &&
                _papan[index[i].baris][index[i].kolom] == ' ')
            {
                *_baris = index[i].baris;
                *_kolom = index[i].kolom;
                break;
            }
            else
                random = true;
        }
    }


    // JIKA SEKITAR BARIS DAN KOLOM PEMAIN 1 BELUM TERISI MAKA ISI RANDOM
    if ( random == true ){
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






/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>



void medium( int _jenisPapan, int *_baris, int *_kolom, char _papan[7][7] )
{
    typedef struct{
        int baris;
        int kolom;
        // bool indexValid;
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
        if( index[i].baris >= 0 && index[i].kolom >= 0 &&
            index[i].baris < _jenisPapan && index[i].kolom < _jenisPapan &&
            _papan[index[i].baris][index[i].kolom] == ' ')
        {
            *_baris = index[i].baris;
            *_kolom = index[i].kolom;
            k++;
        }
    }

    if( k == -1 ){
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
*/