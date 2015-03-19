#include <stdbool.h>
#include <string.h>
#define N 100

static char command[N] = {0}, stack_bf[N] = {0};
static int top = 0, element = 0;
static const char commands[] = {"+-<>.,[]"};

bool EnterCommand()
{
    for(element; element >= 0; element--)
    {
        command[element] = 0;
    }
    element = 0;
    do
    {
        command[element] = getchar();
        if(strchr(commands, command[element]) != NULL)
        {
            element++;
        }
        else if(command[element] == '\n')
        {
            return true;
        }
        else if(command[element] == ';')
        {
            return false;
        }
        else
        {
            printf("This command not found!\n");
        }

    }while(element != ';');
}


void ImplementationCommand()
{
    int i;
    for(i = 0; i <= element; i++)
    {
        switch(command[i])
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
        case ',':
            stack_bf[top] = getchar();
            break;
        case '[':
            if(stack_bf[top] == NULL)
            {
                do
                {
                    i++;
                    if(i > element)
                    {
                        printf("Error. Command not found!\n");
                        return;
                    }
                }while(command[i-1] != ']');
            }
            break;
        case ']':
            if(stack_bf[top] == NULL)
            {
                do
                {
                    i--;
                    if(i < 0)
                    {
                        printf("Error. Command not found!\n");
                        return;
                    }
                }while(command[i-1] != '[');
            }
            break;
        }
    }
}
