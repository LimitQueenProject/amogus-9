#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


char player1[100];
char player2[100];
char papan[10] = "0123456789";
int giliran = 1;


void gameBoard();
void inputNamaPlayer();
void markPlayer1();
void markPlayer2();
void clear();


int main()
{
	gameBoard();
	inputNamaPlayer();
	
	system("cls");
	
	
	while ( giliran <= 9 )
	{
		if ( giliran % 2 == 1 )
		{
			gameBoard();
			markPlayer1();
		}
		else if ( giliran % 2 == 0 )
		{
			gameBoard();
			markPlayer2();
		}
		
		if ( giliran < 10 )
		{
			system("cls");
		}
		else if ( giliran = 10 )
		{
			clear();
			gameBoard();
		}	
	
	}
	
	
	return 0;
}

void markPlayer1()
{
	int pilihanPlayer = 0;
	char mark1 = 'X';
	bool cek_pilihanPlayer = false;

	do {
		clear();
		printf("%d\n", giliran);
		gameBoard();
		printf("X\n");
		printf("%s, Masukan pilihan anda : ", player1);
		scanf("%d", &pilihanPlayer);
	} while ( papan[pilihanPlayer] == 'X' || papan[pilihanPlayer] == 'O' || pilihanPlayer > 9 );
	
	papan[pilihanPlayer] = mark1;
	
	giliran++;
}

void markPlayer2()
{
	int pilihanPlayer = 0;
	char mark2 = 'O';
	bool cek_pilihanPlayer = false;

	do {
		clear();
		printf("%d\n", giliran);
		gameBoard();
	
		printf("O\n");
		printf("%s, Masukan pilihan anda : ", player2);
		scanf("%d", &pilihanPlayer);
		
	} while ( (papan[pilihanPlayer] == 'X' || papan[pilihanPlayer] == 'O') || pilihanPlayer > 9 );
	
	papan[pilihanPlayer] = mark2;
	
	giliran++;
		
}


void inputNamaPlayer()
{
	printf("Nama player 1 : ");
	gets(player1);
	
	printf("Nama player 2 : ");
	gets(player2);
}

void gameBoard()
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

void clear()
{
	system("cls");
}