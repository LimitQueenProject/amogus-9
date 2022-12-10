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
#define d 20

#define W 87
#define S 83
#define A 65
#define D 68

typedef struct {
	char namaPlayer[20];
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
	int pemenang;
	bool kondisiInisialisasi;
    Player pemain1; 	
    Player pemain2; 	
    Board papan; 		
}Game;


// KATEGORI TAMPILAN TAMPILAN
// BANNER > DONE
void dashboard(char _namaPlayer1[20], char _namaPlayer2[20], int _pertama, int _giliran, int _score1, int _score2, int _id);
void banner1();
void banner2();

// TAMPILAN HALAMAN > DONE
void tampilanMenu();
void tampilanPlayer();
void tampilanBoard();
void tampilanHowToPlay();
void tampilanAboutUs();
void tampilSetelahBermain();
void tampilanPilihPertama();
void tampilWinorDraw(char _namaPlayer1[20], char _namaPlayer2[20], int _pemenang, int _giliran, int _jenisPapan);


// LOADING > DONE
void loading();

// PRINT PAPAN
void printPapan(int _flagPapan, char _papan[7][7] );

// KATGORI TEKNIS TEKNIS
// CONSOLE > DONE
HWND WINAPI GetConsoleWindowNT(void);

// KOORDINAT > DONE
void koor(int x, int y);
void printPanah( int _panx, int _pany );

// KATEGORI INISIALISASI
// PILIH HALAMAN > DONE
void pilihHalaman( int _flagHalaman, int *_pilihanHalaman );

// INISIALISASI > DONE
// void inisialisasi( char (*_namaPlayer1)[20], char (*_namaPlayer2)[20], int *_id, int *_giliran, int *_score1, int *_score2, char (*_kotak)[7][7], int _jenisPlayer );
void inisialisasi( Game *game );
int isiID();

// KATEGORI PLAY GAME
// PLAY GAME > DONE
void playgame(Game *game);

// PILIH INDEX > DONE
void pilihIndexPapan(int _flagIndex, int _jenisPapan, int _giliran, int _pilihPertama, char _papan[7][7], int *_baris, int *_kolom);
void pilihIndexKomputer( int _jenisPapan, int *_baris, int *_kolom, char _papan[7][7] );

// MARK INDEX > DONE
void markIndex(int _giliran, int _pilihPertama, char (*_papanKotak)[7][7], int _baris, int _kolom );

// CEK PEMENANG 
int cekPemenang(int _jenisPapan, char kotak[7][7]);

// RESET ATRIBUT > DONE
void resetAtributPlayGame(int *_pemenang, int *_giliran, char (*_papan)[7][7]);

// SETELAH CEK PEMENANG
void setelahCekMenang(Game _game, int *_halaman, bool *_maingame, bool *_kondisiSetelahMenang, bool *_kondisiGantiGiliran, bool *_kondisiInisialisasi);

// KATEGORI FILE HANDLING
// FILE HANDLING > DONE
void saveData( Game _game );

//LOAD DATA > DONE
void loadGame( Game *game, bool *_kondisiLoadgame );

// TAMPILKAN DATA YANG DI BISA DI LOAD > DONE
void tampilkanData();

// HIGSCORE
void highScore();


// typedef struct
// {
// 	int row, col;
// } Move;

// // PLAY GAME
// void playgame(Game *game, bool *_kondisiPilihanPapan, bool *_kondisiPilihanPlayer, bool *_kondisiAfterGame, int _pilihanPlayer );


// // FILE HANDLING
// int isiID();
// void loadGame( Game *game );
// void highscore();
// void tampilkanData();
// void saveData( Game _game );

// // AI
// int _max(int v1, int v2);
// int _min(int v1, int v2);
// bool isMovesLeft(char _papan[7][7]);
// int evaluate(int _flag, char b[7][7]);
// Move findBestMove(int _flag, char _papan[7][7]);
// int minimax(int _flag, char _papan[7][7], int depth, bool isMax);
// void pilihIndexKomputer(int _flag, int *_baris, int *_kolom , char _papan[7][7]);

// // TEKNIS PLAY GAME
// void pilihIndexPapan( int _flagIndex, int _jenisPapan, int _giliran, int _pilihPertama, char _papan[7][7], int *_baris, int *_kolom );
// void tampilkanPemenang(char _namaPlayer1[20], char _namaPlayer2[20], int _pemenang , int _giliran, int _jenisPapan);
// void cekKondisiPemenang(int _flag, char _papan[7][7], int *_pemenang, bool *_kondisiPemenang, int _giliran, int *_score1, int *_score2);
// void setelahCekMenang( Game _game, bool *_kondisiGame, bool *_kondisiPemenang, bool *_kondisiPilihGiliranPertama , bool *_kondisiPilihanPapan, bool *_kondisiPilihanPlayer, bool *_kondisiAfterGame);
// void gantiGiliran(int *_giliran, int *_pilihPertama);

// //INISIALISASI
// void scanNama( int _flagInputNama, char (*_namaPlayer)[20]);

// // TEKNIS
// void setcolor(unsigned short color);

// // BANNER

// // HALAMAN
// void inputNama( int _flagInputNama, char (*_namaPlayer1)[20], char (*_namaPlayer2)[20]);
