#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utama.h"
char papan[11] = "0123456789";
int game_id = 1;
int giliran = 1;

void player2()
{
	printPapan();
	inputNamaPlayer();
	clear();
	playgame();
}

int cekPemenang()
{
	if ( papan[1] == 'X' && papan[2] == 'X' && papan[3] == 'X' )
	{
		return 1;
	}
	else if ( papan[4] == 'X' && papan[5] == 'X' && papan[6] == 'X' )
	{
		return 1;
	}
	else if ( papan[7] == 'X' && papan[8] == 'X' && papan[9] == 'X' )
	{
		return 1;
	}
	else if ( papan[1] == 'X' && papan[4] == 'X' && papan[7] == 'X' )
	{
		return 1;
	}
	else if ( papan[2] == 'X' && papan[5] == 'X' && papan[8] == 'X' )
	{
		return 1;
	}
	else if ( papan[3] == 'X' && papan[6] == 'X' && papan[9] == 'X' )
	{
		return 1;
	}
	else if ( papan[1] == 'X' && papan[5] == 'X' && papan[9] == 'X' )
	{
		return 1;
	}
	else if ( papan[3] == 'X' && papan[5] == 'X' && papan[7] == 'X' )
	{
		return 1;
	}
	
	// O
	else if ( papan[1] == 'O' && papan[2] == 'O' && papan[3] == 'O' )
	{
		return 2;
	}
	else if ( papan[4] == 'O' && papan[5] == 'O' && papan[6] == 'O' )
	{
		return 2;
	}
	else if ( papan[7] == 'O' && papan[8] == 'O' && papan[9] == 'O' )
	{
		return 2;
	}
	else if ( papan[1] == 'O' && papan[4] == 'O' && papan[7] == 'O' )
	{
		return 2;
	}
	else if ( papan[2] == 'O' && papan[5] == 'O' && papan[8] == 'O' )
	{
		return 2;
	}
	else if ( papan[3] == 'O' && papan[6] == 'O' && papan[9] == 'O' )
	{
		return 2;
	}
	else if ( papan[1] == 'O' && papan[5] == 'O' && papan[9] == 'O' )
	{
		return 2;
	}
	else if ( papan[3] == 'O' && papan[5] == 'O' && papan[7] == 'O' )
	{
		return 2;
	}else if ( 
	papan[1] != '1' && 
	papan[2] != '2' && 
	papan[3] != '3' && 
	papan[4] != '4' && 
	papan[5] != '5' && 
	papan[6] != '6' && 
	papan[7] != '7' && 
	papan[8] != '8' && 
	papan[9] != '9' )
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

void playgame()
{
	int pemenang = 0;
	int score = 0;
	game[game_id].score1 = score;
	game[game_id].score2 = score;
	do {
		clear();
		printPapan();
		mark();
		clear();
		printPapan();
		
		pemenang = cekPemenang();
	} 
	while ( giliran <= 9 && pemenang == 0);

	giliran = 1;
	strcpy(papan, "0123456789");
	
	if ( pemenang == 1 )
	{
		printf("Selamat player 1 menang aokwokwkko\n\n");
		game[game_id].score1++;
		replay();
	}
	else if ( pemenang == 2 )
	{
		printf("Selamat player 2 menang aokwokwkko\n\n");
		game[game_id].score2++;
		replay();
	}
	else if ( pemenang == 3 )
	{
		printf("DRAWWWW!!!!!\n\n");
		replay();
	}
	
}

void replay()
{
	char cek;
	printf("\nMau main lagi ? ya (y) tidak (n) : ");
	scanf(" %c", &cek);
	
	if ( cek == 'y' )
	{
		playgame();
	}
	else if( cek == 'n' )
	{
		exit;
	}
	else {
		replay();
	}
}

void clear()
{
	system("cls");
}

void mark()
{
	int pilihanPlayer = 0;
	
	do {
		if ( giliran % 2 == 1 )
		{
			printf("%s, Masukan pilihan anda : ", game[game_id].player1);
			scanf("%d", &pilihanPlayer);
		}else
		{
			printf("%s, Masukan pilihan anda : ", game[game_id].player2);
			scanf("%d", &pilihanPlayer);
		}
			
	} while ( papan[pilihanPlayer] == 'X' || papan[pilihanPlayer] == 'O' || pilihanPlayer > 9 );

	if ( giliran % 2 == 1 ){
		papan[pilihanPlayer] = 'X';
	}else{
		papan[pilihanPlayer] = 'O';
	}
	
	giliran++;
}


void inputNamaPlayer()
{
	printf("Nama player 1 : ");
	scanf(" %[^\n]",game[game_id].player1);
	
	printf("Nama player 2 : ");
	scanf(" %[^\n]",game[game_id].player2);
	
}

void printPapan()
{
	printf("\n\n\n");
    printf("  %c |  %c |  %c \n", papan[1], papan[2], papan[3]);
    printf(" ___|____|____\n");
    printf("    |    |     \n");
    printf("  %c |  %c |  %c \n", papan[4], papan[5], papan[6]);
    printf(" ___|____|____\n");
    printf("    |    |     \n");
    printf("  %c |  %c |  %c \n", papan[7], papan[8], papan[9]);
    printf("\n\n\n");
}
