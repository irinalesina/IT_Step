#include <stdio.h>
#include <stdlib.h>
#include "brainfuck.h"

int main()
{
    printf("Hello:)\nThis is compiler of brainfuck!\nEnter your program:\n");
    bool realization;
    do
    {
        printf(">> ");
        realization = EnterCommand();
        ImplementationCommand();
    }while(realization);
    printf("Goodbye!\n");
    return 0;
}
