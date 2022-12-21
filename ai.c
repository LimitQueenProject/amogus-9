#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"


Index pilihIndexKomputer( int _jenisPapan, Index _indexPilihIndexKomputer, char _papan[7][7] )
{
    int i, j, count=0, pemenang=-1;
    Index indexKomputer[49];
    bool listValid = false;
    int listIndexValid[49];

 ///////////////////////////////////////////////////////////////////////////////////    
    // mode menyerang last hit
    for( i = 0; i < _jenisPapan; i++ ){
        for( j = 0; j < _jenisPapan; j++ ){
            // cek papan yang kosong lalu isi dengan tanda player
            if( _papan[i][j] == ' ' ){
                _papan[i][j] = 'O';
                // cek pemenangnya yang diisi
                pemenang = cekPemenang(_jenisPapan, _papan);
                // kosongkan index yang diisi sebelumnya
                _papan[i][j] = ' ';
                // jika index yang ditandai menghasilkan pemenang maka masukan ke array list
                if( pemenang == 2 ){
                    listValid = true;
                    indexKomputer[count].baris = i;
                    indexKomputer[count].kolom = j;
                    count++;
                }
                pemenang = -1;
            }
        }
    }
    
    // jika terisi maka random dan kembalikan nilai
    if( listValid == true ){
        // random count
        srand(time(0));
        // kembalikan nilai
        return indexKomputer[rand() % count];
    }





///////////////////////////////////////    
    // mode bertahan last hit
    for( i = 0; i < _jenisPapan; i++ ){
        for( j = 0; j < _jenisPapan; j++ ){
            // cek papan yang kosong lalu isi dengan tanda player
            if( _papan[i][j] == ' ' ){
                _papan[i][j] = 'X';
                // cek pemenangnya yang diisi
                pemenang = cekPemenang(_jenisPapan, _papan);
                // kosongkan index yang diisi sebelumnya
                _papan[i][j] = ' ';
                // jika index yang ditandai menghasilkan pemenang maka masukan ke array list
                if( pemenang == 1 ){
                    listValid = true;
                    indexKomputer[count].baris = i;
                    indexKomputer[count].kolom = j;
                    count++;
                }
                pemenang = -1;
            }
        }
    }

    // jika terisi maka random dan kembalikan nilai
    if( listValid == true ){
        // random count
        srand(time(0));
        // kembalikan nilai
        return indexKomputer[rand() % count];
    }



///////////////////////////////////////    
    // blok jalan index terakhir
    typedef struct{
        Index indexValid;
        bool kondisiIndexValid;
    }Valid;

    Valid index[9];
    // MASUKAN INDEX TERAKHIR PADA ARRAY 0
    index[0].indexValid.baris = _indexPilihIndexKomputer.baris;
    index[0].indexValid.kolom = _indexPilihIndexKomputer.kolom;
    
    // MASUKAN BARIS DAN KOLOM KOTAK DISEKITAR INDEX TERAKHIR YANG DIMASUKAN

    index[1].indexValid.baris = index[0].indexValid.baris - 1;
    index[1].indexValid.kolom = index[0].indexValid.kolom - 1;

    index[2].indexValid.baris = index[0].indexValid.baris - 1;
    index[2].indexValid.kolom = index[0].indexValid.kolom - 0;
    
    index[3].indexValid.baris = index[0].indexValid.baris - 1;
    index[3].indexValid.kolom = index[0].indexValid.kolom + 1;

    index[4].indexValid.baris = index[0].indexValid.baris + 0;
    index[4].indexValid.kolom = index[0].indexValid.kolom + 1;

    index[5].indexValid.baris = index[0].indexValid.baris + 1;
    index[5].indexValid.kolom = index[0].indexValid.kolom + 1;
    
    index[6].indexValid.baris = index[0].indexValid.baris + 1;
    index[6].indexValid.kolom = index[0].indexValid.kolom + 0;

    index[7].indexValid.baris = index[0].indexValid.baris + 1;
    index[7].indexValid.kolom = index[0].indexValid.kolom - 1;

    index[8].indexValid.baris = index[0].indexValid.baris + 0;
    index[8].indexValid.kolom = index[0].indexValid.kolom - 1;

    // cek index yang berada didalam kotak papan
    for( i = 1; i <= 8; i++ ){
        if( 
        // _papan[index[i].indexValid.baris][index[i].indexValid.kolom] == ' ' &&
        index[i].indexValid.baris >= 0 && 
        index[i].indexValid.kolom >= 0 && 
        index[i].indexValid.baris < _jenisPapan && 
        index[i].indexValid.kolom < _jenisPapan   )
        {
            index[i].kondisiIndexValid = true;
        }
        else{
            index[i].kondisiIndexValid = false;
        }
    }

    // blok index yang membangun deret yang sama

    for( i = 1; i <= 8; i++ ){
        if( index[i].kondisiIndexValid == true && 
            _papan[index[i].indexValid.baris][index[i].indexValid.kolom] == 'X' && 
            _papan[index[(i+4)%9].indexValid.baris][index[(i+4)%9].indexValid.kolom] == ' ' )
        {
            indexKomputer[i].baris = index[(i+4)%9].indexValid.baris;
            indexKomputer[i].kolom = index[(i+4)%9].indexValid.kolom;
            listIndexValid[count] = i;
            count++;
            listValid = true;
        }
    }

    if( listValid == true ){
        // random count
        srand(time(0));
        // kembalikan nilai
        return indexKomputer[listIndexValid[rand() % count]];
    }

    for( i = 1; i <= 8; i++ ){
        if( index[i].kondisiIndexValid == true && 
            _papan[index[i].indexValid.baris][index[i].indexValid.kolom] == ' ' )
        {
            indexKomputer[i].baris = index[i].indexValid.baris;
            indexKomputer[i].kolom = index[i].indexValid.kolom;
            listIndexValid[count] = i;
            count++;
            listValid = true;
        }
    }

    if( listValid == true ){
        // random count
        srand(time(0));
        // kembalikan nilai
        return indexKomputer[listIndexValid[rand() % count]];
    }
 

    // random jika tidak ada yang bisa diisi
    
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
            indexKomputer[0].baris = randomBaris;
            indexKomputer[0].kolom = randomKolom;
            return indexKomputer[0];
        }
    }while(validIndex == false);




}