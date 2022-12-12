// #include<stdio.h>
// #include<stdlib.h>

// #include "header.h"

// void kirimData( Game _game )
// {
//     FILE *fptr;
//     if ((fptr = fopen("E:\\fmy\\Kuliah\\tictactoev.13.2 - Copy\\filenyoba.bin","wb")) == NULL)
//     {
//        printf("Error! opening file");

//        // Program exits if the file pointer returns NULL.
//        exit(1);
//     }

//     fwrite(&_game, sizeof(_game), 1, fptr);

//     fclose(fptr);
// }