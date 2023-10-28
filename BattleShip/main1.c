#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Prototypages des fonctions

void gotoligcol(int lig, int col);
void menu(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
void initialisation_matrice(unsigned char** mat, unsigned char** mat_ia1);
void decors();
void decors1();
void placement_bateaux(unsigned char ** mat, unsigned char ** mat_ia1, int *a, char *pseudo);
void placement_bateaux_aleatoire(unsigned char ** mat);
void placement_bateaux_aleatoire1(unsigned char ** mat_ia1);
void jouer(unsigned char ** mat, unsigned char ** mat_ia1, int *a, char *pseudo, int w, int choix,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
void tirer(unsigned char ** mat_ia1, char *pseudo);
void tirer_aleatoirement_matelot(unsigned char **  mat ,int compteur_tour);
void tirer_aleatoirement_caporal_chef(unsigned char **  mat ,int compteur_tour);
void tirer_aleatoirement_amiral(unsigned char **  mat ,int compteur_tour);
void fumigene(unsigned char ** mat_ia1, int compteur_tour);
void tir_aerien(unsigned char ** mat_ia1);
void mode_visible(unsigned char ** mat_ia1);
void mode_visible_desactive(unsigned char ** mat_ia1);
void choix_chargement_partie(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
void affichage_matrices_fichiers(unsigned char ** mat, unsigned char ** mat_ia1);
void sauvegarde_matrices(unsigned char ** mat, unsigned char ** mat_ia1,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
void chargement_matrices (unsigned char ** mat, unsigned char ** mat_ia1,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
void sauvegarde(unsigned char ** mat, unsigned char ** mat_ia1, int *a, char *pseudo, int w,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
void sauvegarder_partie(unsigned char ** mat, int choix);
void sauvegarder_partie1(unsigned char ** mat_ia1, int choix);
void charger_partie(unsigned char ** mat);
void charger_partie1(unsigned char ** mat_ia1);
void charger_partie1_0(unsigned char ** mat);
void charger_partie2(unsigned char ** mat_ia1);
void charger_partie2_0(unsigned char ** mat);
void charger_partie3(unsigned char ** mat_ia1);
int vainqueur_joueur(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
int vainqueur_ia(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  gotoligcol( int lig, int col )
{
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

    //Définition des variables
    int k;
    int t = 0;
    int i;
    int z;
    int a = 0;
    int choix;
    char pseudo[100];
    unsigned char ** mat = NULL;
    unsigned char ** mat_ia1 = NULL;
    unsigned char ** mat_bis = NULL;
    unsigned char ** mat_ia1_bis = NULL;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Bataille navale
    gotoligcol(0, 30);
    SetConsoleTextAttribute(hConsole, 11);
    printf("/////////////////////////////////////// B A T T L E S H I P ///////////////////////////////////////\n");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(3, 30);
    printf("////////////////////////////////// Please, open the game page wide ////////////////////////////////");


    //3. Saisie du pseudo de l'utilisateur
    gotoligcol(5, 70);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Enter your nickname: ");
    SetConsoleTextAttribute(hConsole, 15);
    gets(pseudo);
    gotoligcol(6, 70);
    printf("Welcome %s !\n\n", pseudo);

    gotoligcol(44, 95);
    printf("Copyright 2023 Battleship Alassane Wade");

    srand(time(NULL));
    choix = rand() % (2) + 1;

    gotoligcol(9, 0);

    if (choix == 1){
        SetConsoleTextAttribute(hConsole, 11);
        gotoligcol(9, 70);
        printf("           ,_:_,\n");
        gotoligcol(10, 70);
        printf("             |\n");
        gotoligcol(11, 70);
        printf("         -*T_##_:-\n");
        gotoligcol(12, 70);
        printf("        i____||____i\n");
        gotoligcol(13, 70);
        printf("       #|==========|@\n");
        gotoligcol(14, 70);
        printf("       -|==========|-\n");
        gotoligcol(15, 70);
        printf("        |          |\n");
        gotoligcol(16, 70);
        printf("        |_        _|\n");
        gotoligcol(17, 70);
        printf("        |          |\n");
        gotoligcol(18, 70);
        printf("     ______________________________________________________________\n");
        gotoligcol(19, 70);
        printf("    |___  __   |________________  USS WADE _____________|   __  ___|\n");
        gotoligcol(20, 70);
        printf("        l        '-,               -   -             ,-'        /\n");
        gotoligcol(21, 70);
        printf("          l         l        l      ___       /      /         /\n");
        gotoligcol(22, 70);
        printf("            l     (l  l       l____     ____/       /  /)     /\n");
        gotoligcol(23, 70);
        printf("              |    V   |           l---/           |   V     |\n");
        gotoligcol(24, 70);
        printf("              |        |             Y             |         |\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    if (choix == 2){
        SetConsoleTextAttribute(hConsole, 11);
        gotoligcol(8, 70);
        printf("                                 __.#--+.__\n");
        gotoligcol(9, 70);
        printf("                             -==|__.----.__|==-\n");
        gotoligcol(10, 70);
        printf("                                 __l|  |/__\n");
        gotoligcol(11, 70);
        printf("                            --==|__.----.__|==--\n");
        gotoligcol(12, 70);
        printf("                                __/       l__\n");
        gotoligcol(13, 70);
        printf("                            __'{             }'__\n");
        gotoligcol(14, 70);
        printf("                       ___'{  ! 8     8     8 !  }'___\n");
        gotoligcol(15, 70);
        printf("                 ====={                               }=====\n");
        gotoligcol(16, 70);
        printf("                _____________________________________________\n");
        gotoligcol(17, 70);
        printf("               |             /   .  -- . --  .  l            |\n");
        gotoligcol(18, 70);
        printf("               | '--_______/    +      !      +   l______--' |\n");
        gotoligcol(19, 70);
        printf("               |                !             !              |\n");
        gotoligcol(20, 70);
        printf("               |                                             |\n");
        gotoligcol(21, 70);
        printf("                 l                     |                     /");
        gotoligcol(22, 70);
        printf("                  l_                   |                  _/");
        gotoligcol(23, 70);
        printf("                     l_                |               _/");
        gotoligcol(24, 70);
        printf("                        l_             |            _/");
        gotoligcol(25, 70);
        printf("                           l_          |         _/");
        SetConsoleTextAttribute(hConsole, 15);
    }
    gotoligcol(30, 70);
    printf("Loading...");
    sleep(3);
    system("cls");

    //Création de l'échiquier

    //Création de la ligne [1][j]
    mat = (unsigned char **)malloc(16* sizeof(unsigned char*));

    //Création des colonnes
    for ( k = 0; k < 16; k++) {
        mat[k] = (unsigned char *)malloc(16 * sizeof(unsigned char));
    }
    //Création de la ligne [1][j]
    mat_ia1 = (unsigned char **)malloc(16* sizeof(unsigned char*));

    //Création des colonnes
    for ( k = 0; k < 16; k++) {
        mat_ia1[k] = (unsigned char *)malloc(16 * sizeof(unsigned char));
    }
    //Création de la ligne [1][j]
    mat_bis = (unsigned char **)malloc(16* sizeof(unsigned char*));

    //Création des colonnes
    for ( k = 0; k < 16; k++) {
        mat_bis[k] = (unsigned char *)malloc(16 * sizeof(unsigned char));
    }
    //Création de la ligne [1][j]
    mat_ia1_bis = (unsigned char **)malloc(16* sizeof(unsigned char*));

    //Création des colonnes
    for ( k = 0; k < 16; k++) {
        mat_ia1_bis[k] = (unsigned char *)malloc(16 * sizeof(unsigned char));
    }

    //Appel du Menu Principale
    menu(mat,mat_ia1, &a, pseudo, choix, mat_bis,mat_ia1_bis);

    //On libère l'espace occupé par les matrices
    free(mat_ia1);
    free(mat);
    free(mat_ia1_bis);
    free(mat_bis);

    //Fin du programme
    return 0;
}

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
        printf("At the start of the game, Player 1 randomly or manually places all the ships on the grid.\n" 
                "Player 1 does not see the AI grid. Player 1 shoots at (h,7), corresponding to the square\n"
                "of the enemy grid at the crossing of the letter h and of number 7. If Player 1 or the AI\n"
                "fires at an enemy ship, the letter 'X' will appear on the hit space.The shooter can play\n"
                "twice in a row to attempt to hit the enemy once more. If player 1 or the AI does not hit\n"
                "a ship, the message 'O' will appear on the failed space. The 'X' and 'O' marks are used\n"
                "to remember missed shots ('O') and hits ('X').\n\n"
                "Each turn, Player 1 can either fire into the enemy's grid, activate air support which\n"
                "fires 5 shots in the enemy's grid, activate satellite view in order to see enemy's ships or\n"
                "launch a flare. Player 1 is able to save the current game and return to the main menu.\n"
                "A battleship game ends when one of the players has no ships remaining.\n");
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void decors(){

    //Déclarations des variables
    int i;
    int j;
    int k = 65;

    // positionnement à l'écran pour la première matrice
    for (i = 0; i < 16; i++){
        for (j = 0; j < 16; j++){
            //Premiere ligne on parcours les colonnes
            if (i == 0 && j > 0){
                printf("%2d |",j);
            }
                //Premiere colonne on parcours les lignes
            else if(j == 0 && i > 0){
                printf("\n");
                printf("%2c |", k);
                k++;
            }
                //Pour les cases de la matrices on affiche des cases vides
            else{
                printf("%2c |",' ');
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void decors1(){

    //Déclarations des variables
    int a;
    int b;

    for (a = 0; a < 16; a++){
        //Positionnement à l'écran pour la deuxième matrice
        gotoligcol(a,70);
        for (b = 0; b < 16; b++){
            //Premiere ligne on parcours les colonnes
            if (a == 0 && b > 0){
                printf("%2d |",b);
            }
                //Premiere colonne on parcours les lignes
            else if(b == 0 && a > 0){
                printf("%2c |", a + 'a' - 1);
            }
                //pour les cases de la matrices on affiche des cases vides
            else{
                printf("%2c |",' ');
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void placement_bateaux(unsigned char ** mat ,unsigned char ** mat_ia1, int *a, char *pseudo){

    //Définitions des variables
    int k;
    int r;
    int z;
    int x;
    int P = 1;
    int C = 1;
    int D = 1;
    int S = 1;
    int B = 95;
    int col = 0;
    char lig = 0;
    int compteur_general = 1;

    //Choix du bateau par l'utilisateur
    while (compteur_general <= 10) {
        while (P <= 1) {
            printf("\nChoose the position of the"
                   " boat n %d out of 10 to place:\n", compteur_general);
            printf("Column:\n");
            fflush(stdin);
            scanf("%d", &col);
            while (col > 15 || col < 1){
                gotoligcol(25,140);
                printf("Error.");
                gotoligcol(18, 0);
                fflush(stdin);
                scanf("%d", &col);
            }
            printf("Row:\n");
            fflush(stdin);
            scanf("%c", &lig);
            while (lig - 'A' + 1  > 15 || lig - 'A' + 1  < 1){
                gotoligcol(25,140);
                printf("Error.");
                gotoligcol(20, 0);
                fflush(stdin);
                scanf("%c", &lig);
            }
            mat[lig - 'A' + 1 ][col] = 'P';
            gotoligcol(lig - 'A' + 1 , col * 4);
            printf("%2c", 'P');
            gotoligcol(21, 0);
            printf("How would you like to place your boat n%d ?:\n1. Row\n2. Column\n", compteur_general);
            fflush(stdin);
            scanf("%d", &r);

            //Gestion des erreurs de saisie
            while (r != 1 && r != 2) {
                gotoligcol(25,140);
                printf("Error.");
                gotoligcol(24, 0);
                fflush(stdin);
                scanf("%d", &r);
            }
            //Si en ligne
            if (r == 1) {
                gotoligcol(29, 0);
                printf("In which way ?\n1. Towards the left.\n2. Towards the right.\n");
                scanf("%d", &x);
                while (x != 1 && x != 2) {
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                while (x == 1 && col - 6 < 1 || x == 2 && col + 6 > 15) {
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                //Si vers la gauche
                if (x == 1 && col - 6 >= 1){
                    for(z = 1; z < 7; z++) {
                        mat[lig][col - z] = 'P';
                        gotoligcol(lig, (col * 4) - (z * 4));
                        printf("%2c", 'P');
                    }
                }
                //Si vers la droite
                if (x == 2 && col + 6 <= 15){
                    for (z = 1; z < 7; z++) {
                        mat[lig - 'A' + 1 ][col + z] = 'P';
                        gotoligcol(lig - 'A' + 1 , (col * 4) + (z * 4));
                        printf("%2c", 'P');
                    }
                }
            }
                //Si en colonne
            else {
                printf("In which way ?\n1. Upwards\n2. Downwards\n");
                scanf("%d", &x);
                //Gestion des erreurs de saisie
                while (x != 1 && x != 2) {
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(28, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                //Si vers le haut
                while(x == 1 && lig - 'A' + 1  - 6 < 1 || x == 2 && lig - 'A' + 1  + 6 > 15){
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(28, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                //Si vers le haut
                if (x == 1 && lig - 'A' + 1  - 6 >= 1){
                    for (z = 1; z < 7; z++) {
                        mat[lig - 'A' + 1  - z][col] = 'P';
                        gotoligcol(lig - 'A' + 1  - z, col * 4);
                        printf("%2c", 'P');
                    }
                }
                //Si vers le bas
                if(x == 2 && lig - 'A' + 1  + 6 <= 15){
                    for (z = 1; z < 7; z++){
                        mat[lig - 'A' + 1  + z][col] = 'P';
                        gotoligcol(lig - 'A' + 1  + z, col * 4);
                        printf("%2c", 'P');
                    }
                }
            }
            //On augmente de 1 les valeurs de P et du nombre de bateaux posés
            P++;
            compteur_general++;
            gotoligcol(16, 34);
            printf("%d", compteur_general);
            gotoligcol(17, 0);
        }
        //Se procéder pour le porte avion est repeté pour chaque type de bateaux
        while (C <= 2) {
            do {
                gotoligcol(17, 0);
                printf("Column:\n");
                fflush(stdin);
                scanf("%d", &col);
                while (col > 15 || col < 1) {
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(18, 0);
                    fflush(stdin);
                    scanf("%d", &col);
                }
                gotoligcol(19, 0);
                printf("Row:\n");
                fflush(stdin);
                scanf("%c", &lig);
                while (lig - 'A' + 1  > 15 || lig - 'A' + 1  < 1) {
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(20, 0);
                    fflush(stdin);
                    scanf("%c", &lig);
                }
            }
            while (mat[lig - 'A' + 1 ][col] != B);
            mat[lig - 'A' + 1 ][col] = 'C';
            gotoligcol(lig - 'A' + 1 , col * 4);
            printf("%2c", 'C');
            //Gestion des erreurs de saisie
            gotoligcol(21, 0);
            printf("How would you like to place your boat n%d ?:\n1. Row\n2. Column\n", compteur_general);
            fflush(stdin);
            scanf("%d", &r);
            //Gestion des erreurs de saisie
            while (r != 1 && r != 2) {
                gotoligcol(25,140);
                printf("Error.");
                gotoligcol(24, 0);
                fflush(stdin);
                scanf("%d", &r);
            }
            for (int j = 1; j < 5; j ++){
                while (r == 1 && mat[lig - 'A' + 1][col + j] != B && mat[lig - 'A' + 1][col - j] != B){
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(24, 0);
                    fflush(stdin);
                    scanf("%d", &r);
                }
                while (r == 2 && mat[lig - 'A' + 1 + j][col] != B && mat[lig - 'A' + 1 - j][col] != B){
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(24, 0);
                    fflush(stdin);
                    scanf("%d", &r);
                }
            }
            if (r == 1){
                gotoligcol(29, 0);
                printf("In which way ?\n1. Towards the left.\n2. Towards the right.\n");
                fflush(stdin);
                scanf("%d", &x);
                //Gestion des erreurs de saisie
                while (x != 1 && x != 2) {
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                while (x == 1 && col - 4 < 1 || x == 2 && col + 4 > 15){
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                for (int j = 1; j < 5; j ++){
                    while (x == 1 && mat[lig - 'A' + 1 ][col - j] != B) {
                        gotoligcol(25,140);
                        printf("Error.");
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 1 && col - 4 >= 1){
                    for (z = 1; z < 5; z++){
                        mat[lig - 'A' + 1 ][col - z] = 'C';
                        gotoligcol(lig - 'A' + 1 , (col * 4) - (z * 4));
                        printf("%2c", 'C');
                    }
                }
                for (int j = 1; j < 5; j ++){
                    while (x == 2 && mat[lig - 'A' + 1 ][col + j] != B) {
                        gotoligcol(25,140);
                        printf("Error.");
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 2 && col + 4 <= 15) {
                    for (z = 1; z < 5; z++) {
                        mat[lig - 'A' + 1 ][col + z] = 'C';
                        gotoligcol(lig - 'A' + 1 , (col * 4) + (z * 4));
                        printf("%2c", 'C');
                    }
                }
            }
            else {
                printf("In which way ?\n1. Upwards\n2. Downwards\n");
                fflush(stdin);
                scanf("%d", &x);
                //Gestion des erreurs de saisie
                while (x != 1 && x != 2) {
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(28, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                while(x == 1 && lig - 'A' + 1  - 4 < 1 || x == 2 && lig - 'A' + 1  + 4 > 15){
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(28, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                for (int j = 1; j < 5; j ++){
                    while (r == 1 && mat[lig - 'A' + 1 - j][col + j] != B && mat[lig - 'A' + 1 ][col - j] != B){
                        gotoligcol(25,140);
                        printf("Error.");
                        gotoligcol(24, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                    while (r == 2 && mat[lig - 'A' + 1 + j][col] != B && mat[lig - 'A' + 1 - j][col] != B){
                        gotoligcol(25,140);
                        printf("Error.");
                        gotoligcol(24, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                for (int i = 1; i < 5; i ++){
                    while (x == 1 && mat[lig - 'A' + 1  - i][col] != B) {
                        gotoligcol(25,140);
                        printf("Error.");
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 1 && lig - 'A' + 1  - 4 >= 1){
                    for (z = 1; z < 5; z++) {
                        mat[lig - 'A' + 1  - z][col] = 'C';
                        gotoligcol(lig - 'A' + 1  - z, col * 4);
                        printf("%2c", 'C');
                    }
                }
                for (int i = 1; i < 5; i ++){
                    while (x == 2 && mat[lig - 'A' + 1  + i][col] != B) {
                        gotoligcol(25,140);
                        printf("Error.");
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 2 && lig - 'A' + 1  + 4 <= 15){
                    for (z = 1; z < 5; z++) {
                        mat[lig - 'A' + 1  + z][col] = 'C';
                        gotoligcol(lig - 'A' + 1  + z, col * 4);
                        printf("%2c", 'C');
                    }
                }
            }
            C++;
            compteur_general++;
            gotoligcol(16, 34);
            printf("%d", compteur_general);
            gotoligcol(17, 0);
        }
        while (D <= 3) {
            do{
                gotoligcol(17, 0);
                printf("Column:\n");
                fflush(stdin);
                scanf("%d", &col);
                while (col > 15 || col < 1){
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(18, 0);
                    fflush(stdin);
                    scanf("%d", &col);
                }
                gotoligcol(19,0);
                printf("Row:\n");
                fflush(stdin);
                scanf("%c", &lig);
                while (lig - 'A' + 1  > 15 || lig - 'A' + 1  < 1){
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(20, 0);
                    fflush(stdin);
                    scanf("%c", &lig);
                }
            }
            while (mat[lig - 'A' + 1 ][col] != B);
            mat[lig - 'A' + 1 ][col] = 'D';
            gotoligcol(lig - 'A' + 1 , col * 4);
            printf("%2c", 'D');
            gotoligcol(21, 0);
            printf("How would you like to place your boat n%d ?:\n1. Row\n2. Column\n", compteur_general);
            fflush(stdin);
            scanf("%d", &r);
            //Gestion des erreurs de saisie
            while (r != 1 && r != 2) {
                gotoligcol(25,140);
                printf("Error.");
                gotoligcol(24, 0);
                fflush(stdin);
                scanf("%d", &r);
            }
            for (int j = 1; j < 3; j ++){
                while (r == 1 && mat[lig - 'A' + 1 ][col + j] != B && mat[lig - 'A' + 1 ][col - j] != B){
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(24, 0);
                    fflush(stdin);
                    scanf("%d", &r);
                }
                while (r == 2 && mat[lig - 'A' + 1  + j][col] != B && mat[lig - 'A' + 1  - j][col] != B){
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(24, 0);
                    fflush(stdin);
                    scanf("%d", &r);
                }
            }
            if (r == 1) {
                gotoligcol(29, 0);
                printf("In which way ?\n1. Towards the left.\n2. Towards the right.\n");
                fflush(stdin);
                scanf("%d", &x);
                //Gestion des erreurs de saisie
                while (x != 1 && x != 2) {
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                while (x == 1 && col - 2 < 1 || x == 2 && col + 2 > 15) {
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(32, 0);
                    fflush(stdin);
                    scanf("%d", &col);
                }
                for (int j = 1; j < 3; j ++){
                    while (x == 1 && mat[lig - 'A' + 1 ][col - j] != B) {
                        gotoligcol(25,140);
                        printf("Error.");
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 1 && col - 2 >= 1){
                    for (z = 1; z < 3; z++) {
                        mat[lig - 'A' + 1 ][col - z] = 'D';
                        gotoligcol(lig - 'A' + 1 , (col - z)* 4);
                        printf("%2c", 'D');
                    }
                }
                for (int j = 1; j < 3; j ++){
                    while (x == 2 && mat[lig - 'A' + 1 ][col + j] != B) {
                        gotoligcol(25,140);
                        printf("Error.");
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 2 && col + 2 <= 15) {
                    for (z = 1; z < 3; z++){
                        mat[lig - 'A' + 1 ][col + z] = 'D';
                        gotoligcol(lig - 'A' + 1 , (col + z) * 4);
                        printf("%2c", 'D');
                    }
                }
            }
            else {
                printf("In which way ?\n1. Upwards\n2. Downwards\n");
                fflush(stdin);
                scanf("%d", &x);
                //Gestion des erreurs de saisie
                while (x != 1 && x != 2) {
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(28, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                while(x == 1 && lig - 'A' + 1  - 2 < 1 || x == 2 && lig - 'A' + 1  + 2 > 15){
                    gotoligcol(25,140);
                    printf("Error.");
                    gotoligcol(28, 0);
                    fflush(stdin);
                    scanf("%d", &x);
                }
                for (int i = 1; i < 3; i ++){
                    while (x == 1 && mat[lig - 'A' + 1  - i][col] != B) {
                        gotoligcol(25,140);
                        printf("Error.");
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 1 && lig - 'A' + 1  - 2 >= 1) {
                    for (z = 1; z < 3; z++) {
                        mat[lig - 'A' + 1  - z][col * 4] = 'D';
                        gotoligcol(lig - 'A' + 1  - z, col * 4);
                        printf("%2c", 'D');
                    }
                }
                for (int i = 1; i < 3; i ++){
                    while (x == 2 && mat[lig - 'A' + 1  + i][col] != B) {
                        gotoligcol(25,140);
                        printf("Error.");
                        gotoligcol(32, 0);
                        fflush(stdin);
                        scanf("%d", &r);
                    }
                }
                if (x == 2 && lig - 'A' + 1  + 2 <= 15){
                    for (z = 1; z < 3; z++) {
                        mat[lig - 'A' + 1  + z][col * 4] = 'D';
                        gotoligcol(lig - 'A' + 1  + z, col * 4);
                        printf("%2c", 'D');
                    }
                }
            }
            D++;
            compteur_general++;
            gotoligcol(16, 34);
            printf("%d", compteur_general);
            gotoligcol(17, 0);
        }
        while (S <= 4) {
            for (k = 0; k < 1; k++) {
                do{
                    printf("Column:\n");
                    fflush(stdin);
                    scanf("%d", &col);
                    while (col > 15 || col < 1){
                        gotoligcol(25,140);
                        printf("Error.");
                        gotoligcol(18, 0);
                        fflush(stdin);
                        scanf("%d", &col);
                    }
                    printf("Row:\n");
                    fflush(stdin);
                    scanf("%c", &lig);
                    while (lig - 'A' + 1  > 15 || lig - 'A' + 1  < 1){
                        gotoligcol(25,140);
                        printf("Error.");
                        gotoligcol(20, 0);
                        fflush(stdin);
                        scanf("%c", &lig);
                    }
                }while (mat[lig - 'A' + 1 ][col] != B);
                mat[lig - 'A' + 1 ][col] = 'S';
                gotoligcol(lig - 'A' + 1 , col * 4);
                printf("%2c", 'S');
            }
            S++;
            compteur_general++;
            gotoligcol(16, 34);
            printf("%d", compteur_general);
            gotoligcol(17, 0);
        }
    }
}

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

void jouer(unsigned char ** mat, unsigned char ** mat_ia1, int *a, char *pseudo, int w, int choix,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){

    //Définition des variables
    int f;
    int g;
    int i;
    int j;
    int q;
    int x;
    int b = 0;
    int B = 95;
    int tir_air = 2;
    int satellite = 3;
    int nombre_fumigene = 4;
    int compteur_tour = 1;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoligcol(16, 0);
    SetConsoleTextAttribute(hConsole, 11);
    printf("////////////////////// Last shots recorded /////////////////////");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(44, 95);
    printf("Copyright 2023 Battleship Alassane Wade");

    //Tant que les tours ne sont inférieurs a 200 et que La matrice de l'ordinateur pleine on boucle
    for (int d = 0; d < 15; d++){
        for (int c = 0; c < 15; c++){
            while ((mat_ia1[d][c] != 'X' && mat_ia1[d][c] != 'O' && mat_ia1[d][c] == B) || (mat[d][c] != 'X' && mat[d][c] != 'O' && mat[d][c] != B)){
                gotoligcol(16, 70);
                fflush(stdin);
                SetConsoleTextAttribute(hConsole, 11);
                printf("///////////////////////// R O U N D  %d /////////////////////////", compteur_tour);
                gotoligcol(17, 70);
                printf("Would you like to :");
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
                fflush(stdin);
                scanf("%d", &g);

                //Gestions des erreurs
                while (g != 1 && g != 2 && g!= 3 && g != 4 && g != 5 && g != 6) {
                    gotoligcol(25,140);
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("Error.");
                    SetConsoleTextAttribute(hConsole, 15);
                    gotoligcol(25, 70);
                    fflush(stdin);
                    scanf("%d", &g);
                }
                if (g == 1){
                    //Appel de la fonction Tirer et tirer aleatoirement pour l'IA
                    tirer( mat_ia1, pseudo);
                    if (w == 1){
                        tirer_aleatoirement_matelot(mat,  compteur_tour);
                        compteur_tour++;
                    }
                    if (w == 2){
                        tirer_aleatoirement_caporal_chef(mat,  compteur_tour);
                        compteur_tour++;
                    }
                    if (w == 3){
                        tirer_aleatoirement_amiral(mat,  compteur_tour);
                        compteur_tour++;
                    }
                }
                else if (g == 2){
                    //Appel de la fonction fumigene
                    //Si on a plus de fumigene on en peux plus en tirer
                    if (nombre_fumigene == 0) {
                        gotoligcol(21, 140);
                        printf("                                   ");
                        gotoligcol(21, 140);
                        printf("Total number of flares exhausted !");
                        gotoligcol(25, 70);
                        fflush(stdin);
                        scanf("%d", &g);
                    }
                        //Si il nous reste des fumigènes on rentre dans le else
                    else {
                        nombre_fumigene --;
                        fumigene(mat_ia1, compteur_tour);
                        gotoligcol(21, 140);
                        printf("                                                ");
                        gotoligcol(21, 140);
                        printf("Flare lit for    seconds !");
                        for(int k = 6; k >= 0; k --){
                            gotoligcol(21, 154);
                            printf("%2d", k);
                            if (k == 1 || k == 0){
                                gotoligcol(21, 163);
                                printf(" ");
                            }
                            sleep(1);
                        }
                        gotoligcol(21, 140);
                        printf("                                               ");
                        gotoligcol(21, 140);
                        printf("Number of flare remaining: %d", nombre_fumigene);
                        mode_visible_desactive(mat_ia1);
                    }
                    if (w == 1){
                        tirer_aleatoirement_matelot(mat,  compteur_tour);
                        compteur_tour++;
                    }
                    if (w == 2){
                        tirer_aleatoirement_caporal_chef(mat,  compteur_tour);
                        compteur_tour++;
                    }
                    if (w == 3){
                        tirer_aleatoirement_amiral(mat,  compteur_tour);
                        compteur_tour++;
                    }
                }
                while (g == 5){
                    sauvegarde(mat, mat_ia1, a, pseudo, w, mat_bis, mat_ia1_bis);
                    gotoligcol(20, 140);
                    printf("Saved game!");
                    gotoligcol(25, 70);
                    fflush(stdin);
                    scanf("%d", &g);
                }
                if (g == 4){
                    if (tir_air == 0){
                        gotoligcol(21, 140);
                        printf("                                 ");
                        gotoligcol(21, 140);
                        printf("Air support not available !");
                        gotoligcol(25, 70);
                        fflush(stdin);
                        scanf("%d", &g);
                    }
                    else {
                        tir_air --;
                        gotoligcol(21, 140);
                        printf("                                 ");
                        gotoligcol(21, 140);
                        printf("Aerial bombardment remaining: %d", tir_air);
                        tir_aerien(mat_ia1);
                        if (w == 1){
                            tirer_aleatoirement_matelot(mat,  compteur_tour);
                            compteur_tour++;
                        }
                        if (w == 2){
                            tirer_aleatoirement_caporal_chef(mat,  compteur_tour);
                            compteur_tour++;
                        }
                        if (w == 3){
                            tirer_aleatoirement_amiral(mat,  compteur_tour);
                            compteur_tour++;
                        }
                    }
                }
                else if(g == 6){
                    //On efface l'ecran
                    system("cls");

                    //On retourne au menu principale
                    menu(mat, mat_ia1,a ,pseudo, choix, mat_bis,mat_ia1_bis);
                }
                else if (g == 3){
                    if (satellite == 0){
                        gotoligcol(21, 140);
                        printf("                                 ");
                        gotoligcol(21, 140);
                        printf("Satellite view not available !");
                        gotoligcol(25, 70);
                        fflush(stdin);
                        scanf("%d", &g);
                    }
                    else {
                        satellite --;
                        mode_visible(mat_ia1);
                        gotoligcol(21, 140);
                        printf("                                                             ");
                        gotoligcol(21, 140);
                        printf("Satellite view enabled. Enemy fleet revealed for    seconds !");
                        for(int k = 10; k >= 0; k --){
                            gotoligcol(21, 189);
                            printf("%2d", k);
                            if (k == 1 || k == 0){
                                gotoligcol(21, 198);
                                printf(" ");
                            }
                            sleep(1);
                        }
                        gotoligcol(21, 140);
                        printf("                                                                     ");
                        gotoligcol(21, 140);
                        printf("Satellite view remaining : %d", satellite);
                        mode_visible_desactive(mat_ia1);
                        if (w == 1){
                            tirer_aleatoirement_matelot(mat,  compteur_tour);
                            compteur_tour++;
                        }
                        if (w == 2){
                            tirer_aleatoirement_caporal_chef(mat,  compteur_tour);
                            compteur_tour++;
                        }
                        if (w == 3){
                            tirer_aleatoirement_amiral(mat,  compteur_tour);
                            compteur_tour++;
                        }
                    }
                }
            }
            if (mat_ia1[d][c] == 'X' || mat_ia1[d][c] == 'O' || mat_ia1[d][c] == B){
                vainqueur_joueur(mat,mat_ia1, a, pseudo, choix , mat_bis, mat_ia1_bis);
            }
            else if (mat[d][c] == 'X' || mat[d][c] == 'O' || mat[d][c] == B){
                vainqueur_ia(mat,mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
            }
        }
    }
}

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
void fumigene(unsigned char ** mat_ia1, int compteur_tour){

    //Définitions des variables
    int i;
    int j;
    int l;
    char a;
    int col;
    char lig;
    int const compte = compteur_tour;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Fumigene
    //On demande à l'utilisateur les coordonnées de la case à éclairer
    gotoligcol(30, 70);
    printf("                                                        ");
    gotoligcol(30, 70);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Where would you like to fire your flare ?\n");
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

    l = lig - 'a' + 1;

    if (l == 1 && col == 1){
        SetConsoleTextAttribute(hConsole, 10);
        gotoligcol(l,(col * 4) + 70);
        printf("%2c", mat_ia1[l][col]);
        gotoligcol(l,(col * 4) + 70 + 4);
        printf("%2c", mat_ia1[l][col + 1]);
        gotoligcol(l + 1,(col * 4) + 70 + 4);
        printf("%2c", mat_ia1[l + 1][col + 1]);
        gotoligcol(l + 1,(col * 4) + 70);
        printf("%2c", mat_ia1[l + 1][col]);
        SetConsoleTextAttribute(hConsole, 15);
    }
    else if (l == 1 && col == 15){
        SetConsoleTextAttribute(hConsole, 10);
        gotoligcol(l,(col * 4) + 70);
        printf("%2c", mat_ia1[l][col]);
        gotoligcol(l,(col * 4) + 70 - 4);
        printf("%2c", mat_ia1[l][col - 1]);
        gotoligcol(l - 1,(col * 4) + 70 - 4);
        printf("%2c", mat_ia1[l - 1][col - 1]);
        gotoligcol(l - 1,(col * 4) + 70);
        printf("%2c", mat_ia1[l - 1][col]);
        SetConsoleTextAttribute(hConsole, 15);
    }
    else if (l == 15 && col == 1){
        SetConsoleTextAttribute(hConsole, 10);
        gotoligcol(l,(col * 4) + 70);
        printf("%2c", mat_ia1[l][col]);
        gotoligcol(l,(col * 4) + 70 + 4);
        printf("%2c", mat_ia1[l][col + 1]);
        gotoligcol(l - 1,(col * 4) + 70 + 4);
        printf("%2c", mat_ia1[l - 1][col + 1]);
        gotoligcol(l - 1,(col * 4) + 70);
        printf("%2c", mat_ia1[l - 1][col]);
        SetConsoleTextAttribute(hConsole, 15);
    }
    else if (l == 15 && col == 15){
        SetConsoleTextAttribute(hConsole, 10);
        gotoligcol(l,(col * 4) + 70);
        printf("%2c", mat_ia1[l][col]);
        gotoligcol(l - 1,(col * 4) + 70);
        printf("%2c", mat_ia1[l - 1][col]);
        gotoligcol(l,(col * 4) + 70 - 4);
        printf("%2c", mat_ia1[l][col - 1]);
        gotoligcol(l - 1,(col * 4) + 70 - 4);
        printf("%2c", mat_ia1[l - 1][col - 1]);
        SetConsoleTextAttribute(hConsole, 15);
    }
    else if (l == 15 && col != 1 && col != 15){
        SetConsoleTextAttribute(hConsole, 10);
        gotoligcol(l,(col * 4) + 70);
        printf("%2c", mat_ia1[l][col]);
        gotoligcol(l - 1,(col * 4) + 70 - 4);
        printf("%2c", mat_ia1[l - 1][col - 1]);
        gotoligcol(l - 1,(col * 4) + 70);
        printf("%2c", mat_ia1[l - 1][col]);
        gotoligcol(l - 1,(col * 4) + 70 + 4);
        printf("%2c", mat_ia1[l - 1][col + 1]);
        gotoligcol(l,(col * 4) + 70 - 4);
        printf("%2c", mat_ia1[l][col - 1]);
        gotoligcol(l,(col * 4) + 70 + 4);
        printf("%2c", mat_ia1[l][col + 1]);
        SetConsoleTextAttribute(hConsole, 15);
    }
    else if (l == 1 && col != 1 && col != 15){
        SetConsoleTextAttribute(hConsole, 10);
        gotoligcol(l,(col * 4) + 70);
        printf("%2c", mat_ia1[l][col]);
        gotoligcol(l,(col * 4) + 70 - 4);
        printf("%2c", mat_ia1[l][col - 1]);
        gotoligcol(l,(col * 4) + 70 + 4);
        printf("%2c", mat_ia1[l][col + 1]);
        gotoligcol(l + 1,(col * 4) + 70 - 4);
        printf("%2c", mat_ia1[l + 1][col - 1]);
        gotoligcol(l + 1,(col * 4) + 70);
        printf("%2c", mat_ia1[l + 1][col]);
        gotoligcol(l + 1,(col * 4) + 70 + 4);
        printf("%2c", mat_ia1[l + 1][col + 1]);
        SetConsoleTextAttribute(hConsole, 15);
    }
    else if (col == 15 && lig != 1 && lig != 15){
        SetConsoleTextAttribute(hConsole, 10);
        gotoligcol(l,(col * 4) + 70);
        printf("%2c", mat_ia1[l][col]);
        gotoligcol(l - 1,(col * 4) + 70 - 4);
        printf("%2c", mat_ia1[l- 1][col - 1]);
        gotoligcol(l - 1,(col * 4) + 70);
        printf("%2c", mat_ia1[l - 1][col]);
        gotoligcol(l,(col * 4) + 70 - 4);
        printf("%2c", mat_ia1[l][col - 1]);
        gotoligcol(l + 1,(col * 4) + 70 - 4);
        printf("%2c", mat_ia1[l + 1][col - 1]);
        gotoligcol(l + 1,(col * 4) + 70);
        printf("%2c", mat_ia1[l + 1][col]);
        SetConsoleTextAttribute(hConsole, 15);
    }
    else if (col == 1 && lig != 1 && lig != 15){
        SetConsoleTextAttribute(hConsole, 10);
        gotoligcol(l,(col * 4) + 70);
        printf("%2c", mat_ia1[l][col]);
        gotoligcol(l - 1,(col * 4) + 70);
        printf("%2c", mat_ia1[l - 1][col]);
        gotoligcol(l - 1,(col * 4) + 70 + 4);
        printf("%2c", mat_ia1[l- 1][col + 1]);
        gotoligcol(l,(col * 4) + 70 + 4);
        printf("%2c", mat_ia1[l][col + 1]);
        gotoligcol(l + 1,(col * 4) + 70);
        printf("%2c", mat_ia1[l + 1][col]);
        gotoligcol(l + 1,(col * 4) + 70 + 4);
        printf("%2c", mat_ia1[l + 1][col + 1]);
        SetConsoleTextAttribute(hConsole, 15);
    }
    else {
        SetConsoleTextAttribute(hConsole, 10);
        // Affichage de la zone eclaire. On éclaire les cases autour de la case sélèctionneée par le joueur.
        gotoligcol(l,(col * 4) + 70);
        printf("%2c", mat_ia1[l][col]);
        gotoligcol(l - 1,(col * 4) + 70 - 4);
        printf("%2c", mat_ia1[l- 1][col - 1]);
        gotoligcol(l - 1,(col * 4) + 70);
        printf("%2c", mat_ia1[l - 1][col]);
        gotoligcol(l - 1,(col * 4) + 70 + 4);
        printf("%2c", mat_ia1[l- 1][col + 1]);
        gotoligcol(l,(col * 4) + 70 - 4);
        printf("%2c", mat_ia1[l][col - 1]);
        gotoligcol(l,(col * 4) + 70 + 4);
        printf("%2c", mat_ia1[l][col + 1]);
        gotoligcol(l + 1,(col * 4) + 70 - 4);
        printf("%2c", mat_ia1[l + 1][col - 1]);
        gotoligcol(l + 1,(col * 4) + 70);
        printf("%2c", mat_ia1[l + 1][col]);
        gotoligcol(l + 1,(col * 4) + 70 + 4);
        printf("%2c", mat_ia1[l + 1][col + 1]);
        SetConsoleTextAttribute(hConsole, 15);
        compteur_tour++;
    }
}
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
            mat_ia1[lig][col] = 'O';
            gotoligcol(lig, (col * 4) + 70);
            SetConsoleTextAttribute(hConsole, 9);
            printf("%2c", 'O');
            SetConsoleTextAttribute(hConsole, 15);
        }
        //Sinon, un navire est touché
        if (mat_ia1[lig][col] == 'P' || mat_ia1[lig][col] == 'C' || mat_ia1[lig][col] == 'D' || mat_ia1[lig][col] == 'S'){
            mat_ia1[lig][col] = 'X';
            gotoligcol(lig, (col * 4) + 70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("%2c", 'X');
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
}

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void choix_chargement_partie(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){

    //DDV
    int i;
    int j;
    int s;
    int B = 95;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //On efface l'ecran
    system("cls");
    affichage_matrices_fichiers(mat,mat_ia1);
    SetConsoleTextAttribute(hConsole, 11);
    //Chaque couple de grille se voit attribuer un numéro (1,2,3)
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

    gotoligcol(20, 70);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Which game do you want to load ?");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(21,70);
    printf("1. Game 1");
    gotoligcol(22, 70);
    printf("2. Game 2");
    gotoligcol(23, 70);
    printf("3. Game 3");
    gotoligcol(24, 70);
    printf("4. Main menu");
    gotoligcol(44, 95);
    printf("Copyright 2023 Battleship Alassane Wade");
    gotoligcol(25, 70);
    fflush(stdin);
    scanf("%d", &s);

    while (s != 1 && s != 2 && s != 3 && s != 4){
        gotoligcol(25,140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(25,70);
        fflush(stdin);
        scanf("%d", &s);
    }
    if (s == 1){
        //Affichage des decors
        system("cls");
        decors();
        decors1();

        //Message du debut du chargement
        gotoligcol(17,0);
        printf("Game loading in progress, please wait...\n");
        sleep(1);

        //Appel de la fonction de chargement chaque matrice à son fichier de chargement
        charger_partie1(mat_ia1);
        charger_partie(mat);
    }

    if (s == 2){
        //Affichage des decors
        system("cls");
        decors();
        decors1();

        //Message du debut du chargement
        gotoligcol(17,0);
        printf("Game loading in progress, please wait...\n");
        sleep(1);

        //Appel de la fonction de chargement chaque matrice à son fichier de chargement
        charger_partie2(mat_ia1);
        charger_partie1_0(mat);
    }

    if (s == 3){
        //Affichage des decors
        system("cls");
        decors();
        decors1();

        //Message du debut du chargement
        gotoligcol(17,0);
        printf("Game loading in progress, please wait...\n");
        sleep(1);

        //Appel de la fonction de chargement chaque matrice à son fichier de chargement
        charger_partie3(mat_ia1);
        charger_partie2_0(mat);
    }
    if (s == 4){
        //On efface l'écran
        system("cls");
        //On appel le menu principal
        menu(mat, mat_ia1, a , pseudo, choix, mat_bis,mat_ia1_bis);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void affichage_matrices_fichiers(unsigned char ** mat, unsigned char ** mat_ia1){

    //DDV
    int B = 95;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Initialisation de la matrice 1
    initialisation_matrice(mat,  mat_ia1);

    //Ouverture de tout les fichier comportant les grilles du joueur et de l'adversaire
    //Ouverture du fichier matrice J1
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
        gotoligcol(0, 0);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Game 1 :");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(1, 0);
        for (int i = 1 ; i < 16 ; i++){
            for (int j = 1 ;j < 16 ; j++){
                //On scan la matrice
                fscanf(fp0, "%2s", &mat[i][j]);
                printf("%2c", mat[i][j]);
            }
            printf("\n");
        }
        //Fermeture du fichier.
        fclose(fp0);
    }
    //Ouverture du fichier matrice adversaire
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
        for (int i = 1 ; i < 16 ; i++){
            gotoligcol(i,35);
            for (int j = 1 ;j < 16 ; j++){
                fscanf(fp1, "%2s", &mat_ia1[i][j]);
                if (mat_ia1[i][j] == 'X' || mat_ia1[i][j] == 'O'){
                    printf("%2c", mat_ia1[i][j]);
                }
                else {
                    printf("%2c", B);
                }
            }
        }
        //Fermeture fichier
        fclose(fp1);
    }

    initialisation_matrice(mat,  mat_ia1);
    FILE *fp2 = NULL;
    fp2 = fopen("bataille_navale2.0.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp2 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        gotoligcol(0, 80);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Game 2 :");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol (1, 80);
        for (int i = 1 ; i < 16 ; i++){
            gotoligcol(i, 80);
            for (int j = 1 ;j < 16 ; j++){
                //On scan la matrice
                fscanf(fp2, "%2s", &mat[i][j]);
                printf("%2c", mat[i][j]);
            }
        }
        //Fermeture du fichier.
        fclose(fp2);
    }

    //Ouverture du fichier matrice adversaire
    FILE *fp3 = NULL;
    fp3 = fopen("bataille_navale2.1.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp3 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        //On scan la matrice et on l'affiche si T ou O
        for (int i = 1 ; i < 16 ; i++){
            gotoligcol(i,115);
            for (int j = 1 ;j < 16 ; j++){
                fscanf(fp3, "%2s", &mat_ia1[i][j]);
                if (mat_ia1[i][j] == 'X' || mat_ia1[i][j] == 'O'){
                    printf("%2c", mat_ia1[i][j]);
                }
                else {
                    printf("%2c", B);
                }
            }
        }
        //Fermeture fichier
        fclose(fp3);
    }

    initialisation_matrice(mat,  mat_ia1);
    FILE *fp4 = NULL;
    fp4 = fopen("bataille_navale3.0.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp4 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        gotoligcol(0, 160);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Game 3 :");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol (1, 160);
        for (int i = 1 ; i < 16 ; i++){
            gotoligcol(i, 160);
            for (int j = 1 ;j < 16 ; j++){
                //On scan la matrice
                fscanf(fp4, "%2s", &mat[i][j]);
                printf("%2c", mat[i][j]);
            }
        }
        //Fermeture du fichier.
        fclose(fp4);
    }
    //Ouverture du fichier matrice adversaire
    FILE *fp5 = NULL;
    fp5 = fopen("bataille_navale3.1.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp5 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        //On scan la matrice et on l'affiche si T ou E
        for (int i = 1 ; i < 16 ; i++){
            gotoligcol(i,195);
            for (int j = 1 ;j < 16 ; j++){
                fscanf(fp5, "%2s", &mat_ia1[i][j]);
                if (mat_ia1[i][j] == 'X' || mat_ia1[i][j] == 'O'){
                    printf("%2c", mat_ia1[i][j]);
                }
                else {
                    printf("%2c", B);
                }
            }
        }
        //Fermeture fichier
        fclose(fp5);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sauvegarde_matrices(unsigned char ** mat, unsigned char ** mat_ia1,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){
    //DDV
    int i;
    int j;

    //Sauvegarde des matrices dans les matrices bis
    for (i = 1; i < 16; i++){
        for (j = 1; j < 16; j++){
            mat_bis[i][j] = mat[i][j];
            mat_ia1_bis[i][j] = mat_ia1[i][j];
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void chargement_matrices (unsigned char ** mat, unsigned char ** mat_ia1,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){
    //DDV
    int i;
    int j;

    //Sauvegarde des matrices dans les matrices bis
    for (i = 1; i < 16; i++){
        for (j = 1; j < 16; j++){
            mat[i][j] = mat_bis[i][j];
            mat_ia1[i][j] = mat_ia1_bis[i][j];
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sauvegarde(unsigned char ** mat, unsigned char ** mat_ia1, int *a, char *pseudo, int w,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){

    //DDV
    int i;
    int j;
    int choix = 0;
    int B = 95;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //On efface l'écran
    system("cls");

    //Sauvegarde des matrices dans les matrices bis
    sauvegarde_matrices(mat, mat_ia1,mat_bis, mat_ia1_bis);

    //Affichage des fichiers contenant les matrices de jeux
    affichage_matrices_fichiers(mat,mat_ia1);

    //Les matrices reprennent les valeurs des matrices bis
    chargement_matrices(mat,mat_ia1,mat_bis,mat_ia1_bis);
    SetConsoleTextAttribute(hConsole, 11);
    gotoligcol(28, 140);
    printf("           ,_:_,\n");
    gotoligcol(29, 140);
    printf("             |\n");
    gotoligcol(30, 140);
    printf("         -*T_##_:-\n");
    gotoligcol(31, 140);
    printf("        i____||____i\n");
    gotoligcol(32, 140);
    printf("       #|==========|@\n");
    gotoligcol(33, 140);
    printf("       -|==========|-\n");
    gotoligcol(34, 140);
    printf("        |          |\n");
    gotoligcol(35, 140);
    printf("        |_        _|\n");
    gotoligcol(36, 140);
    printf("        |          |\n");
    gotoligcol(37, 140);
    printf("     ______________________________________________________________\n");
    gotoligcol(38, 140);
    printf("    |___  __   |________________  USS WADE _____________|   __  ___|\n");
    gotoligcol(39, 140);
    printf("        l        '-,               -   -             ,-'        /\n");
    gotoligcol(40, 140);
    printf("          l         l        l      ___       /      /         /\n");
    gotoligcol(41, 140);
    printf("            l     (l  l       l____     ____/       /  /)     /\n");
    gotoligcol(42, 140);
    printf("              |    V   |           l---/           |   V     |\n");
    gotoligcol(43, 140);
    printf("              |        |             Y             |         |\n");
    SetConsoleTextAttribute(hConsole, 15);


    //Deamnde a l'utilisateur ou sauvegarder sa partie en cours
    gotoligcol(20, 70);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Where do you want to save the current game ?");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(21,70);
    printf("1. Over Game 1");
    gotoligcol(22, 70);
    printf("2. Over Game 2");
    gotoligcol(23, 70);
    printf("3. Over Game 3");
    gotoligcol(24, 70);
    printf("4. Back to the game");
    gotoligcol(44, 95);
    printf("Copyright 2023 Battleship Alassane Wade");
    gotoligcol(25, 70);
    fflush(stdin);
    scanf("%d", &choix);

    while (choix != 1 && choix != 2 && choix != 3 && choix != 4){
        gotoligcol(25,140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        fflush(stdin);
        gotoligcol(25, 70);
        scanf("%d", &choix);
    }

    //On efface l'écran
    system("cls");

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

    //Sauvegarder partie dans l'endroit indiqué
    if (choix == 1){
        sauvegarder_partie(mat, choix);
        sauvegarder_partie1(mat_ia1, choix);
        //Revenir à la partie en cours

        //Affichage des deux matrices
        gotoligcol(0, 0);
        decors();
        decors1();
        //Afficher les matrices dans les grilles
        //Matrice IA
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
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

        //Matrice joueur 1
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
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
                if (mat[i][j] == 'O'){
                    gotoligcol(i, (j * 4 ));
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }
        }

        //Appel de la fonction de jeux
        jouer(mat, mat_ia1, a, pseudo,w, choix, mat_bis,mat_ia1_bis);
    }
    if (choix == 2){
        sauvegarder_partie(mat, choix);
        sauvegarder_partie1(mat_ia1, choix);
        //Revenir à la partie en cours
        //Affichage des deux matrices

        gotoligcol(0, 0);
        decors();
        decors1();
        //Afficher les matrices dans les grilles
        //Matrice IA
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
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

        //Matrice joueur 1
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
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

        //Appel de la fonction de jeux
        jouer(mat, mat_ia1, a, pseudo,w, choix, mat_bis,mat_ia1_bis);
    }
    if (choix == 3){
        sauvegarder_partie(mat, choix);
        sauvegarder_partie1(mat_ia1, choix);
        //Revenir à la partie en cours
        //Affichage des deux matrices
        gotoligcol(0, 0);
        decors();
        decors1();
        //Afficher les matrices dans les grilles
        //Matrice IA
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
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

        //Matrice joueur 1
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
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

        //Appel de la fonction de jeux
        jouer(mat, mat_ia1, a, pseudo,w, choix, mat_bis,mat_ia1_bis);
    }
    if (choix == 4){
        //Revenir à la partie en cours
        //Affichage des deux matrices
        gotoligcol(0, 0);
        decors();
        decors1();

        //Afficher les matrices dans les grilles
        //Matrice IA
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
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

        //Matrice joueur 1
        for (i = 1 ; i < 16 ; i++){
            for (j = 1 ;j < 16 ; j++){
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
                if (mat[i][j] == 'O'){
                    gotoligcol(i, (j * 4 ));
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }
        }
        //Appel de la fonction de jeux
        jouer(mat, mat_ia1, a, pseudo,w, choix, mat_bis,mat_ia1_bis);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sauvegarder_partie(unsigned char ** mat, int choix){

    //Définition des variables
    int i;
    int j;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Ce sspg sauvegarde la matrice du joueur dans le fichier fp
    //Ouverture d'un fichier

    if (choix == 1){

        FILE *fp0 = NULL;
        fp0 = fopen("bataille_navale1.0.txt", "w");

        //Gestions des erreurs d'ouverture du fichier
        if (fp0 == NULL) {
            gotoligcol(48,70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error. File opening problem.\n");
            SetConsoleTextAttribute(hConsole, 15);
        }

        else {
            //Affichage de la matrice
            for (i = 1; i < 16; i++){
                for (j = 1; j < 16; j++){
                    //On print la matrice dans le fichier
                    fprintf(fp0,"%2c", mat[i][j]);
                }
                //Retour à la ligne
                fprintf(fp0, "\n");
            }
            //Fermeture ficjhier
            fclose(fp0);
        }
    }
    if (choix == 2){

        FILE *fp2 = NULL;
        fp2 = fopen("bataille_navale2.0.txt", "w");

        //Gestions des erreurs d'ouverture du fichier
        if (fp2 == NULL) {
            gotoligcol(48,70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error. File opening problem.\n");
            SetConsoleTextAttribute(hConsole, 15);
        }

        else {
            //Affichage de la matrice
            for (i = 1; i < 16; i++){
                for (j = 1; j < 16; j++){
                    //On print la matrice dans le fichier
                    fprintf(fp2,"%2c", mat[i][j]);
                }
                //Retour à la ligne
                fprintf(fp2, "\n");
            }
            //Fermeture ficjhier
            fclose(fp2);
        }
    }
    if (choix == 3){

        FILE *fp4 = NULL;
        fp4 = fopen("bataille_navale3.0.txt", "w");

        //Gestions des erreurs d'ouverture du fichier
        if (fp4 == NULL) {
            gotoligcol(48,70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error. File opening problem.\n");
            SetConsoleTextAttribute(hConsole, 15);
        }

        else {
            //Affichage de la matrice
            for (i = 1; i < 16; i++){
                for (j = 1; j < 16; j++){
                    //On print la matrice dans le fichier
                    fprintf(fp4,"%2c", mat[i][j]);
                }
                //Retour à la ligne
                fprintf(fp4, "\n");
            }
            //Fermeture ficjhier
            fclose(fp4);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sauvegarder_partie1(unsigned char ** mat_ia1, int choix){

    //Définition des variables
    int i;
    int j;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Ce sspg sauvegarde la matrice de l'IA dans le fichier fp1
    //Ouverture d'un fichier
    if (choix == 1){
        FILE *fp1 = NULL;
        fp1 = fopen("bataille_navale1.1.txt", "w");

        //Gestions des erreurs d'ouverture du fichier
        if (fp1 == NULL) {
            gotoligcol(48,70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error. File opening problem.\n");
            SetConsoleTextAttribute(hConsole, 15);
        }

        else {
            //Affichage de la matrice
            for (i = 1; i < 16; i++){
                for (j = 1; j < 16; j++){
                    //Sauvegarde de la matrice dans le fichier
                    fprintf(fp1,"%2c", mat_ia1[i][j]);
                }
                //Retour à la ligne
                fprintf(fp1, "\n");
            }
            //Fermeture fichier
            fclose(fp1);
        }
    }
    if (choix == 2){

        FILE *fp3 = NULL;
        fp3 = fopen("bataille_navale2.1.txt", "w");

        //Gestions des erreurs d'ouverture du fichier
        if (fp3 == NULL) {
            gotoligcol(48,70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error. File opening problem.\n");
            SetConsoleTextAttribute(hConsole, 15);
        }

        else {
            //Affichage de la matrice
            for (i = 1; i < 16; i++){
                for (j = 1; j < 16; j++){
                    //Sauvegarde de la matrice dans le fichier
                    fprintf(fp3,"%2c", mat_ia1[i][j]);
                }
                //Retour à la ligne
                fprintf(fp3, "\n");
            }
            //Fermeture fichier
            fclose(fp3);
        }
    }
    if (choix == 3){

        FILE *fp5 = NULL;
        fp5 = fopen("bataille_navale3.1.txt", "w");

        //Gestions des erreurs d'ouverture du fichier
        if (fp5 == NULL) {
            gotoligcol(48,70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error. File opening problem.\n");
            SetConsoleTextAttribute(hConsole, 15);
        }
        else {
            //Affichage de la matrice
            for (i = 1; i < 16; i++){
                for (j = 1; j < 16; j++){
                    //Sauvegarde de la matrice dans le fichier
                    fprintf(fp5,"%2c", mat_ia1[i][j]);
                }
                //Retour à la ligne
                fprintf(fp5, "\n");
            }
            //Fermeture fichier
            fclose(fp5);
        }
    }
}

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
        printf("Loading completed !\n");
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
        printf("Loading completed !\n");
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
        printf("Loading completed !\n");
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

int vainqueur_joueur(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){

    //Clear l'écran
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    gotoligcol(1, 30);
    //Affichage de la victoire du joueur
    printf("//////////////////////////////////////////// Y O U  W I N !////////////////////////////////////////////");
    gotoligcol(3, 70);
    printf("%s won the battle", pseudo);

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
    system("cls");
    //Appel du Menu Principale
    menu(mat,mat_ia1, a, pseudo, choix, mat_bis,mat_ia1_bis);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int vainqueur_ia(unsigned char ** mat,unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){

    //Clear de l'écran
    system("cls");
    gotoligcol(1, 30);
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //Affichage de la défaite du joueur
    SetConsoleTextAttribute(hConsole, 11);
    printf("//////////////////////////////////////////// Y O U  L O S E !//////////////////////////////////////////");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(3, 70);
    printf("%s lost the battle", pseudo);

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
    system("cls");
    //Appel du Menu Principale
    menu(mat, mat_ia1, a, pseudo, choix, mat_bis,mat_ia1_bis);
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////