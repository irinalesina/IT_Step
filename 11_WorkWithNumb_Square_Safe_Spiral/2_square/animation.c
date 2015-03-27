#include <windows.h>

int token = 1;
void Animation(int size_of_square, int n)
{
    int i = 0;
    for(i; i < size_of_square-n; i++)
    {
        if(i < n)
        {
            printf("\n");
        }
        else
        {
            int amount_of_space = size_of_square/2, amount_of_elements = 0;

            while(amount_of_space < size_of_square / 2 + n)
            {
                printf(" ");
                amount_of_space++;
            }
            while(amount_of_elements < size_of_square-n*2)
            {
                printf("*");
                amount_of_elements++;
            }
            printf("\n");
        }
    }
    Sleep(300);
    system("cls");

    if(n < size_of_square/2 && n + token >= 0)
    {
        return Animation(size_of_square, n + token);
    }
    else
    {
        token *= -1;
        return Animation(size_of_square, n + token);
    }


}
