#include "prototypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void initialisation_matrice(unsigned char ** mat, unsigned char ** mat_ia1){

    //Définitions des variables
    int i;
    int j;
    int B = 95;

    //Initialisation de la matrice
    for (i = 1; i < 16; i++){
        for (j = 1; j < 16; j++){
            mat[i][j] = B;
            mat_ia1[i][j] = B;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////