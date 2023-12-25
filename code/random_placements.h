#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void placement_bateaux_aleatoire(unsigned char **mat)
{

    // Définitions des variables
    int P = 1;
    int C = 1;
    int D = 1;
    int S = 1;
    int z;
    int lig;
    int col;
    int B = 95;
    int direction;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    do
    {
        lig = rand() % (15) + 1;
        col = rand() % (15) + 1;
    } while (mat[lig][col] != B);

    mat[lig][col] = 'P';

    gotoligcol(lig, col * 4);
    SetConsoleTextAttribute(hConsole, 10);
    printf("%2c", 'P');

    direction = rand() % (4) + 1;

    while (direction == 1 && col - 6 < 1)
    {
        direction = rand() % (4) + 1;
    }
    while (direction == 2 && col + 6 > 15)
    {
        direction = rand() % 5;
    }
    for (z = 1; z < 7; z++)
    {
        while ((direction == 1 && mat[lig][col - z] != B) || (direction == 2 && mat[lig][col + z] != B))
        {
            direction = rand() % (4) + 1;
        }
    }
    while (direction == 3 && lig - 6 < 1)
    {
        direction = rand() % (4) + 1;
    }
    while (direction == 4 && lig + 6 > 15)
    {
        direction = rand() % (4) + 1;
    }
    for (z = 1; z < 7; z++)
    {
        while ((direction == 3 && mat[lig - z][col] != B) || (direction == 4 && mat[lig + z][col] != B))
        {
            direction = rand() % (4) + 1;
        }
    }

    // Si vers la gauche
    if (direction == 1 && col - 6 >= 1)
    {
        for (z = 1; z < 7; z++)
        {
            mat[lig][col - z] = 'P';
            gotoligcol(lig, ((col - z) * 4));
            SetConsoleTextAttribute(hConsole, 10);
            printf("%2c", 'P');
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
    // Si vers la droite
    if (direction == 2 && col + 6 <= 15)
    {
        for (z = 1; z < 7; z++)
        {
            mat[lig][col + z] = 'P';
            gotoligcol(lig, ((col + z) * 4));
            SetConsoleTextAttribute(hConsole, 10);
            printf("%2c", 'P');
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
    // Si vers le haut
    if (direction == 3 && lig - 6 >= 1)
    {
        for (z = 1; z < 7; z++)
        {
            mat[lig - z][col] = 'P';
            gotoligcol(lig - z, col * 4);
            SetConsoleTextAttribute(hConsole, 10);
            printf("%2c", 'P');
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
    // Si vers le bas
    if (direction == 4 && lig + 6 <= 15)
    {
        for (z = 1; z < 7; z++)
        {
            mat[lig + z][col] = 'P';
            gotoligcol(lig + z, col * 4);
            SetConsoleTextAttribute(hConsole, 10);
            printf("%2c", 'P');
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
    P++;

    while (C < 3)
    {
        do
        {
            lig = rand() % (15) + 1;
            col = rand() % (15) + 1;
        } while (mat[lig][col] != B);

        mat[lig][col] = 'C';

        gotoligcol(lig, col * 4);
        SetConsoleTextAttribute(hConsole, 10);
        printf("%2c", 'C');

        direction = rand() % (4) + 1;

        while ((direction == 1 && col - 4 < 1) || (direction == 2 && col + 4 > 15))
        {
            direction = rand() % (4) + 1;
        }
        for (z = 1; z < 5; z++)
        {
            while ((direction == 1 && mat[lig][col - z] != B) || (direction == 2 && mat[lig][col + z] != B))
            {
                direction = rand() % (4) + 1;
            }
        }
        while ((direction == 3 && lig - 4 < 1) || (direction == 4 && lig + 4 > 15))
        {
            direction = rand() % (4) + 1;
        }
        for (z = 1; z < 5; z++)
        {
            while ((direction == 3 && mat[lig - z][col] != B) || (direction == 4 && mat[lig + z][col] != B))
            {
                direction = rand() % (4) + 1;
            }
        }

        // Si vers la gauche
        if (direction == 1 && col - 4 >= 1)
        {
            for (z = 1; z < 5; z++)
            {
                mat[lig][col - z] = 'C';
                gotoligcol(lig, ((col - z) * 4));
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'C');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        // Si vers la droite
        if (direction == 2 && col + 4 <= 15)
        {
            for (z = 1; z < 5; z++)
            {
                mat[lig][col + z] = 'C';
                gotoligcol(lig, ((col + z) * 4));
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'C');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        // Si vers le haut
        if (direction == 3 && lig - 4 >= 1)
        {
            for (z = 1; z < 5; z++)
            {
                mat[lig - z][col] = 'C';
                gotoligcol(lig - z, col * 4);
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'C');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        // Si vers le bas
        if (direction == 4 && lig + 4 <= 15)
        {
            for (z = 1; z < 5; z++)
            {
                mat[lig + z][col] = 'C';
                gotoligcol(lig + z, col * 4);
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'C');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        C++;
    }

    while (D < 4)
    {
        do
        {
            lig = rand() % (15) + 1;
            col = rand() % (15) + 1;
        } while (mat[lig][col] != B);

        mat[lig][col] = 'D';

        gotoligcol(lig, col * 4);
        SetConsoleTextAttribute(hConsole, 10);
        printf("%2c", 'D');

        direction = rand() % (4) + 1;

        while (direction == 1 && col - 2 < 1)
        {
            direction = rand() % (4) + 1;
        }
        while (direction == 2 && col + 2 > 15)
        {
            direction = rand() % (4) + 1;
        }
        for (z = 1; z < 3; z++)
        {
            while ((direction == 1 && mat[lig][col - z] != B) || (direction == 2 && mat[lig][col + z] != B))
            {
                direction = rand() % (4) + 1;
            }
        }
        while (direction == 3 && lig - 2 < 1)
        {
            direction = rand() % (4) + 1;
        }
        while (direction == 4 && lig + 2 > 15)
        {
            direction = rand() % (4) + 1;
        }
        for (z = 1; z < 3; z++)
        {
            while ((direction == 3 && mat[lig - z][col] != B) || (direction == 4 && mat[lig + z][col] != B))
            {
                direction = rand() % (4) + 1;
            }
        }

        // Si vers la gauche
        if (direction == 1 && col - 2 >= 1)
        {
            for (z = 1; z < 3; z++)
            {
                mat[lig][col - z] = 'D';
                gotoligcol(lig, ((col - z) * 4));
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'D');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        // Si vers la droite
        if (direction == 2 && col + 2 <= 15)
        {
            for (z = 1; z < 3; z++)
            {
                mat[lig][col + z] = 'D';
                gotoligcol(lig, ((col + z) * 4));
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'D');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        // Si vers le haut
        if (direction == 3 && lig - 2 >= 1)
        {
            for (z = 1; z < 3; z++)
            {
                mat[lig - z][col] = 'D';
                gotoligcol(lig - z, col * 4);
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'D');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        // Si vers le bas
        if (direction == 4 && lig + 2 <= 15)
        {
            for (z = 1; z < 3; z++)
            {
                mat[lig + z][col] = 'D';
                gotoligcol(lig + z, col * 4);
                SetConsoleTextAttribute(hConsole, 10);
                printf("%2c", 'D');
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        D++;
    }
    while (S < 5)
    {
        srand(time(NULL));
        do
        {
            lig = rand() % (15) + 1;
            col = rand() % (15) + 1;
        } while (mat[lig][col] != B);

        mat[lig][col] = 'S';
        gotoligcol(lig, col * 4);
        SetConsoleTextAttribute(hConsole, 10);
        printf("%2c", 'S');
        SetConsoleTextAttribute(hConsole, 15);
        S++;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void placement_bateaux_aleatoire1(unsigned char **mat_ia1)
{

    // Définitions des variables
    int P = 1;
    int C = 1;
    int D = 1;
    int S = 1;
    int z;
    int lig;
    int col;
    int B = 95;
    int direction;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    srand(time(NULL));
    do
    {
        lig = rand() % (15) + 1;
        col = rand() % (15) + 1;
    } while (mat_ia1[lig][col] != B);

    mat_ia1[lig][col] = 'P';

    direction = rand() % (4) + 1;

    while (direction == 1 && col - 6 < 1)
    {
        direction = rand() % (4) + 1;
    }
    while (direction == 2 && col + 6 > 15)
    {
        direction = rand() % (4) + 1;
    }
    for (z = 1; z < 7; z++)
    {
        while ((direction == 1 && mat_ia1[lig][col - z] != B) || (direction == 2 && mat_ia1[lig][col + z] != B))
        {
            direction = rand() % (4) + 1;
        }
    }
    while (direction == 3 && lig - 6 < 1)
    {
        direction = rand() % (4) + 1;
    }
    while (direction == 4 && lig + 6 > 15)
    {
        direction = rand() % (4) + 1;
    }
    for (z = 1; z < 7; z++)
    {
        while ((direction == 3 && mat_ia1[lig - z][col] != B) || (direction == 4 && mat_ia1[lig + z][col] != B))
        {
            direction = rand() % (4) + 1;
        }
    }

    // Si vers la gauche
    if (direction == 1 && col - 6 >= 1)
    {
        for (z = 1; z < 7; z++)
        {
            mat_ia1[lig][col - z] = 'P';
        }
    }
    // Si vers la droite
    if (direction == 2 && col + 6 <= 15)
    {
        for (z = 1; z < 7; z++)
        {
            mat_ia1[lig][col + z] = 'P';
        }
    }
    // Si vers le haut
    if (direction == 3 && lig - 6 >= 1)
    {
        for (z = 1; z < 7; z++)
        {
            mat_ia1[lig - z][col] = 'P';
        }
    }
    // Si vers le bas
    if (direction == 4 && lig + 6 <= 15)
    {
        for (z = 1; z < 7; z++)
        {
            mat_ia1[lig + z][col] = 'P';
        }
    }
    P++;

    while (C < 3)
    {
        srand(time(NULL));
        do
        {
            lig = rand() % (15) + 1;
            col = rand() % (15) + 1;
        } while (mat_ia1[lig][col] != B);

        mat_ia1[lig][col] = 'C';

        direction = rand() % (4) + 1;

        while (direction == 1 && col - 4 < 1)
        {
            direction = rand() % (4) + 1;
        }
        while (direction == 2 && col + 4 > 15)
        {
            direction = rand() % (4) + 1;
        }
        for (z = 1; z < 5; z++)
        {
            while ((direction == 1 && mat_ia1[lig][col - z] != B) || (direction == 2 && mat_ia1[lig][col + z] != B))
            {
                direction = rand() % (4) + 1;
            }
        }
        while (direction == 3 && lig - 4 < 1)
        {
            direction = rand() % (4) + 1;
        }
        while (direction == 4 && lig + 4 > 15)
        {
            direction = rand() % (4) + 1;
        }
        for (z = 1; z < 5; z++)
        {
            while ((direction == 3 && mat_ia1[lig - z][col] != B) || (direction == 4 && mat_ia1[lig + z][col] != B))
            {
                direction = rand() % (4) + 1;
            }
        }

        // Si vers la gauche
        if (direction == 1 && col - 4 >= 1)
        {
            for (z = 1; z < 5; z++)
            {
                mat_ia1[lig][col - z] = 'C';
            }
        }
        // Si vers la droite
        if (direction == 2 && col + 4 <= 15)
        {
            for (z = 1; z < 5; z++)
            {
                mat_ia1[lig][col + z] = 'C';
            }
        }
        // Si vers le haut
        if (direction == 3 && lig - 4 >= 1)
        {
            for (z = 1; z < 5; z++)
            {
                mat_ia1[lig - z][col] = 'C';
            }
        }
        // Si vers le bas
        if (direction == 4 && lig + 4 <= 15)
        {
            for (z = 1; z < 5; z++)
            {
                mat_ia1[lig + z][col] = 'C';
            }
        }
        C++;
    }

    while (D < 4)
    {
        srand(time(NULL));
        do
        {
            lig = rand() % (15) + 1;
            col = rand() % (15) + 1;
        } while (mat_ia1[lig][col] != B);

        mat_ia1[lig][col] = 'D';

        direction = rand() % (4) + 1;

        while (direction == 1 && col - 2 < 1)
        {
            direction = rand() % (4) + 1;
        }
        while (direction == 2 && col + 2 > 15)
        {
            direction = rand() % (4) + 1;
        }
        for (z = 1; z < 3; z++)
        {
            while ((direction == 1 && mat_ia1[lig][col - z] != B) || (direction == 2 && mat_ia1[lig][col + z] != B))
            {
                direction = rand() % (4) + 1;
            }
        }
        while (direction == 3 && lig - 2 < 1)
        {
            direction = rand() % (4) + 1;
        }
        while (direction == 4 && lig + 2 > 15)
        {
            direction = rand() % (4) + 1;
        }
        for (z = 1; z < 3; z++)
        {
            while ((direction == 3 && mat_ia1[lig - z][col] != B) || (direction == 4 && mat_ia1[lig + z][col] != B))
            {
                direction = rand() % (4) + 1;
            }
        }

        // Si vers la gauche
        if (direction == 1 && col - 2 >= 1)
        {
            for (z = 1; z < 3; z++)
            {
                mat_ia1[lig][col - z] = 'D';
            }
        }
        // Si vers la droite
        if (direction == 2 && col + 2 <= 15)
        {
            for (z = 1; z < 3; z++)
            {
                mat_ia1[lig][col + z] = 'D';
            }
        }
        // Si vers le haut
        if (direction == 3 && lig - 2 >= 1)
        {
            for (z = 1; z < 3; z++)
            {
                mat_ia1[lig - z][col] = 'D';
            }
        }
        // Si vers le bas
        if (direction == 4 && lig + 2 <= 15)
        {
            for (z = 1; z < 3; z++)
            {
                mat_ia1[lig + z][col] = 'D';
            }
        }
        D++;
    }
    while (S < 5)
    {
        srand(time(NULL));
        do
        {
            lig = rand() % (15) + 1;
            col = rand() % (15) + 1;
        } while (mat_ia1[lig][col] != B);

        mat_ia1[lig][col] = 'S';
        S++;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////