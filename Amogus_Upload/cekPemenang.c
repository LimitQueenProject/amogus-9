#include <stdio.h>
#include <stdbool.h>

#include "header.h"

int cekPemenang(int _jenisPapan, char kotak[7][7])
{
    int baris;
    int kolom;

    if ( _jenisPapan == 3 ){
        // CEK PEMENANG HORIZONTAL
        for ( baris = 0; baris < 3; baris++ )
        {
            if (kotak[baris][0] == kotak[baris][1] && kotak[baris][1] == kotak[baris][2])
            {
                if (kotak[baris][1] == 'X' && kotak[baris][2] == 'X'){
                    return 1;
                }
                else if (kotak[baris][1] == 'O' && kotak[baris][2] == 'O'){
                    return 2;
                }
            }
        }
        // CEK PEMENANG VERTIKAL
        for ( kolom = 0; kolom < 3; kolom++ )
        {
            if (kotak[0][kolom] == kotak[1][kolom] && kotak[1][kolom] == kotak[2][kolom])
            {
                if (kotak[1][kolom] == 'X' && kotak[2][kolom] == 'X'){
                    return 1;
                }
                else if (kotak[1][kolom] == 'O' && kotak[2][kolom] == 'O'){
                    return 2;
                }
            }
        }
        // CEK PEMENANG DIAGONAL 1
        if ( kotak[1][1] != ' ' && kotak[0][0] == kotak[1][1] && kotak[1][1] == kotak[2][2]){
            if ( kotak[1][1] == 'X' && kotak[2][2] == 'X' ){
                return 1;
            }
            else if ( kotak[1][1] == 'O' && kotak[2][2] == 'O' ){
                return 2;
            }
        }
        // CEK PEMENANG DIAGONAL 2
        if (kotak[1][1] != ' ' && kotak[0][2] == kotak[1][1] && kotak[1][1] == kotak[2][0]){
            if ( kotak[1][1] == 'X' && kotak[2][0] == 'X' ){
                return 1;
            }
            else if ( kotak[1][1] == 'O' && kotak[2][0] == 'O' ){
                return 2;
            }
        }
        return -1;
    }

    else if ( _jenisPapan == 5 )
    {
        // CEK HORIZONTAL
        for ( baris = 0; baris < 4; baris++ )
        {
            if (kotak[baris][0] == kotak[baris][1] && kotak[baris][1] == kotak[baris][2] && kotak[baris][2] == kotak[baris][3])
            {
                if (kotak[baris][1] == 'X'){
                    return 1;
                }
                else if (kotak[baris][1] == 'O' )
                {
                    return 2;
                }
            }
            else if (kotak[baris][1] == kotak[baris][2] && kotak[baris][2] == kotak[baris][3] && kotak[baris][3] == kotak[baris][4])
            {
                if (kotak[baris][1] == 'X'){
                    return 1;
                }
                else if (kotak[baris][1] == 'O' )
                {
                    return 2;
                }
            }
        }
        // CEK VERTIKAL
        for ( kolom = 0; kolom < 4; kolom++ )
        {
            if (kotak[0][kolom] == kotak[1][kolom] && kotak[1][kolom] == kotak[2][kolom] && kotak[2][kolom] == kotak[3][kolom])
            {
                if (kotak[1][kolom] == 'X'){
                    return 1;
                }
                else if (kotak[1][kolom] == 'O' )
                {
                    return 2;
                }
            }
            else if (kotak[1][kolom] == kotak[2][kolom] && kotak[2][kolom] == kotak[3][kolom] && kotak[3][kolom] == kotak[4][kolom])
            {
                if (kotak[2][kolom] == 'X'){
                    return 1;
                }
                else if (kotak[2][kolom] == 'O' )
                {
                    return 2;
                }
            }
        }
        // CEK DIAGONAL 1
        if (kotak[1][1] != ' ' && kotak[0][0] == kotak[1][1] && kotak[1][1] == kotak[2][2] && kotak[2][2] == kotak[3][3])
        {
            if (kotak[1][1] == 'X'){
                return 1;
            }
            else if (kotak[1][1] == 'O' )
            {
                return 2;
            }
        }
        else if (kotak[1][1] != ' ' && kotak[1][1] == kotak[2][2] && kotak[2][2] == kotak[3][3] && kotak[3][3] == kotak[4][4])
        {
            if (kotak[2][2] == 'X'){
                return 1;
            }
            else if (kotak[2][2] == 'O' )
            {
                return 2;
            }
        }
        else if (kotak[1][2] != ' ' && kotak[0][1] == kotak[1][2] && kotak[1][2] == kotak[2][3] && kotak[2][3] == kotak[3][4])
        {
            if (kotak[1][2] == 'X'){
                return 1;
            }
            else if (kotak[1][2] == 'O' )
            {
                return 2;
            }
        }
        else if (kotak[2][1] != ' ' && kotak[1][0] == kotak[2][1] && kotak[2][1] == kotak[3][2] && kotak[3][2] == kotak[4][3])
        {
            if (kotak[2][1] == 'X'){
                return 1;
            }
            else if (kotak[2][1] == 'O' )
            {
                return 2;
            }
        }

        // CEK DIAGONAL 2
        else if (kotak[2][2] != ' ' && kotak[0][4] == kotak[1][3] && kotak[1][3] == kotak[2][2] && kotak[2][2] == kotak[3][1])
        {
            if (kotak[2][2] == 'X'){
                return 1;
            }
            else if (kotak[2][2] == 'O' )
            {
                return 2;
            }
        }
        else if (kotak[2][2] != ' ' && kotak[1][3] == kotak[2][2] && kotak[2][2] == kotak[3][1] && kotak[3][1] == kotak[4][1-1])
        {
            if (kotak[2][2] == 'X'){
                return 1;
            }
            else if (kotak[2][2] == 'O' )
            {
                return 2;
            }
        }
        else if (kotak[1][2] != ' ' && kotak[0][3] == kotak[1][2] && kotak[1][2] == kotak[2][1] && kotak[2][1] == kotak[3][1-1])
        {
            if (kotak[1][2] == 'X'){
                return 1;
            }
            else if (kotak[1][2] == 'O' )
            {
                return 2;
            }
        }
        else if (kotak[1][4] != ' ' && kotak[1][4] == kotak[2][3] && kotak[2][3] == kotak[3][2] && kotak[3][2] == kotak[4][1])
        {
            if (kotak[1][4] == 'X'){
                return 1;
            }
            else if (kotak[1][4] == 'O' )
            {
                return 2;
            }
        }
        return -1;
    }

    else if (_jenisPapan == 7)
    {
        // CEK HORIZONTAL
        for ( baris = 0; baris < 5; baris++ )
        {
            if( kotak[baris][0] == kotak[baris][1] && 
                kotak[baris][1] == kotak[baris][2] && 
                kotak[baris][2] == kotak[baris][3] && 
                kotak[baris][3] == kotak[baris][4] ){
                if ( kotak[baris][2] == 'X' ){
                    return 1;
                }
                else if ( kotak[baris][2] == 'O' ){
                    return 2;
                }
            }
            else if( kotak[baris][1] == kotak[baris][2] && 
                kotak[baris][2] == kotak[baris][3] && 
                kotak[baris][3] == kotak[baris][4] && 
                kotak[baris][4] == kotak[baris][5] ){
                if ( kotak[baris][2] == 'X' ){
                    return 1;
                }
                else if ( kotak[baris][2] == 'O' ){
                    return 2;
                }
            }
            else if( kotak[baris][2] == kotak[baris][3] && 
                kotak[baris][3] == kotak[baris][4] && 
                kotak[baris][4] == kotak[baris][5] && 
                kotak[baris][5] == kotak[baris][6] ){
                if ( kotak[baris][2] == 'X' ){
                    return 1;
                }
                else if ( kotak[baris][2] == 'O' ){
                    return 2;
                }
            }
        }
        // CEK VERTIKAL
        for ( kolom = 0; kolom < 5; kolom++ )
        {
            if( kotak[0][kolom] == kotak[1][kolom] && 
                kotak[1][kolom] == kotak[2][kolom] && 
                kotak[2][kolom] == kotak[3][kolom] && 
                kotak[3][kolom] == kotak[4][kolom] ){
                if ( kotak[2][kolom] == 'X' ){
                    return 1;
                }
                else if ( kotak[2][kolom] == 'O' ){
                    return 2;
                }
            }
            else if( kotak[1][kolom] == kotak[2][kolom] && 
                kotak[2][kolom] == kotak[3][kolom] && 
                kotak[3][kolom] == kotak[4][kolom] && 
                kotak[4][kolom] == kotak[5][kolom] ){
                if ( kotak[3][kolom] == 'X' ){
                    return 1;
                }
                else if ( kotak[3][kolom] == 'O' ){
                    return 2;
                }
            }
            else if( kotak[2][kolom] == kotak[3][kolom] && 
                kotak[3][kolom] == kotak[4][kolom] && 
                kotak[4][kolom] == kotak[5][kolom] && 
                kotak[5][kolom] == kotak[6][kolom] ){
                if ( kotak[4][kolom] == 'X' ){
                    return 1;
                }
                else if ( kotak[4][kolom] == 'O' ){
                    return 2;
                }
            }
        }
        // CEK DIAGONAL 1
        if( kotak[0][0] != ' ' &&
            kotak[0][0] == kotak[1][1] &&
            kotak[0][0] == kotak[2][2] &&
            kotak[0][0] == kotak[3][3] &&
            kotak[0][0] == kotak[4][4] ){
            if ( kotak[0][0] == 'X' )
            {
                return 1;
            }
            else if ( kotak[0][0] == 'O' )
            {
                return 2;
            }
        }
        else if( kotak[1][1] != ' ' &&
            kotak[1][1] == kotak[2][2] &&
            kotak[1][1] == kotak[3][3] &&
            kotak[1][1] == kotak[4][4] &&
            kotak[1][1] == kotak[5][5] ){
            if ( kotak[1][1] == 'X' )
            {
                return 1;
            }
            else if ( kotak[1][1] == 'O' )
            {
                return 2;
            }
        }
        else if( kotak[2][2] != ' ' &&
            kotak[2][2] == kotak[3][3] &&
            kotak[2][2] == kotak[4][4] &&
            kotak[2][2] == kotak[5][5] &&
            kotak[2][2] == kotak[6][6] ){
            if ( kotak[2][2] == 'X' )
            {
                return 1;
            }
            else if ( kotak[2][2] == 'O' )
            {
                return 2;
            }
        }
        else if( kotak[1][0] != ' ' &&
            kotak[1][0] == kotak[2][1] &&
            kotak[1][0] == kotak[3][2] &&
            kotak[1][0] == kotak[4][3] &&
            kotak[1][0] == kotak[5][4] ){
            if ( kotak[1][0] == 'X' )
            {
                return 1;
            }
            else if ( kotak[1][0] == 'O' )
            {
                return 2;
            }
        }
        else if( kotak[2][1] != ' ' &&
            kotak[2][1] == kotak[3][2] &&
            kotak[2][1] == kotak[4][3] &&
            kotak[2][1] == kotak[5][4] &&
            kotak[2][1] == kotak[6][5] ){
            if ( kotak[2][1] == 'X' )
            {
                return 1;
            }
            else if ( kotak[2][1] == 'O' )
            {
                return 2;
            }
        }
        else if( kotak[1][2] != ' ' &&
            kotak[1][2] == kotak[2][3] &&
            kotak[1][2] == kotak[3][4] &&
            kotak[1][2] == kotak[4][5] &&
            kotak[1][2] == kotak[5][6] ){
            if ( kotak[1][2] == 'X' )
            {
                return 1;
            }
            else if ( kotak[1][2] == 'O' )
            {
                return 2;
            }
        }
        else if( kotak[2][0] != ' ' &&
            kotak[2][0] == kotak[3][1] &&
            kotak[2][0] == kotak[4][2] &&
            kotak[2][0] == kotak[5][3] &&
            kotak[2][0] == kotak[6][4] ){
            if ( kotak[2][0] == 'X' )
            {
                return 1;
            }
            else if ( kotak[2][0] == 'O' )
            {
                return 2;
            }
        }
        else if( kotak[0][2] != ' ' &&
            kotak[0][2] == kotak[1][3] &&
            kotak[0][2] == kotak[2][4] &&
            kotak[0][2] == kotak[3][5] &&
            kotak[0][2] == kotak[4][6] ){
            if ( kotak[0][2] == 'X' )
            {
                return 1;
            }
            else if ( kotak[0][2] == 'O' )
            {
                return 2;
            }
        }
        
        // CEK DIAGONAL 2
        else if( kotak[0][6] != ' ' &&
            kotak[0][6] == kotak[1][5] &&
            kotak[0][6] == kotak[2][4] &&
            kotak[0][6] == kotak[3][3] &&
            kotak[0][6] == kotak[4][2] ){
            if ( kotak[0][6] == 'X' )
            {
                return 1;
            }
            else if ( kotak[0][6] == 'O' )
            {
                return 2;
            }
        }
        else if( kotak[1][5] != ' ' &&
            kotak[1][5] == kotak[2][4] &&
            kotak[1][5] == kotak[3][3] &&
            kotak[1][5] == kotak[4][2] &&
            kotak[1][5] == kotak[5][1] ){
            if ( kotak[1][5] == 'X' )
            {
                return 1;
            }
            else if ( kotak[1][5] == 'O' )
            {
                return 2;
            }
        }
        else if( kotak[2][4] != ' ' &&
            kotak[2][4] == kotak[3][3] &&
            kotak[2][4] == kotak[4][2] &&
            kotak[2][4] == kotak[5][1] &&
            kotak[2][4] == kotak[6][0] ){
            if ( kotak[2][4] == 'X' )
            {
                return 1;
            }
            else if ( kotak[2][4] == 'O' )
            {
                return 2;
            }
        }
        else if( kotak[1][6] != ' ' &&
            kotak[1][6] == kotak[2][5] &&
            kotak[1][6] == kotak[3][4] &&
            kotak[1][6] == kotak[4][3] &&
            kotak[1][6] == kotak[5][2] ){
            if ( kotak[1][6] == 'X' )
            {
                return 1;
            }
            else if ( kotak[1][6] == 'O' )
            {
                return 2;
            }
        }
        else if( kotak[2][5] != ' ' &&
            kotak[2][5] == kotak[3][4] &&
            kotak[2][5] == kotak[4][3] &&
            kotak[2][5] == kotak[5][2] &&
            kotak[2][5] == kotak[6][1] ){
            if ( kotak[2][5] == 'X' )
            {
                return 1;
            }
            else if ( kotak[2][5] == 'O' )
            {
                return 2;
            }
        }
        else if( kotak[0][4] != ' ' &&
            kotak[0][4] == kotak[1][3] &&
            kotak[0][4] == kotak[2][2] &&
            kotak[0][4] == kotak[3][1] &&
            kotak[0][4] == kotak[4][0] ){
            if ( kotak[0][4] == 'X' )
            {
                return 1;
            }
            else if ( kotak[0][4] == 'O' )
            {
                return 2;
            }
        }
        else if( kotak[2][6] != ' ' &&
            kotak[2][6] == kotak[3][5] &&
            kotak[2][6] == kotak[4][4] &&
            kotak[2][6] == kotak[5][3] &&
            kotak[2][6] == kotak[6][2] ){
            if ( kotak[2][6] == 'X' )
            {
                return 1;
            }
            else if ( kotak[2][6] == 'O' )
            {
                return 2;
            }
        }
        return -1;
    }
}