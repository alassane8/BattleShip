#include "prototypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu(unsigned char ** mat,unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){

    //DDV
    int k;
    int x;
    int w;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //Acceuil du joueur 1
    gotoligcol(8, 30);
    SetConsoleTextAttribute(hConsole, 11);
    printf("/////////////////////////////////////// M A I N  M E N U ////////////////////////////////////////");
    SetConsoleTextAttribute(hConsole, 15);


    gotoligcol(44, 95);
    printf("Copyright 2023 Battleship Alassane Wade");
    SetConsoleTextAttribute(hConsole, 11);
    gotoligcol(9, 140);
    printf("           ,_:_,\n");
    gotoligcol(10, 140);
    printf("             |\n");
    gotoligcol(11, 140);
    printf("         -*T_##_:-\n");
    gotoligcol(12, 140);
    printf("        i____||____i\n");
    gotoligcol(13, 140);
    printf("       #|==========|@\n");
    gotoligcol(14, 140);
    printf("       -|==========|-\n");
    gotoligcol(15, 140);
    printf("        |          |\n");
    gotoligcol(16, 140);
    printf("        |_        _|\n");
    gotoligcol(17, 140);
    printf("        |          |\n");
    gotoligcol(18, 140);
    printf("     ______________________________________________________________\n");
    gotoligcol(19, 140);
    printf("    |___  __   |________________  USS WADE _____________|   __  ___|\n");
    gotoligcol(20, 140);
    printf("        l        '-,               -   -             ,-'        /\n");
    gotoligcol(21, 140);
    printf("          l         l        l      ___       /      /         /\n");
    gotoligcol(22, 140);
    printf("            l     (l  l       l____     ____/       /  /)     /\n");
    gotoligcol(23, 140);
    printf("              |    V   |           l---/           |   V     |\n");
    gotoligcol(24, 140);
    printf("              |        |             Y             |         |\n");
    SetConsoleTextAttribute(hConsole, 15);

    gotoligcol(10, 70);
    printf("1. P1 VS AI");
    gotoligcol(11,70);
    printf("2. Load game");
    gotoligcol(12, 70);
    printf("3. Rules");
    gotoligcol(13, 70);
    printf("4. Exit ");
    gotoligcol(14, 70);
    fflush(stdin);
    scanf("%d", &*a);

    //Erreur de saisie
    while (*a != 1 && *a != 2 && *a != 3 && *a != 4) {
        gotoligcol(25,140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(14, 70);
        fflush(stdin);
        scanf("%d", &*a);
    }
    //Jouer contre IA
    if (*a == 1) {
        //Choix du niveau de l'ia
        gotoligcol(15, 70);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Choose AI level :");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(16, 70);
        printf("1. Sailor");
        gotoligcol(17, 70);
        printf("2. Master Corporal");
        gotoligcol(18, 70);
        printf("3. Admiral");
        gotoligcol(19, 70);
        fflush(stdin);
        scanf("%d",&w);

        while (w != 1 && w != 2 && w != 3) {
            gotoligcol(25,140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(19, 70);
            fflush(stdin);
            scanf("%d", &w);
        }

        gotoligcol(20, 70);
        SetConsoleTextAttribute(hConsole, 11);
        printf("How would you like to place your boats ?");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(21, 70);
        printf("1. Randomly");
        gotoligcol(22, 70);
        printf("2. Manually");
        gotoligcol(23, 70);
        fflush(stdin);
        scanf("%d", &k);

        while (k != 1 && k != 2) {
            gotoligcol(25,140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(23, 70);
            fflush(stdin);
            scanf("%d", &k);
        }

        if (k == 2) {
            //On efface la page
            system("cls");

            //Affichage des deux matrices
            decors();
            decors1();

            //Initialisation de la matrice 1
            initialisation_matrice(mat,  mat_ia1);

            //Sélectionner l'emplacement des bateaux
            placement_bateaux(mat, mat_ia1, a, pseudo);
            placement_bateaux_aleatoire1(mat_ia1);

            SetConsoleTextAttribute(hConsole, 11);
            gotoligcol(28, 140);
            printf("                                 __..||..__\n");
            gotoligcol(29, 140);
            printf("                             -==|__.----.__|==-\n");
            gotoligcol(30, 140);
            printf("                                 __l|  |/__\n");
            gotoligcol(31, 140);
            printf("                            --==|__.----.__|==--\n");
            gotoligcol(32, 140);
            printf("                                __/       l__\n");
            gotoligcol(33, 140);
            printf("                            __'{             }'__\n");
            gotoligcol(34, 140);
            printf("                       ___'{  ! 8     8     8 !  }'___\n");
            gotoligcol(35, 140);
            printf("                 ====={                               }=====\n");
            gotoligcol(36, 140);
            printf("                _____________________________________________\n");
            gotoligcol(37, 140);
            printf("               |             /   .  -- . --  .  l            |\n");
            gotoligcol(38, 140);
            printf("               | '--_______/    +      !      +   l______--' |\n");
            gotoligcol(39, 140);
            printf("               |                !             !              |\n");
            gotoligcol(40, 140);
            printf("               |                                             |\n");
            gotoligcol(41, 140);
            printf("                 l                     |                     /");
            gotoligcol(42, 140);
            printf("                  l_                   |                  _/");
            gotoligcol(43, 140);
            printf("                     l_                |               _/");
            gotoligcol(44, 140);
            printf("                        l_             |            _/");
            gotoligcol(45, 140);
            printf("                           l_          |         _/");
            SetConsoleTextAttribute(hConsole, 15);

            //Appel de la fonction de jeux
            jouer(mat, mat_ia1, a, pseudo,w, choix, mat_bis,mat_ia1_bis);
        }
        else {

            //On efface la page
            system("cls");

            //Affichage des matrices de décors
            decors();
            decors1();

            //Initialisation de la matrice 1
            initialisation_matrice(mat,  mat_ia1);

            //Placement aléatoire des bateaux
            placement_bateaux_aleatoire(mat);
            placement_bateaux_aleatoire1(mat_ia1);

            SetConsoleTextAttribute(hConsole, 11);
            gotoligcol(28, 140);
            printf("                                 __..||..__\n");
            gotoligcol(29, 140);
            printf("                             -==|__.----.__|==-\n");
            gotoligcol(30, 140);
            printf("                                 __l|  |/__\n");
            gotoligcol(31, 140);
            printf("                            --==|__.----.__|==--\n");
            gotoligcol(32, 140);
            printf("                                __/       l__\n");
            gotoligcol(33, 140);
            printf("                            __'{             }'__\n");
            gotoligcol(34, 140);
            printf("                       ___'{  ! 8     8     8 !  }'___\n");
            gotoligcol(35, 140);
            printf("                 ====={                               }=====\n");
            gotoligcol(36, 140);
            printf("                _____________________________________________\n");
            gotoligcol(37, 140);
            printf("               |             /   .  -- . --  .  l            |\n");
            gotoligcol(38, 140);
            printf("               | '--_______/    +      !      +   l______--' |\n");
            gotoligcol(39, 140);
            printf("               |                !             !              |\n");
            gotoligcol(40, 140);
            printf("               |                                             |\n");
            gotoligcol(41, 140);
            printf("                l                     |                     /");
            gotoligcol(42, 140);
            printf("                  l_                   |                  _/");
            gotoligcol(43, 140);
            printf("                     l_                |               _/");
            gotoligcol(44, 140);
            printf("                        l_             |            _/");
            gotoligcol(45, 140);
            printf("                           l_          |         _/");
            SetConsoleTextAttribute(hConsole, 15);

            //Appel de la fonction de jeux
            jouer(mat,  mat_ia1, a, pseudo,w, choix, mat_bis, mat_ia1_bis);

        }
    }
        //Chargement d'une partie
    else if (*a == 2){

        //Choix du niveau de l'ia
        gotoligcol(15, 70);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Choose AI level:");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(16, 70);
        printf("1. Sailor");
        gotoligcol(17, 70);
        printf("2. Master Corporal");
        gotoligcol(18, 70);
        printf("3. Admiral");
        gotoligcol(19, 70);
        fflush(stdin);
        scanf("%d",&w);

        //Gestion des erreurs
        while (w != 1 && w != 2 && w != 3) {
            gotoligcol(25,140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(19, 70);
            fflush(stdin);
            scanf("%d", &w);
        }

        //Choix de la partie que le joueur peut charger
        choix_chargement_partie(mat, mat_ia1, a , pseudo, choix, mat_bis, mat_ia1_bis);



        SetConsoleTextAttribute(hConsole, 11);
        gotoligcol(28, 140);
        printf("                                 __..||..__\n");
        gotoligcol(29, 140);
        printf("                             -==|__.----.__|==-\n");
        gotoligcol(30, 140);
        printf("                                 __l|  |/__\n");
        gotoligcol(31, 140);
        printf("                            --==|__.----.__|==--\n");
        gotoligcol(32, 140);
        printf("                                __/       l__\n");
        gotoligcol(33, 140);
        printf("                            __'{             }'__\n");
        gotoligcol(34, 140);
        printf("                       ___'{  ! 8     8     8 !  }'___\n");
        gotoligcol(35, 140);
        printf("                 ====={                               }=====\n");
        gotoligcol(36, 140);
        printf("                _____________________________________________\n");
        gotoligcol(37, 140);
        printf("               |             /   .  -- . --  .  l            |\n");
        gotoligcol(38, 140);
        printf("               | '--_______/    +      !      +   l______--' |\n");
        gotoligcol(39, 140);
        printf("               |                !             !              |\n");
        gotoligcol(40, 140);
        printf("               |                                             |\n");
        gotoligcol(41, 140);
        printf("                 l                     |                     /");
        gotoligcol(42, 140);
        printf("                  l_                   |                  _/");
        gotoligcol(43, 140);
        printf("                     l_                |               _/");
        gotoligcol(44, 140);
        printf("                        l_             |            _/");
        gotoligcol(45, 140);
        printf("                           l_          |         _/");
        SetConsoleTextAttribute(hConsole, 15);
        //Appel de la fonction jouer
        jouer(mat, mat_ia1, a, pseudo,w, choix,mat_bis,mat_ia1_bis);
    }
        //Règles du jeu
    else if (*a == 3) {
        system("cls");

        //Affichage des regles
        printf("Before playing, here are some explanations about the rules of the game:"
               "\n\nAt the start of the game, player 1 randomly or manually places all his ships \n"
               "on its grid.\nThe goal being to complicate the task of the AI as much as possible,\n"
               "that is to say\n"
               "destroy all your ships. Of course, the player does not see the AI grid.\n"
               "Once all the boats are in play, the game can begin... One by one, player 1 and the AI shoot\n"
               "to destroy enemy ships.\n"
               "\n"
               "Example:\nPlayer 1 shoots at (h,7), corresponding to the square of the enemy grid at the crossing of the letter h\n"
               "and of number 7.\n"
               "If player 1 or the AI fires at an enemy ship, the letter 'T' will appear on the hit space.\n"
               "The shooter can play twice in a row to attempt to hit the enemy once more.\n"
               "If player 1 or the AI does not hit a ship, the message 'E' will appear on the failed space.\n\n"
               "The 'T' and 'E' marks are used to remember missed shots ('E') and hits ('T').\n"
               "It is essential to use them so as not to shoot twice at the same place and therefore\n"
               "don't lose turns unnecessarily.\n"
               "A naval battle game ends when one of the players has no more ships.\n\n"
               "Each turn, Player 1 can either fire into the enemy's grid, activate air support"
               "\nwhich fire 5 shots in the enemy's grid or launch a flare.\n"
               "He has the possibility in one turn to save the game, activate satellite view\n"
               "in order to see enemy's ships and return to the main menu.\n");
        printf("\n\nHere are the ships you can place:\n\n"
               "Aircraft Carrier, Cruiser, Destroyer and Submarine.\n"
               "- The unique Aircraft Carrier with symbol P takes up 7 spaces.\n"
               "- 2 Cruisers with symbol C take up 5 spaces.\n"
               "- 3 Destroyers with symbol D take 3 spaces.\n"
               "- 4 Submarines with symbol S take up 1 space.\n\n\n");
        SetConsoleTextAttribute(hConsole, 11);
        gotoligcol(8, 140);
        printf("                                 __..||..__\n");
        gotoligcol(9, 140);
        printf("                             -==|__.----.__|==-\n");
        gotoligcol(10, 140);
        printf("                                 __l|  |/__\n");
        gotoligcol(11, 140);
        printf("                            --==|__.----.__|==--\n");
        gotoligcol(12, 140);
        printf("                                __/       l__\n");
        gotoligcol(13, 140);
        printf("                            __'{             }'__\n");
        gotoligcol(14, 140);
        printf("                       ___'{  ! 8     8     8 !  }'___\n");
        gotoligcol(15, 140);
        printf("                 ====={                               }=====\n");
        gotoligcol(16, 140);
        printf("                _____________________________________________\n");
        gotoligcol(17, 140);
        printf("               |             /   .  -- . --  .  l            |\n");
        gotoligcol(18, 140);
        printf("               | '--_______/    +      !      +   l______--' |\n");
        gotoligcol(19, 140);
        printf("               |                !             !              |\n");
        gotoligcol(20, 140);
        printf("               |                                             |\n");
        gotoligcol(21, 140);
        printf("                 l                     |                     /");
        gotoligcol(22, 140);
        printf("                  l_                   |                  _/");
        gotoligcol(23, 140);
        printf("                     l_                |               _/");
        gotoligcol(24, 140);
        printf("                        l_             |            _/");
        gotoligcol(25, 140);
        printf("                           l_          |         _/");
        SetConsoleTextAttribute(hConsole, 15);


        gotoligcol(44, 95);
        printf("Copyright 2023 Battleship Alassane Wade");

        gotoligcol(39, 0);
        //Appel du menu
        SetConsoleTextAttribute(hConsole, 11);
        printf("MAIN MENU: \n");
        SetConsoleTextAttribute(hConsole, 15);
        printf("1. Yes\n");
        scanf("%d", &w);
        while (w != 1){
            gotoligcol(42, 0);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(41, 0);
            fflush(stdin);
            scanf("%d", &w);
        }
        if (w == 1){
            system("cls");
            menu(mat, mat_ia1, a, pseudo, choix, mat_bis,mat_ia1_bis);
        }
    }

        //Quitter
    else if (*a == 4) {
        system("cls");
        gotoligcol(4, 60);
        SetConsoleTextAttribute(hConsole, 11);
        printf("///////////////////////////// T H A N K  Y O U ! /////////////////////////////");
        gotoligcol(6, 83);
        SetConsoleTextAttribute(hConsole, 15);
        printf("We hope to see you soon %s !", pseudo);

        SetConsoleTextAttribute(hConsole, 11);
        gotoligcol(8, 140);
        printf("                                 __..||..__\n");
        gotoligcol(9, 140);
        printf("                             -==|__.----.__|==-\n");
        gotoligcol(10, 140);
        printf("                                 __l|  |/__\n");
        gotoligcol(11, 140);
        printf("                            --==|__.----.__|==--\n");
        gotoligcol(12, 140);
        printf("                                __/       l__\n");
        gotoligcol(13, 140);
        printf("                            __'{             }'__\n");
        gotoligcol(14, 140);
        printf("                       ___'{  ! 8     8     8 !  }'___\n");
        gotoligcol(15, 140);
        printf("                 ====={                               }=====\n");
        gotoligcol(16, 140);
        printf("                _____________________________________________\n");
        gotoligcol(17, 140);
        printf("               |             /   .  -- . --  .  l            |\n");
        gotoligcol(18, 140);
        printf("               | '--_______/    +      !      +   l______--' |\n");
        gotoligcol(19, 140);
        printf("               |                !             !              |\n");
        gotoligcol(20, 140);
        printf("               |                                             |\n");
        gotoligcol(21, 140);
        printf("                 l                     |                     /");
        gotoligcol(22, 140);
        printf("                  l_                   |                  _/");
        gotoligcol(23, 140);
        printf("                     l_                |               _/");
        gotoligcol(24, 140);
        printf("                        l_             |            _/");
        gotoligcol(25, 140);
        printf("                           l_          |         _/");

        gotoligcol(9, 0);
        printf("           ,_:_,\n");
        gotoligcol(10,0);
        printf("             |\n");
        gotoligcol(11, 0);
        printf("         -*T_##_:-\n");
        gotoligcol(12, 0);
        printf("        i____||____i\n");
        gotoligcol(13, 0);
        printf("       #|==========|@\n");
        gotoligcol(14, 0);
        printf("       -|==========|-\n");
        gotoligcol(15, 0);
        printf("        |          |\n");
        gotoligcol(16, 0);
        printf("        |_        _|\n");
        gotoligcol(17, 0);
        printf("        |          |\n");
        gotoligcol(18, 0);
        printf("     ______________________________________________________________\n");
        gotoligcol(19, 0);
        printf("    |___  __   |________________  USS WADE _____________|   __  ___|\n");
        gotoligcol(20, 0);
        printf("        l        '-,               -   -             ,-'        /\n");
        gotoligcol(21, 0);
        printf("          l         l        l      ___       /      /         /\n");
        gotoligcol(22, 0);
        printf("            l     (l  l       l____     ____/       /  /)     /\n");
        gotoligcol(23, 0);
        printf("              |    V   |           l---/           |   V     |\n");
        gotoligcol(24, 0);
        printf("              |        |             Y             |         |\n");
        SetConsoleTextAttribute(hConsole, 15);

        gotoligcol(44, 95);
        printf("Copyright 2023 Battleship Alassane Wade");
        sleep(6);
        exit(0);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialisation_matrice(unsigned char ** mat, unsigned char ** mat_ia1){

    //Définitions des variables
    int i;
    int j;
    int B = 95;

    //Initialisation de la matrice
    for (i = 1; i < 16; i++){
        for (j = 1; j < 16; j++){
            mat[i][j] = B;
            mat_ia1[i][j] = B;
        }
    }
}