#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void charger_partie(unsigned char ** mat){

    //Définition des variables
    int i;
    int j;
    int z;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //Ce sspg permet de charger depuis le fichier fp de charger la matrice du joueur

    //Ouverture d'un fichier
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
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                //On scan la matrice
                fscanf(fp0, "%2s", &mat[i][j]);
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
        //Fermeture du fichier.
        fclose(fp0);
        //Affichage des possibilités du joueur
        gotoligcol(17,0);
        printf("                                                      ");
        gotoligcol(17,0);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Loading completed !\n");
        SetConsoleTextAttribute(hConsole, 15);
        sleep(2);
        gotoligcol(17,0);
        printf("                                                      ");

    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void charger_partie1(unsigned char ** mat_ia1){

    //Définition des variables
    int i;
    int j;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Ce sspg charge la matrice de l'IA depuis le fichier fp1
    //Ouverture d'un fichier
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
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                fscanf(fp1, "%2s", &mat_ia1[i][j]);
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
        //Fermeture fichier
        fclose(fp1);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void charger_partie1_0(unsigned char ** mat){

    //Définition des variables
    int i;
    int j;
    int z;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //Ce sspg permet de charger depuis le fichier fp de charger la matrice du joueur

    //Ouverture d'un fichier
    FILE *fp0 = NULL;
    fp0 = fopen("bataille_navale2.0.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp0 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                //On scan la matrice
                fscanf(fp0, "%2s", &mat[i][j]);
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
        //Fermeture du fichier.
        fclose(fp0);
        //Affichage des possibilités du joueur
        gotoligcol(17,0);
        printf("                                                      ");
        gotoligcol(17,0);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Loading completed !\n");
        SetConsoleTextAttribute(hConsole, 15);
        sleep(2);
        gotoligcol(17,0);
        printf("                                                      ");

    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void charger_partie2(unsigned char ** mat_ia1){

    //Définition des variables
    int i;
    int j;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Ce sspg charge la matrice de l'IA depuis le fichier fp1
    //Ouverture d'un fichier
    FILE *fp1 = NULL;
    fp1 = fopen("bataille_navale2.1.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp1 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }else{
        //On scan la matrice et on l'affiche si T ou E
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                fscanf(fp1, "%2s", &mat_ia1[i][j]);
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
        //Fermeture fichier
        fclose(fp1);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void charger_partie2_0(unsigned char ** mat){

    //Définition des variables
    int i;
    int j;
    int z;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //Ce sspg permet de charger depuis le fichier fp de charger la matrice du joueur

    //Ouverture d'un fichier
    FILE *fp0 = NULL;
    fp0 = fopen("bataille_navale3.0.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp0 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                //On scan la matrice
                fscanf(fp0, "%2s", &mat[i][j]);
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
        //Fermeture du fichier.
        fclose(fp0);
        //Affichage des possibilités du joueur
        gotoligcol(17,0);
        printf("                                                      ");
        gotoligcol(17,0);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Loading completed !\n");
        SetConsoleTextAttribute(hConsole, 15);
        sleep(2);
        gotoligcol(17,0);
        printf("                                                      ");

    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void charger_partie3(unsigned char ** mat_ia1){
       //Définition des variables
    int i;
    int j;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Ce sspg charge la matrice de l'IA depuis le fichier fp1
    //Ouverture d'un fichier
    FILE *fp1 = NULL;
    fp1 = fopen("bataille_navale3.1.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp1 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        //On scan la matrice et on l'affiche si T ou E
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                fscanf(fp1, "%2s", &mat_ia1[i][j]);
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
        //Fermeture fichier
        fclose(fp1);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////