#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

#define up 72
#define down 80
#define left 75
#define right 77

#define w 119
#define s 115
#define a 97
#define d 100

#define W 87
#define S 83
#define A 65
#define D 68

typedef struct {
	char namaPlayer[100];
	int score;
}Player;

typedef struct {
	char kotak[7][7];
	int jenisPapan;
}Board;

typedef struct {
	int id_game; 		
	int giliran;
    int pilihPertama;
	int jenisPermainanPlayer;
    Player pemain1; 	
    Player pemain2; 	
    Board papan; 		
}Game;

typedef struct
{
	int row, col;
} Move;

// PLAY GAME
void playgame(Game *game, bool *_kondisiPilihanPapan, bool *_kondisiPilihanPlayer, bool *_kondisiAfterGame, int _pilihanPlayer );


// FILE HANDLING
int isiID();
void loadGame( Game *game );
void highscore();
void tampilkanData();
void saveData( Game _game );

// AI
int _max(int v1, int v2);
int _min(int v1, int v2);
bool isMovesLeft(char _papan[7][7]);
int evaluate(int _flag, char b[7][7]);
Move findBestMove(int _flag, char _papan[7][7]);
int minimax(int _flag, char _papan[7][7], int depth, bool isMax);
void pilihIndexKomputer(int _flag, int *_baris, int *_kolom , char _papan[7][7]);

// TEKNIS PLAY GAME
void markIndex(int _giliran, int _pilihPertama, char (*_papanKotak)[7][7], int _baris, int _kolom );
void pilihIndexPapan( int _flagIndex, int _jenisPapan, int _giliran, int _pilihPertama, char _papan[7][7], int *_baris, int *_kolom );
void tampilkanPemenang(char _namaPlayer1[100], char _namaPlayer2[100], int _pemenang , int _giliran, int _jenisPapan);
void resetAtributPlayGame( int *_pemenang, int *_giliran, int *_pilihPertama, char (*_papan)[7][7], bool *_kondisiPemenang );
void cekKondisiPemenang(int _flag, char _papan[7][7], int *_pemenang, bool *_kondisiPemenang, int _giliran, int *_score1, int *_score2);
void setelahCekMenang( Game _game, bool *_kondisiGame, bool *_kondisiPemenang, bool *_kondisiPilihGiliranPertama , bool *_kondisiPilihanPapan, bool *_kondisiPilihanPlayer, bool *_kondisiAfterGame);
void gantiGiliran(int *_giliran, int *_pilihPertama);

//INISIALISASI
// void inisialisasi( Game *_game, int _id );
void scanNama( int _flagInputNama, char (*_namaPlayer)[100]);
void inisialisasi(Game *_game, int *_jenisPapan, int _pilihanPapan, bool *_kondisiPilihGiliranPertama,  bool *_kondisiPemenang, bool *_kondisiGame );

// TEKNIS
void koor(int x, int y);
void setcolor(unsigned short color);
HWND WINAPI GetConsoleWindowNT(void);
void printPanah( int _panx, int _pany );
void pilihHalaman( int _flagHalaman, int *_pilihanHalaman );

// BANNER
void dashboard(char _namaPlayer1[100], char _namaPlayer2[100], int _pertama, int _giliran, int _score1, int _score2, int _id);
void banner1();
void banner2();
void loading();

// HALAMAN
void tampilanMenu();
void tampilanPlayer();
void tampilanBoard();
void tampilanHowToPlay();
void tampilanAboutUs();
void tampilSetelahBermain();
void tampilanPilihPertama();
void tampilWinorDraw(char _namaPlayer1[100], char _namaPlayer2[100], int _pemenang, int _giliran, int _jenisPapan);
void inputNama( int _flagInputNama, char (*_namaPlayer1)[100], char (*_namaPlayer2)[100]);

// PAPAN
void printPapan(int _flagPapan, char _papan[7][7] );