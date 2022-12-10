#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

#include "header.h"

int main()
{
    // DEKLARASI HALAMAN
    int pilihanMenu;
    bool kondisiPilihanMenu;

    int pilihanPlayer;
    bool kondisiPilihanPlayer;

    int pilihanPapan;
    bool kondisiPilihanPapan;

    // DEKLARASI PLAY GAME
    Game game;

    // 1.
    bool kondisiGame;
    bool kondisiPemenang;
    bool kondisiPilihGiliranPertama;
    bool kondisiAfterGame;

    // Pengaturan ukuran console dengan lebar 1000 dan tinggi 600
    HWND hWnd = GetConsoleWindowNT();
    MoveWindow(hWnd, 180, 50, 1000, 600, TRUE);

    // Menampilkan loading
    loading();

    kondisiPilihanMenu = true;
    do
    {
        pilihHalaman(0, &pilihanMenu);
        if (pilihanMenu == 1)
        {
            kondisiPilihanPlayer = true;
            do
            {
                pilihHalaman(1, &pilihanPlayer);
                if (pilihanPlayer == 1)
                {
                    inputNama( pilihanPlayer, &game.pemain1.namaPlayer, &game.pemain2.namaPlayer);
                    kondisiPilihanPapan = true;
                    do
                    {
                        pilihHalaman(11, &pilihanPapan); 
                        if (pilihanPapan == 1)
                        {
                            inisialisasi(&game, &game.papan.jenisPapan, pilihanPapan, &kondisiPilihGiliranPertama, &kondisiPemenang, &kondisiGame );
                            playgame( &game, &kondisiPilihanPapan, &kondisiPilihanPlayer, &kondisiAfterGame, pilihanPlayer);
                        }
                        else if (pilihanPapan == 2)
                        {
                            inisialisasi(&game, &game.papan.jenisPapan, pilihanPapan, &kondisiPilihGiliranPertama, &kondisiPemenang, &kondisiGame );
                            playgame( &game, &kondisiPilihanPapan, &kondisiPilihanPlayer, &kondisiAfterGame, pilihanPlayer);
                        }
                        else if (pilihanPapan == 3)
                        {
                            inisialisasi(&game, &game.papan.jenisPapan, pilihanPapan, &kondisiPilihGiliranPertama, &kondisiPemenang, &kondisiGame );
                            playgame( &game, &kondisiPilihanPapan, &kondisiPilihanPlayer, &kondisiAfterGame, pilihanPlayer);
                        }

                        else if (pilihanPapan == 0) // kembali
                        {
                            kondisiPilihanPapan = false;
                        }
                    } while (kondisiPilihanPapan == true);
                }
                else if (pilihanPlayer == 2) // 2 player
                {
                    kondisiPilihanPapan = true;
                    do
                    {
                        inputNama( pilihanPlayer, &game.pemain1.namaPlayer, &game.pemain2.namaPlayer);
                        pilihHalaman(11, &pilihanPapan); // Tampil halaman pilih papan untuk 2 player
                        if (pilihanPapan == 1)           // papan 3x3
                        {
                            
                            inisialisasi(&game, &game.papan.jenisPapan, pilihanPapan, &kondisiPilihGiliranPertama, &kondisiPemenang, &kondisiGame );
                            playgame( &game, &kondisiPilihanPapan, &kondisiPilihanPlayer, &kondisiAfterGame, pilihanPlayer);
                        }
                        else if (pilihanPapan == 2) // papan 5x5
                        {
                            inisialisasi(&game, &game.papan.jenisPapan, pilihanPapan, &kondisiPilihGiliranPertama, &kondisiPemenang, &kondisiGame );
                            playgame( &game, &kondisiPilihanPapan, &kondisiPilihanPlayer, &kondisiAfterGame, pilihanPlayer);
                        }
                        else if (pilihanPapan == 3) // papan 7x7
                        {
                            inisialisasi(&game, &game.papan.jenisPapan, pilihanPapan, &kondisiPilihGiliranPertama, &kondisiPemenang, &kondisiGame );
                            playgame( &game, &kondisiPilihanPapan, &kondisiPilihanPlayer, &kondisiAfterGame, pilihanPlayer);
                        }
                        else if (pilihanPapan == 0) // kembali
                        {
                            kondisiPilihanPapan = false;
                        }
                    } while (kondisiPilihanPapan == true);
                }
                else if (pilihanPlayer == 0) // kembali
                {
                    kondisiPilihanPlayer = false;
                }
            } while (kondisiPilihanPlayer == true);
        }
        else if (pilihanMenu == 2) // load game
        {
            bool kondisiLoadGame = false;
                loadGame(&game);
            if (kondisiLoadGame)
            {
                
            }
        }
        else if (pilihanMenu == 3) // highscore
        {
            highscore();
        }
        else if (pilihanMenu == 4) // how to play
        {
            tampilanHowToPlay();
        }
        else if (pilihanMenu == 5) // about us
        {
            tampilanAboutUs();
        }
        else if (pilihanMenu == 0) // exit
        {
            kondisiPilihanMenu = false;
        }
    } while (kondisiPilihanMenu);

    return 0;
}