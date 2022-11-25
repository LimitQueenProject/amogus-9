
#include <stdio.h>
typedef struct {
	char namaPlayer;    // nama dari player yang bermain
	int scored;         // score atau poin dari pemain
	int giliran;		// 1 untuk player dan 0 untuk lawan
}Player;

typedef struct {
	char kotak[7][7];   // array yang dipakai untuk mengisi kotak tic tac toe
	int jenisPapan;     // jenis papan, contoh : 3x3, 5x5, 7x7
}Board;

typedef struct {
	int id_game;  
/*
    id game adalah kode atau no permainan yang mana akan di inputkan 
    ketika load game dan disimpan ketika save game
*/
    Player pemain[2];
/*
    pemain adalah array integer bertipe Player yang digunakan 
    untuk permainan player versus player
*/    
    Board papan;
/*
    papan adalah tempat permainan tictactoe berlangsung
    digunakan juga pada proses save dan load
*/
    int jenisPlayer;
/*
    seperti flag yang jika nilai nya 1 adalah player vs computer, dan jika 2 adalah player vs player
*/
}Game;

void banner1();
/*Menampilkan tampilan awal seperti logo dan loading*/
void banner2();
/*Menampilkan tampilan awal seperti logo dan loading*/

void tampilanMenu();
/*Menampilkan pilihan menu sebagai berikut :
    1. Play Game
    2. How To Play
    3. About Us
*/

void tampilanHowToPlay();
/*Menampilkan cara bermain permainan Tic Tac Toe, yaitu sebagai berikut
    1. Permainan di mulai dengan menggunakan ukuran papan, yaitu 3x3, 5x5, dan 7x7
    2. Terdapat 2 player yang dapat bermain, yaitu dapat melawan sesama player atau melawan computer
    3. Player 1 menggunakan tanda X dan player 2 menggunakan tanda O
    4. Memilih kotak yang akan diisi oleh player, dengan ketentuan tidak boleh memilih kotak yang sudah dipiloh
    5. Player pertama yang berhasil membuat garis dengan tandanya baik itu horizontal, vertikal, maupun diagonal
       maka dinyatakan pemenangnya
    6. Jika tidak ada satupun player yang berhasil membuat garis, maka game tersebut di anggap seri atau draw
*/

void tampilanAboutUs();
/*

*/

void opening();
/*
    I.S = belum ada tampilan awal game
    F.S = sudah ada tampilan awal game
*/

void listMenu();
/*
    I.S = belum ada tampilan menu
    F.S = tampil isi dari pilihan menu

    dan 
*/

