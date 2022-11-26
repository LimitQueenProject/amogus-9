

#include "header.h"

#include <stdio.h>

void DisplayPapan3x3(int _id)
{
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         game[_id].papan.kotak[i][j]=' ';
    //     }
    // }
    koor(73,6);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,194,196,196,196,196,196,194,196,196,196,196,196,194,196,196,196,196,196,191);
    koor(73,7);printf("%c     %c     %c     %c     %c",179,179,179,179,179);
    koor(73,8);printf("%c  i  %c  1  %c  2  %c  3  %c",179,179,179,179,179);
    koor(73,9);printf("%c     %c     %c     %c     %c",179,179,179,179,179);
    koor(73,10);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(73,11);printf("%c     %c     %c     %c     %c",179,179,179,179,179);
    koor(73,12);printf("%c  A  %c  %c  %c  %c  %c  %c  %c",179,179, game[_id].papan.kotak[0][0],179, game[_id].papan.kotak[0][1],179, game[_id].papan.kotak[0][2],179);
    koor(73,13);printf("%c     %c     %c     %c     %c",179,179,179,179,179);
    koor(73,14);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(73,15);printf("%c     %c     %c     %c     %c",179,179,179,179,179);
    koor(73,16);printf("%c  B  %c  %c  %c  %c  %c  %c  %c",179,179, game[_id].papan.kotak[1][0],179, game[_id].papan.kotak[1][1],179, game[_id].papan.kotak[1][2],179);
    koor(73,17);printf("%c     %c     %c     %c     %c",179,179,179,179,179);
    koor(73,18);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(73,19);printf("%c     %c     %c     %c     %c",179,179,179,179,179);
    koor(73,20);printf("%c  C  %c  %c  %c  %c  %c  %c  %c",179,179, game[_id].papan.kotak[2][0],179, game[_id].papan.kotak[2][1],179, game[_id].papan.kotak[2][2],179);
    koor(73,21);printf("%c     %c     %c     %c     %c",179,179,179,179,179);
    koor(73,22);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,193,196,196,196,196,196,193,196,196,196,196,196,193,196,196,196,196,196,217);
}
void DisplayPapan5x5(int _id){
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5;j++){
    //         game[_id].papan.kotak[i][j]=' ';
    //     }
    // }
    koor(67,6);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,194,196,196,196,196,196,194,196,196,196,196,196,194,196,196,196,196,196,194,196,196,196,196,196,194,196,196,196,196,196,191);
    koor(67,7);printf("%c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179);
    koor(67,8);printf("%c  i  %c  1  %c  2  %c  3  %c  4  %c  5  %c",179,179,179,179,179,179,179);
    koor(67,9);printf("%c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179);
    koor(67,10);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(67,11);printf("%c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179);
    koor(67,12);printf("%c  A  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c",179,179,game[_id].papan.kotak[0][0],179,game[_id].papan.kotak[0][1],179,game[_id].papan.kotak[0][2],179,game[_id].papan.kotak[0][3],179,game[_id].papan.kotak[0][4],179);
    koor(67,13);printf("%c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179);
    koor(67,14);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(67,15);printf("%c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179);
    koor(67,16);printf("%c  B  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c",179,179,game[_id].papan.kotak[1][0],179,game[_id].papan.kotak[1][1],179,game[_id].papan.kotak[1][2],179,game[_id].papan.kotak[1][3],179,game[_id].papan.kotak[1][4],179);
    koor(67,17);printf("%c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179);
    koor(67,18);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(67,19);printf("%c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179);
    koor(67,20);printf("%c  C  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c",179,179,game[_id].papan.kotak[2][0],179,game[_id].papan.kotak[2][1],179,game[_id].papan.kotak[2][2],179,game[_id].papan.kotak[2][3],179,game[_id].papan.kotak[2][4],179);
    koor(67,21);printf("%c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179);
    koor(67,22);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(67,23);printf("%c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179);
    koor(67,24);printf("%c  D  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c",179,179,game[_id].papan.kotak[3][0],179,game[_id].papan.kotak[3][1],179,game[_id].papan.kotak[3][2],179,game[_id].papan.kotak[3][3],179,game[_id].papan.kotak[3][4],179);
    koor(67,25);printf("%c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179);
    koor(67,26);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(67,27);printf("%c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179);
    koor(67,28);printf("%c  E  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c",179,179,game[_id].papan.kotak[4][0],179,game[_id].papan.kotak[4][1],179,game[_id].papan.kotak[4][2],179,game[_id].papan.kotak[4][3],179,game[_id].papan.kotak[4][4],179);
    koor(67,29);printf("%c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179);
    koor(67,30);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,193,196,196,196,196,196,193,196,196,196,196,196,193,196,196,196,196,196,193,196,196,196,196,196,193,196,196,196,196,196,217);
}

void DisplayPapan7x7(int _id)
{
    // for(int i=0;i<7;i++){
    //     for(int j=0;j<7;j++){
    //         game[_id].papan.kotak[i][j]=' ';
    //     }
    // }
    koor(64,6);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,194,196,196,196,196,196,194,196,196,196,196,196,194,196,196,196,196,196,194,196,196,196,196,196,194,196,196,196,196,196,194,196,196,196,196,196,194,196,196,196,196,196,191);
    koor(64,7);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,8);printf("%c  i  %c  1  %c  2  %c  3  %c  4  %c  5  %c  6  %c  7  %c",179,179,179,179,179,179,179,179,179);
    koor(64,9);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,10);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(64,11);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,12);printf("%c  A  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c",179,179,game[_id].papan.kotak[0][0],179,game[_id].papan.kotak[0][1],179,game[_id].papan.kotak[0][2],179,game[_id].papan.kotak[0][3],179,game[_id].papan.kotak[0][4],179,game[_id].papan.kotak[0][5],179,game[_id].papan.kotak[0][6],179);
    koor(64,13);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,14);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(64,15);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,16);printf("%c  B  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c",179,179,game[_id].papan.kotak[1][0],179,game[_id].papan.kotak[1][1],179,game[_id].papan.kotak[1][2],179,game[_id].papan.kotak[1][3],179,game[_id].papan.kotak[1][4],179,game[_id].papan.kotak[1][5],179,game[_id].papan.kotak[1][6],179);
    koor(64,17);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,18);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(64,19);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,20);printf("%c  C  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c",179,179,game[_id].papan.kotak[2][0],179,game[_id].papan.kotak[2][1],179,game[_id].papan.kotak[2][2],179,game[_id].papan.kotak[2][3],179,game[_id].papan.kotak[2][4],179,game[_id].papan.kotak[2][5],179,game[_id].papan.kotak[2][6],179);
    koor(64,21);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,22);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(64,23);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,24);printf("%c  D  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c",179,179,game[_id].papan.kotak[3][0],179,game[_id].papan.kotak[3][1],179,game[_id].papan.kotak[3][2],179,game[_id].papan.kotak[3][3],179,game[_id].papan.kotak[3][4],179,game[_id].papan.kotak[3][5],179,game[_id].papan.kotak[3][6],179);
    koor(64,25);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,26);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(64,27);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,28);printf("%c  E  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c",179,179,game[_id].papan.kotak[4][0],179,game[_id].papan.kotak[4][1],179,game[_id].papan.kotak[4][2],179,game[_id].papan.kotak[4][3],179,game[_id].papan.kotak[4][4],179,game[_id].papan.kotak[4][5],179,game[_id].papan.kotak[4][6],179);
    koor(64,29);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,30);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(64,31);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,32);printf("%c  F  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c",179,179,game[_id].papan.kotak[5][0],179,game[_id].papan.kotak[5][1],179,game[_id].papan.kotak[5][2],179,game[_id].papan.kotak[5][3],179,game[_id].papan.kotak[5][4],179,game[_id].papan.kotak[5][5],179,game[_id].papan.kotak[5][6],179);
    koor(64,33);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,34);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
    koor(64,35);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,36);printf("%c  G  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c",179,179,game[_id].papan.kotak[6][0],179,game[_id].papan.kotak[6][1],179,game[_id].papan.kotak[6][2],179,game[_id].papan.kotak[6][3],179,game[_id].papan.kotak[6][4],179,game[_id].papan.kotak[6][5],179,game[_id].papan.kotak[6][6],179);
    koor(64,37);printf("%c     %c     %c     %c     %c     %c     %c     %c     %c",179,179,179,179,179,179,179,179,179);
    koor(64,38);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,193,196,196,196,196,196,193,196,196,196,196,196,193,196,196,196,196,196,193,196,196,196,196,196,193,196,196,196,196,196,193,196,196,196,196,196,193,196,196,196,196,196,217);
}