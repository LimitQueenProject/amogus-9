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
		koor(57,1); printf("%c%c%c%c",203,205,205,187);
		koor(54 - (length1),2);printf("%c %s %c%d%c",186,_namaPlayer1,186,_score1,186);
		koor(57,3); printf("%c%c%c%c",202,205,205,188);
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
	else 
	{
		koor(58,1);printf("%c%c%c",203,205,187);
		koor(55 - (length1),2);printf("%c %s %c%d%c",186,_namaPlayer1,186,_score1,186);
		koor(58,3);printf("%c%c%c",202,205,188);
		koor(55 - (length1),1);
		printf("%c",201);
		for(i=1;i<=length1+2;i++)
		{
			printf("%c", 205);
		}
		koor(55 - (length1),3);
		printf("%c",200);
		for(i=1;i<=length1+2;i++)
		{
			printf("%c", 205);
		}
	}
	if(_score2>9)
	{
		koor(63,1); printf("%c%c%c%c",201,205,205,203);
		koor(63,2); printf("%c%d%c %s %c",186,_score2,186,_namaPlayer2,186);
		koor(63,3); printf("%c%c%c%c",200,205,205,202);
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
	else
	{
		koor(63,1); printf("%c%c%c",201,205,203);
		koor(63,2); printf("%c%d%c %s %c",186,_score2,186,_namaPlayer2,186);
		koor(63,3); printf("%c%c%c",200,205,202);
		koor(66,1);
		for(i=1;i<=length2+2;i++)
		{
			printf("%c",205);
		}printf("%c",187);
		koor(66,3);
		for(i=1;i<=length2+2;i++)
		{
			printf("%c",205);
		}printf("%c",188);
	}


	koor(56, 4);
	printf("Giliran ke : %d ", _giliran);
	koor(56, 5);
	if (_pertama == 1)
	{
		printf("Giliran : %s ", _namaPlayer1);
	}
	else if (_pertama == 2)
	{
		printf("Giliran : %s ", _namaPlayer2);
	}
}

void banner1()
{
	koor(9, 0);
	printf("%c", 201);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c", 187);

	koor(9, 1);
	printf("%c%c", 186, 201);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c%c", 187, 186);

	koor(9, 2);   printf("%c%c\t\t\t\t                ^PGGBBBG5?^.       \t\t\t              %c%c", 186, 186, 186, 186);
	koor(9, 3);   printf("%c%c\t\t\t\t              ^@@&_________&P:     \t\t\t              %c%c", 186, 186, 186, 186);
	koor(9, 4);   printf("%c%c\t\t\t\t            :&@&_____@@@@@@@@@@    \t\t\t              %c%c", 186, 186, 186, 186);
	koor(9, 5);   printf("%c%c\t\t\t\t            B@&____@           @^  \t\t\t              %c%c", 186, 186, 186, 186);
	koor(9, 6);   printf("%c%c\t\t\t\t        :~7Y@@&___@ Mr. Amogus  @  \t\t\t              %c%c", 186, 186, 186, 186);
	koor(9, 7);   printf("%c%c\t\t\t\t       G@___@@&___@             @  \t\t\t              %c%c", 186, 186, 186, 186);
	koor(9, 8);   printf("%c%c\t\t\t\t      :@____@@&____@@          @   \t\t\t              %c%c", 186, 186, 186, 186);
	koor(9, 9);   printf("%c%c\t\t\t\t      ^@____@@&______@@@@@&&&&@@   \t\t\t              %c%c", 186, 186, 186, 186);
	koor(9, 10);  printf("%c%c\t\t\t\t      !@____@@&_______________@@   \t\t\t              %c%c", 186, 186, 186, 186);
	koor(9, 11);  printf("%c%c\t\t\t\t      :@____@@&_______________@@   \t\t\t              %c%c", 186, 186, 186, 186);
	koor(9, 12);  printf("%c%c\t   TTTTTTTT IIIIIIII  .cCCc.   TTTTTTTT  .aAa.   .cCCc.   TTTTTTTT  .oOOo.  eEEEEEE           %c%c", 186, 186, 186, 186);
	koor(9, 13);  printf("%c%c\t   `  TT  '   `II'   cCc  Cc   `  TT  ' aA' `Aa cCc  Cc   `  TT  ' .oO  Oo. EE'               %c%c", 186, 186, 186, 186);
	koor(9, 14);  printf("%c%c\t      TT       II    CC           TT    AAaaaAA CC           TT    OO    OO EEeeeee           %c%c", 186, 186, 186, 186);
	koor(9, 15);  printf("%c%c\t      TT       II    CC           TT    AA   AA CC           TT    OO    OO EE                %c%c", 186, 186, 186, 186);
	koor(9, 16);  printf("%c%c\t      TT      .II.   cCc  Cc      TT    AA   AA cCc  Cc      TT    `Oo  oO' EE.               %c%c", 186, 186, 186, 186);
	koor(9, 17);  printf("%c%c\t      TT    IIIIIIII  `CccC'      TT    AA   AA  `CccC'      TT     `OooO'  Eeeeeee           %c%c", 186, 186, 186, 186);
	koor(9, 18);  printf("%c%c", 186, 186);
	koor(110,18); printf("%c%c", 186, 186);
	koor(100,19); printf("by Amogus %c%c", 186, 186);
	koor(9, 19);  printf("%c%c", 186, 186);

	koor(9, 20);
	printf("%c%c", 186, 200);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c%c", 188, 186);

	koor(9, 21);
	printf("%c", 200);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c", 188);
}

void banner2()
{
	koor(14, 0);
	printf("%c", 201);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c", 187);

	koor(14, 1);
	printf("%c%c", 186, 201);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c%c", 187, 186);

	koor(14, 2); printf("%c%c      TTTTTTTT IIIIIIII  .cCCc.   TTTTTTTT  .aAa.   .cCCc.   TTTTTTTT  .oOOo.  eEEEEEE     %c%c", 186, 186, 186, 186);
	koor(14, 3); printf("%c%c      `  TT  '   `II'   cCc  Cc   `  TT  ' aA' `Aa cCc  Cc   `  TT  ' .oO  Oo. EE'         %c%c", 186, 186, 186, 186);
	koor(14, 4); printf("%c%c         TT       II    CC           TT    AAaaaAA CC           TT    OO    OO EEeeeee     %c%c", 186, 186, 186, 186);
	koor(14, 5); printf("%c%c         TT       II    CC           TT    AA   AA CC           TT    OO    OO EE          %c%c", 186, 186, 186, 186);
	koor(14, 6); printf("%c%c         TT      .II.   cCc  Cc      TT    AA   AA cCc  Cc      TT    `Oo  oO' EE.         %c%c", 186, 186, 186, 186);
	koor(14, 7); printf("%c%c         TT    IIIIIIII  `CccC'      TT    AA   AA  `CccC'      TT     `OooO'  Eeeeeee     %c%c", 186, 186, 186, 186);

	koor(14, 8);
	printf("%c%c", 186, 200);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c%c", 188, 186);

	koor(14, 9);
	printf("%c", 200);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	printf("%c", 188);
}
