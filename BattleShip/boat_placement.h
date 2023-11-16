
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
    int P = 1;
    int C = 1;
    int D = 1;
    int S = 1;
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
    while (compteur_general <= 10) {
        while (P <= 1) {
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
            SetConsoleTextAttribute(hConsole, 11);
            printf("Row:\n");
            SetConsoleTextAttribute(hConsole, 15);
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
                while (x == 1 && col - 6 < 1 || x == 2 && col + 6 > 15) {
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
                        mat[lig][col - z] = 'P';
                        gotoligcol(lig, (col * 4) - (z * 4));
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'P');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
                //Si vers la droite
                if (x == 2 && col + 6 <= 15){
                    for (z = 1; z < 7; z++) {
                        mat[lig - 'A' + 1 ][col + z] = 'P';
                        gotoligcol(lig - 'A' + 1 , (col * 4) + (z * 4));
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
        }
        
        //Se procéder pour le porte avion est repeté pour chaque type de bateaux
        while (C <= 2) {
            do {
                gotoligcol(17, 0);
                SetConsoleTextAttribute(hConsole, 11);
                printf("Column:\n");
                SetConsoleTextAttribute(hConsole, 15);
                fflush(stdin);
                scanf("%d", &col);
                while (col > 15 || col < 1) {
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(18, 0);
                    fflush(stdin);
                    scanf("%d", &col);
                }
                gotoligcol(19, 0);
                SetConsoleTextAttribute(hConsole, 11);
                printf("Row:\n");
                SetConsoleTextAttribute(hConsole, 15);
                fflush(stdin);
                scanf("%c", &lig);
                while (lig - 'A' + 1  > 15 || lig - 'A' + 1  < 1) {
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(20, 0);
                    fflush(stdin);
                    scanf("%c", &lig);
                }
            }
            while (mat[lig - 'A' + 1 ][col] != B);
            mat[lig - 'A' + 1 ][col] = 'C';
            gotoligcol(lig - 'A' + 1 , col * 4);
            SetConsoleTextAttribute(hConsole, 10);
            printf("%2c", 'C');
            SetConsoleTextAttribute(hConsole, 15);
            //Gestion des erreurs de saisie
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
            for (int j = 1; j < 5; j ++){
                while (r == 1 && mat[lig - 'A' + 1][col + j] != B && mat[lig - 'A' + 1][col - j] != B){
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(24, 0);
                    fflush(stdin);
                    scanf("%d", &r);
                }
                while (r == 2 && mat[lig - 'A' + 1 + j][col] != B && mat[lig - 'A' + 1 - j][col] != B){
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(24, 0);
                    fflush(stdin);
                    scanf("%d", &r);
                }
            }
            if (r == 1){
                gotoligcol(29, 0);
                SetConsoleTextAttribute(hConsole, 11);
                printf("In which way ?:\n");
                SetConsoleTextAttribute(hConsole, 15);
                printf("1. Towards the left.\n");
                printf("2. Towards the right.\n");
                fflush(stdin);
                scanf("%d", &x);
                //Gestion des erreurs de saisie
                while (x != 1 && x != 2) {
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                while (x == 1 && col - 4 < 1 || x == 2 && col + 4 > 15){
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                for (int j = 1; j < 5; j ++){
                    while (x == 1 && mat[lig - 'A' + 1 ][col - j] != B) {
                        gotoligcol(25,140);
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("Error.");
                        SetConsoleTextAttribute(hConsole, 15);
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 1 && col - 4 >= 1){
                    for (z = 1; z < 5; z++){
                        mat[lig - 'A' + 1 ][col - z] = 'C';
                        gotoligcol(lig - 'A' + 1 , (col * 4) - (z * 4));
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'C');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
                for (int j = 1; j < 5; j ++){
                    while (x == 2 && mat[lig - 'A' + 1 ][col + j] != B) {
                        gotoligcol(25,140);
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("Error.");
                        SetConsoleTextAttribute(hConsole, 15);
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 2 && col + 4 <= 15) {
                    for (z = 1; z < 5; z++) {
                        mat[lig - 'A' + 1 ][col + z] = 'C';
                        gotoligcol(lig - 'A' + 1 , (col * 4) + (z * 4));
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'C');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
            }
            else {
                SetConsoleTextAttribute(hConsole, 11);
                printf("In which way ?:\n");
                SetConsoleTextAttribute(hConsole, 15);
                printf("1. Upwards.\n");
                printf("2. Downwards.\n");
                fflush(stdin);
                scanf("%d", &x);
                //Gestion des erreurs de saisie
                while (x != 1 && x != 2) {
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(28, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                while(x == 1 && lig - 'A' + 1  - 4 < 1 || x == 2 && lig - 'A' + 1  + 4 > 15){
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(28, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                for (int j = 1; j < 5; j ++){
                    while (r == 1 && mat[lig - 'A' + 1 - j][col + j] != B && mat[lig - 'A' + 1 ][col - j] != B){
                        gotoligcol(25,140);
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("Error.");
                        SetConsoleTextAttribute(hConsole, 15);
                        gotoligcol(24, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                    while (r == 2 && mat[lig - 'A' + 1 + j][col] != B && mat[lig - 'A' + 1 - j][col] != B){
                        gotoligcol(25,140);
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("Error.");
                        SetConsoleTextAttribute(hConsole, 15);
                        gotoligcol(24, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                for (int i = 1; i < 5; i ++){
                    while (x == 1 && mat[lig - 'A' + 1  - i][col] != B) {
                        gotoligcol(25,140);
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("Error.");
                        SetConsoleTextAttribute(hConsole, 15);
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 1 && lig - 'A' + 1  - 4 >= 1){
                    for (z = 1; z < 5; z++) {
                        mat[lig - 'A' + 1  - z][col] = 'C';
                        gotoligcol(lig - 'A' + 1  - z, col * 4);
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'C');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
                for (int i = 1; i < 5; i ++){
                    while (x == 2 && mat[lig - 'A' + 1  + i][col] != B) {
                        gotoligcol(25,140);
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("Error.");
                        SetConsoleTextAttribute(hConsole, 15);
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 2 && lig - 'A' + 1  + 4 <= 15){
                    for (z = 1; z < 5; z++) {
                        mat[lig - 'A' + 1  + z][col] = 'C';
                        gotoligcol(lig - 'A' + 1  + z, col * 4);
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'C');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
            }
            C++;
            compteur_general++;
            gotoligcol(16, 34);
            printf("%d", compteur_general);
            gotoligcol(17, 0);
        }
        while (D <= 3) {
            do{
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
                gotoligcol(19,0);
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
            }
            while (mat[lig - 'A' + 1 ][col] != B);
            mat[lig - 'A' + 1 ][col] = 'D';
            gotoligcol(lig - 'A' + 1 , col * 4);
            SetConsoleTextAttribute(hConsole, 10);
            printf("%2c", 'D');
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
            for (int j = 1; j < 3; j ++){
                while (r == 1 && mat[lig - 'A' + 1 ][col + j] != B && mat[lig - 'A' + 1 ][col - j] != B){
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(24, 0);
                    fflush(stdin);
                    scanf("%d", &r);
                }
                while (r == 2 && mat[lig - 'A' + 1  + j][col] != B && mat[lig - 'A' + 1  - j][col] != B){
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(24, 0);
                    fflush(stdin);
                    scanf("%d", &r);
                }
            }
            if (r == 1) {
                gotoligcol(29, 0);
                SetConsoleTextAttribute(hConsole, 11);
                printf("In which way ?:\n");
                SetConsoleTextAttribute(hConsole, 15);
                printf("1. Towards the left.\n");
                printf("2. Towards the right.\n");
                fflush(stdin);
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
                while (x == 1 && col - 2 < 1 || x == 2 && col + 2 > 15) {
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                for (int j = 1; j < 3; j ++){
                    while (x == 1 && mat[lig - 'A' + 1 ][col - j] != B) {
                        gotoligcol(25,140);
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("Error.");
                        SetConsoleTextAttribute(hConsole, 15);
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 1 && col - 2 >= 1){
                    for (z = 1; z < 3; z++) {
                        mat[lig - 'A' + 1 ][col - z] = 'D';
                        gotoligcol(lig - 'A' + 1 , (col - z)* 4);
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'D');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
                for (int j = 1; j < 3; j ++){
                    while (x == 2 && mat[lig - 'A' + 1 ][col + j] != B) {
                        gotoligcol(25,140);
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("Error.");
                        SetConsoleTextAttribute(hConsole, 15);
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 2 && col + 2 <= 15) {
                    for (z = 1; z < 3; z++){
                        mat[lig - 'A' + 1 ][col + z] = 'D';
                        gotoligcol(lig - 'A' + 1 , (col + z) * 4);
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'D');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
            }
            else {
                SetConsoleTextAttribute(hConsole, 11);
                printf("In which way ?:\n");
                SetConsoleTextAttribute(hConsole, 15);
                printf("1. Upwards.\n");
                printf("2. Downwards.\n");
                fflush(stdin);
                scanf("%d", &x);
                //Gestion des erreurs de saisie
                while (x != 1 && x != 2) {
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(28, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                while(x == 1 && lig - 'A' + 1  - 2 < 1 || x == 2 && lig - 'A' + 1  + 2 > 15){
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(28, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                for (int i = 1; i < 3; i ++){
                    while (x == 1 && mat[lig - 'A' + 1  - i][col] != B) {
                        gotoligcol(25,140);
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("Error.");
                        SetConsoleTextAttribute(hConsole, 15);
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 1 && lig - 'A' + 1  - 2 >= 1) {
                    for (z = 1; z < 3; z++) {
                        mat[lig - 'A' + 1  - z][col * 4] = 'D';
                        gotoligcol(lig - 'A' + 1  - z, col * 4);
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'D');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
                for (int i = 1; i < 3; i ++){
                    while (x == 2 && mat[lig - 'A' + 1  + i][col] != B) {
                        gotoligcol(25,140);
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("Error.");
                        SetConsoleTextAttribute(hConsole, 15);
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 2 && lig - 'A' + 1  + 2 <= 15){
                    for (z = 1; z < 3; z++) {
                        mat[lig - 'A' + 1  + z][col * 4] = 'D';
                        gotoligcol(lig - 'A' + 1  + z, col * 4);
                        SetConsoleTextAttribute(hConsole, 10);
                        printf("%2c", 'D');
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                }
            }
            D++;
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
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void placement_bateaux_aleatoire(unsigned char ** mat){

    //Définitions des variables
    int P = 1;
    int C = 1;
    int D = 1;
    int S = 1;
    int lig;
    int col;
    int B = 95;
    int direction;
    int sens;
    int compte_ba = 1;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    srand(time(NULL));
    //Tant que 10 bateaux n'ont pas été posés on reste dans la boucle
    while (compte_ba <= 10){
        while (P < 2) {
            do{
                lig = rand() % (15) + 1;
                col = rand() % (15) + 1;
                direction = rand() % (2) + 1;
            }
            while (mat[lig][col] != B);
            if (mat[lig][col] == B){
                mat[lig][col] = 'P';
                gotoligcol(lig, col * 4);
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'P');
                SetConsoleTextAttribute(hConsole, 15);

                //Si la direction aléatoire est Verticale
                if (direction == 1){
                    for (int i = 0; i < 7; i++){
                        //On place le bateau vers le bas
                        if ((lig + 7) <= 15 && mat[lig + i][col] == B){
                            mat[lig + i][col] = 'P';
                            gotoligcol(lig + i, col * 4);
                            SetConsoleTextAttribute(hConsole, 10);
                            printf("%2c", 'P');
                            SetConsoleTextAttribute(hConsole, 15);
                        }
                            //On place le bateau vers le haut
                        else if ((lig - 7) >= 1 && mat[lig - i][col] == B){
                            mat[lig - i][col] = 'P';
                            gotoligcol(lig - i, col * 4);
                            SetConsoleTextAttribute(hConsole, 10);
                            printf("%2c", 'P');
                            SetConsoleTextAttribute(hConsole, 15);
                        }
                    }
                }
                    //Si la direction aléatoire est horizontale
                else{
                    mat[lig][col] = 'P';
                    for (int j = 0; j < 7; j++) {
                        //On place le bateau vers la droite
                        if ((col + 7) <= 15 && mat[lig][col + j] == B) {
                            mat[lig][col + j] = 'P';
                            gotoligcol(lig, (col + j)* 4);
                            SetConsoleTextAttribute(hConsole, 10);
                            printf("%2c", 'P');
                            SetConsoleTextAttribute(hConsole, 15);
                        }
                            //On place le bateau vers la gauche
                        else if ((col - 7) >= 1 && mat[lig][col - j] == B) {
                            mat[lig][col - j] = 'P';
                            gotoligcol(lig, (col - j) * 4);
                            SetConsoleTextAttribute(hConsole, 10);
                            printf("%2c", 'P');
                            SetConsoleTextAttribute(hConsole, 15);
                        }
                    }
                }
            }
            else{
                mat[lig][col] = B;
                gotoligcol(lig, col * 4);
                printf("%2c", ' ');
            }
            P++;
            compte_ba ++;
        }
        while (C < 3){
            do {
                lig = rand() % (15) + 1;
                col = rand() % (15) + 1;
                direction = rand() % (2) + 1;
            }while (mat[lig][col] != B);
            if (mat[lig][col] == B){
                mat[lig][col] = 'C';
                gotoligcol(lig, col * 4);
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'C');
                SetConsoleTextAttribute(hConsole, 15);
                //Si la direction aléatoire est vertical
                if (direction == 1){
                    for (int i = 0; i < 5; i++){
                        //On place le bateau vers le bas
                        if ((lig + 5) <= 15 && mat[lig + i][col] == B){
                            mat[lig + i][col] = 'C';
                            gotoligcol(lig + i, (col * 4));
                            SetConsoleTextAttribute(hConsole, 10);
                            printf("%2c", 'C');
                            SetConsoleTextAttribute(hConsole, 15);
                        }
                            //On place le bateau vers le haut
                        else if ((lig - 5) >= 1 && mat[lig - i][col] == B){
                            mat[lig - i][col] = 'C';
                            gotoligcol(lig - i, (col * 4));
                            SetConsoleTextAttribute(hConsole, 10);
                            printf("%2c", 'C');
                            SetConsoleTextAttribute(hConsole, 15);
                        }
                    }
                }
                    //Si la direction aléatoire est horizontale
                else{
                    mat[lig][col] = 'C';
                    for (int j = 0; j < 5; j++){
                        //On place le bateau vers la droite
                        if ((col + 5) <= 15 && mat[lig][col + j] == B) {
                            mat[lig][col + j] = 'C';
                            gotoligcol(lig, (col * 4) + j * 4);
                            SetConsoleTextAttribute(hConsole, 10);
                            printf("%2c", 'C');
                            SetConsoleTextAttribute(hConsole, 15);
                        }
                            //On place le bateau vers la gauche
                        else if ((col - 5) >= 1 && mat[lig][col - j] == B){
                            mat[lig][col - j] = B;
                            gotoligcol(lig, ((col *4)- j* 4));
                            SetConsoleTextAttribute(hConsole, 10);
                            printf("%2c", 'C');
                            SetConsoleTextAttribute(hConsole, 15);
                        }
                    }
                }
            }
            else{
                mat[lig][col] = B;
                gotoligcol(lig, (col * 4));
                printf("%2c", ' ');
            }
            C++;
            compte_ba++;
        }
        while (D < 4){
            do{
                lig = rand() % (15) + 1;
                col = rand() % (15) + 1;
                direction = rand() % (2) + 1;
            }
            while (mat[lig][col] != B);
            if (mat[lig][col] == B){
                mat[lig][col] = 'D';
                gotoligcol(lig, col * 4);
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'D');
                SetConsoleTextAttribute(hConsole, 15);
                //Si la direction aléatoire est verticale
                if (direction == 1){
                    for (int i = 0; i < 3; i++){
                        //On place le bateau vers  le bas
                        if ((lig + 3) <= 15 && mat[lig + i][col] == B){
                            mat[lig + i][col] = 'D';
                            gotoligcol(lig + i, (col * 4));
                            SetConsoleTextAttribute(hConsole, 10);
                            printf("%2c", 'D');
                            SetConsoleTextAttribute(hConsole, 15);
                        }
                            //On place le bateau vers le haut
                        else if ((lig - 3) >= 1 && mat[lig - i][col] == B){
                            mat[lig - i][col] = 'D';
                            gotoligcol(lig - i, (col * 4));
                            SetConsoleTextAttribute(hConsole, 10);
                            printf("%2c", 'D');
                            SetConsoleTextAttribute(hConsole, 15);
                        }
                    }
                }
                    //Si la direction aléatoire est horizontale
                else{
                    mat[lig][col] = 'D';
                    for (int j = 0; j < 3; j++) {
                        //On place le bateau vers la droite
                        if ((col + 3) <= 15 && mat[lig][col + j] == B) {
                            mat[lig][col + j] = 'D';
                            gotoligcol(lig, (col * 4) + j * 4);
                            SetConsoleTextAttribute(hConsole, 10);
                            printf("%2c", 'D');
                            SetConsoleTextAttribute(hConsole, 15);
                        }
                            //On place le bateau vers la gauche
                        else if ((col - 3) >= 1 && mat[lig][col - j] == B){
                            mat[lig][col - j] = 'D';
                            gotoligcol(lig, ((col - j)* 4));
                            SetConsoleTextAttribute(hConsole, 10);
                            printf("%2c", 'D');
                            SetConsoleTextAttribute(hConsole, 15);
                        }
                    }
                }
            }
            else{
                mat[lig][col] = B;
                gotoligcol(lig, (col * 4));
                printf("%2c", ' ');
            }
            D++;
            compte_ba++;
        }
        while (S < 5){
            do{
                lig = rand() % (15) + 1;
                col = rand() % (15) + 1;
            }
            while (mat[lig][col] != B);
            //On place le bateau
            if (mat[lig][col] == B) {
                mat[lig][col] = 'S';
                gotoligcol(lig, col * 4);
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'S');
                SetConsoleTextAttribute(hConsole, 15);
            }
            else{
                mat[lig][col] = B;
            }
            S++;
            compte_ba++;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void placement_bateaux_aleatoire1(unsigned char ** mat_ia1){

    //Définitions des variables
    int P = 1;
    int C = 1;
    int D = 1;
    int S = 1;
    int lig;
    int col;
    int B = 95;
    int direction;
    int compte_ba = 1;

    //Ces bateau ne seront pas afficher dans les decors
    while (compte_ba <= 10) {
        while (P < 2){
            lig = rand() % (15) + 1;
            col = rand() % (15) + 1;
            direction = rand() % (2) + 1;
            while (mat_ia1[lig][col] != B){
                lig = rand() % (15) + 1;
                col = rand() % (15) + 1;
                direction = rand() % (2) + 1;
            }
            if (mat_ia1[lig][col] == B){
                mat_ia1[lig][col] = 'P';
                if (direction == 1){
                    for (int i = 0; i < 7; i++){
                        if ((lig + 7) <= 15 && mat_ia1[lig + i][col] == B){
                            mat_ia1[lig + i][col] = 'P';
                        }
                        else if ((lig - 7) >= 1 && mat_ia1[lig - i][col] == B){
                            mat_ia1[lig - i][col] = 'P';
                        }
                    }
                }
                    //Si la direction aléatoire est horizontale
                else{
                    mat_ia1[lig][col] = 'P';
                    for (int j = 0; j < 7; j++) {
                        if ((col + 7) < 15 && mat_ia1[lig][col + j] == B){
                            mat_ia1[lig][col + j] = 'P';
                        }
                        else if ((col - 7) >= 1 && mat_ia1[lig][col - j] == B){
                            mat_ia1[lig][col - j] = 'P';
                        }
                    }
                }
            }
            else {
                mat_ia1[lig][col] = B;
            }
            P++;
            compte_ba ++;
        }
        while (C < 3){
            lig = rand() % (15) + 1;
            col = rand() % (15) + 1;
            direction = rand() % (2) + 1;
            while (mat_ia1[lig][col] != B){
                lig = rand() % (15) + 1;
                col = rand() % (15) + 1;
                direction = rand() % (2) + 1;
            }
            if (mat_ia1[lig][col] == B){
                mat_ia1[lig][col] = 'C';
                if (direction == 1){
                    for (int i = 0; i < 5; i++){
                        if ((lig + 5) <= 15 && mat_ia1[lig + i][col] == B){
                            mat_ia1[lig + i][col] = 'C';
                        }
                        else if ((lig - 5) >= 1 && mat_ia1[lig - i][col] == B){
                            mat_ia1[lig - i][col] = 'C';
                        }
                    }
                }
                    //Si la direction aléatoire est horizontale
                else{
                    mat_ia1[lig][col] = 'C';
                    for (int j = 0; j < 5; j++) {
                        if ((col + 5) < 15 && mat_ia1[lig][col + j] == B){
                            mat_ia1[lig][col + j] = 'C';
                        }
                        else if ((col - 5) >= 1 && mat_ia1[lig][col - j] == B){
                            mat_ia1[lig][col - j] = 'C';
                        }
                    }
                }
            }
            else {
                mat_ia1[lig][col] = B;
            }
            C++;
            compte_ba++;
        }
        while (D < 4){
            lig = rand() % (15) + 1;
            col = rand() % (15) + 1;
            direction = rand() % (2) + 1;
            while (mat_ia1[lig][col] != B) {
                lig = rand() % (15) + 1;
                col = rand() % (15) + 1;
                direction = rand() % (2) + 1;
            }
            if (mat_ia1[lig][col] == B){
                mat_ia1[lig][col] = 'D';
                if (direction == 1){
                    for (int i = 0; i < 3; i++){
                        if ((lig + 3) <= 15 && mat_ia1[lig + i][col] == B){
                            mat_ia1[lig + i][col] = 'D';
                        }
                        else if ((lig - 3) >= 1 && mat_ia1[lig - i][col] == B){
                            mat_ia1[lig - i][col] = 'D';
                        }
                    }
                }
                    //Si la direction aléatoire est horizontale
                else{
                    mat_ia1[lig][col] = 'D';
                    for (int j = 0; j < 3; j++) {
                        if ((col + 3) <= 15 && mat_ia1[lig][col + j] == B){
                            mat_ia1[lig][col + j] = 'D';
                        }
                        else if ((col - 3) >= 1 && mat_ia1[lig][col - j] == B){
                            mat_ia1[lig][col - j] = 'D';
                        }
                    }
                }
            }
            else{
                mat_ia1[lig][col] = B;
            }
            D++;
            compte_ba++;
        }
        while (S < 5){
            lig = rand() % (15) + 1;
            col = rand() % (15) + 1;
            while (mat_ia1[lig][col] != B){
                lig = rand() % (15) + 1;
                col = rand() % (15) + 1;
                direction = rand() % (2) + 1;
            }
            if (mat_ia1[lig][col] == B) {
                mat_ia1[lig][col] = 'S';
            }
            else{
                mat_ia1[lig][col] = B;
            }
            S++;
            compte_ba++;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////