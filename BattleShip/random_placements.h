
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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