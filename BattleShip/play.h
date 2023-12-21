#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void jouer(unsigned char **mat, unsigned char **mat_ia1, int *a, char *pseudo, int w, int choix, unsigned char **mat_bis, unsigned char **mat_ia1_bis)
{

    // Définition des variables
    int f;
    int g;
    int i;
    int j;
    int q;
    int x;
    int b = 0;
    int B = 95;
    int tir_air = 4;
    int satellite = 2;
    int nombre_fumigene = 4;
    int compteur_tour = 1;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoligcol(16, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("/////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("%s's grid ", pseudo);
    SetConsoleTextAttribute(hConsole, 11);
    printf("//////////////////////");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(17, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("///////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("Last shots recorded ");
    SetConsoleTextAttribute(hConsole, 11);
    printf("//////////////////////");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(44, 70);
    printf("Copyright 2023 Battleship Alassane Wade");

    while (1)
    {
        gotoligcol(16, 70);
        SetConsoleTextAttribute(hConsole, 11);
        printf("///////////////////////// ");
        SetConsoleTextAttribute(hConsole, 15);
        printf("Enemy's grid", pseudo);
        SetConsoleTextAttribute(hConsole, 11);
        printf(" /////////////////////////");
        gotoligcol(17, 70);
        fflush(stdin);
        SetConsoleTextAttribute(hConsole, 11);
        printf("///////////////////////// ");
        SetConsoleTextAttribute(hConsole, 15);
        printf("R O U N D  %d ", compteur_tour);
        SetConsoleTextAttribute(hConsole, 11);
        printf("/////////////////////////");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(19, 70);
        printf("1. Shoot");
        gotoligcol(20, 70);
        printf("2. Flare");
        gotoligcol(21, 70);
        printf("3. Satellite view");
        gotoligcol(22, 70);
        printf("4. Air support");
        gotoligcol(23, 70);
        printf("5. Save");
        gotoligcol(24, 70);
        printf("6. Main menu");
        gotoligcol(25, 70);
        printf("  ");
        gotoligcol(25, 70);
        fflush(stdin);
        scanf("%d", &g);

        // Gestions des erreurs
        while (g != 1 && g != 2 && g != 3 && g != 4 && g != 5 && g != 6)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(25, 70);
            printf("  ");
            gotoligcol(25, 70);
            fflush(stdin);
            scanf("%d", &g);
        }
        if (g == 1)
        {
            // Appel de la fonction Tirer et tirer aleatoirement pour l'IA
            tirer(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
            gotoligcol(30, 70);
            printf("                                                   ");
            gotoligcol(31, 70);
            printf("                                                   ");
            gotoligcol(32, 70);
            printf("                                                   ");
            gotoligcol(33, 70);
            printf("                                                   ");
            gotoligcol(34, 70);
            printf("                                                   ");
            if (w == 1)
            {
                tirer_aleatoirement_matelot(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
                compteur_tour++;
            }
            if (w == 2)
            {
                tirer_aleatoirement_caporal_chef(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
                compteur_tour++;
            }
            if (w == 3)
            {
                tirer_aleatoirement_amiral(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
                compteur_tour++;
            }
        }
        else if (g == 2)
        {
            // Appel de la fonction fumigene
            // Si on a plus de fumigene on en peux plus en tirer
            if (nombre_fumigene == 0)
            {
                gotoligcol(21, 140);
                printf("                                       ");
                gotoligcol(21, 140);
                printf("Total number of flares exhausted !");
                gotoligcol(25, 70);
                printf("  ");
                gotoligcol(25, 70);
                fflush(stdin);
                scanf("%d", &g);
            }
            // Si il nous reste des fumigènes on rentre dans le else
            else
            {
                nombre_fumigene--;
                fumigene(mat_ia1);
                gotoligcol(30, 70);
                printf("                                                   ");
                gotoligcol(31, 70);
                printf("                                                   ");
                gotoligcol(32, 70);
                printf("                                                   ");
                gotoligcol(33, 70);
                printf("                                                   ");
                gotoligcol(34, 70);
                printf("                                                   ");
                gotoligcol(21, 140);
                printf("                                       ");
                gotoligcol(21, 140);
                printf("Flare lit for    seconds !");
                for (int k = 6; k >= 0; k--)
                {
                    gotoligcol(21, 154);
                    printf("%2d", k);
                    if (k == 1 || k == 0)
                    {
                        gotoligcol(21, 163);
                        printf(" ");
                    }
                    sleep(1);
                }
                gotoligcol(21, 140);
                printf("                                       ");
                gotoligcol(21, 140);
                printf("Number of flare remaining: %d", nombre_fumigene);
                mode_visible_desactive(mat_ia1);
            }
            if (w == 1)
            {
                tirer_aleatoirement_matelot(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
                compteur_tour++;
            }
            if (w == 2)
            {
                tirer_aleatoirement_caporal_chef(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
                compteur_tour++;
            }
            if (w == 3)
            {
                tirer_aleatoirement_amiral(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
                compteur_tour++;
            }
        }
        while (g == 5)
        {
            sauvegarde(mat, mat_ia1, a, pseudo, w, mat_bis, mat_ia1_bis);
            gotoligcol(20, 140);
            printf("Saved game!");
            gotoligcol(25, 70);
            printf("  ");
            gotoligcol(25, 70);
            fflush(stdin);
            scanf("%d", &g);
        }
        if (g == 4)
        {
            if (tir_air == 0)
            {
                gotoligcol(21, 140);
                printf("                                       ");
                gotoligcol(21, 140);
                printf("Air support not available !");
                gotoligcol(25, 70);
                printf("  ");
                gotoligcol(25, 70);
                fflush(stdin);
                scanf("%d", &g);
            }
            else
            {
                tir_air--;
                gotoligcol(21, 140);
                printf("                                       ");
                gotoligcol(21, 140);
                printf("Aerial bombardment remaining: %d", tir_air);
                tir_aerien(mat_ia1);
                if (w == 1)
                {
                    tirer_aleatoirement_matelot(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
                    compteur_tour++;
                }
                if (w == 2)
                {
                    tirer_aleatoirement_caporal_chef(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
                    compteur_tour++;
                }
                if (w == 3)
                {
                    tirer_aleatoirement_amiral(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
                    compteur_tour++;
                }
            }
        }
        else if (g == 6)
        {
            // On retourne au menu principale
            menu(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
        }
        else if (g == 3)
        {
            if (satellite == 0)
            {
                gotoligcol(21, 140);
                printf("                                       ");
                gotoligcol(21, 140);
                printf("Satellite view not available !");
                gotoligcol(25, 70);
                printf("  ");
                gotoligcol(25, 70);
                fflush(stdin);
                scanf("%d", &g);
            }
            else
            {
                satellite--;
                mode_visible(mat_ia1);
                gotoligcol(21, 140);
                printf("                                       ");
                gotoligcol(21, 140);
                printf("Satellite view enabled for   seconds !");
                for (int k = 5; k >= 0; k--)
                {
                    gotoligcol(21, 166);
                    printf("%2d", k);
                    if (k == 1 || k == 0)
                    {
                        gotoligcol(21, 175);
                        printf(" ");
                    }
                    sleep(1);
                }
                gotoligcol(21, 140);
                printf("                                       ");
                gotoligcol(21, 140);
                printf("Satellite view remaining : %d", satellite);
                mode_visible_desactive(mat_ia1);
                if (w == 1)
                {
                    tirer_aleatoirement_matelot(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
                    compteur_tour++;
                }
                if (w == 2)
                {
                    tirer_aleatoirement_caporal_chef(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
                    compteur_tour++;
                }
                if (w == 3)
                {
                    tirer_aleatoirement_amiral(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
                    compteur_tour++;
                }
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////