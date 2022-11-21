#include <stdio.h>
#include "global.h"
void inputNamaPlayer( int _player, int _id )
{
    if ( _player == 1 )
    {
       printf("Masukan nama player ke 1 : ");
       scanf(" %[^\n]", &game[_id].player1);
    }else if ( _player == 2)
    {
       printf("Masukan nama player ke 2 : ");
       scanf(" %[^\n]", &game[_id].player2);
    }
}