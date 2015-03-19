#include <stdio.h>
#include <stdlib.h>
#define N 100

int main()
{
    printf("Hello!\nThis is compiler of brainfuck!\nEnter your program:\n>> ");
    char element, stack_bf[N] = {0};
    int top = 0;
    do
    {
        element = getchar();
        switch(element)
        {
        case '+':
            if(stack_bf[top] == 255)
            {
                stack_bf[top] = 0;
            }
            else
            {
                stack_bf[top]++;
            }
            break;
        case '-':
            stack_bf[top]--;
            break;
        case '>':
            if(top == 99)
            {
                printf("You go out of memory limits!!\n");
            }
            else
            {
                top++;
            }
            break;
        case '<':
            if(top == 0)
            {
                printf("You go out of memory limits!\n");
            }
            else
            {
                top--;
            }
            break;
        case '.':
            printf("%c\n", stack_bf[top]);
            break;
        case ';':
            break;
        case '\n':
            printf(">> ");
            break;
        default:
            printf("You enter invalid command!\n");
            exit(1);
        }
    }while(element != ';');
    return 0;
}
