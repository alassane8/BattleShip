#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sauvegarde(unsigned char ** mat, unsigned char ** mat_ia1, int *a, char *pseudo, int w,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){

    //DDV
    int i;
    int j;
    int choix = 0;
    int B = 95;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //On efface l'écran
    system("cls");

    //Sauvegarde des matrices dans les matrices bis
    sauvegarde_matrices(mat, mat_ia1,mat_bis, mat_ia1_bis);

    //Affichage des fichiers contenant les matrices de jeux
    affichage_matrices_fichiers(mat,mat_ia1);

    //Les matrices reprennent les valeurs des matrices bis
    chargement_matrices(mat,mat_ia1,mat_bis,mat_ia1_bis);
    SetConsoleTextAttribute(hConsole, 11);
    
    boats_decoration_save1();

    //Deamnde a l'utilisateur ou sauvegarder sa partie en cours
    gotoligcol(20, 70);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Where do you want to save the current game ?");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(21,70);
    printf("1. Over Game 1");
    gotoligcol(22, 70);
    printf("2. Over Game 2");
    gotoligcol(23, 70);
    printf("3. Over Game 3");
    gotoligcol(24, 70);
    printf("4. Back to the game");
    gotoligcol(44, 70);
    printf("Copyright 2023 Battleship Alassane Wade");
    gotoligcol(25, 70);
    fflush(stdin);
    scanf("%d", &choix);

    while (choix != 1 && choix != 2 && choix != 3 && choix != 4){
        gotoligcol(25,140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(25, 70);
        printf("  ");
        gotoligcol(25, 70);
        fflush(stdin);
        scanf("%d", &choix);
    }

    //On efface l'écran
    system("cls");

    boats_decoration_save2();

    //Sauvegarder partie dans l'endroit indiqué
    if (choix == 1){
        sauvegarder_partie(mat, choix);
        sauvegarder_partie1(mat_ia1, choix);
        //Revenir à la partie en cours

        //Affichage des deux matrices
        gotoligcol(0, 0);
        decors();
        decors1();
        //Afficher les matrices dans les grilles
        //Matrice IA
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                if (mat_ia1[i][j] == 'X'){
                    gotoligcol(i, (j * 4 )+ 70);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat_ia1[i][j] == 'O'){
                    gotoligcol(i, (j * 4 )+ 70);
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }

            }
        }

        //Matrice joueur 1
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                if (mat[i][j] == 'P' || mat[i][j] == 'C' || mat[i][j] == 'D' || mat[i][j] == 'S'){
                    gotoligcol(i, (j * 4 ));
                    SetConsoleTextAttribute(hConsole, 10);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == 'X'){
                    gotoligcol(i, (j * 4 ));
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == 'O'){
                    gotoligcol(i, (j * 4 ));
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }
        }

        //Appel de la fonction de jeux
        jouer(mat, mat_ia1, a, pseudo,w, choix, mat_bis,mat_ia1_bis);
    }
    if (choix == 2){
        sauvegarder_partie(mat, choix);
        sauvegarder_partie1(mat_ia1, choix);
        //Revenir à la partie en cours
        //Affichage des deux matrices

        gotoligcol(0, 0);
        decors();
        decors1();
        //Afficher les matrices dans les grilles
        //Matrice IA
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                if (mat_ia1[i][j] == 'X'){
                    gotoligcol(i, (j * 4 )+ 70);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat_ia1[i][j] == 'O'){
                    gotoligcol(i, (j * 4 )+ 70);
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }
        }

        //Matrice joueur 1
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                if (mat[i][j] == 'P' || mat[i][j] == 'C' || mat[i][j] == 'D' || mat[i][j] == 'S'){
                    gotoligcol(i, (j * 4 ));
                    SetConsoleTextAttribute(hConsole, 10);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == 'X'){
                    gotoligcol(i, (j * 4 ));
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if ( mat[i][j] == 'O'){
                    gotoligcol(i, (j * 4 ));
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }
        }

        //Appel de la fonction de jeux
        jouer(mat, mat_ia1, a, pseudo,w, choix, mat_bis,mat_ia1_bis);
    }
    if (choix == 3){
        sauvegarder_partie(mat, choix);
        sauvegarder_partie1(mat_ia1, choix);
        //Revenir à la partie en cours
        //Affichage des deux matrices
        gotoligcol(0, 0);
        decors();
        decors1();
        //Afficher les matrices dans les grilles
        //Matrice IA
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                if (mat_ia1[i][j] == 'X'){
                    gotoligcol(i, (j * 4 )+ 70);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat_ia1[i][j] == 'O'){
                    gotoligcol(i, (j * 4 )+ 70);
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }
        }

        //Matrice joueur 1
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                if (mat[i][j] == 'P' || mat[i][j] == 'C' || mat[i][j] == 'D' || mat[i][j] == 'S'){
                    gotoligcol(i, (j * 4 ));
                    SetConsoleTextAttribute(hConsole, 10);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == 'X'){
                    gotoligcol(i, (j * 4 ));
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if ( mat[i][j] == 'O'){
                    gotoligcol(i, (j * 4 ));
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }
        }

        //Appel de la fonction de jeux
        jouer(mat, mat_ia1, a, pseudo,w, choix, mat_bis,mat_ia1_bis);
    }
    if (choix == 4){
        //Revenir à la partie en cours
        //Affichage des deux matrices
        gotoligcol(0, 0);
        decors();
        decors1();

        //Afficher les matrices dans les grilles
        //Matrice IA
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                if (mat_ia1[i][j] == 'X'){
                    gotoligcol(i, (j * 4 )+ 70);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat_ia1[i][j] == 'O'){
                    gotoligcol(i, (j * 4 )+ 70);
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }
        }

        //Matrice joueur 1
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                if (mat[i][j] == 'P' || mat[i][j] == 'C' || mat[i][j] == 'D' || mat[i][j] == 'S'){
                    gotoligcol(i, (j * 4 ));
                    SetConsoleTextAttribute(hConsole, 10);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == 'X'){
                    gotoligcol(i, (j * 4 ));
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == 'O'){
                    gotoligcol(i, (j * 4 ));
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }
        }
        //Appel de la fonction de jeux
        jouer(mat, mat_ia1, a, pseudo,w, choix, mat_bis,mat_ia1_bis);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sauvegarder_partie(unsigned char ** mat, int choix){

    //Définition des variables
    int i;
    int j;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Ce sspg sauvegarde la matrice du joueur dans le fichier fp
    //Ouverture d'un fichier

    if (choix == 1){

        FILE *fp0 = NULL;
        fp0 = fopen("bataille_navale1.0.txt", "w");

        //Gestions des erreurs d'ouverture du fichier
        if (fp0 == NULL) {
            gotoligcol(48,70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error. File opening problem.\n");
            SetConsoleTextAttribute(hConsole, 15);
        }

        else {
            //Affichage de la matrice
            for (i = 1; i < 16; i++){
                for (j = 1; j < 16; j++){
                    //On print la matrice dans le fichier
                    fprintf(fp0,"%2c", mat[i][j]);
                }
                //Retour à la ligne
                fprintf(fp0, "\n");
            }
            //Fermeture ficjhier
            fclose(fp0);
        }
    }
    if (choix == 2){

        FILE *fp2 = NULL;
        fp2 = fopen("bataille_navale2.0.txt", "w");

        //Gestions des erreurs d'ouverture du fichier
        if (fp2 == NULL) {
            gotoligcol(48,70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error. File opening problem.\n");
            SetConsoleTextAttribute(hConsole, 15);
        }

        else {
            //Affichage de la matrice
            for (i = 1; i < 16; i++){
                for (j = 1; j < 16; j++){
                    //On print la matrice dans le fichier
                    fprintf(fp2,"%2c", mat[i][j]);
                }
                //Retour à la ligne
                fprintf(fp2, "\n");
            }
            //Fermeture ficjhier
            fclose(fp2);
        }
    }
    if (choix == 3){

        FILE *fp4 = NULL;
        fp4 = fopen("bataille_navale3.0.txt", "w");

        //Gestions des erreurs d'ouverture du fichier
        if (fp4 == NULL) {
            gotoligcol(48,70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error. File opening problem.\n");
            SetConsoleTextAttribute(hConsole, 15);
        }

        else {
            //Affichage de la matrice
            for (i = 1; i < 16; i++){
                for (j = 1; j < 16; j++){
                    //On print la matrice dans le fichier
                    fprintf(fp4,"%2c", mat[i][j]);
                }
                //Retour à la ligne
                fprintf(fp4, "\n");
            }
            //Fermeture ficjhier
            fclose(fp4);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sauvegarder_partie1(unsigned char ** mat_ia1, int choix){

    //Définition des variables
    int i;
    int j;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Ce sspg sauvegarde la matrice de l'IA dans le fichier fp1
    //Ouverture d'un fichier
    if (choix == 1){
        FILE *fp1 = NULL;
        fp1 = fopen("bataille_navale1.1.txt", "w");

        //Gestions des erreurs d'ouverture du fichier
        if (fp1 == NULL) {
            gotoligcol(48,70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error. File opening problem.\n");
            SetConsoleTextAttribute(hConsole, 15);
        }

        else {
            //Affichage de la matrice
            for (i = 1; i < 16; i++){
                for (j = 1; j < 16; j++){
                    //Sauvegarde de la matrice dans le fichier
                    fprintf(fp1,"%2c", mat_ia1[i][j]);
                }
                //Retour à la ligne
                fprintf(fp1, "\n");
            }
            //Fermeture fichier
            fclose(fp1);
        }
    }
    if (choix == 2){

        FILE *fp3 = NULL;
        fp3 = fopen("bataille_navale2.1.txt", "w");

        //Gestions des erreurs d'ouverture du fichier
        if (fp3 == NULL) {
            gotoligcol(48,70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error. File opening problem.\n");
            SetConsoleTextAttribute(hConsole, 15);
        }

        else {
            //Affichage de la matrice
            for (i = 1; i < 16; i++){
                for (j = 1; j < 16; j++){
                    //Sauvegarde de la matrice dans le fichier
                    fprintf(fp3,"%2c", mat_ia1[i][j]);
                }
                //Retour à la ligne
                fprintf(fp3, "\n");
            }
            //Fermeture fichier
            fclose(fp3);
        }
    }
    if (choix == 3){

        FILE *fp5 = NULL;
        fp5 = fopen("bataille_navale3.1.txt", "w");

        //Gestions des erreurs d'ouverture du fichier
        if (fp5 == NULL) {
            gotoligcol(48,70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error. File opening problem.\n");
            SetConsoleTextAttribute(hConsole, 15);
        }
        else {
            //Affichage de la matrice
            for (i = 1; i < 16; i++){
                for (j = 1; j < 16; j++){
                    //Sauvegarde de la matrice dans le fichier
                    fprintf(fp5,"%2c", mat_ia1[i][j]);
                }
                //Retour à la ligne
                fprintf(fp5, "\n");
            }
            //Fermeture fichier
            fclose(fp5);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////