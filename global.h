#include <stdbool.h>
struct Game
{
	int game_id; // untuk save and load nanti

	int score1; // untuk menyimpan score player 1
	int score2; // untuk menyimpan score player 2
	int score_com; // untuk menyimpan score computer

	char player1[100]; // nama dari player 1
	char player2[100]; // nama dari player 2

    int jenisPlayer; // untuk mengecek kondisi jenis player yang dimainkan 1 untuk p vs com, 2 untuk p vs p

	int giliran; // untuk mengecek giliran yang menginput mark O dan X jika ganjil maka X

	char papan[7][7]; // untuk papan matrik

	bool papan1; // untuk papan matrik 3x3 jika true
	bool papan2; // untuk papan matrik 5x5 jika true
	bool papan3; // untuk papan matrik 7x7 jika true

    // bool inisialisasi; // kondisi untuk di cek jika inisialisasi sudah di lakukan
};

struct Game game[100]; // game yang memiliki maks id game hingga 100
int id; // untuk mengisi save and load pada file id
int pilihanMenu;
int pilihPapanGlobal;