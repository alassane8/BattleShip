#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void decors(){

    //Variables Definitions
    int i;
    int j;
    int k = 65;

    //Grid setup
    for (i = 0; i < 16; i++){
        for (j = 0; j < 16; j++){
            if (i == 0 && j > 0){
                printf("%2d |",j);
            }
            else if(j == 0 && i > 0){
                printf("\n");
                printf("%2c |", k);
                k ++;
            }
            else{
                printf("%2c |",' ');
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void decors1(){

    //Variables Definitions
    int a;
    int b;

    //Grid setup
    for (a = 0; a < 16; a++){
        gotoligcol(a,70);
        for (b = 0; b < 16; b++){
            if (a == 0 && b > 0){
                printf("%2d |",b);
            }
            else if(b == 0 && a > 0){
                printf("%2c |", a + 'a' - 1);
            }
            else{
                printf("%2c |",' ');
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////