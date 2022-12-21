#include<conio.h>
#include<windows.h>

#include "header.h"

void panahLoadGame(int _count, int _daftarID[10000], bool *_next, int *_id)
{
    koor(0,0);
    int panx,pany;
    int button;
    int urutan=0;
    *_next=true;

    //default
    panx=45;
    pany=15;
    
    do
    {
        button=0;
        koor(panx,pany);    printf("<==");koor(panx+40,pany+4);
        // Inputan player
        if(pany==15){
            koor(0,0);
        }
        button=getch();
        // Kondisi inputan player

        if(button == down || button == s || button == S )
        {
            koor(panx,pany);printf("   ");
            pany += 7;
        }else if (button == up || button == w || button == W)
        {
            koor(panx,pany);printf("   ");
            pany -= 7;
        }
        if(pany<15 ){
            pany += 7;
        }else if( pany>15+7*(_count-2)){
            pany -= 7 ;
        }

        if(button==27){
            *_next=false;
        }
    } while(button!=13 && *_next==true);

        // if(_count>0){
        //     if(pany>15){
        //         pany += 7;
        //     }
        // }
        // if(_count>15+7*_count){
        //     pany -= 7;
        // }

    if(*_next==true){
        urutan = (pany-15)/7;
        *_id = _daftarID[urutan];
    }
}