#include <stdbool.h>
struct Game
{
	int game_id;
	int score1;
	int score2;
	char player1[100];
	char player2[100];
	char papan[10];
	int giliran;
    bool inisialisasi;
};

struct Game game[100];
int id;
int giliran;