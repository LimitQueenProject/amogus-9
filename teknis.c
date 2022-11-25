#include "header.h"
#include <conio.h>
#include <windows.h>

void koor(int x, int y)
{
    HANDLE h;
    COORD c;
    c.X = x;
    c.Y = y;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h,c);
}


int panah( int _flagChoise )
{
    int panx=69,pany=22,button;

    if ( _flagChoise == 1 ) // khusus menu
    {
        do 
        {
            tampilanMenu();
            koor(panx,pany);
            printf("%c%c",205,62);
            button = getch();
            if(button == 80) 
            {
                switch(pany) 
                {
                    case 22 :
                        pany = 23;
                        break;
                    case 23 :
                        pany = 24;
                        break;
                    case 24 :
                        pany = 22;
                        break;
                }
            }
            else if(button == 72) 
            {
                switch(pany) 
                {
                    case 22 :
                        pany = 24;
                        break;
                    case 23 :
                        pany = 22;
                        break;
                    case 24 :
                        pany = 23;
                        break;
                }
            }
        }
        while(button != 13);

        if ( pany == 22 )
            return 1;
        else if ( pany == 23 )
            return 2;
        else if ( pany == 24 )
            return 3;
    }
    
    else if ( _flagChoise == 2 )
    {   
        do 
        {
            void tampilanPlayer();
            koor(panx,pany);
            printf("%c%c",205,62);
            button = getch();
            if(button == 80) 
            {
                switch(pany) 
                {
                    case 22 :
                        pany = 23;
                        break;
                    case 23 :
                        pany = 24;
                        break;
                    case 24 :
                        pany = 22;
                        break;
                }
            }
            else if(button == 72) 
            {
                switch(pany) 
                {
                    case 22 :
                        pany = 24;
                        break;
                    case 23 :
                        pany = 22;
                        break;
                    case 24 :
                        pany = 23;
                        break;
                }
            }
        }
        while(button != 13);

        if ( pany == 22 )
            return 1;
        else if ( pany == 23 )
            return 2;
        else if ( pany == 24 )
            return 0;
    }
}