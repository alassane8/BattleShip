#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tirer(unsigned char **mat, unsigned char **mat_ia1, int *a, char *pseudo, int choix, unsigned char **mat_bis, unsigned char **mat_ia1_bis)
{

    // Variables definitions
    int col = 0;
    char lig = 0;
    int B = 95;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoligcol(22, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Traces of shots from %s:", pseudo);
    SetConsoleTextAttribute(hConsole, 15);

    gotoligcol(30, 70);
    printf("                                                   ");
    gotoligcol(30, 70);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Where would you like to shoot ?\n");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(31, 70);
    printf("Row :\n");
    gotoligcol(32, 70);
    printf("  ");
    gotoligcol(32, 70);
    fflush(stdin);
    scanf("%c", &lig);

    while (lig - 'a' + 1 > 15 || lig - 'a' + 1 < 1)
    {
        gotoligcol(25, 140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(32, 70);
        printf("  ");
        gotoligcol(32, 70);
        fflush(stdin);
        scanf("%c", &lig);
    }
    gotoligcol(33, 70);
    printf("Column :\n");
    gotoligcol(34, 70);
    printf("  ");
    gotoligcol(34, 70);
    fflush(stdin);
    scanf("%d", &col);

    while (col > 15 || col < 1)
    {
        gotoligcol(25, 140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(34, 70);
        printf("  ");
        gotoligcol(34, 70);
        fflush(stdin);
        scanf("%d", &col);
    }

    // Failed shot
    if (mat_ia1[lig - 'a' + 1][col] == B)
    {
        mat_ia1[lig - 'a' + 1][col] = 'O';
        gotoligcol(lig - 'a' + 1, (col * 4) + 70);
        SetConsoleTextAttribute(hConsole, 9);
        printf("%2c", 'O');
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(23, 0);
        printf("                                                   ");
        gotoligcol(23, 0);
        printf("%s fires in water (%c,%d)", pseudo, lig, col);
    }

    // Success shot
    if (mat_ia1[lig - 'a' + 1][col] == 'P' || mat_ia1[lig - 'a' + 1][col] == 'C' || mat_ia1[lig - 'a' + 1][col] == 'D' || mat_ia1[lig - 'a' + 1][col] == 'S')
    {
        do
        {
            mat_ia1[lig - 'a' + 1][col] = 'X';
            gotoligcol(lig - 'a' + 1, (col * 4) + 70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("%2c", 'X');
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(24, 0);
            printf("                                                   ");
            gotoligcol(24, 0);
            printf("%s fires on ship (%c,%d)", pseudo, lig, col);

            if (game_over(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis))
            {
                vainqueur_joueur(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
            }
            gotoligcol(31, 70);
            printf("Row :\n");
            gotoligcol(32, 70);
            printf("  ");
            gotoligcol(32, 70);
            fflush(stdin);
            scanf("%c", &lig);

            while (lig - 'a' + 1 > 15 || lig - 'a' + 1 < 1)
            {
                gotoligcol(25, 140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(32, 70);
                printf("  ");
                gotoligcol(32, 70);
                fflush(stdin);
                scanf("%c", &lig);
            }
            gotoligcol(33, 70);
            printf("Column :\n");
            gotoligcol(34, 70);
            printf("  ");
            gotoligcol(34, 70);
            fflush(stdin);
            scanf("%d", &col);

            while (col > 15 || col < 1)
            {
                gotoligcol(25, 140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(34, 70);
                printf("  ");
                gotoligcol(34, 70);
                fflush(stdin);
                scanf("%d", &col);
            }
            // Failed shot
            if (mat_ia1[lig - 'a' + 1][col] == B)
            {
                mat_ia1[lig - 'a' + 1][col] = 'O';
                gotoligcol(lig - 'a' + 1, (col * 4) + 70);
                SetConsoleTextAttribute(hConsole, 9);
                printf("%2c", 'O');
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(23, 0);
                printf("                                                   ");
                gotoligcol(23, 0);
                printf("%s fires in water (%c,%d)", pseudo, lig, col);
            }
        } while (mat_ia1[lig - 'a' + 1][col] == 'P' || mat_ia1[lig - 'a' + 1][col] == 'C' || mat_ia1[lig - 'a' + 1][col] == 'D' || mat_ia1[lig - 'a' + 1][col] == 'S');
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tirer_aleatoirement_matelot(unsigned char **mat, unsigned char **mat_ia1, int *a, char *pseudo, int choix, unsigned char **mat_bis, unsigned char **mat_ia1_bis)
{

    // Variables definition
    int i;
    int j;
    int B = 95;
    int lig = 0;
    int col = 0;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoligcol(28, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Enemy's Level: ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("Private");
    gotoligcol(19, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Traces of enemy's fire:");
    SetConsoleTextAttribute(hConsole, 15);

    gotoligcol(18, 0);
    SetConsoleTextAttribute(hConsole, 12);
    printf("Enemy's fire incoming !");
    SetConsoleTextAttribute(hConsole, 15);
    sleep(3);
    gotoligcol(18, 0);
    printf("                                  ");

    // Choose random coordonate
    srand(time(NULL));
    lig = rand() % (15) + 1;
    col = rand() % (15) + 1;

    // Failed shot
    if (mat[lig][col] == B)
    {
        mat[lig][col] = 'O';
        gotoligcol(lig, (col * 4));
        SetConsoleTextAttribute(hConsole, 9);
        printf("%2c", 'O');
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(20, 0);
        printf("                                                   ");
        gotoligcol(20, 0);
        printf("Enemy fires in water (%c,%d)", lig + 64, col);
    }
    // Success shot
    if (mat[lig][col] == 'P' || mat[lig][col] == 'C' || mat[lig][col] == 'D' || mat[lig][col] == 'S')
    {

        do
        {
            mat[lig][col] = 'X';
            gotoligcol(lig, (col * 4));
            SetConsoleTextAttribute(hConsole, 12);
            printf("%2c", 'X');
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(21, 0);
            printf("                                                   ");
            gotoligcol(21, 0);
            printf("Enemy fires on ship (%c,%d)", lig + 64, col);
            if (game_over_ia(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis))
            {
                vainqueur_ia(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
            }

            // 2nd shot
            srand(time(NULL));
            lig = rand() % (15) + 1;
            col = rand() % (15) + 1;

            if (mat[lig][col] == B)
            {
                mat[lig][col] = 'O';
                gotoligcol(lig, (col * 4));
                SetConsoleTextAttribute(hConsole, 9);
                printf("%2c", 'O');
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(20, 0);
                printf("                                                   ");
                gotoligcol(20, 0);
                printf("Enemy fires in water (%c,%d)", lig + 64, col);
            }
        } while (mat[lig][col] == 'P' || mat[lig][col] == 'C' || mat[lig][col] == 'D' || mat[lig][col] == 'S');
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void tirer_aleatoirement_caporal_chef(unsigned char **mat, unsigned char **mat_ia1, int *a, char *pseudo, int choix, unsigned char **mat_bis, unsigned char **mat_ia1_bis)
{

    // Variables definition
    int i;
    int j;
    int l;
    int c;
    int B = 95;
    int lig = 0;
    int col = 0;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoligcol(28, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Enemy's Level: ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("Lieutenant");
    gotoligcol(19, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Traces of enemy's fire:");
    SetConsoleTextAttribute(hConsole, 15);

    gotoligcol(18, 0);
    SetConsoleTextAttribute(hConsole, 12);
    printf("Enemy's fire incoming !");
    SetConsoleTextAttribute(hConsole, 15);
    sleep(3);
    gotoligcol(18, 0);
    printf("                                  ");

    srand(time(NULL));
    lig = rand() % (15) + 1;
    col = rand() % (15) + 1;

    if (mat[lig][col] == B)
    {

        mat[lig][col] = 'O';
        gotoligcol(lig, (col * 4));
        SetConsoleTextAttribute(hConsole, 9);
        printf("%2c", 'O');
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(20, 0);
        printf("                                                   ");
        gotoligcol(20, 0);
        printf("Enemy fires in water (%c,%d)", lig + 64, col);
    }

    if (mat[lig][col] == 'P' || mat[lig][col] == 'C' || mat[lig][col] == 'D' || mat[lig][col] == 'S')
    {
        do
        {
            mat[lig][col] = 'X';
            gotoligcol(lig, (col * 4));
            SetConsoleTextAttribute(hConsole, 12);
            printf("%2c", 'X');
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(21, 0);
            printf("                                                   ");
            gotoligcol(21, 0);
            printf("Enemy fires on ship  (%c,%d)", lig + 64, col);
            if (game_over_ia(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis))
            {
                vainqueur_ia(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
            }

            choix = rand() % (4) + 1;

            if (choix == 1)
            {
                lig = lig - 1;
            }
            if (choix == 2)
            {
                lig = lig + 1;
            }
            if (choix == 3)
            {
                col = col - 1;
            }
            if (choix == 4)
            {
                col = col + 1;
            }
            if (mat[lig][col] == B)
            {
                // 1.1 Afficher E dans la case
                mat[lig][col] = 'O';
                gotoligcol(lig, (col * 4));
                SetConsoleTextAttribute(hConsole, 9);
                printf("%2c", 'O');
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(20, 0);
                printf("                                                   ");
                gotoligcol(20, 0);
                printf("Enemy fires in water (%c,%d)", lig + 64, col);
            }
        } while (mat[lig][col] == 'P' || mat[lig][col] == 'C' || mat[lig][col] == 'D' || mat[lig][col] == 'S');
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void tirer_aleatoirement_amiral(unsigned char **mat, unsigned char **mat_ia1, int *a, char *pseudo, int choix, unsigned char **mat_bis, unsigned char **mat_ia1_bis)
{

    // Variables definition
    int i;
    int j;
    int l;
    int c;
    int z;
    int B = 95;
    int lig = 0;
    int col = 0;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoligcol(28, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Enemy's Level: ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("Admiral");
    gotoligcol(19, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Traces of enemy's fire:");
    SetConsoleTextAttribute(hConsole, 15);

    srand(time(NULL));
    z = rand() % (2) + 1;

    if (z == 1)
    {
        gotoligcol(18, 0);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Enemy's shot incoming !");
        SetConsoleTextAttribute(hConsole, 15);
        sleep(3);
        gotoligcol(18, 0);
        printf("                                  ");
        srand(time(NULL));
        lig = rand() % (15) + 1;
        col = rand() % (15) + 1;

        if (mat[lig][col] == B)
        {
            mat[lig][col] = 'O';
            gotoligcol(lig, (col * 4));
            SetConsoleTextAttribute(hConsole, 9);
            printf("%2c", 'O');
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(20, 0);
            printf("                                                   ");
            gotoligcol(20, 0);
            printf("Enemy fires in water (%c,%d)", lig + 64, col);
        }
        if (mat[lig][col] == 'P' || mat[lig][col] == 'C' || mat[lig][col] == 'D' || mat[lig][col] == 'S')
        {
            do
            {
                mat[lig][col] = 'X';
                gotoligcol(lig, (col * 4));
                SetConsoleTextAttribute(hConsole, 12);
                printf("%2c", 'X');
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(21, 0);
                printf("                                                   ");
                gotoligcol(21, 0);
                printf("Enemy fires on ship (%c,%d)", lig + 64, col);
                if (game_over_ia(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis))
                {
                    vainqueur_ia(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
                }
                choix = rand() % (4) + 1;

                if (choix == 1)
                {
                    lig = lig - 1;
                }
                if (choix == 2)
                {
                    lig = lig + 1;
                }
                if (choix == 3)
                {
                    col = col - 1;
                }
                if (choix == 4)
                {
                    col = col + 1;
                }

                if (mat[lig][col] == B)
                {
                    mat[lig][col] = 'O';
                    gotoligcol(lig, (col * 4));
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", 'O');
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(20, 0);
                    printf("                                                   ");
                    gotoligcol(20, 0);
                    printf("Enemy fires in water (%c,%d)", lig + 64, col);
                }

            } while (mat[lig][col] == 'P' || mat[lig][col] == 'C' || mat[lig][col] == 'D' || mat[lig][col] == 'S');
        }
    }
    if (z == 2)
    {
        srand(time(NULL));
        gotoligcol(18, 0);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Enemy's air support incoming !");
        SetConsoleTextAttribute(hConsole, 15);
        sleep(3);
        gotoligcol(18, 0);
        printf("                                  ");

        for (i = 0; i < 5; i++)
        {

            lig = rand() % (15) + 1;
            col = rand() % (15) + 1;

            if (mat[lig][col] == B)
            {
                mat[lig][col] = 'O';
                gotoligcol(lig, (col * 4));
                SetConsoleTextAttribute(hConsole, 9);
                printf("%2c", 'O');
                SetConsoleTextAttribute(hConsole, 15);
            }
            if (mat[lig][col] == 'P' || mat[lig][col] == 'C' || mat[lig][col] == 'D' || mat[lig][col] == 'S')
            {
                mat[lig][col] = 'X';
                gotoligcol(lig, (col * 4));
                SetConsoleTextAttribute(hConsole, 12);
                printf("%2c", 'X');
                SetConsoleTextAttribute(hConsole, 15);
                if (game_over_ia(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis))
                {
                    vainqueur_ia(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
                }
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////