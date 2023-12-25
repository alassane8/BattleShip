#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void affichage_matrices_fichiers(unsigned char ** mat, unsigned char ** mat_ia1){

    //DDV
    int B = 95;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Initialisation de la matrice 1
    initialisation_matrice(mat,  mat_ia1);

    //Ouverture de tout les fichier comportant les grilles du joueur et de l'adversaire
    //Ouverture du fichier matrice J1
    FILE *fp0 = NULL;
    fp0 = fopen("bataille_navale1.0.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp0 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        gotoligcol(0, 0);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Game 1 :");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(1, 0);
        for (int i = 1 ; i < 16 ; i++){
            for (int j = 1 ;j < 16 ; j++){
                //On scan la matrice
                fscanf(fp0, "%2s", &mat[i][j]);
                if (mat[i][j] == 'P' || mat[i][j] == 'C' || mat[i][j] == 'D' || mat[i][j] == 'S'){
                    SetConsoleTextAttribute(hConsole, 10);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == 'X'){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == 'O'){
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == B){
                    printf("%2c", mat[i][j]);
                }
            }
            printf("\n");
        }
        //Fermeture du fichier.
        fclose(fp0);
    }
    //Ouverture du fichier matrice adversaire
    FILE *fp1 = NULL;
    fp1 = fopen("bataille_navale1.1.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp1 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        //On scan la matrice et on l'affiche si T ou E
        for (int i = 1 ; i < 16 ; i++){
            gotoligcol(i,31);
            for (int j = 1 ;j < 16 ; j++){
                fscanf(fp1, "%2s", &mat_ia1[i][j]);
                if (mat_ia1[i][j] == 'P' || mat_ia1[i][j] == 'C' || mat_ia1[i][j] == 'D' || mat_ia1[i][j] == 'S'){
                    printf("%2c", B);
                }
                if (mat_ia1[i][j] == 'X'){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat_ia1[i][j] == 'O'){
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat_ia1[i][j] == B){
                    printf("%2c", mat_ia1[i][j]);
                }
            }
        }
        //Fermeture fichier
        fclose(fp1);
    }

    initialisation_matrice(mat,  mat_ia1);
    FILE *fp2 = NULL;
    fp2 = fopen("bataille_navale2.0.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp2 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        gotoligcol(0, 65);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Game 2 :");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol (1, 65);
        for (int i = 1 ; i < 16 ; i++){
            gotoligcol(i, 65);
            for (int j = 1 ;j < 16 ; j++){
                //On scan la matrice
                fscanf(fp2, "%2s", &mat[i][j]);
                if (mat[i][j] == 'P' || mat[i][j] == 'C' || mat[i][j] == 'D' || mat[i][j] == 'S'){
                    SetConsoleTextAttribute(hConsole, 10);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == 'X'){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == 'O'){
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == B){
                    printf("%2c", mat[i][j]);
                }
            }
        }
        //Fermeture du fichier.
        fclose(fp2);
    }

    //Ouverture du fichier matrice adversaire
    FILE *fp3 = NULL;
    fp3 = fopen("bataille_navale2.1.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp3 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        //On scan la matrice et on l'affiche si T ou E
        for (int i = 1 ; i < 16 ; i++){
            gotoligcol(i,96);
            for (int j = 1 ;j < 16 ; j++){
                fscanf(fp3, "%2s", &mat_ia1[i][j]);
                if (mat_ia1[i][j] == 'P' || mat_ia1[i][j] == 'C' || mat_ia1[i][j] == 'D' || mat_ia1[i][j] == 'S'){
                    printf("%2c", B);
                }
                if (mat_ia1[i][j] == 'X'){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat_ia1[i][j] == 'O'){
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat_ia1[i][j] == B){
                    printf("%2c", mat_ia1[i][j]);
                }
            }
        }
        //Fermeture fichier
        fclose(fp3);
    }

    initialisation_matrice(mat,  mat_ia1);
    FILE *fp4 = NULL;
    fp4 = fopen("bataille_navale3.0.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp4 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        gotoligcol(0, 130);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Game 3 :");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol (1, 130);
        for (int i = 1 ; i < 16 ; i++){
            gotoligcol(i, 130);
            for (int j = 1 ;j < 16 ; j++){
                //On scan la matrice
                fscanf(fp4, "%2s", &mat[i][j]);
                if (mat[i][j] == 'P' || mat[i][j] == 'C' || mat[i][j] == 'D' || mat[i][j] == 'S'){
                    SetConsoleTextAttribute(hConsole, 10);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == 'X'){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == 'O'){
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == B){
                    printf("%2c", mat[i][j]);
                }
            }
        }
        //Fermeture du fichier.
        fclose(fp4);
    }
    //Ouverture du fichier matrice adversaire
    FILE *fp5 = NULL;
    fp5 = fopen("bataille_navale3.1.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp5 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        //On scan la matrice et on l'affiche si T ou E
        for (int i = 1 ; i < 16 ; i++){
            gotoligcol(i, 161);
            for (int j = 1 ;j < 16 ; j++){
                fscanf(fp5, "%2s", &mat_ia1[i][j]);
                if (mat_ia1[i][j] == 'P' || mat_ia1[i][j] == 'C' || mat_ia1[i][j] == 'D' || mat_ia1[i][j] == 'S'){
                    printf("%2c", B);
                }
                if (mat_ia1[i][j] == 'X'){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat_ia1[i][j] == 'O'){
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat_ia1[i][j] == B){
                    printf("%2c", mat_ia1[i][j]);
                }
            }
        }
        //Fermeture fichier
        fclose(fp5);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////