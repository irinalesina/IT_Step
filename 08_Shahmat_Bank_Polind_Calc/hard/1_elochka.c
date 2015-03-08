#include <stdio.h>
#include <stdlib.h>

int main()
{
    int height;
    printf("Enter a height = ");
    scanf("%d", &height);
    system("cls");
    int i, j, k;
    //chislo yarusov
    for(j = 0; j < height; j++)
    {
        //chislo strok yarusa
        for(i = 0; i < j+2; i++)
        {
            //chislo elementov stroki
            for(k = 0; k < height+1+i; k++)
            {
                //poslednaya stroka yarusa
                if(i == j+1)
                {
                    while(k < height-i)
                    {
                        printf(" ");
                        k++;
                    }
                    while(k < height+i+1)
                    {
                        printf("*");
                        k++;
                    }
                }
                //osnovnye stoki
                else if((i == 0 && k == height+1) || (i > 0 && k == height-i || k == height+i))
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }

            }
            printf("\n");
        }
    }
    //nogka
    //dly <=3h yarusov
    if(j <= 3)
    {
        for(i = 0; i < 1; i++)
        {
            for(j = 0; j < height+1; j++)
            {
                if(j == height)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    //dly >3h yarusov
    else
    {
        for(i = 0; i < 2; i++)
        {
            for(j = 0; j < height+2; j++)
            {
                if(i == 1)
                {
                    while(j < height-1)
                    {
                        printf(" ");
                        j++;
                    }
                    while(j < height+2)
                    {
                        printf("*");
                        j++;
                    }
                }
                if(j == height-1 || j == height+1)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}
