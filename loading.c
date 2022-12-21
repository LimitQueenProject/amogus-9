#include <stdio.h>
#include <unistd.h>

#include "header.h"

void loading()
{
    int button;
	int z;
	banner1();
	sleep(1);

	koor(56, 23);
	printf("Loading ...");
	sleep(1.5);
   	setColor(11);
	koor(41, 25);
	printf("%c", 178);
	sleep(1);
	for (z = 0; z < 14; z++)
	{
		printf("%c", 178);
	}
	sleep(2);
	for (z = 0; z < 10; z++)
	{
		printf("%c", 178);
	}
	sleep(1);
	for (z = 0; z < 9; z++)
	{
		printf("%c", 178);
	}
	sleep(0.5);
	for (z = 0; z < 6; z++)
	{
		printf("%c", 178);
	}
	sleep(1);
	system("cls");
	setColor(7);
	banner1();
	koor(47, 25);
	printf("press any key to continue...");
	button = getch();
}