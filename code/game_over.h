#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int game_over(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){

    //Variables definition
    int B = 95;

    for (int i = 1; i < 16; i++){
        for (int j = 1; j < 16; j++){
            if (mat_ia1[i][j] != 'X' && mat_ia1[i][j] != 'O' && mat_ia1[i][j] != B){
                return 0;// il reste des bateaux a couler
            }
        }
    }
    return 1; // plus de bateaux a couler
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int game_over_ia(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){

    //Variables definition
    int B = 95;

    for (int i = 1; i < 16; i++){
        for (int j = 1; j < 16; j++){
            if (mat[i][j] != 'X' && mat[i][j] != 'O' && mat[i][j] != B){
                return 0;// il reste des bateaux a couler
            }
        }
    }
    return 1; // plus de bateaux a couler
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////