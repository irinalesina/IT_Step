#include <stdio.h>
#include <stdlib.h>
#include "reverse_polish_notation.h"

int main()
{
    int exit = 1;
    char element, char_enter;
    double result;
    do
    {
        printf("Hello!\nThis is calculator of reverse polish notation(RPN)\n\n");
        printf("Enter RPN >> ");
        do
        {
            element = getchar();
            switch(element)
            {
            case '\n':
                break;
            case '+':
                PushStack(PopStack() + PopStack());
                break;
            case '-':
                PushStack(-PopStack() + PopStack());
                break;
            case '*':
                PushStack(PopStack() * PopStack());
                break;
            case '/':
                PushStack(1/PopStack() * PopStack());
                break;
            default:
                {
                    char ch[2] = {0};
                    ch[0] = element;
                    PushStack((double)atoi(ch));
                }
            }
        }while(element != '\n');
        result = PopStack();
        if(StackIsEmpty())
        {
            printf("Result >> %f\n\n", result);
        }
        else
        {
            printf("Error...You enter invalid command!\n");
        }

        printf("Do you want to exit(0-yes)? ");
        scanf("%d%c", &exit, &char_enter);
        system("cls");
    }while(exit);
    return 0;
}
