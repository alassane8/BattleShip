
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tir_aerien(unsigned char ** mat_ia1){

    //DDV
    int lig;
    int col;
    int B = 95;
    int i;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    srand(time(NULL));
    //5 tirs aérien par passage
    for (i = 0; i < 5; i ++){
        //Choix aleatoire des colonnes et lignes de tirs
        lig = rand() % (15) + 1;
        col = rand() % (15) + 1;

        //Si le tir n'est pas réussi
        if (mat_ia1[lig][col] == B) {
            // 1.1 Afficher E dans la case
            mat_ia1[lig][col] = 'E';
            gotoligcol(lig, (col * 4) + 70);
            SetConsoleTextAttribute(hConsole, 9);
            printf("%2c", 'E');
            SetConsoleTextAttribute(hConsole, 15);
        }
        //Sinon, un navire est touché
        if (mat_ia1[lig][col] == 'P' || mat_ia1[lig][col] == 'C' || mat_ia1[lig][col] == 'D' || mat_ia1[lig][col] == 'S'){
            mat_ia1[lig][col] = 'T';
            gotoligcol(lig, (col * 4) + 70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("%2c", 'T');
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////