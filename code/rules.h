#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void rules(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis)
{
    int w;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Affichage des regles
    gotoligcol(1, 60);
    SetConsoleTextAttribute(hConsole, 11);
    printf("///////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("R U L E S");
    SetConsoleTextAttribute(hConsole, 11);
    printf(" /////////////////////////////");
    gotoligcol(5, 0);
    printf("Before playing, here are some explanations about the rules of the game:");
    SetConsoleTextAttribute(hConsole, 15);
    printf("\nAt the start of the game, Player 1 randomly or manually places all its boats on its\n"
           "grid.\n"
           "Of course, Player 1 doesn't see AI's grid.\n"
           "Once all the boats are in play, the game can begin... One by one, Player 1 and AI fire\n" 
           "to destroy enemy boats.\n\n");
    SetConsoleTextAttribute(hConsole, 11);
    printf("Example:\n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("Player 1 fire in (h,7), corresponding to the square of the enemy's grid at the crossing\n" 
           "of the row 'h' and the column '7'.\n"
           "If Player 1 or AI fire at an enemy boat, the letter 'X' will appear on the hit space.\n"
           "The shooter can play twice in a row to attempt to hit the enemy once more.\n"
           "If Player 1 or AI does not hit a boat, the letter 'O' will appear on the failed space.\n\n"
           "The 'X' and 'O' marks are used to remember missed shots ('O') and hits ('X').\n"
           "It is essential to use them so as not to shoot twice at the same place.\n"
           "A Battleship game ends when one of the players has no more ships on it's grid.\n\n"
           "Each turn, Player 1 can either fire into the enemy's grid, activate air support which\n" 
           "fires 5 shots in the\n"
           "enemy's grid or launch a flare wich illuminates a small part of the enemy's grid.\n"
           "He has the possibility in one turn to save the current game, activate satellite view\n"
           "wich reveal\n"
           "the enemy grid for a short period and return to the main menu.\n");
    SetConsoleTextAttribute(hConsole, 11);
    printf("\nHere are the boats you can place:\n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("Aircraft Carrier, Cruiser, Destroyer and Submarine.\n"
           "- 1 Aircraft Carrier with symbol P takes 7 spaces.\n"
           "- 2 Cruisers with symbol C takes 5 spaces.\n"
           "- 3 Destroyers with symbol D takes 3 spaces.\n"
           "- 4 Submarines with symbol S takes 1 space.");
    SetConsoleTextAttribute(hConsole, 11);

    boat_decoration_rules();

    gotoligcol(44, 70);
    printf("Copyright 2023 Battleship Alassane Wade");

    gotoligcol(37, 0);
    // Appel du menu
    SetConsoleTextAttribute(hConsole, 11);
    printf("Main menu: \n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("1. Yes\n");
    scanf("%d", &w);
    while (w != 1)
    {
        gotoligcol(42, 0);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(39, 0);
        printf("  ");
        gotoligcol(39, 0);
        fflush(stdin);
        scanf("%d", &w);
    }
    if (w == 1)
    {
        system("cls");
        menu(mat, mat_ia1, a, pseudo, choix, mat_bis, mat_ia1_bis);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////