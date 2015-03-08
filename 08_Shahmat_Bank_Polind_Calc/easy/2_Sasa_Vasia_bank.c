#include <stdio.h>
#include <stdlib.h>

int main()
{
    int money_Sasha = 1000, money_Vasia = 1000, money_Sasha_with_procent = 1000;
    double Sasa = 1000, Vasia = 1000, Sasa_with_procent = 1000;
    int i = 1;
    do
    {
        // int
        money_Sasha_with_procent += money_Sasha*6/(4*100);
        money_Vasia += money_Vasia*4/(4*100);
        //double
        Sasa_with_procent += Sasa*6/(4*100);
        Vasia += Vasia*4/(4*100);

        printf("%d\n", i++);
        printf("Money Sasha = %f\n", Sasa_with_procent);
        printf("Money Vasia = %f\n\n", Vasia);

    }while(money_Sasha_with_procent > money_Vasia);

    printf("BINGO!!! Vasia is richer then Sasha!!!\n\n");

    for(i = 0; i < 2; i++)
    {
        // int
        money_Sasha_with_procent += money_Sasha*6/(4*100);
        money_Vasia += money_Vasia*4/(4*100);
        //double
        Sasa_with_procent += Sasa*6/(4*100);
        Vasia += Vasia*4/(4*100);

        printf("Money Sasha = %f\n", Sasa_with_procent);
        printf("Money Vasia = %f\n\n", Vasia);

    }
    return 0;
}
