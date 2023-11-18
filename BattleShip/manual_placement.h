
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void placement_bateaux(unsigned char ** mat ,unsigned char ** mat_ia1, int *a, char *pseudo){

    //Définitions des variables
    int k;
    int r;
    int z;
    int x;
    int P = 0;
    int C = 0;
    int D = 0;
    int S = 0;
    int B = 95;
    int col = 0;
    char lig = 0;
    HANDLE hConsole;
    int compteur_general = 1;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    
    gotoligcol(16, 70);
    SetConsoleTextAttribute(hConsole, 10);
    printf("Here are the boats you can place: Aircraft Carrier, Cruiser, Destroyer and Submarine.\n");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(18, 70);
    printf("The unique Aircraft Carrier with the letter P takes up 7 spaces.\n");
    gotoligcol(19, 70);
    printf("2 Cruisers with the letter C take up 5 spaces.\n");
    gotoligcol(20, 70);
    printf("3 Destroyers with the letter D take 3 spaces.\n");
    gotoligcol(21, 70);
    printf("4 Submarines with the letter S take up 1 space.\n");

    //Choix du bateau par l'utilisateur
    gotoligcol(15, 0);
    SetConsoleTextAttribute(hConsole, 11);
            printf("\nChoose the position of the boat n %d out of 10 to place:\n", compteur_general);
            SetConsoleTextAttribute(hConsole, 15);
            printf("Column:\n");
            fflush(stdin);
            scanf("%d", &col);
            while (col > 15 || col < 1){
                gotoligcol(25,140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(18, 0);
                fflush(stdin);
                scanf("%d", &col);
            }
            printf("Row:\n");
            fflush(stdin);
            scanf("%c", &lig);
            while (lig - 'A' + 1  > 15 || lig - 'A' + 1  < 1){
                gotoligcol(25,140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(20, 0);
                fflush(stdin);
                scanf("%c", &lig);
            }
            mat[lig - 'A' + 1 ][col] = 'P';

            gotoligcol(lig - 'A' + 1 , col * 4);
            SetConsoleTextAttribute(hConsole, 10);
            printf("%2c", 'P');
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(21, 0);
            SetConsoleTextAttribute(hConsole, 11);

            printf("How would you like to place your boat n%d ?:\n", compteur_general);
            SetConsoleTextAttribute(hConsole, 15);
            printf("1. Row\n");
            printf("2. Column\n");
            fflush(stdin);
            scanf("%d", &r);

            //Gestion des erreurs de saisie
            while (r != 1 && r != 2) {
                gotoligcol(25,140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(24, 0);
                fflush(stdin);
                scanf("%d", &r);
            }
            //Si en ligne
            if (r == 1) {
                gotoligcol(29, 0);
                SetConsoleTextAttribute(hConsole, 11);
                printf("In which way ?:\n");
                SetConsoleTextAttribute(hConsole, 15);
                printf("1. Towards the left.\n");
                printf("2. Towards the right.\n");
                scanf("%d", &x);
                while (x != 1 && x != 2) {
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                while (x == 1 && col - 6 < 1) {
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                while (x == 2 && col + 6 > 15) {
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                //Si vers la gauche
                if (x == 1 && col - 6 >= 1){
                    for(z = 1; z < 7; z++) {
                        mat[lig - 'A' + 1 ][col - z] = 'P';
                        gotoligcol(lig - 'A' + 1 , ((col - z) * 4));
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'P');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
                //Si vers la droite
                if (x == 2 && col + 6 <= 15){
                    for (z = 1; z < 7; z++) {
                        mat[lig - 'A' + 1 ][col + z] = 'P';
                        gotoligcol(lig - 'A' + 1 , ((col + z) * 4));
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'P');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
            }
            //Si en colonne
            else {
                SetConsoleTextAttribute(hConsole, 11);
                printf("In which way ?:\n");
                SetConsoleTextAttribute(hConsole, 15);
                printf("1. Upwards.\n");
                printf("2. Downwards.\n");
                scanf("%d", &x);
                //Gestion des erreurs de saisie
                while (x != 1 && x != 2) {
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(28, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                //Si vers le haut
                while(x == 1 && lig - 'A' + 1  - 6 < 1 || x == 2 && lig - 'A' + 1  + 6 > 15){
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(28, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                //Si vers le haut
                if (x == 1 && lig - 'A' + 1  - 6 >= 1){
                    for (z = 1; z < 7; z++) {
                        mat[lig - 'A' + 1  - z][col] = 'P';
                        gotoligcol(lig - 'A' + 1  - z, col * 4);
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'P');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
                //Si vers le bas
                if(x == 2 && lig - 'A' + 1  + 6 <= 15){
                    for (z = 1; z < 7; z++){
                        mat[lig - 'A' + 1  + z][col] = 'P';
                        gotoligcol(lig - 'A' + 1  + z, col * 4);
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'P');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
            }
            //On augmente de 1 les valeurs de P et du nombre de bateaux posés
            P++;
            compteur_general++;
            gotoligcol(16, 34);
            printf("%d", compteur_general);
            gotoligcol(17, 0);

        while (C < 2){
            gotoligcol(17, 0);
            printf("Column:\n");
            fflush(stdin);
            scanf("%d", &col);

            while (col > 15 || col < 1){
                gotoligcol(25,140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(18, 0);
                fflush(stdin);
                scanf("%d", &col);
            }

            gotoligcol(19, 0);
            printf("Row:\n");
            fflush(stdin);
            scanf("%c", &lig);

            while (lig - 'A' + 1  > 15 || lig - 'A' + 1  < 1){
                gotoligcol(25,140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(20, 0);
                fflush(stdin);
                scanf("%c", &lig);
            }
/*
            for (z = 1; z < 5; z++){
                while (mat[lig - 'A' + 1  - z][col] != B && mat[lig - 'A' + 1 + z][col] != B && mat[lig - 'A' + 1][col - z] != B && mat[lig - 'A' + 1][col + z] != B){
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(18, 0);
                    fflush(stdin);
                    scanf("%d", &col);
                    gotoligcol(20, 0);
                    fflush(stdin);
                    scanf("%c", &lig);
                    }
                }
            
*/
            mat[lig - 'A' + 1 ][col] = 'C';
            gotoligcol(lig - 'A' + 1 , col * 4);
            SetConsoleTextAttribute(hConsole, 10);
            printf("%2c", 'C');
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(21, 0);
            SetConsoleTextAttribute(hConsole, 11);

            printf("How would you like to place your boat n%d ?:\n", compteur_general);
            SetConsoleTextAttribute(hConsole, 15);
            printf("1. Row\n");
            printf("2. Column\n");
            fflush(stdin);
            scanf("%d", &r);

            //Gestion des erreurs de saisie
            while (r != 1 && r != 2) {
                gotoligcol(25,140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(24, 0);
                fflush(stdin);
                scanf("%d", &r);
            }
            for (z = 1; z < 5; z++){
                while (r == 2 && mat[lig - 'A' + 1  - z][col] != B && mat[lig - 'A' + 1 + z][col] != B){
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(24, 0);
                    fflush(stdin);
                    scanf("%d", &r);
                }
            }
            for (z = 1; z < 5; z++){
                while (r == 1 && mat[lig - 'A' + 1][col - z] != B && mat[lig - 'A' + 1][col + z] != B){
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(24, 0);
                    fflush(stdin);
                    scanf("%d", &r);
                }
            }
            //Si en ligne
            if (r == 1) {
                gotoligcol(29, 0);
                SetConsoleTextAttribute(hConsole, 11);
                printf("In which way ?:\n");
                SetConsoleTextAttribute(hConsole, 15);
                printf("1. Towards the left.\n");
                printf("2. Towards the right.\n");
                scanf("%d", &x);
                while (x != 1 && x != 2) {
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                while (x == 1 && col - 4 < 1) {
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                while (x == 2 && col + 4 > 15) {
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                while (x == 1 && lig - 'A' + 1  - 4 < 1 || x == 2 && lig - 'A' + 1  + 4 > 15){
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                for (z = 1; z < 5; z++){
                    while (x == 1 && mat[lig - 'A' + 1][col - z] != B || x == 2 && mat[lig - 'A' + 1][col + z] != B){
                        gotoligcol(25,140);
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("Error.");
                        SetConsoleTextAttribute(hConsole, 15);
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                } 
            
                //Si vers la gauche
                if (x == 1 && col - 4 >= 1){
                    for(z = 1; z < 5; z++) {
                        mat[lig - 'A' + 1 ][col - z] = 'C';
                        gotoligcol(lig - 'A' + 1 , ((col - z) * 4));
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'C');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
                //Si vers la droite
                if (x == 2 && col + 4 <= 15){
                    for (z = 1; z < 5; z++) {
                        mat[lig - 'A' + 1 ][col + z] = 'C';
                        gotoligcol(lig - 'A' + 1 , ((col + z) * 4));
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'C');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
            }
            //Si en colonne
            else {
                SetConsoleTextAttribute(hConsole, 11);
                printf("In which way ?:\n");
                SetConsoleTextAttribute(hConsole, 15);
                printf("1. Upwards.\n");
                printf("2. Downwards.\n");
                scanf("%d", &x);
                //Gestion des erreurs de saisie
                while (x != 1 && x != 2) {
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(28, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                //Si vers le haut
                while (x == 1 && lig - 'A' + 1  - 4 < 1 || x == 2 && lig - 'A' + 1  + 4 > 15){
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(28, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                for (z = 1; z < 5; z++){
                    while (x == 1 && mat[lig - 'A' + 1 - z][col] != B || x == 2 && mat[lig - 'A' + 1 + z][col] != B){
                        gotoligcol(25,140);
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("Error.");
                        SetConsoleTextAttribute(hConsole, 15);
                        gotoligcol(28, 0);
                        fflush(stdin);
                        scanf("%d", &x);
                    }
                } 
                //Si vers le haut
                if (x == 1 && lig - 'A' + 1  - 4 >= 1){
                    for (z = 1; z < 5; z++) {
                        mat[lig - 'A' + 1  - z][col] = 'C';
                        gotoligcol(lig - 'A' + 1  - z, col * 4);
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'C');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
                //Si vers le bas
                if(x == 2 && lig - 'A' + 1  + 4 <= 15){
                    for (z = 1; z < 5; z++){
                        mat[lig - 'A' + 1  + z][col] = 'C';
                        gotoligcol(lig - 'A' + 1  + z, col * 4);
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'C');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
            }
            //On augmente de 1 les valeurs de P et du nombre de bateaux posés
            C++;
            compteur_general++;
            gotoligcol(16, 34);
            printf("%d", compteur_general);
            gotoligcol(17, 0);
        }
        
        
        while (S <= 4) {
            for (k = 0; k < 1; k++) {
                do{
                    printf("Column:\n");
                    fflush(stdin);
                    scanf("%d", &col);
                    while (col > 15 || col < 1){
                        gotoligcol(25,140);
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("Error.");
                        SetConsoleTextAttribute(hConsole, 15);
                        gotoligcol(18, 0);
                        fflush(stdin);
                        scanf("%d", &col);
                    }
                    printf("Row:\n");
                    fflush(stdin);
                    scanf("%c", &lig);
                    while (lig - 'A' + 1  > 15 || lig - 'A' + 1  < 1){
                        gotoligcol(25,140);
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("Error.");
                        SetConsoleTextAttribute(hConsole, 15);
                        gotoligcol(20, 0);
                        fflush(stdin);
                        scanf("%c", &lig);
                    }
                }while (mat[lig - 'A' + 1 ][col] != B);
                mat[lig - 'A' + 1 ][col] = 'S';
                gotoligcol(lig - 'A' + 1 , col * 4);
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'S');
                SetConsoleTextAttribute(hConsole, 15);
            }
            S++;
            compteur_general++;
            gotoligcol(16, 34);
            printf("%d", compteur_general);
            gotoligcol(17, 0);
        }   
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
