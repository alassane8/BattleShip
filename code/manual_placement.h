#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void placement_bateaux(unsigned char **mat, unsigned char **mat_ia1, int *a, char *pseudo, int choix, unsigned char **mat_bis, unsigned char **mat_ia1_bis)
{

    // Définitions des variables
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
    gotoligcol(16, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("/////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("%s's grid ", pseudo);
    SetConsoleTextAttribute(hConsole, 11);
    printf("//////////////////////");
    
    gotoligcol(16, 70); 
    SetConsoleTextAttribute(hConsole, 11);
    printf("Here are the boats you can place: Aircraft Carrier, Cruiser,"); 
    gotoligcol(17, 70); 
    printf("Destroyer and Submarine.\n");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(19, 70);
    printf("- 1 Aircraft Carrier with the letter P takes up 7 spaces.\n");
    gotoligcol(20, 70);
    printf("- 2 Cruisers with the letter C take up 5 spaces.\n");
    gotoligcol(21, 70);
    printf("- 3 Destroyers with the letter D take 3 spaces.\n");
    gotoligcol(22, 70);
    printf("- 4 Submarines with the letter S take up 1 space.\n");
    gotoligcol(44, 70);
    printf("Copyright 2023 Battleship Alassane Wade");

    // Choix du bateau par l'utilisateur
    do
    {
        gotoligcol(18, 0);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Choose the position of the ");
        gotoligcol(18, 28);
        SetConsoleTextAttribute(hConsole, 15);
        printf("boat %2d/10 ", compteur_general);
        gotoligcol(18, 39);
        SetConsoleTextAttribute(hConsole, 11);
        printf(" to place:");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(19, 0);
        printf("Row:\n");
        printf("  ");
        gotoligcol(20, 0);
        fflush(stdin);
        scanf("%c", &lig);
        while ((lig - 'A' + 1 > 15 || lig - 'A' + 1 < 1))
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(20, 0);
            printf("  ");
            gotoligcol(20, 0);
            fflush(stdin);
            scanf("%c", &lig);
        }
        printf("Column:\n");
        printf("  ");
        gotoligcol(22, 0);
        fflush(stdin);
        scanf("%d", &col);
        while (col > 15 || col < 1)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(22, 0);
            printf("  ");
            gotoligcol(22, 0);
            fflush(stdin);
            scanf("%d", &col);
        }
    } while (mat[lig - 'A' + 1][col] != B);
    mat[lig - 'A' + 1][col] = 'P';

    gotoligcol(lig - 'A' + 1, col * 4);
    SetConsoleTextAttribute(hConsole, 10);
    printf("%2c", 'P');
    SetConsoleTextAttribute(hConsole, 11);
    gotoligcol(23, 0);
    printf("How would you like to place your boat n%d ?:\n", compteur_general);
    SetConsoleTextAttribute(hConsole, 15);
    printf("1. Towards the left\n");
    printf("2. Towards the right\n");
    printf("3. Upwards\n");
    printf("4. Downwards\n");
    printf("5. Menu\n");
    printf("  ");
    gotoligcol(29, 0);
    scanf("%d", &x);
    while (x != 1 && x != 2 && x != 3 && x != 4 && x != 5)
    {
        gotoligcol(25, 140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(29, 0);
        printf("  ");
        gotoligcol(29, 0);
        fflush(stdin);
        scanf("%d", &x);
    }
    while (x == 1 && col - 6 < 1)
    {
        gotoligcol(25, 140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(29, 0);
        printf("  ");
        gotoligcol(29, 0);
        fflush(stdin);
        scanf("%d", &x);
    }
    while (x == 2 && col + 6 > 15)
    {
        gotoligcol(25, 140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(29, 0);
        printf("  ");
        gotoligcol(29, 0);
        fflush(stdin);
        scanf("%d", &x);
    }
    for (z = 1; z < 7; z++)
    {
        while ((x == 1 && mat[lig - 'A' + 1][col - z] != B) || (x == 2 && mat[lig - 'A' + 1][col + z] != B))
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(29, 0);
            printf("  ");
            gotoligcol(29, 0);
            fflush(stdin);
            scanf("%d", &x);
        }
    }
    while (x == 3 && lig - 'A' + 1 - 6 < 1)
    {
        gotoligcol(25, 140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(29, 0);
        printf("  ");
        gotoligcol(29, 0);
        fflush(stdin);
        scanf("%d", &x);
    }
    while (x == 4 && lig - 'A' + 1 + 6 > 15)
    {
        gotoligcol(25, 140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(29, 0);
        printf("  ");
        gotoligcol(29, 0);
        fflush(stdin);
        scanf("%d", &x);
    }
    for (z = 1; z < 7; z++)
    {
        while ((x == 3 && mat[lig - 'A' + 1 - z][col] != B) || (x == 4 && mat[lig - 'A' + 1 + z][col] != B))
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(29, 0);
            printf("  ");
            gotoligcol(29, 0);
            fflush(stdin);
            scanf("%d", &x);
        }
    }
    if (x == 5)
    {
        menu(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
    }

    // Si vers la gauche
    if (x == 1 && col - 6 >= 1)
    {
        for (z = 1; z < 7; z++)
        {
            mat[lig - 'A' + 1][col - z] = 'P';
            gotoligcol(lig - 'A' + 1, ((col - z) * 4));
            SetConsoleTextAttribute(hConsole, 10);
            printf("%2c", 'P');
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
    // Si vers la droite
    if (x == 2 && col + 6 <= 15)
    {
        for (z = 1; z < 7; z++)
        {
            mat[lig - 'A' + 1][col + z] = 'P';
            gotoligcol(lig - 'A' + 1, ((col + z) * 4));
            SetConsoleTextAttribute(hConsole, 10);
            printf("%2c", 'P');
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
    // Si vers le haut
    if (x == 3 && lig - 'A' + 1 - 6 >= 1)
    {
        for (z = 1; z < 7; z++)
        {
            mat[lig - 'A' + 1 - z][col] = 'P';
            gotoligcol(lig - 'A' + 1 - z, col * 4);
            SetConsoleTextAttribute(hConsole, 10);
            printf("%2c", 'P');
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
    // Si vers le bas
    if (x == 4 && lig - 'A' + 1 + 6 <= 15)
    {
        for (z = 1; z < 7; z++)
        {
            mat[lig - 'A' + 1 + z][col] = 'P';
            gotoligcol(lig - 'A' + 1 + z, col * 4);
            SetConsoleTextAttribute(hConsole, 10);
            printf("%2c", 'P');
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
    // On augmente de 1 les valeurs de P et du nombre de bateaux posés
    P++;
    compteur_general++;
    gotoligcol(18, 34);
    printf("%d", compteur_general);

    while (C < 2)
    {
        do
        {
            gotoligcol(19, 0);
            printf("Row:\n");
            printf("  ");
            gotoligcol(20, 0);
            fflush(stdin);
            scanf("%c", &lig);
            while (lig - 'A' + 1 > 15 || lig - 'A' + 1 < 1)
            {
                gotoligcol(25, 140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(20, 0);
                printf("  ");
                gotoligcol(20, 0);
                fflush(stdin);
                scanf("%c", &lig);
            }
            printf("Column:\n");
            printf("  ");
            gotoligcol(22, 0);
            fflush(stdin);
            scanf("%d", &col);
            while (col > 15 || col < 1)
            {
                gotoligcol(25, 140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(22, 0);
                printf("  ");
                gotoligcol(22, 0);
                fflush(stdin);
                scanf("%d", &col);
            }
        } while (mat[lig - 'A' + 1][col] != B);
        mat[lig - 'A' + 1][col] = 'C';

        gotoligcol(lig - 'A' + 1, col * 4);
        SetConsoleTextAttribute(hConsole, 10);
        printf("%2c", 'C');
        SetConsoleTextAttribute(hConsole, 11);
        gotoligcol(23, 0);
        printf("How would you like to place your boat n%d ?:\n", compteur_general);
        SetConsoleTextAttribute(hConsole, 15);
        printf("1. Towards the left\n");
        printf("2. Towards the right\n");
        printf("3. Upwards\n");
        printf("4. Downwards\n");
        printf("5. Menu\n");
        printf("  ");
        gotoligcol(29, 0);
        scanf("%d", &x);
        while (x != 1 && x != 2 && x != 3 && x != 4 && x != 5)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(29, 0);
            printf("  ");
            gotoligcol(29, 0);
            fflush(stdin);
            scanf("%d", &x);
        }
        while (x == 1 && col - 4 < 1)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(29, 0);
            printf("  ");
            gotoligcol(29, 0);
            fflush(stdin);
            scanf("%d", &x);
        }
        while (x == 2 && col + 4 > 15)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(29, 0);
            printf("  ");
            gotoligcol(29, 0);
            fflush(stdin);
            scanf("%d", &x);
        }
        for (z = 1; z < 5; z++)
        {
            while ((x == 1 && mat[lig - 'A' + 1][col - z] != B) || (x == 2 && mat[lig - 'A' + 1][col + z] != B))
            {
                gotoligcol(25, 140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(29, 0);
                printf("  ");
                gotoligcol(29, 0);
                fflush(stdin);
                scanf("%d", &x);
            }
        }
        while (x == 3 && lig - 'A' + 1 - 4 < 1)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(29, 0);
            printf("  ");
            gotoligcol(29, 0);
            fflush(stdin);
            scanf("%d", &x);
        }
        while (x == 4 && lig - 'A' + 1 + 4 > 15)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(29, 0);
            printf("  ");
            gotoligcol(29, 0);
            fflush(stdin);
            scanf("%d", &x);
        }
        for (z = 1; z < 5; z++)
        {
            while ((x == 3 && mat[lig - 'A' + 1 - z][col] != B) || (x == 4 && mat[lig - 'A' + 1 + z][col] != B))
            {
                gotoligcol(25, 140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(29, 0);
                printf("  ");
                gotoligcol(29, 0);
                fflush(stdin);
                scanf("%d", &x);
            }
        }
        if (x == 5)
        {
            menu(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
        }
        // Si vers la gauche
        if (x == 1 && col - 4 >= 1)
        {
            for (z = 1; z < 5; z++)
            {
                mat[lig - 'A' + 1][col - z] = 'C';
                gotoligcol(lig - 'A' + 1, ((col - z) * 4));
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'C');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        // Si vers la droite
        if (x == 2 && col + 4 <= 15)
        {
            for (z = 1; z < 5; z++)
            {
                mat[lig - 'A' + 1][col + z] = 'C';
                gotoligcol(lig - 'A' + 1, ((col + z) * 4));
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'C');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        // Si vers le haut
        if (x == 3 && lig - 'A' + 1 - 4 >= 1)
        {
            for (z = 1; z < 5; z++)
            {
                mat[lig - 'A' + 1 - z][col] = 'C';
                gotoligcol(lig - 'A' + 1 - z, col * 4);
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'C');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        // Si vers le bas
        if (x == 4 && lig - 'A' + 1 + 4 <= 15)
        {
            for (z = 1; z < 5; z++)
            {
                mat[lig - 'A' + 1 + z][col] = 'C';
                gotoligcol(lig - 'A' + 1 + z, col * 4);
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'C');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        // On augmente de 1 les valeurs de C et du nombre de bateaux posés
        C++;
        compteur_general++;
        gotoligcol(18, 34);
        printf("%d", compteur_general);
    }
    while (D < 3)
    {
        do
        {
            gotoligcol(19, 0);
            printf("Row:\n");
            printf("  ");
            gotoligcol(20, 0);
            fflush(stdin);
            scanf("%c", &lig);
            while (lig - 'A' + 1 > 15 || lig - 'A' + 1 < 1)
            {
                gotoligcol(25, 140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(20, 0);
                printf("  ");
                gotoligcol(20, 0);
                fflush(stdin);
                scanf("%c", &lig);
            }
            printf("Column:\n");
            printf("  ");
            gotoligcol(22, 0);
            fflush(stdin);
            scanf("%d", &col);
            while (col > 15 || col < 1)
            {
                gotoligcol(25, 140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(22, 0);
                printf("  ");
                gotoligcol(22, 0);
                fflush(stdin);
                scanf("%d", &col);
            }
        } while (mat[lig - 'A' + 1][col] != B);
        mat[lig - 'A' + 1][col] = 'D';

        gotoligcol(lig - 'A' + 1, col * 4);
        SetConsoleTextAttribute(hConsole, 10);
        printf("%2c", 'D');
        SetConsoleTextAttribute(hConsole, 11);
        gotoligcol(23, 0);
        printf("How would you like to place your boat n%d ?:\n", compteur_general);
        SetConsoleTextAttribute(hConsole, 15);
        printf("1. Towards the left\n");
        printf("2. Towards the right\n");
        printf("3. Upwards\n");
        printf("4. Downwards\n");
        printf("5. Menu\n");
        printf("  ");
        gotoligcol(29, 0);
        scanf("%d", &x);
        while (x != 1 && x != 2 && x != 3 && x != 4 && x != 5)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(29, 0);
            printf("  ");
            gotoligcol(29, 0);
            fflush(stdin);
            scanf("%d", &x);
        }
        while (x == 1 && col - 2 < 1)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(29, 0);
            printf("  ");
            gotoligcol(29, 0);
            fflush(stdin);
            scanf("%d", &x);
        }
        while (x == 2 && col + 2 > 15)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(29, 0);
            printf("  ");
            gotoligcol(29, 0);
            fflush(stdin);
            scanf("%d", &x);
        }
        for (z = 1; z < 3; z++)
        {
            while ((x == 1 && mat[lig - 'A' + 1][col - z] != B) || (x == 2 && mat[lig - 'A' + 1][col + z] != B))
            {
                gotoligcol(25, 140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(29, 0);
                printf("  ");
                gotoligcol(29, 0);
                fflush(stdin);
                scanf("%d", &x);
            }
        }
        while (x == 3 && lig - 'A' + 1 - 2 < 1)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(29, 0);
            printf("  ");
            gotoligcol(29, 0);
            fflush(stdin);
            scanf("%d", &x);
        }
        while (x == 4 && lig - 'A' + 1 + 2 > 15)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(29, 0);
            printf("  ");
            gotoligcol(29, 0);
            fflush(stdin);
            scanf("%d", &x);
        }
        for (z = 1; z < 3; z++)
        {
            while ((x == 3 && mat[lig - 'A' + 1 - z][col] != B) || (x == 4 && mat[lig - 'A' + 1 + z][col] != B))
            {
                gotoligcol(25, 140);
                SetConsoleTextAttribute(hConsole, 12);
                printf("Error.");
                SetConsoleTextAttribute(hConsole, 15);
                gotoligcol(29, 0);
                printf("  ");
                gotoligcol(29, 0);
                fflush(stdin);
                scanf("%d", &x);
            }
        }
        if (x == 5)
        {
            menu(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
        }
        // Si vers la gauche
        if (x == 1 && col - 2 >= 1)
        {
            for (z = 1; z < 3; z++)
            {
                mat[lig - 'A' + 1][col - z] = 'D';
                gotoligcol(lig - 'A' + 1, ((col - z) * 4));
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'D');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        // Si vers la droite
        if (x == 2 && col + 2 <= 15)
        {
            for (z = 1; z < 3; z++)
            {
                mat[lig - 'A' + 1][col + z] = 'D';
                gotoligcol(lig - 'A' + 1, ((col + z) * 4));
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'D');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        // Si vers le haut
        if (x == 3 && lig - 'A' + 1 - 2 >= 1)
        {
            for (z = 1; z < 3; z++)
            {
                mat[lig - 'A' + 1 - z][col] = 'D';
                gotoligcol(lig - 'A' + 1 - z, col * 4);
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'D');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        // Si vers le bas
        if (x == 4 && lig - 'A' + 1 + 2 <= 15)
        {
            for (z = 1; z < 3; z++)
            {
                mat[lig - 'A' + 1 + z][col] = 'D';
                gotoligcol(lig - 'A' + 1 + z, col * 4);
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'D');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        // On augmente de 1 les valeurs de C et du nombre de bateaux posés
        D++;
        compteur_general++;
        gotoligcol(18, 34);
        printf("%d", compteur_general);
    }

    while (S < 4)
    {
        for (k = 0; k < 1; k++)
        {
            do
            {
                gotoligcol(19, 0);
                printf("Row:\n");
                printf("  ");
                gotoligcol(20, 0);
                fflush(stdin);
                scanf("%c", &lig);
                while (lig - 'A' + 1 > 15 || lig - 'A' + 1 < 1)
                {
                    gotoligcol(25, 140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(20, 0);
                    printf("  ");
                    gotoligcol(20, 0);
                    fflush(stdin);
                    scanf("%c", &lig);
                }
                printf("Column:\n");
                printf("  ");
                gotoligcol(22, 0);
                fflush(stdin);
                scanf("%d", &col);
                while (col > 15 || col < 1)
                {
                    gotoligcol(25, 140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(22, 0);
                    printf("  ");
                    gotoligcol(22, 0);
                    fflush(stdin);
                    scanf("%d", &col);
                }
            } while (mat[lig - 'A' + 1][col] != B);
            mat[lig - 'A' + 1][col] = 'S';
            gotoligcol(lig - 'A' + 1, col * 4);
            SetConsoleTextAttribute(hConsole, 10);
            printf("%2c", 'S');
            SetConsoleTextAttribute(hConsole, 15);
        }
        S++;
        compteur_general++;
        gotoligcol(18, 34);
        printf("%d", compteur_general);
    }

    for (int delete = 0; delete < 20; delete ++)
    {
        gotoligcol(16 + delete, 0);
        printf("                                                                                       ");
        gotoligcol(16 + delete, 70);
        printf("                                                                                       ");
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////