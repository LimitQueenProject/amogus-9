#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <string.h>

#include "header.h"

void dashboard(char _namaPlayer1[100], char _namaPlayer2[100], int _pertama, int _giliran, int _score1, int _score2,int  _id)
{
	int length1, length2, i;
	length1 = strlen(_namaPlayer1);
	length2 = strlen(_namaPlayer2);

	if(_id < 10)
	{
		koor(5,2); printf("%c%c%c%c%c%c%c%c%c%c%c",218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);        
    	koor(5,3); printf("%c ID = %d  %c",179,_id, 179 );                                
    	koor(5,4); printf("%c%c%c%c%c%c%c%c%c%c%c",192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
	}
	else if (_id > 10)
	{
		koor(5,2); printf("%c%c%c%c%c%c%c%c%c%c%c%c",218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);        
    	koor(5,3); printf("%c ID = %d  %c",179,_id, 179 );                                
    	koor(5,4); printf("%c%c%c%c%c%c%c%c%c%c%c%c",192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
	}
	else if (_id > 100)
	{
		koor(5,2); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);        
    	koor(5,3); printf("%c ID = %d  %c",179,_id, 179 );                                
    	koor(5,4); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
	}


	if(_score1>9)
	{
		koor(56,1); printf("%c%c%c%c",203,205,205,187);
		koor(53 - (length1),2);printf("%c %s %c%d%c",186,_namaPlayer1,186,_score1,186);
		koor(56,3); printf("%c%c%c%c",202,205,205,188);
		koor(53 - (length1),1);
		printf("%c",201);
		for(i=1;i<=length1+2;i++)
		{
			printf("%c", 205);
		}
		koor(53 - (length1),3);
		printf("%c",200);
		for(i=1;i<=length1+2;i++)
		{
			printf("%c", 205);
		}
	}
	else 
	{
		koor(57,1);printf("%c%c%c",203,205,187);
		koor(54 - (length1),2);printf("%c %s %c%d%c",186,_namaPlayer1,186,_score1,186);
		koor(57,3);printf("%c%c%c",202,205,188);
		koor(54 - (length1),1);
		printf("%c",201);
		for(i=1;i<=length1+2;i++)
		{
			printf("%c", 205);
		}
		koor(54 - (length1),3);
		printf("%c",200);
		for(i=1;i<=length1+2;i++)
		{
			printf("%c", 205);
		}
	}
	if(_score2>9)
	{
		koor(64,1); printf("%c%c%c%c",201,205,205,203);
		koor(64,2); printf("%c%d%c %s %c",186,_score2,186,_namaPlayer2,186);
		koor(64,3); printf("%c%c%c%c",200,205,205,202);
		koor(68,1);
		for(i=1;i<=length2+2;i++)
		{
			printf("%c",205);
		}	printf("%c",187);
		koor(68,3);
		for(i=1;i<=length2+2;i++)
		{
			printf("%c",205);
		}printf("%c",188);
	}
	else
	{
		koor(64,1); printf("%c%c%c",201,205,203);
		koor(64,2); printf("%c%d%c %s %c",186,_score2,186,_namaPlayer2,186);
		koor(64,3); printf("%c%c%c",200,205,202);
		koor(67,1);
		for(i=1;i<=length2+2;i++)
		{
			printf("%c",205);
		}printf("%c",187);
		koor(67,3);
		for(i=1;i<=length2+2;i++)
		{
			printf("%c",205);
		}printf("%c",188);
	}


	koor(56, 4);
	printf("Turn : %d ", _giliran);
	koor(56, 5);
	if (_giliran %2 == 1 &&  _pertama==1 || _giliran %2 == 0 &&  _pertama==2)
	{
		printf("%s's turn", _namaPlayer1);
	}
	else if (_giliran %2 == 1 && _pertama==2 || _giliran %2 == 0 && _pertama==1)
	{
		printf("%s's turn", _namaPlayer2);
	}
}

void banner1()
{
	koor(8, 0);
	printf("%c", 201);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c", 187);

	koor(8, 1);
	printf("%c %c", 186, 201);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c %c", 187, 186);

	koor(8, 2);   printf("%c %c\t\t\t\t                ^PGGBBBG5?^.       \t\t\t              %c %c", 186, 186, 186, 186);
	koor(8, 3);   printf("%c %c\t\t\t\t              ^@@&_________&P:     \t\t\t              %c %c", 186, 186, 186, 186);
	koor(8, 4);   printf("%c %c\t\t\t\t            :&@&_____@@@@@@@@@@    \t\t\t              %c %c", 186, 186, 186, 186);
	koor(8, 5);   printf("%c %c\t\t\t\t            B@&____@           @^  \t\t\t              %c %c", 186, 186, 186, 186);
	koor(8, 6);   printf("%c %c\t\t\t\t        :~7Y@@&___@ Mr. Amogus  @  \t\t\t              %c %c", 186, 186, 186, 186);
	koor(8, 7);   printf("%c %c\t\t\t\t       G@___@@&___@             @  \t\t\t              %c %c", 186, 186, 186, 186);
	koor(8, 8);   printf("%c %c\t\t\t\t      :@____@@&____@@          @   \t\t\t              %c %c", 186, 186, 186, 186);
	koor(8, 9);   printf("%c %c\t\t\t\t      ^@____@@&______@@@@@&&&&@@   \t\t\t              %c %c", 186, 186, 186, 186);
	koor(8, 10);  printf("%c %c\t\t\t\t      !@____@@&_______________@@   \t\t\t              %c %c", 186, 186, 186, 186);
	koor(8, 11);  printf("%c %c\t\t\t\t      :@____@@&_______________@@   \t\t\t              %c %c", 186, 186, 186, 186);
	koor(8, 12);  printf("%c %c\t   TTTTTTTT IIIIIIII  .cCCc.   TTTTTTTT  .aAa.   .cCCc.   TTTTTTTT  .oOOo.  eEEEEEE           %c %c", 186, 186, 186, 186);
	koor(8, 13);  printf("%c %c\t   `  TT  '   `II'   cCc  Cc   `  TT  ' aA' `Aa cCc  Cc   `  TT  ' .oO  Oo. EE'               %c %c", 186, 186, 186, 186);
	koor(8, 14);  printf("%c %c\t      TT       II    CC           TT    AAaaaAA CC           TT    OO    OO EEeeeee           %c %c", 186, 186, 186, 186);
	koor(8, 15);  printf("%c %c\t      TT       II    CC           TT    AA   AA CC           TT    OO    OO EE                %c %c", 186, 186, 186, 186);
	koor(8, 16);  printf("%c %c\t      TT      .II.   cCc  Cc      TT    AA   AA cCc  Cc      TT    `Oo  oO' EE.               %c %c", 186, 186, 186, 186);
	koor(8, 17);  printf("%c %c\t      TT    IIIIIIII  `CccC'      TT    AA   AA  `CccC'      TT     `OooO'  Eeeeeee           %c %c", 186, 186, 186, 186);
	koor(8, 18);  printf("%c %c", 186, 186);
	koor(110,18); printf("%c %c", 186, 186);
	setColor(2);
	koor(100,19); printf("by Amogus");
	setColor(7);
	koor(109,19);printf(" %c %c", 186, 186);
	koor(8, 19);  printf("%c %c", 186, 186);

	koor(8, 20);
	printf("%c %c", 186, 200);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c %c", 188, 186);

	koor(8, 21);
	printf("%c", 200);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c", 188);
	setColor(7);
}

void banner2()
{
	setColor(4);
	koor(12, 0);
	printf("%c", 201);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c", 187);

	koor(12, 1);
	printf("%c %c", 186, 201);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c %c", 187, 186);
	setColor(7);

	setColor(4);
	koor(12, 2); printf("%c %c", 186, 186); koor(107, 2); printf("%c %c", 186, 186);
	koor(12, 3); printf("%c %c", 186, 186); koor(107, 3); printf("%c %c", 186, 186);
	koor(12, 4); printf("%c %c", 186, 186); koor(107, 4); printf("%c %c", 186, 186);
	koor(12, 5); printf("%c %c", 186, 186); koor(107, 5); printf("%c %c", 186, 186);
	koor(12, 6); printf("%c %c", 186, 186); koor(107, 6); printf("%c %c", 186, 186);
	koor(12, 7); printf("%c %c", 186, 186); koor(107, 7); printf("%c %c", 186, 186);

	setColor(2);
	koor(21,2); printf("%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c %c%c%c%c%c%c  %c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c%c", 219, 219, 219, 219,219, 219, 219, 219, 187, 219, 219, 187, 219, 219, 219, 219, 219, 219, 187, 219, 219, 219, 219, 219, 219, 219, 219, 187, 219, 219, 219, 219, 219, 187, 219, 219, 219, 219, 219, 219, 187, 219, 219, 219, 219, 219, 219, 219, 219, 187, 219, 219, 219, 219, 219, 219, 187, 219, 219, 219, 219, 219, 219, 219, 187);
	koor(21,3); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200 ,205 ,205 ,219 ,219 ,201 ,205 ,205 ,188 ,219 ,219 ,186 ,219 ,219 ,201 ,205 ,205 ,205 ,205 ,188 ,200 ,205 ,205 ,219 ,219 ,201 ,205 ,205 ,188 ,219 ,219 ,201 ,205 ,205 ,219 ,219 ,187,219 ,219 ,201 ,205 ,205 ,205 ,205 ,188 ,200 ,205 ,205 ,219 ,219 ,201 ,205 ,205 ,188 ,219 ,219 ,201 ,205 ,205 ,205 ,219 ,219 ,187,219 ,219 ,201 ,205 ,205 ,205 ,205 ,188 );
	koor(21,4); printf("   %c%c%c   %c%c%c%c%c%c            %c%c%c   %c%c%c%c%c%c%c%c%c%c%c            %c%c%c   %c%c%c   %c%c%c%c%c%c%c%c%c  ",219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,219 ,219 ,219 ,219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,219 ,219 ,219 ,187);
	koor(21,5); printf("   %c%c%c   %c%c%c%c%c%c            %c%c%c   %c%c%c%c%c%c%c%c%c%c%c            %c%c%c   %c%c%c   %c%c%c%c%c%c%c%c%c  ",219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,201 ,205 ,205 ,219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,201 ,205 ,205 ,188);
	koor(21,6); printf("   %c%c%c   %c%c%c%c%c%c%c%c%c%c%c       %c%c%c   %c%c%c  %c%c%c%c%c%c%c%c%c%c%c       %c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219 ,219 ,186 ,219 ,219 ,186 ,200 ,219 ,219 ,219 ,219 ,219 ,219 ,187 ,219 ,219 ,186 ,219 ,219 ,186 ,219 ,219 ,186 ,200 ,219 ,219 ,219 ,219 ,219 ,219 ,187 ,219 ,219 ,186 ,200 ,219 ,219 ,219 ,219 ,219 ,219 ,201 ,188 ,219 ,219 ,219 ,219 ,219 ,219 ,219 ,187);
	koor(21,7); printf("   %c%c%c   %c%c%c %c%c%c%c%c%c%c       %c%c%c   %c%c%c  %c%c%c %c%c%c%c%c%c%c       %c%c%c    %c%c%c%c%c%c%c %c%c%c%c%c%c%c%c",200 ,205 ,188 ,200 ,205 ,188  ,200 ,205 ,205 ,205 ,205 ,205 ,188 ,200 ,205 ,188 ,200 ,205 ,188 ,200 ,205 ,188 ,200 ,205 ,205 ,205 ,205 ,205 ,188 ,200 ,205 ,188 ,200 ,205 ,205 ,205 ,205 ,205 ,188  ,200 ,205 ,205 ,205 ,205 ,205 ,205 ,188);
	setColor(7);
    
	setColor(4);
	koor(12, 8);
	printf("%c %c", 186, 200);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c %c", 188, 186);

	koor(12, 9);
	printf("%c", 200);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c", 188);
	setColor(7);
}

