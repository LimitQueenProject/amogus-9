#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

/*---------------------------------------Deklarasi variabel konstan---------------------------------------*/
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
/*--------------------------------------------------------------------------------------------------------*/

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
	bool kondisiInisialisasi;
    Player pemain1; 	
    Player pemain2; 	
    Board papan; 		
}Game;

typedef struct {
	int baris;
	int kolom;
}Index;

// KATEGORI TAMPILAN TAMPILAN
// BANNER > DONE
void dashboard(char _namaPlayer1[20], char _namaPlayer2[20], int _pertama, int _giliran, int _score1, int _score2, int _id);
/*
	Deskripsi = Modul ini bertujuan untuk menampilkan data, 
				yaitu ID Game, nama player 1 dan player 2 beserta score yang diperoleh, 
				waktu yang tersisa atau countdown, dan giliran player.
	
	I.S = Data dashboard belum tampil yaitu score, nama, giliran, dan id. 
	F.S = Sudah tampil score, nama, giliran, dan id pada layar.
*/

void banner1();
/*
	Deskripsi = Modul ini bertujuan untuk menampilkan banner yang 
				digunakan pada bagian loading
	
	I.S = Banner belum tampil pada layar. 
	F.S = Banner sudah tampil pada layar.
*/
void banner2();
/*
	Deskripsi = Modul ini bertujuan untuk menampilkan banner yang 
				digunakan pada halaman menu, loadgame, highscore,
				How To Play, dan About us
	
	I.S = Banner belum tampil pada layar. 
	F.S = Banner sudah tampil pada layar.
*/


// TAMPILAN HALAMAN > DONE
void tampilanMenu();
/*
	Deskripsi = Modul ini dipakai untuk menampilkan tampilan menu.

	I.S = belum tampil menu.
	F.S = sudah tampil menu.
*/

void tampilanPlayer();
/*
	Deskripsi = Modul ini dipakai untuk menampilkan tampilan pilih player.

	I.S = belum tampil pilih player.
	F.S = sudah tampil pilih player.
*/

void tampilanBoard();
/*
	Deskripsi = Modul ini dipakai untuk menampilkan tampilan pilih papan.

	I.S = belum tampil pilih papan.
	F.S = sudah tampil pilih papan.
*/

void tampilanHowToPlay();
/*
	Deskripsi = Modul ini dipakai untuk menampilkan tampilan penjelasan
				cara bermain.

	I.S = belum tampil penjelasan cara bermain.
	F.S = sudah tampil penjelasan cara bermain.
*/

void tampilanAboutUs();
/*
	Deskripsi = Modul ini dipakai untuk menampilkan tampilan profil pembuat program.

	I.S = belum tampil profil pembuat program.
	F.S = sudah tampil profil pembuat program.
*/

void tampilSetelahBermain();
/*
	Deskripsi = Modul ini dipakai untuk menampilkan tampilan menu setelah bermain.

	I.S = belum tampil menu setelah bermain.
	F.S = sudah tampil menu setelah bermain.
*/

void tampilanPilihPertama();
/*
	Deskripsi = Modul ini dipakai untuk menampilkan tampilan pilihan pertama.

	I.S = belum tampil pilihan pertama.
	F.S = sudah tampil pilihan pertama.
*/

void tampilWinorDraw(char _namaPlayer1[20], char _namaPlayer2[20], int _pemenang, int _giliran, int _jenisPapan);
/*
	Deskripsi = Modul ini dipakai untuk menampilkan tampilan siapa pemenangnya atau seri.

	I.S = belum tampil siapa pemenangnya atau seri.
	F.S = sudah tampil siapa pemenangnya atau seri.
*/


// LOADING > DONE
void loading();
/*
	Deskripsi = Modul ini berfungsi untuk menampilkan tampilan loading game. 

	I.S. = Tampilan loading game belum tampil.
	F.S. = Tampilan loading game sudah tampil.
*/

// PRINT PAPAN
void printPapan(int _flagPapan, char _papan[7][7] );
/*
	Deskripsi = Modul ini berfungsi untuk menampilkan papan TicTacToe pada layar
				terdapat 3 jenis papan, yaitu 3x3, 5x5, dan 7x7.
	
	I.S. = Papan belum tampil pada layar.
	F.S. = Papan sudah tampil pada layar.
*/

// KATEGORI TEKNIS 
// CONSOLE > DONE
HWND WINAPI GetConsoleWindowNT(void);
/*
	Deskripsi = Modul ini mengatur ukuran konsol sesuai dengan ukuran yang dimasukan.

	I.S. = Ukuran konsol sesuai dengan default.
	F.S. = Ukuran konsol sudah berubah dengan ukuran yang masukan.

	{source: https://www.codeincodeblock.com/2011/03/move-console-windows-using-codeblock.html}
*/


// KOORDINAT > DONE
void koor(int x, int y);
/*
	Deskripsi = Modul ini berfungsi untuk memindahkan pointer ke koordinat yang di inginkan.

	I.S = Pointer berjalan sequence di titik terakhir.
	F.S = Pointer berpindah ke koordinat yang diinginkan.
*/

void printPanah( int _panx, int _pany );
/*
	Deskripsi = Modul ini berfungsi untuk menapilkan panah yang digunakan untuk menandakan
				pilihan halaman.

	I.S. = Tampilan panah belum tampil pada layar.
	F.S. = Tampilan panah sudah tampil pada layar.
*/

// TEKNIS
void setColor(unsigned short color);
/*
	Deskripsi = Modul ini dipanggil ketika dibutuhkan untuk mewarnai suatu teks atau gambar

	I.S. = Warna tulisan putih sesuai default.
	F.S. = Tulisan berwarna sesuai dengan warna yang dipilih berdasarkan kode warna
*/


// KATEGORI INISIALISASI
// PILIH HALAMAN > DONE
void pilihHalaman( int _flagHalaman, int *_pilihanHalaman );
/*
	Deskripsi = Modul ini dipakai untuk memilih halaman pada setiap menu awal menggunakan panah.
	
	I.S = Tidak ada panah.
	F.s = Tampil panah dan bisa digerakkan.
*/

// INISIALISASI > DONE
void inisialisasi( Game *game, int *_pemenang );
/*
	Deskripsi = Modul ini digunakan ketika akan memulai permainan baru dan data 
				masih diisi nilai default yang telah ditentukan oleh pembuat game.

	I.S = Variabel game di dalam tipe data Game belum terisi nilai yang ditentukan dalam kondisi awal game.
	F.S = Variabel game sudah terisi nilai kondisi awal game.
*/

int isiID();
/*
	Deskripsi = Fungsi ini digunakan untuk mengisi id_game yang ada pada variabel game. Fungsi ini akan
				mengembalikan nilai id game terakhir yang akan digunakan sebagai tanda game.
				
	I.S. = ID belum terisi.
	F.S. = ID sudah terisi
*/

// Input Nama
void inputNama( int _jenisPermainanPlayer, char (*_namaPlayer1)[20], char (*_namaPlayer2)[20]);
/*
	Deskripsi = Modul ini bertujuan untuk menampilan tampilan input nama Player 1 dan Player 2

	I.S = Tampilan inputNama belum tampil pada layar
	F.S = Tampilan inputNama sudah tampil pada layar
*/

void scanNama( char (*_namaPlayer)[20]);
/*
	Deskripsi = Modul ini bertujuan untuk mescan nama player 1 dan player 2 

	I.S = Nama player belum terisi
	F.S = Nama player sudah terisi
*/


// KATEGORI PLAY GAME
// PLAY GAME > DONE
void playGame(Game *game, int *_pemenang);
/*
	Deskripsi = Modul ini digunakan ketika loadgame dan juga ketika data 
				inisialisasi sudah diisi dengan lengkap dan juga modul ini 
				adalah modul khusus permainan.

	I.S = Pemain belum masuk ke dalam permainan.
	F.S = Pemain sudah bisa bermain tictactoe berdasarkan data pada inisialisasi 
		  yang sudah diinputkan.
*/


// PILIH INDEX > DONE
void pilihIndexPapan(int _flagIndex, int _jenisPapan, int _giliran, int _pilihPertama, char _papan[7][7], Index *_indexPilihIndexPapan, bool *_valid);
/*
	Deskripsi = Modul ini dipanggil di dalam modul playgame.
				Modul ini berfungsi untuk memilih index papan.
				
	I.S = Baris dan kolom belum terisi nilai baru.
	F.s = Baris dan kolom sudah terisi nilai baru.
*/

Index pilihIndexKomputer( int _jenisPapan, Index _indexPilihIndexKomputer, char _papan[7][7] );
/*
	Deskripsi = Modul ini digunakan untuk jneis permainan 2 player
				yang dimana player 1 adalah manusia dan player 2 adalah
				komputer. Modul ini digunakan untuk menentukan pilihan
				index untuk melawan player 1. Modul ini memiliki tipe
				algoritma bertahan dimana komputer akan menganalisis index
				terakhir yang diisikan oleh player 1 dan akan mengecek pola
				yang memiliki kemungkinan membuat tiga pola secara beruntun.
				Algoritma ini belum sempurna, mengingat waktu yang sudah menipis.
				
	I.S = Baris dan kolom belum terisi.
	F.S = Baris dan kolom sudah terisi.
*/


// MARK INDEX > DONE
void markIndex(int _giliran, int _pilihPertama, char (*_papanKotak)[7][7], int _baris, int _kolom );
/*
	Deskripsi = Modul ini berfungsi untuk mengisi array papan yang di inginkan
				oleh X atau O.
				
	I.S = Index baris dan kolom pada papan yang sudah diterima di modul
		  sebelumnya belum terisi.
	F.S = Index baris dan kolom pada papan yang sudah diterima di modul
		  sebelumnya sudah terisi.
*/


// CEK PEMENANG 
int cekPemenang(int _jenisPapan, char kotak[7][7]);
/*
	Deskripsi = Modul ini berfungsi untuk mengecek apakah sudah selesai
				game (menang atau draw) atau belum selesai game. Modul
				ini mengembalikan nilai flag agar diketahui menang atau draw nya.

	I.S = Pemenang belum diketahui.
	F.S = Pemenang sudah diketahui.
*/


// RESET ATRIBUT > DONE
void resetAtributPlayGame(int *_pemenang, int *_giliran, char (*_papan)[7][7]);
/*
	Deskripsi = Modul ini dipanggil saat setelah permainan berakhir dan me-reset
				seperti mengosongkan papan.
				
	I.S = Variabel yang bersifat belum dihapus setelah bermain game direset default kembali.
	F.S = Variabel yang bersifat sudah dihapus setelah bermain game direset default kembali.
*/


// SETELAH CEK PEMENANG
void setelahCekMenang(Game _game, int *_pemenang, int *_halaman, bool *_maingame, bool *_kondisiSetelahMenang, bool *_kondisiGantiGiliran, bool *_kondisiInisialisasi);
/*
	Deskripsi = Modul ini dipanggil setelah permainan berakhir, dan terdapat pilihan untuk
				bermain kembali atau ke menu dll.

	I.S = Permainan selesai tanpa ada pilihan.
	F.S = Tampil pilihan bermain lagi, pilih jenis papan, save, kembali ke menu, dan pilih giliran pertama.
*/


// KATEGORI FILE HANDLING
// FILE HANDLING > DONE
void saveData( Game _game );
/*
	Deskripsi = Modul ini berfungsi untuk menyimpan data

	I.S. = Data pemain pada variabel game belum tersimpan ke dalam file data.dat
	F.S. = Data pemain pada variabel game sudah tersimpan ke dalam file data.dat
*/


//LOAD DATA > DONE
void loadGame( Game *game, bool *_kondisiLoadgame );
/*
	Deskripsi = Modul ini berfungsi untuk melanjutkan permainan yang 
				sudah di save sebelumnya.

	I.S. = Variabel game di main belum terisi data yang di load
	F.S. = Variabel game di main sudah terisi data yang di load
*/


// TAMPILKAN DATA YANG DI BISA DI LOAD > DONE
void tampilkanData(int *_IDPilihanPlayer, bool *_lanjut);
/*
	Deskripsi = Modul ini berfungsi untuk menampilkan data yang sudah ada ke layar.

	I.S. = Data yang sudah di simpan belum ditampilkan ke layar
	F.S. = Data yang sudah di simpan sudah ditampilkan ke layar
*/


// HIGSCORE
void highScore();
/*
	Deskripsi = Modul ini berfungsi untuk menyimpan dan membaca data highscore

	I.S. = Data highscore belum didapatkan
	F.S. = Data highscore sudah didapatkan
*/

void tampilHighScore(char _namaPlayer[20], int _score, int _urutanData, int _akhirData);
/*
	Deskripsi = Modul ini berfungsi untuk menampilkan 10 pemain peraih poin terbanyak.

	I.S. = Data highscore belum ditampilkan
	F.S. = Data highscore sudah ditampilkan
*/



int namaYangSama(char _namaPlayer[20]);

//PILIH LOAD GAME
void panahLoadGame(int _count, int _daftarID[10000], bool *_next, int *_id);

int cekNamaDuplikat( int _awal, char listNamaValid[10000][20], char _namaPlayer[20] );