
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
    printf("//////////////////////////////////////////// Y O U  W I N !////////////////////////////////////////////");
    gotoligcol(3, 70);
    printf("%s won the battle", pseudo);

    SetConsoleTextAttribute(hConsole, 11);
    gotoligcol(8, 125);
    printf("                                 __..||..__\n");
    gotoligcol(9, 125);
    printf("                             -==|__.----.__|==-\n");
    gotoligcol(10, 125);
    printf("                                 __l|  |/__\n");
    gotoligcol(11, 125);
    printf("                            --==|__.----.__|==--\n");
    gotoligcol(12, 125);
    printf("                                __/       l__\n");
    gotoligcol(13, 125);
    printf("                            __'{             }'__\n");
    gotoligcol(14, 125);
    printf("                       ___'{  ! 8     8     8 !  }'___\n");
    gotoligcol(15, 125);
    printf("                 ====={                               }=====\n");
    gotoligcol(16, 125);
    printf("                _____________________________________________\n");
    gotoligcol(17, 125);
    printf("               |             /   .  -- . --  .  l            |\n");
    gotoligcol(18, 125);
    printf("               | '--_______/    +      !      +   l______--' |\n");
    gotoligcol(19, 125);
    printf("               |                !             !              |\n");
    gotoligcol(20, 125);
    printf("               |                                             |\n");
    gotoligcol(21, 125);
    printf("                 l                     |                     /");
    gotoligcol(22, 125);
    printf("                  l_                   |                  _/");
    gotoligcol(23, 125);
    printf("                     l_                |               _/");
    gotoligcol(24, 125);
    printf("                        l_             |            _/");
    gotoligcol(25, 125);
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
    gotoligcol(8, 125);
    printf("                                 __..||..__\n");
    gotoligcol(9, 125);
    printf("                             -==|__.----.__|==-\n");
    gotoligcol(10, 125);
    printf("                                 __l|  |/__\n");
    gotoligcol(11, 125);
    printf("                            --==|__.----.__|==--\n");
    gotoligcol(12, 125);
    printf("                                __/       l__\n");
    gotoligcol(13, 125);
    printf("                            __'{             }'__\n");
    gotoligcol(14, 125);
    printf("                       ___'{  ! 8     8     8 !  }'___\n");
    gotoligcol(15, 125);
    printf("                 ====={                               }=====\n");
    gotoligcol(16, 125);
    printf("                _____________________________________________\n");
    gotoligcol(17, 125);
    printf("               |             /   .  -- . --  .  l            |\n");
    gotoligcol(18, 125);
    printf("               | '--_______/    +      !      +   l______--' |\n");
    gotoligcol(19, 125);
    printf("               |                !             !              |\n");
    gotoligcol(20, 125);
    printf("               |                                             |\n");
    gotoligcol(21, 125);
    printf("                 l                     |                     /");
    gotoligcol(22, 125);
    printf("                  l_                   |                  _/");
    gotoligcol(23, 125);
    printf("                     l_                |               _/");
    gotoligcol(24, 125);
    printf("                        l_             |            _/");
    gotoligcol(25, 125);
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

    gotoligcol(44, 70);
    printf("Copyright 2023 Battleship Alassane Wade");

    sleep(6);
    system("cls");
    //Appel du Menu Principale
    menu(mat, mat_ia1, a, pseudo, choix, mat_bis,mat_ia1_bis);
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////