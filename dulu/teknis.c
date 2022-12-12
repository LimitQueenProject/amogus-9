#include <stdio.h>
#include <windows.h>
#include <unistd.h>

#include "header.h"

void koor(int x, int y)
{
    HANDLE h;
    COORD c;
    c.X = x;
    c.Y = y;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h,c);
}

// Ukuran layar
HWND WINAPI GetConsoleWindowNT(void)
{
    //mendeklarasikan modul fingsi dengan tipe pointer
    typedef HWND WINAPI(*GetConsoleWindowT)(void);

    //declare one such function pointer
    GetConsoleWindowT GetConsoleWindow;

    //get a handle on kernel32.dll
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));

    //assign procedure address to function pointer
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib, TEXT("GetConsoleWindow"));

    //check if the function pointer is valid
    //since the function is undocumented
    if(GetConsoleWindow == NULL){
        return NULL;
    }
    
    //call the undocumented function
    return GetConsoleWindow();
}



void setcolor(unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}



void printPanah( int _panx, int _pany )
{
    koor(_panx, _pany);printf("==>");koor(0,0);
}




void pilihHalaman( int _flagHalaman, int *_pilihanHalaman )
{

    int panx = 46;
    int pany = 18;
    int button;

    if ( _flagHalaman == 0 )
    {
        tampilanMenu();
        printPanah(panx,pany);
        do
        {
            button = getch();
            if( button == down || button == s || button == S )
            {
                switch (pany)
                {
                case 18:
                    pany = 20;
                    koor(panx,18);printf("   ");
                    break;
                case 20:
                    pany = 22;
                    koor(panx,20);printf("   ");
                    break;
                case 22:
                    pany = 24;
                    koor(panx,22);printf("   ");
                    break;
                case 24:
                    pany = 26;
                    koor(panx,24);printf("   ");
                    break;
                case 26:
                    pany = 28;
                    koor(panx,26);printf("   ");
                    break;
                case 28:
                    pany = 18;
                    koor(panx,28);printf("   ");
                    break;
                }
            }
            else if(button == up || button == w || button == W) 
            {
                switch(pany) 
                {
                    case 18 :
                        pany = 28;
                        koor(panx,18);printf("   ");
                        break;
                    case 20 :
                        pany = 18;
                        koor(panx,20);printf("   ");
                        break;
                    case 22 :
                        pany = 20;
                        koor(panx,22);printf("   ");
                        break;
                    case 24 :
                        pany = 22;
                        koor(panx,24);printf("   ");
                        break;
                    case 26 :
                        pany = 24;
                        koor(panx,26);printf("   ");
                        break;
                    case 28 :
                        pany = 26;
                        koor(panx,28);printf("   ");
                        break;
                }
            }
            printPanah(panx,pany);    
        }while( button != 13 );
        
        if ( pany == 18 )
        {
            *_pilihanHalaman = 1;
        } 
        else if ( pany == 20 )
        {
            *_pilihanHalaman = 2;
        }
        else if ( pany == 22 )
        {
            *_pilihanHalaman = 3;
        }
        else if ( pany == 24 )
        {
            *_pilihanHalaman = 4;
        }
        else if ( pany == 26 )
        {
            *_pilihanHalaman = 5;
        }
        else if ( pany == 28 )
        {
            *_pilihanHalaman = -1;
        }
    }


    else if ( _flagHalaman == 1 )
    {
        tampilanPlayer();
        printPanah(panx,pany);
        do
        {
            button = getch();
            if( button == down || button == s || button == S )
            {
                switch (pany)
                {
                case 18:
                    pany = 20;
                    koor(panx,18);printf("   ");
                    break;
                
                case 20:
                    pany = 22;
                    koor(panx,20);printf("   ");
                    break;

                case 22:
                    pany = 18;
                    koor(panx,22);printf("   ");
                    break;
                }
            }
            else if(button == 72 || button == w || button == W) 
            {
                switch(pany) 
                {
                    case 18 :
                        pany = 22;
                        koor(panx,18);printf("   ");
                        break;
                    case 20 :
                        pany = 18;
                        koor(panx,20);printf("   ");
                        break;
                    case 22 :
                        pany = 20;
                        koor(panx,22);printf("   ");
                        break;
                }
            }
            printPanah(panx,pany);    
        }while( button != 13 );
        
        if ( pany == 18 )
        {
            *_pilihanHalaman = 1;
        } 
        else if ( pany == 20 )
        {
            *_pilihanHalaman = 2;
        }
        else if ( pany == 22 )
        {
            *_pilihanHalaman = -1;
        }
    }



    else if ( _flagHalaman == 11 || _flagHalaman == 12)
    {
        tampilanBoard();
        printPanah(panx,pany);
        do
        {
            button = getch();
            if( button == down || button == s || button == S )
            {
                switch (pany)
                {
                case 18:
                    pany = 20;
                    koor(panx,18);printf("   ");
                    break;
                case 20:
                    pany = 22;
                    koor(panx,20);printf("   ");
                    break;
                case 22:
                    pany = 24;
                    koor(panx,22);printf("   ");
                    break;
                case 24:
                    pany = 18;
                    koor(panx,24);printf("   ");
                    break;
                }
            }
            else if(button == 72 || button == w || button == W) 
            {
                switch(pany) 
                {
                    case 18 :
                        pany = 24;
                        koor(panx,18);printf("   ");
                        break;
                    case 20 :
                        pany = 18;
                        koor(panx,20);printf("   ");
                        break;
                    case 22 :
                        pany = 20;
                        koor(panx,22);printf("   ");
                        break;
                    case 24:
                        pany = 22;
                        koor(panx,24);printf("   ");
                        break;
                }
            }
            printPanah(panx,pany);    
        }while( button != 13 );
        if ( pany == 18 )
        {
            *_pilihanHalaman = 3;
        } 
        else if ( pany == 20 )
        {
            *_pilihanHalaman = 5;
        }
        else if ( pany == 22 )
        {
            *_pilihanHalaman = 7;
        }
        else if ( pany == 24 )
        {
            *_pilihanHalaman = -1;
        }

    }else if (_flagHalaman == 111)
    {
        panx=48;
        pany=17;
        tampilanPilihPertama();
        do
        {
            printPanah(panx,pany);    
            button = getch();
            if( button == down || button == s || button == S )
            {
                switch (pany)
                {
                case 17:
                    pany = 19;
                    koor(panx,17);printf("   ");
                    break;
                case 19:
                    pany = 17;
                    koor(panx,19);printf("   ");
                    break;
                }
            }
            else if(button == 72 || button == w || button == W) 
            {
                switch(pany) 
                {
                    case 17 :
                        pany = 19;
                        koor(panx,17);printf("   ");
                        break;
                    case 19 :
                        pany = 17;
                        koor(panx,19);printf("   ");
                        break;
                }
            }
        }while( button != 13 );
        if ( pany == 17 )
        {
            *_pilihanHalaman = 1;
        } 
        else if ( pany == 19 )
        {
            *_pilihanHalaman = 2;
        }
    }
}