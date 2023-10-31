
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>


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