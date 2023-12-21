#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "prototypes.h"
#include "menu.h"
#include "gotoligcol.h"
#include "file_matrices.h"
#include "load_matrices.h"
#include "load.h"
#include "choice_loading_game.h"
#include "decorations.h"
#include "smoke.h"
#include "initialization_matrices.h"
#include "play.h"
#include "visible_mode.h"
#include "manual_placement.h"
#include "random_placements.h"
#include "save_matrices.h"
#include "save.h"
#include "aerial_shot.h"
#include "shot.h"
#include "winner.h"
#include "game_over.h"
#include "asciiboats.h"
#include "rules.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

    //Définition des variables
    int k;
    int t = 0;
    int i;
    int z;
    int a = 0;
    int choix;
    char pseudo[100];
    unsigned char ** mat = NULL;
    unsigned char ** mat_ia1 = NULL;
    unsigned char ** mat_bis = NULL;
    unsigned char ** mat_ia1_bis = NULL;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Bataille navale
    system("cls");
    gotoligcol(0, 30);
    SetConsoleTextAttribute(hConsole, 11);
    printf("/////////////////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("B A T T L E S H I P");
    SetConsoleTextAttribute(hConsole, 11);
    printf(" ///////////////////////////////////////\n");
    gotoligcol(3, 30);
    printf("////////////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("Please, open the game page wide");
    SetConsoleTextAttribute(hConsole, 11);
    printf(" ////////////////////////////////");
    SetConsoleTextAttribute(hConsole, 15);


    //3. Saisie du pseudo de l'utilisateur
    gotoligcol(5, 70);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Enter your nickname: ");
    SetConsoleTextAttribute(hConsole, 15);
    gets(pseudo);
    gotoligcol(6, 70);
    printf("Welcome %s !\n\n", pseudo);

    gotoligcol(44, 70);
    printf("Copyright 2023 Battleship Alassane Wade");

    boat_decoration_main();

    gotoligcol(30, 70);
    printf("Loading...");
    sleep(3);
    system("cls");

    //Création de l'échiquier

    //Création de la ligne [1][j]
    mat = (unsigned char **)malloc(16* sizeof(unsigned char*));

    //Création des colonnes
    for ( k = 0; k < 16; k++) {
        mat[k] = (unsigned char *)malloc(16 * sizeof(unsigned char));
    }
    //Création de la ligne [1][j]
    mat_ia1 = (unsigned char **)malloc(16* sizeof(unsigned char*));

    //Création des colonnes
    for ( k = 0; k < 16; k++) {
        mat_ia1[k] = (unsigned char *)malloc(16 * sizeof(unsigned char));
    }
    //Création de la ligne [1][j]
    mat_bis = (unsigned char **)malloc(16* sizeof(unsigned char*));

    //Création des colonnes
    for ( k = 0; k < 16; k++) {
        mat_bis[k] = (unsigned char *)malloc(16 * sizeof(unsigned char));
    }
    //Création de la ligne [1][j]
    mat_ia1_bis = (unsigned char **)malloc(16* sizeof(unsigned char*));

    //Création des colonnes
    for ( k = 0; k < 16; k++) {
        mat_ia1_bis[k] = (unsigned char *)malloc(16 * sizeof(unsigned char));
    }

    //Appel du Menu Principale
    menu(mat,mat_ia1, &a, pseudo, choix, mat_bis,mat_ia1_bis);

    //Fin du programme
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////