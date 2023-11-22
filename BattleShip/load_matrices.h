#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void chargement_matrices (unsigned char ** mat, unsigned char ** mat_ia1,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){
    //DDV
    int i;
    int j;

    //Sauvegarde des matrices dans les matrices bis
    for (i = 1; i < 16; i++){
        for (j = 1; j < 16; j++){
            mat[i][j] = mat_bis[i][j];
            mat_ia1[i][j] = mat_ia1_bis[i][j];
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////