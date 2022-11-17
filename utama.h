#ifndef UTAMA_H
#define UTAMA_H

// Deklaration Struct for 2 player
struct Game
{	
	int id_game;
	int score1;
	int score2;
	char player1[100];
	char player2[100];	
} game[100];

// Deklarasi Modular
void player2();
void printPapan();
void inputNamaPlayer();
void clear();
void playgame();
void mark();
void replay();
int cekPemenang();



// Declaration Variabel Global
extern char papan[11];
extern int game_id;
extern int giliran;

//#define papan 0123456789
//#define game_id 1
//#define giliran 1
#endif