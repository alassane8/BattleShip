#include "prototypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void decors(){

    //Déclarations des variables
    int i;
    int j;
    int k = 65;

    // positionnement à l'écran pour la première matrice
    for (i = 0; i < 16; i++){
        for (j = 0; j < 16; j++){
            //Premiere ligne on parcours les colonnes
            if (i == 0 && j > 0){
                printf("%2d |",j);
            }
                //Premiere colonne on parcours les lignes
            else if(j == 0 && i > 0){
                printf("\n");
                printf("%2c |", k);
                k++;
            }
                //Pour les cases de la matrices on affiche des cases vides
            else{
                printf("%2c |",' ');
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void decors1(){

    //Déclarations des variables
    int a;
    int b;

    for (a = 0; a < 16; a++){
        //Positionnement à l'écran pour la deuxième matrice
        gotoligcol(a,70);
        for (b = 0; b < 16; b++){
            //Premiere ligne on parcours les colonnes
            if (a == 0 && b > 0){
                printf("%2d |",b);
            }
                //Premiere colonne on parcours les lignes
            else if(b == 0 && a > 0){
                printf("%2c |", a + 'a' - 1);
            }
                //pour les cases de la matrices on affiche des cases vides
            else{
                printf("%2c |",' ');
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////