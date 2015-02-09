#include <stdio.h>
#include <stdlib.h>
#include "tic_tac_toe.h"

int main()
{
    int characters[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Prototip(characters, 3, 3);
    int exit[8], operetion, i;
    for(i = 0; i < 9; i++)
    {
        EnterCharactersPlayer(characters, 3, 3);

    }
    return 0;
}
