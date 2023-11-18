
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void choix_chargement_partie(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int w, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){

    //Variables Definitions
    int i;
    int j;
    int s;
    int B = 95;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Clean page
    system("cls");

    //Display files matrices
    affichage_matrices_fichiers(mat,mat_ia1);

    SetConsoleTextAttribute(hConsole, 11);
    gotoligcol(28, 125);
    printf("                                 __..||..__\n");
    gotoligcol(29, 125);
    printf("                             -==|__.----.__|==-\n");
    gotoligcol(30, 125);
    printf("                                 __l|  |/__\n");
    gotoligcol(31, 125);
    printf("                            --==|__.----.__|==--\n");
    gotoligcol(32, 125);
    printf("                                __/       l__\n");
    gotoligcol(33, 125);
    printf("                            __'{             }'__\n");
    gotoligcol(34, 125);
    printf("                       ___'{  ! 8     8     8 !  }'___\n");
    gotoligcol(35, 125);
    printf("                 ====={                               }=====\n");
    gotoligcol(36, 125);
    printf("                _____________________________________________\n");
    gotoligcol(37, 125);
    printf("               |             /   .  -- . --  .  l            |\n");
    gotoligcol(38, 125);
    printf("               | '--_______/    +      !      +   l______--' |\n");
    gotoligcol(39, 125);
    printf("               |                !             !              |\n");
    gotoligcol(40, 125);
    printf("               |                                             |\n");
    gotoligcol(41, 125);
    printf("                 l                     |                     /");
    gotoligcol(42, 125);
    printf("                  l_                   |                  _/");
    gotoligcol(43, 125);
    printf("                     l_                |               _/");
    gotoligcol(44, 125);
    printf("                        l_             |            _/");
    gotoligcol(45, 125);
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
    gotoligcol(44, 70);
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
        //Display decorations
        system("cls");
        decors();
        decors1();

        //begin loading
        gotoligcol(17,0);
        printf("Game loading in progress, please wait...\n");
        sleep(1);

        //Load matrices
        charger_partie1(mat_ia1);
        charger_partie(mat);
        
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                if (mat[i][j] != B && mat_ia1[i][j] != B){
                    //Appel de la fonction de jeux
                    jouer(mat,  mat_ia1, a, pseudo,w, choix, mat_bis, mat_ia1_bis);
                }
            }
        }
        gotoligcol(16,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error: You loaded an empty game.");
        gotoligcol(17,70);
        printf("You will be redirected to the menu.");
        SetConsoleTextAttribute(hConsole, 15);
        sleep(4);
        //Clean page
        system("cls");
        //Back menu page
        menu(mat, mat_ia1, a , pseudo, choix, mat_bis,mat_ia1_bis);
    }

    if (s == 2){
        //Display decorations
        system("cls");
        decors();
        decors1();

        //Begin loading
        gotoligcol(17,0);
        printf("Game loading in progress, please wait...\n");
        sleep(1);

        //Load matrices
        charger_partie2(mat_ia1);
        charger_partie1_0(mat);

        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                if (mat[i][j] != B && mat_ia1[i][j] != B){
                    //Appel de la fonction de jeux
                    jouer(mat,  mat_ia1, a, pseudo,w, choix, mat_bis, mat_ia1_bis);
                }
            }
        }
        gotoligcol(16,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error: You loaded an empty game.");
        gotoligcol(17,70);
        printf("You will be redirected to the menu.");
        SetConsoleTextAttribute(hConsole, 15);
        sleep(4);
        //Clean page
        system("cls");
        //Back menu page
        menu(mat, mat_ia1, a , pseudo, choix, mat_bis,mat_ia1_bis);
    }

    if (s == 3){
        //Display decorations
        system("cls");
        decors();
        decors1();

        //Begin loading
        gotoligcol(17,0);
        printf("Game loading in progress, please wait...\n");
        sleep(1);

        //Load matrices
        charger_partie3(mat_ia1);
        charger_partie2_0(mat);

        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                if (mat[i][j] != B && mat_ia1[i][j] != B){
                    //Appel de la fonction de jeux
                    jouer(mat,  mat_ia1, a, pseudo,w, choix, mat_bis, mat_ia1_bis);
                }
            }
        }
        gotoligcol(16,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error: You loaded an empty game.");
        gotoligcol(17,70);
        printf("You will be redirected to the menu.");
        SetConsoleTextAttribute(hConsole, 15);
        sleep(4);
        //Clean page
        system("cls");
        //Back menu page
        menu(mat, mat_ia1, a , pseudo, choix, mat_bis,mat_ia1_bis);
    }
    if (s == 4){
        //Clean page
        system("cls");
        //Back menu page
        menu(mat, mat_ia1, a , pseudo, choix, mat_bis,mat_ia1_bis);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////