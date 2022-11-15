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


int cekVertikal();
int cekPemenang();

int main()
{
	int pemenang = 0;
	
	gameBoard();
	inputNamaPlayer();
	
	system("cls");
	
	
	
	do {
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
		
		pemenang = cekPemenang();
		
		
	
	} while ( giliran <= 9 && pemenang == 0 );
	
	
	if ( pemenang == 1 )
	{
		printf("Selamat player 1 menang aokwokwkko kontol\n");
	}
	else if ( pemenang == 2 )
	{
		printf("Selamat player 2 menang aokwokwkko MEMEK\n");
	}
	else if ( pemenang == 3 )
	{
		printf("DRAWWWW!!!!!\n");
		
	}
	
		
	return 0;
}

int cekPemenang()
{
	
	if ( 
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
	else if ( papan[1] == 'X' && papan[2] == 'X' && papan[3] == 'X' )
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
	}

	else
	{
		return 0;
	}
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