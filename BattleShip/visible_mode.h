
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mode_visible_desactive(unsigned char ** mat_ia1){
    //DDV
    int i;
    int j;
    int B = 95;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (i = 1 ; i < 16 ; i++){
        for (j = 1 ;j < 16 ; j++){
            if (mat_ia1[i][j] == 'X'){
                gotoligcol(i, (j * 4)+ 70);
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
            if (mat_ia1[i][j] == 'P' || mat_ia1[i][j] == 'C' || mat_ia1[i][j] == 'D' || mat_ia1[i][j] == 'S'|| mat_ia1[i][j] == B) {
                gotoligcol(i, (j * 4) + 70);
                printf("%2c", ' ');
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mode_visible(unsigned char ** mat_ia1){

    //Définition des variables
    int i;
    int j;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Ouverture du fichier
    FILE *fp1 = NULL;
    fp1 = fopen("bataille_navale.txt", "w");

    //Gestions des erreurs d'ouverture du fichier
    if (fp1 == NULL) {
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else {
        //Ecriture de la matrice dans le fichier
        for (i = 1; i < 16; i++){
            for (j = 1; j < 16; j++){
                //On sauvegarde la matrice dans le fichier
                fprintf(fp1,"%2c", mat_ia1[i][j]);
            }
            fprintf(fp1, "\n");
        }
        //Fermeture fichier
        fclose(fp1);
    }
    fp1 = fopen("bataille_navale.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp1 == NULL) {
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
                //On scan le fichier et on l'affiche dans le decor de l'IA
                fscanf(fp1, "%2s", &mat_ia1[i][j]);
                if (mat_ia1[i][j] == 'P' || mat_ia1[i][j] == 'C' || mat_ia1[i][j] == 'D' || mat_ia1[i][j] == 'S'){
                    gotoligcol(i, (j * 4 ) + 70);
                    SetConsoleTextAttribute(hConsole, 10);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat_ia1[i][j] == 'X'){
                    gotoligcol(i, (j * 4 ) + 70);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat_ia1[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat_ia1[i][j] == 'O'){
                    gotoligcol(i, (j * 4 ) + 70);
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////