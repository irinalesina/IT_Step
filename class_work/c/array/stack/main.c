#include <stdio.h>
#include <stdlib.h>

int main()
{
    int stack[1000], array[13] = {"1 2 + 3 * 4 + 7 8 - 2 * /"}, top = 0, i, answer;
    for(i = 0; i < 13; i++)
    {
        if(array[i] == '+' || array[i] == '-' || array[i] == '*' || array[i] == '/')
        {
            switch(array[i])
            {
            case '+':

                answer += stack[top-1] + stack[top-2]
                top -= 2;
                break;
            case '-':

                answer -= stack[top-1] - stack[top-2]
                top -= 2;
                break;
            case '*':

                answer *= stack[top-1] * stack[top-2]
                top -= 2;
                break;
            case '/':

                answer /= stack[top-1] / stack[top-2]
                top -= 2;
                break;
            }
        }
        else
        {
            stack[top] = array[i];
            top ++;
        }
    }

    return 0;
}
