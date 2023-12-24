
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tir_aerien(unsigned char ** mat_ia1){

    //Variables Definitions
    int i;
    int lig;
    int col;
    int B = 95;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    srand(time(NULL));
    //5 random shots are made
    for (i = 0; i < 5; i ++){
        //Random choice of lig and col values
        lig = rand() % (15) + 1;
        col = rand() % (15) + 1;

        //If shot missed
        if (mat_ia1[lig][col] == B) {
            //Display 'O' in the (lig,col)
            mat_ia1[lig][col] = 'O';
            gotoligcol(lig, (col * 4) + 70);
            SetConsoleTextAttribute(hConsole, 9);
            printf("%2c", 'O');
            SetConsoleTextAttribute(hConsole, 15);
        }
        //Else shot touched a ship
        if (mat_ia1[lig][col] == 'P' || mat_ia1[lig][col] == 'C' || mat_ia1[lig][col] == 'D' || mat_ia1[lig][col] == 'S'){
            //Display 'X' in the (lig,col)
            mat_ia1[lig][col] = 'X';
            gotoligcol(lig, (col * 4) + 70);
            SetConsoleTextAttribute(hConsole, 12);
            printf("%2c", 'X');
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////