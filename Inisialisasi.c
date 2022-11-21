#include <string.h>
#include "global.h"

void Inisialisasi(int _id, int _giliran)
{
    game[_id].game_id = _id;
    game[_id].score1 = 0;
    game[_id].score2 = 0;
    strcpy(game[_id].papan, "0123456789");
    game[_id].giliran = _giliran;
    game[_id].inisialisasi = true;
}