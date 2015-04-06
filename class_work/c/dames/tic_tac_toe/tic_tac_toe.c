#include <stdio.h>

void Prototip(int characters[][3], int rows, int colons)
{
    int i, j;
    for(i = 0; i < rows + 2; i++)
    {
        for(j = 0; j < colons + 2; j++)
        {
            if(j % 2 == 0 && i % 2 == 0)
            {
                printf("%d", characters[i/2][j/2]);
            }
            else if(i % 2 == 0)
            {
                printf("|");
            }
            else
            {
                printf("-");
            }

        }
        printf("\n");
    }
    printf("\n");
}
static int characters[3][3] = {0}, exit[8] = {0};

// человек ходит Х и первым

int EnterCharactersPlayer(int characters[][3]; int rows, int colons)
{
    int position, operation;
    char player = "X", computer = "O";
    do
    {
        printf("Enter position(1-9): ");
        swich(posirion)
        {
        case 1:
            break;

        }
    }while(characters);



}








