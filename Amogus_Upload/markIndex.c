#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "header.h"

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
        if (_giliran % 2 == 1)
            (*_papanKotak)[_baris][_kolom] = 'O';
        else if (_giliran % 2 == 0)
            (*_papanKotak)[_baris][_kolom] = 'X';
    }
}