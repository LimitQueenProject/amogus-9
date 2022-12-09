#include <stdio.h>
#include <unistd.h>

#include "header.h"

void loading()
{
	/*
    1. Membutuhkan modul koor
    */
   	system("color F");
    int button;
	int z;
	banner1();
	sleep(1);

	koor(57, 23);
	printf("Loading ...");
	sleep(0.5);
	koor(40, 25);
	for (z = 0; z < 15; z++)
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
	banner1();
	koor(47, 27);
	printf("press any key to continue...");
	button = getch();
}