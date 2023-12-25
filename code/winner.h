#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int vainqueur_joueur(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis){

    //Clear l'écran
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    gotoligcol(1, 30);
    //Affichage de la victoire du joueur
    SetConsoleTextAttribute(hConsole, 11);
    printf("//////////////////////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("Y O U  W I N !");
    SetConsoleTextAttribute(hConsole, 11);
    printf(" ////////////////////////////////////////////");
    gotoligcol(3, 70);
    printf("%s wins the battle !", pseudo);

    boats_decoration_winner();

    gotoligcol(44, 70);
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
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //Affichage de la défaite du joueur
    gotoligcol(1, 30);
    SetConsoleTextAttribute(hConsole, 11);
    printf("//////////////////////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("Y O U  L O O S E !");
    SetConsoleTextAttribute(hConsole, 11);
    printf(" ////////////////////////////////////////////");
    gotoligcol(3, 70);
    printf("%s lost the battle...", pseudo);
    
    boats_decoration_winner();
    
    gotoligcol(44, 70);
    printf("Copyright 2023 Battleship Alassane Wade");

    sleep(6);
    system("cls");
    //Appel du Menu Principale
    menu(mat, mat_ia1, a, pseudo, choix, mat_bis,mat_ia1_bis);
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////