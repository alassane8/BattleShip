#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu(unsigned char **mat, unsigned char **mat_ia1, int *a, char *pseudo, int choix, unsigned char **mat_bis, unsigned char **mat_ia1_bis)
{

    // DDV
    int k;
    int x;
    int niveauIA;
    int choice_placement;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Acceuil du joueur 1
    system("cls");
    gotoligcol(0, 30);
    SetConsoleTextAttribute(hConsole, 11);
    printf("/////////////////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("B A T T L E S H I P");
    SetConsoleTextAttribute(hConsole, 11);
    printf(" ///////////////////////////////////////\n");
    gotoligcol(8, 30);
    SetConsoleTextAttribute(hConsole, 11);
    printf("/////////////////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("M A I N  M E N U");
    SetConsoleTextAttribute(hConsole, 11);
    printf(" ////////////////////////////////////////");
    SetConsoleTextAttribute(hConsole, 15);

    gotoligcol(44, 70);
    printf("Copyright 2023 Battleship Alassane Wade");

    boat_decoration_menu();

    gotoligcol(10, 70);
    printf("1. P1 VS AI");
    gotoligcol(11, 70);
    printf("2. Load game");
    gotoligcol(12, 70);
    printf("3. Rules");
    gotoligcol(13, 70);
    printf("4. Exit ");
    gotoligcol(14, 70);
    fflush(stdin);
    scanf("%d", &*a);

    // Erreur de saisie
    while (*a != 1 && *a != 2 && *a != 3 && *a != 4)
    {
        gotoligcol(25, 140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(14, 70);
        printf("  ");
        gotoligcol(14, 70);
        fflush(stdin);
        scanf("%d", &*a);
    }
    // Jouer contre IA
    if (*a == 1)
    {
        // Choix du niveau de l'ia
        gotoligcol(15, 70);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Choose AI level:");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(16, 70);
        printf("1. Private");
        gotoligcol(17, 70);
        printf("2. Lieutenant");
        gotoligcol(18, 70);
        printf("3. Admiral");
        gotoligcol(19, 70);
        fflush(stdin);
        scanf("%d", &niveauIA);

        while (niveauIA != 1 && niveauIA != 2 && niveauIA != 3)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(19, 70);
            printf("  ");
            gotoligcol(23, 70);
            fflush(stdin);
            scanf("%d", &niveauIA);
        }

        gotoligcol(20, 70);
        SetConsoleTextAttribute(hConsole, 11);
        printf("How do you want to place your boats ?");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(21, 70);
        printf("1. Manually");
        gotoligcol(22, 70);
        printf("2. Randomly");
        gotoligcol(23, 70);
        fflush(stdin);
        scanf("%d", &choice_placement);

        while (choice_placement != 1 && choice_placement != 2)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(23, 70);
            printf("  ");
            gotoligcol(23, 70);
            fflush(stdin);
            scanf("%d", &choice_placement);
        }
        if (choice_placement == 1)
        {
            // On efface la page
            system("cls");

            // Affichage des matrices de décors
            decors();
            decors1();

            // Initialisation de la matrice 1
            initialisation_matrice(mat, mat_ia1);

            // Placement aléatoire des bateaux
            placement_bateaux(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
            placement_bateaux_aleatoire1(mat_ia1);
            
            boat_decoration_load();

            // Appel de la fonction de jeux
            jouer(mat, mat_ia1, a, pseudo, niveauIA, choix, mat_bis, mat_ia1_bis);
        }
        else if (choice_placement == 2)
        {
            // On efface la page
            system("cls");

            // Affichage des matrices de décors
            decors();
            decors1();

            // Initialisation de la matrice 1
            initialisation_matrice(mat, mat_ia1);

            // Placement aléatoire des bateaux
            placement_bateaux_aleatoire(mat);
            placement_bateaux_aleatoire1(mat_ia1);

            boat_decoration_load();

            // Appel de la fonction de jeux
            jouer(mat, mat_ia1, a, pseudo, niveauIA, choix, mat_bis, mat_ia1_bis);
        }
    }
    // Chargement d'une partie
    else if (*a == 2)
    {

        // Choix de la partie que le joueur peut charger
        choix_chargement_partie(mat, mat_ia1, a, pseudo, niveauIA, choix, mat_bis, mat_ia1_bis);
        boat_decoration_load();
        // Appel de la fonction jouer
        jouer(mat, mat_ia1, a, pseudo, niveauIA, choix, mat_bis, mat_ia1_bis);
    }
    // Règles du jeu
    else if (*a == 3)
    {
        system("cls");
        rules(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
    }

    // Quitter
    else if (*a == 4)
    {
        system("cls");
        gotoligcol(4, 45);
        SetConsoleTextAttribute(hConsole, 11);
        printf("///////////////////////////// ");
        SetConsoleTextAttribute(hConsole, 15);
        printf("T H A N K  Y O U !");
        SetConsoleTextAttribute(hConsole, 11);
        printf(" /////////////////////////////");
        gotoligcol(6, 65);
        SetConsoleTextAttribute(hConsole, 15);
        printf("We hope to see you soon %s !", pseudo);

        boats_decoration_exit();

        gotoligcol(44, 70);
        printf("Copyright 2023 Battleship Alassane Wade"); // On libère l'espace occupé par les matrices
        free(mat_ia1);
        free(mat);
        free(mat_ia1_bis);
        free(mat_bis);
        sleep(4);
        system("cls");
        exit(0);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////