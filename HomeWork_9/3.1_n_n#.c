#include <stdio.h>
#include <stdlib.h>

void contur(int);
int main()
{
    int n;
    printf("Enter n = ");
    scanf("%d", &n);
    contur(n);
    return 0;
}
int nod(int, int);
void contur(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(nod(i+1, j+1) == 1)
            {
                printf("#");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
}
int nod(int a, int b)
{
    int max, min, answer;
    max = a > b ? a : b;
    min = a < b ? a : b;

    while(max % min != 0)
    {
        answer = max % min;
        max = min;
        min = answer;

    }
    return min;
}
