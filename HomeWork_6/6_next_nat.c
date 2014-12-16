#include <stdio.h>
#include <stdlib.h>

int main()
{
    int answer, number1, number2, summa1 = 0, summa2;
    printf("Enter a number : ");
    scanf("%d", &number1);
    answer = number1;
    while(number1)
    {
        summa1 += number1 % 10;
        number1 /= 10;
    }

    do
    {
        summa2 = 0;
        answer++;
        number2 = answer;
        while(number2)
        {
            summa2 += number2 % 10;
            number2 /= 10;
        }
    } while(summa1 != summa2);


    printf("%d\n", answer);
    return 0;
}
