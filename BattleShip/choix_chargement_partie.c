#include "prototype.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void choix_chargement_partie(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){

    //DDV
    int i;
    int j;
    int s;
    int B = 95;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //On efface l'ecran
    system("cls");
    affichage_matrices_fichiers(mat,mat_ia1);
    SetConsoleTextAttribute(hConsole, 11);
    //Chaque couple de grille se voit attribuer un numéro (1,2,3)
    gotoligcol(28, 140);
    printf("                                 __..||..__\n");
    gotoligcol(29, 140);
    printf("                             -==|__.----.__|==-\n");
    gotoligcol(30, 140);
    printf("                                 __l|  |/__\n");
    gotoligcol(31, 140);
    printf("                            --==|__.----.__|==--\n");
    gotoligcol(32, 140);
    printf("                                __/       l__\n");
    gotoligcol(33, 140);
    printf("                            __'{             }'__\n");
    gotoligcol(34, 140);
    printf("                       ___'{  ! 8     8     8 !  }'___\n");
    gotoligcol(35, 140);
    printf("                 ====={                               }=====\n");
    gotoligcol(36, 140);
    printf("                _____________________________________________\n");
    gotoligcol(37, 140);
    printf("               |             /   .  -- . --  .  l            |\n");
    gotoligcol(38, 140);
    printf("               | '--_______/    +      !      +   l______--' |\n");
    gotoligcol(39, 140);
    printf("               |                !             !              |\n");
    gotoligcol(40, 140);
    printf("               |                                             |\n");
    gotoligcol(41, 140);
    printf("                 l                     |                     /");
    gotoligcol(42, 140);
    printf("                  l_                   |                  _/");
    gotoligcol(43, 140);
    printf("                     l_                |               _/");
    gotoligcol(44, 140);
    printf("                        l_             |            _/");
    gotoligcol(45, 140);
    printf("                           l_          |         _/");
    SetConsoleTextAttribute(hConsole, 15);

    gotoligcol(20, 70);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Which game do you want to load ?");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(21,70);
    printf("1. Game 1");
    gotoligcol(22, 70);
    printf("2. Game 2");
    gotoligcol(23, 70);
    printf("3. Game 3");
    gotoligcol(24, 70);
    printf("4. Main menu");
    gotoligcol(44, 95);
    printf("Copyright 2023 Battleship Alassane Wade");
    gotoligcol(25, 70);
    fflush(stdin);
    scanf("%d", &s);

    while (s != 1 && s != 2 && s != 3 && s != 4){
        gotoligcol(25,140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(25,70);
        fflush(stdin);
        scanf("%d", &s);
    }
    if (s == 1){
        //Affichage des decors
        system("cls");
        decors();
        decors1();

        //Message du debut du chargement
        gotoligcol(17,0);
        printf("Game loading in progress, please wait...\n");
        sleep(1);

        //Appel de la fonction de chargement chaque matrice à son fichier de chargement
        charger_partie1(mat_ia1);
        charger_partie(mat);
    }

    if (s == 2){
        //Affichage des decors
        system("cls");
        decors();
        decors1();

        //Message du debut du chargement
        gotoligcol(17,0);
        printf("Game loading in progress, please wait...\n");
        sleep(1);

        //Appel de la fonction de chargement chaque matrice à son fichier de chargement
        charger_partie2(mat_ia1);
        charger_partie1_0(mat);
    }

    if (s == 3){
        //Affichage des decors
        system("cls");
        decors();
        decors1();

        //Message du debut du chargement
        gotoligcol(17,0);
        printf("Game loading in progress, please wait...\n");
        sleep(1);

        //Appel de la fonction de chargement chaque matrice à son fichier de chargement
        charger_partie3(mat_ia1);
        charger_partie2_0(mat);
    }
    if (s == 4){
        //On efface l'écran
        system("cls");
        //On appel le menu principal
        menu(mat, mat_ia1, a , pseudo, choix, mat_bis,mat_ia1_bis);
    }
}
