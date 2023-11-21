#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void boat_decoration_main(){

    int choix;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void boat_decoration_rules(){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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
        SetConsoleTextAttribute(hConsole, 15);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void boat_decoration_load(){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(hConsole, 11);
        gotoligcol(28, 125);
        printf("                                 __..||..__\n");
        gotoligcol(29, 125);
        printf("                             -==|__.----.__|==-\n");
        gotoligcol(30, 125);
        printf("                                 __l|  |/__\n");
        gotoligcol(31, 125);
        printf("                            --==|__.----.__|==--\n");
        gotoligcol(32, 125);
        printf("                                __/       l__\n");
        gotoligcol(33, 125);
        printf("                            __'{             }'__\n");
        gotoligcol(34, 125);
        printf("                       ___'{  ! 8     8     8 !  }'___\n");
        gotoligcol(35, 125);
        printf("                 ====={                               }=====\n");
        gotoligcol(36, 125);
        printf("                _____________________________________________\n");
        gotoligcol(37, 125);
        printf("               |             /   .  -- . --  .  l            |\n");
        gotoligcol(38, 125);
        printf("               | '--_______/    +      !      +   l______--' |\n");
        gotoligcol(39, 125);
        printf("               |                !             !              |\n");
        gotoligcol(40, 125);
        printf("               |                                             |\n");
        gotoligcol(41, 125);
        printf("                 l                     |                     /");
        gotoligcol(42, 125);
        printf("                  l_                   |                  _/");
        gotoligcol(43, 125);
        printf("                     l_                |               _/");
        gotoligcol(44, 125);
        printf("                        l_             |            _/");
        gotoligcol(45, 125);
        printf("                           l_          |         _/");
        SetConsoleTextAttribute(hConsole, 15);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void boat_decoration_menu(){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 11);
    gotoligcol(9, 125);
    printf("           ,_:_,\n");
    gotoligcol(10, 125);
    printf("             |\n");
    gotoligcol(11, 125);
    printf("         -*T_##_:-\n");
    gotoligcol(12, 125);
    printf("        i____||____i\n");
    gotoligcol(13, 125);
    printf("       #|==========|@\n");
    gotoligcol(14, 125);
    printf("       -|==========|-\n");
    gotoligcol(15, 125);
    printf("        |          |\n");
    gotoligcol(16, 125);
    printf("        |_        _|\n");
    gotoligcol(17, 125);
    printf("        |          |\n");
    gotoligcol(18, 125);
    printf("     ______________________________________________________________\n");
    gotoligcol(19, 125);
    printf("    |___  __   |________________  USS WADE _____________|   __ ___|\n");
    gotoligcol(20, 125);
    printf("        l        '-,               -   -             ,-'        /\n");
    gotoligcol(21, 125);
    printf("          l         l        l      ___       /      /         /\n");
    gotoligcol(22, 125);
    printf("            l     (l  l       l____     ____/       /  /)     /\n");
    gotoligcol(23, 125);
    printf("              |    V   |           l---/           |   V     |\n");
    gotoligcol(24, 125);
    printf("              |        |             Y             |         |\n");
    SetConsoleTextAttribute(hConsole, 15);
    
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void boats_decoration_exit(){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
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

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void boats_decoration_winner(){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
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

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
void boats_decoration_save1(){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoligcol(28, 125);
    printf("           ,_:_,\n");
    gotoligcol(29, 125);
    printf("             |\n");
    gotoligcol(30, 125);
    printf("         -*T_##_:-\n");
    gotoligcol(31, 125);
    printf("        i____||____i\n");
    gotoligcol(32, 125);
    printf("       #|==========|@\n");
    gotoligcol(33, 125);
    printf("       -|==========|-\n");
    gotoligcol(34, 125);
    printf("        |          |\n");
    gotoligcol(35, 125);
    printf("        |_        _|\n");
    gotoligcol(36, 125);
    printf("        |          |\n");
    gotoligcol(37, 125);
    printf("     ______________________________________________________________\n");
    gotoligcol(38, 125);
    printf("    |___  __   |________________  USS WADE _____________|  __  ___|\n");
    gotoligcol(39, 125);
    printf("        l        '-,               -   -             ,-'        /\n");
    gotoligcol(40, 125);
    printf("          l         l        l      ___       /      /         /\n");
    gotoligcol(41, 125);
    printf("            l     (l  l       l____     ____/       /  /)     /\n");
    gotoligcol(42, 125);
    printf("              |    V   |           l---/           |   V     |\n");
    gotoligcol(43, 125);
    printf("              |        |             Y             |         |\n");
    SetConsoleTextAttribute(hConsole, 15);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void boats_decoration_save2(){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleTextAttribute(hConsole, 11);
    gotoligcol(28, 125);
    printf("                                 __..||..__\n");
    gotoligcol(29, 125);
    printf("                             -==|__.----.__|==-\n");
    gotoligcol(30, 125);
    printf("                                 __l|  |/__\n");
    gotoligcol(31, 125);
    printf("                            --==|__.----.__|==--\n");
    gotoligcol(32, 125);
    printf("                                __/       l__\n");
    gotoligcol(33, 125);
    printf("                            __'{             }'__\n");
    gotoligcol(34, 125);
    printf("                       ___'{  ! 8     8     8 !  }'___\n");
    gotoligcol(35, 125);
    printf("                 ====={                               }=====\n");
    gotoligcol(36, 125);
    printf("                _____________________________________________\n");
    gotoligcol(37, 125);
    printf("               |             /   .  -- . --  .  l            |\n");
    gotoligcol(38, 125);
    printf("               | '--_______/    +      !      +   l______--' |\n");
    gotoligcol(39, 125);
    printf("               |                !             !              |\n");
    gotoligcol(40, 125);
    printf("               |                                             |\n");
    gotoligcol(41, 125);
    printf("                 l                     |                     /");
    gotoligcol(42, 125);
    printf("                  l_                   |                  _/");
    gotoligcol(43, 125);
    printf("                     l_                |               _/");
    gotoligcol(44, 125);
    printf("                        l_             |            _/");
    gotoligcol(45, 125);
    printf("                           l_          |         _/");
    SetConsoleTextAttribute(hConsole, 15);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
