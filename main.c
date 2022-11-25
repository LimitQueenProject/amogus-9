/* Bermain Game TicTacToe
I.S. : Diketahui data yang dibutuhkan pada file header
F.F. : Bermain game tictactoe dengan happy
Author : Farhan, Azhar, Roy
Versi : v.1
Tanggal : 11/2022
*/
#include "header.h"

#include <stdio.h>
#include <windows.h>

int main()
{
    int i;
    int pilihanMenu;
    int pilihanPlayer;

    // 1. Halaman Menu
    system("mode 800");
    pilihanMenu = CekMenu( panah(1) );


    // 
    switch (pilihanMenu)
    {
    case 1:
        pilihanPlayer = CekPlayer( panah(2) );
        break;
    // case 2:
    //     tampilanHowToPlay();        
    //     break;
    // case 3:
    //     tampilanAboutUs();
    //     break;
    }



    scanf("%d", &i);
    return 0;
}