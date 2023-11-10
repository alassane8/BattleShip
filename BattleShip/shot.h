
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tirer (unsigned char ** mat_ia1, char *pseudo){

    //sous-p tirer sur une case
    //declaration des variables
    int col = 0;
    char lig = 0;
    int B = 95;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoligcol(22, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("%s's shooting's traces :", pseudo);
    SetConsoleTextAttribute(hConsole, 15);

    //On demande a l'utilisateur de saisir les coordonnées d'une case
    gotoligcol(30, 70);
    printf("                                                   ");
    gotoligcol(30, 70);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Where would you like to shoot ?\n");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(31, 70);
    printf("Row :\n");
    gotoligcol(32, 70);
    fflush(stdin);
    scanf("%c", &lig);
    while (lig - 'a' + 1 > 15 || lig - 'a' + 1 < 1){
        gotoligcol(25,140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(32, 70);
        fflush(stdin);
        scanf("%c", &lig);
    }
    gotoligcol(33, 70);
    printf("Column :\n");
    gotoligcol(34, 70);
    fflush(stdin);
    scanf("%d", &col);
    while (col > 15 || col < 1){
        gotoligcol(25,140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(34, 70);
        fflush(stdin);
        scanf("%d", &col);
    }

    //Si le tir n'est pas réussi
    if (mat_ia1[lig - 'a' + 1][col] == B){
        // 1.1 Afficher E dans la case
        mat_ia1[lig - 'a' + 1][col] = 'O';
        gotoligcol(lig - 'a' + 1, (col * 4) + 70);
        SetConsoleTextAttribute(hConsole, 9);//12 Rouge 9 Bleu 10 Vert
        printf("%2c", 'O');
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(23, 0);
        printf("                                                   ");
        gotoligcol(23,0);
        printf("%s fire in water (%c,%d)", pseudo,  lig, col);
    }

    //Sinon, un navire est touché
    if (mat_ia1[lig - 'a' + 1][col] == 'P' || mat_ia1[lig - 'a' + 1][col] == 'C' || mat_ia1[lig - 'a' + 1][col] == 'D' || mat_ia1[lig - 'a' + 1][col] == 'S'){
        // 2.1 Afficher T
        do {
            mat_ia1[lig - 'a' + 1][col] = 'X';
            gotoligcol(lig - 'a' + 1, (col * 4) + 70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("%2c", 'X');
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(24, 0);
            printf("                                                   ");
            gotoligcol(24, 0);
            printf("%s fire on ship (%c,%d)",pseudo , lig, col);
            gotoligcol(31, 70);
            printf("Row :\n");
            gotoligcol(32, 70);
            fflush(stdin);
            scanf("%c", &lig);
            while (lig - 'a' + 1 > 15 || lig - 'a' + 1 < 1){
                gotoligcol(25,140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(32, 70);
                fflush(stdin);
                scanf("%c", &lig);
            }
            gotoligcol(33, 70);
            printf("Column :\n");
            gotoligcol(34, 70);
            fflush(stdin);
            scanf("%d", &col);
            while (col > 15 || col < 1){
                gotoligcol(25,140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(34, 70);
                fflush(stdin);
                scanf("%d", &col);
            }
            //Si le tir n'est pas réussi
            if (mat_ia1[lig - 'a' + 1][col] == B){
                // 1.1 Afficher E dans la case
                mat_ia1[lig - 'a' + 1][col] = 'O';
                gotoligcol(lig - 'a' + 1, (col * 4) + 70);
                SetConsoleTextAttribute(hConsole, 9);
                printf("%2c", 'O');
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(23, 0);
                printf("                                                   ");
                gotoligcol(23,0);
                printf("%s fire in water (%c,%d)", pseudo , lig, col);
            }
        }
        while (mat_ia1[lig - 'a' + 1][col] == 'P' || mat_ia1[lig - 'a' + 1][col] == 'C' || mat_ia1[lig - 'a' + 1][col] == 'D' || mat_ia1[lig - 'a' + 1][col] == 'S');
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tirer_aleatoirement_matelot(unsigned char **mat, int compteur_tour) {

    //Définitions des variables
    int i;
    int j;
    int B = 95;
    int lig = 0;
    int col = 0;
    int choix;
    int const compte = compteur_tour;
    int compte_bateau_touche;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    gotoligcol(28, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("AI Level : Sailor");
    gotoligcol(19, 0);
    printf("Traces of enemy fire :");
    SetConsoleTextAttribute(hConsole, 15);

    gotoligcol(18, 0);
    SetConsoleTextAttribute(hConsole, 12);
    printf("Enemy fire incoming !");
    SetConsoleTextAttribute(hConsole, 15);
    sleep(3);
    gotoligcol(18, 0);
    printf("                                  ");
    //Choix aleatoire des colonnes et lignes de tirs
    srand(time(NULL));
    lig = rand() % (15) + 1;
    col = rand() % (15) + 1;

    //Si le tir n'est pas réussi
    if (mat[lig][col] == B) {
        // 1.1 Afficher E dans la case
        mat[lig][col] = 'O';
        gotoligcol(lig, (col * 4));
        SetConsoleTextAttribute(hConsole, 9);
        printf("%2c", 'O');
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(20, 0);
        printf("                                                   ");
        gotoligcol(20, 0);
        printf("Enemy fire in water (%c,%d)",lig + 64, col);
    }
    //Sinon, un navire est touché
    if (mat[lig][col] == 'P' || mat[lig][col] == 'C' || mat[lig][col] == 'D' || mat[lig][col] == 'S'){

        //2.1 Afficher T
        do{
            mat[lig][col] = 'X';
            gotoligcol(lig, (col * 4));
            SetConsoleTextAttribute(hConsole, 12);
            printf("%2c", 'X');
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(21, 0);
            printf("                                                   ");
            gotoligcol(21, 0);
            printf("Enemy fire on ship (%c,%d)",lig + 64, col);
            //Si le tir n'est pas réussi

            srand(time(NULL));
            lig = rand() % (15) + 1;
            col = rand() % (15) + 1;

            if (mat[lig][col] == B) {
                // 1.1 Afficher E dans la case
                mat[lig][col] = 'O';
                gotoligcol(lig, (col * 4));
                SetConsoleTextAttribute(hConsole, 9);
                printf("%2c", 'O');
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(20, 0);
                printf("                                                   ");
                gotoligcol(20, 0);
                printf("Enemy fire in water (%c,%d)",lig + 64, col);
            }
        }
        while (mat[lig][col] == 'P' || mat[lig][col] == 'C' || mat[lig][col] == 'D' || mat[lig][col] == 'S');
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void tirer_aleatoirement_caporal_chef(unsigned char **  mat, int compteur_tour){

    //Définitions des variables
    int i;
    int j;
    int l;
    int c;
    int B = 95;
    int lig = 0;
    int col = 0;
    int choix;
    int compte = compteur_tour;
    int a = compte;
    int compte_bateau_touche;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    gotoligcol(28, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("AI Level : Master Corporal");
    gotoligcol(19, 0);
    printf("Traces of enemy fire :");
    SetConsoleTextAttribute(hConsole, 15);

    gotoligcol(18, 0);
    SetConsoleTextAttribute(hConsole, 12);
    printf("Enemy fire incoming !");
    SetConsoleTextAttribute(hConsole, 15);
    sleep(3);
    gotoligcol(18, 0);
    printf("                                  ");
    //Choix aleatoire des colonnes et lignes de tirs
    srand(time(NULL));
    lig = rand() % (15) + 1;
    col = rand() % (15) + 1;

    //Si le tir n'est pas réussi
    if (mat[lig][col] == B) {
        // 1.1 Afficher E dans la case
        mat[lig][col] = 'O';
        gotoligcol(lig, (col * 4));
        SetConsoleTextAttribute(hConsole, 9);
        printf("%2c", 'O');
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(20, 0);
        printf("                                                   ");
        gotoligcol(20, 0);
        printf("Enemy fire in water (%c,%d)",lig + 64, col);
    }
    //Sinon, un navire est touché
    if (mat[lig][col] == 'P' || mat[lig][col] == 'C' || mat[lig][col] == 'D' || mat[lig][col] == 'S'){

        //2.1 Afficher T
        do{
            mat[lig][col] = 'X';
            gotoligcol(lig, (col * 4));
            SetConsoleTextAttribute(hConsole, 12);
            printf("%2c", 'X');
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(21, 0);
            printf("                                                   ");
            gotoligcol(21, 0);
            printf("Enemy fire on ship  (%c,%d)",lig + 64, col);


            choix = rand() % (4) + 1;

            if (choix == 1){
                lig = lig - 1;
            }
            if (choix == 2){
                lig = lig + 1;
            }
            if (choix == 3){
                col = col - 1;
            }
            if (choix == 4){
                col = col + 1;
            }

            //Si le tir n'est pas réussi
            if (mat[lig][col] == B) {
                // 1.1 Afficher E dans la case
                mat[lig][col] = 'O';
                gotoligcol(lig, (col * 4));
                SetConsoleTextAttribute(hConsole, 9);
                printf("%2c", 'O');
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(20, 0);
                printf("                                                   ");
                gotoligcol(20, 0);
                printf("Enemy fire in water (%c,%d)",lig + 64, col);
            }
        }
        while (mat[lig][col] == 'P' || mat[lig][col] == 'C' || mat[lig][col] == 'D' || mat[lig][col] == 'S');
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void tirer_aleatoirement_amiral(unsigned char **  mat, int compteur_tour){

    //Définitions des variables
    int i;
    int j;
    int l;
    int c;
    int z;
    int B = 95;
    int lig = 0;
    int col = 0;
    int choix;
    int compte = compteur_tour;
    int a = compte;
    int compte_bateau_touche;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    gotoligcol(28, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("AI Level : Admiral");
    gotoligcol(19, 0);
    printf("Traces of enemy fire :");
    SetConsoleTextAttribute(hConsole, 15);

    srand(time(NULL));
    z = rand() % (2) + 1;

    if (z == 1){

        gotoligcol(18, 0);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Enemy fire incoming !");
        SetConsoleTextAttribute(hConsole, 15);
        sleep(3);
        gotoligcol(18, 0);
        printf("                                  ");
        //Choix aleatoire des colonnes et lignes de tirs
        srand(time(NULL));
        lig = rand() % (15) + 1;
        col = rand() % (15) + 1;

        //Si le tir n'est pas réussi
        if (mat[lig][col] == B) {
            // 1.1 Afficher E dans la case
            mat[lig][col] = 'O';
            gotoligcol(lig, (col * 4));
            SetConsoleTextAttribute(hConsole, 9);
            printf("%2c", 'O');
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(20, 0);
            printf("                                                   ");
            gotoligcol(20, 0);
            printf("Enemy fire in water (%c,%d)",lig + 64, col);
        }
        //Sinon, un navire est touché
        if (mat[lig][col] == 'P' || mat[lig][col] == 'C' || mat[lig][col] == 'D' || mat[lig][col] == 'S'){

            //2.1 Afficher T
            do{
                mat[lig][col] = 'X';
                gotoligcol(lig, (col * 4));
                SetConsoleTextAttribute(hConsole, 12);
                printf("%2c", 'X');
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(21, 0);
                printf("                                                   ");
                gotoligcol(21, 0);
                printf("Enemy fire on ship (%c,%d)",lig + 64, col);


                choix = rand() % (4) + 1;

                if (choix == 1){
                    lig = lig - 1;
                }
                if (choix == 2){
                    lig = lig + 1;
                }
                if (choix == 3){
                    col = col - 1;
                }
                if (choix == 4){
                    col = col + 1;
                }

                //Si le tir n'est pas réussi
                if (mat[lig][col] == B) {
                    // 1.1 Afficher E dans la case
                    mat[lig][col] = 'O';
                    gotoligcol(lig, (col * 4));
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", 'O');
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(20, 0);
                    printf("                                                   ");
                    gotoligcol(20, 0);
                    printf("Enemy fire in water (%c,%d)",lig + 64, col);
                }
            }
            while (mat[lig][col] == 'P' || mat[lig][col] == 'C' || mat[lig][col] == 'D' || mat[lig][col] == 'S');
        }
    }
    if (z == 2){
        srand(time(NULL));
        gotoligcol(18, 0);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Air support enemy incoming !");
        SetConsoleTextAttribute(hConsole, 15);
        sleep(3);
        gotoligcol(18, 0);
        printf("                                  ");

        //5 tirs aérien par passage
        for (i = 0; i < 5; i ++){
            //Choix aleatoire des colonnes et lignes de tirs
            lig = rand() % (15) + 1;
            col = rand() % (15) + 1;

            //Si le tir n'est pas réussi
            if (mat[lig][col] == B) {
                // 1.1 Afficher E dans la case
                mat[lig][col] = 'O';
                gotoligcol(lig, (col * 4));
                SetConsoleTextAttribute(hConsole, 9);
                printf("%2c", 'O');
                SetConsoleTextAttribute(hConsole, 15);
            }
            //Sinon, un navire est touché
            if (mat[lig][col] == 'P' || mat[lig][col] == 'C' || mat[lig][col] == 'D' || mat[lig][col] == 'S'){
                mat[lig][col] = 'X';
                gotoligcol(lig, (col * 4));
                SetConsoleTextAttribute(hConsole, 12);
                printf("%2c", 'X');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////