#include <stdio.h>
#include "simpletron.h"

static int amount_of_commands, memory[100] = {0}, error = 0;

void EnterProgram()
{
    int i, j, enter;
    for(i = 0; i < 100; i++)
    {
        printf("%02d? ", i);
        scanf(" %d", &enter);
        if((enter < -9999 || enter > 9999) && enter != -99999)
        {
            i -= 1;
            continue;
        }
        if(enter == -99999)
        {
            break;
        }
        memory[i] = enter;
    }
    amount_of_commands = i;
}

void ImplementationProgram()
{
    int command, i, accumulator = 0, cell_of_memory;
    for(i = 0; i < amount_of_commands; i++)
    {
        command = memory[i] / 100;
        cell_of_memory = memory[i] % 100;
        switch(command)
        {
        case 10:
            printf("input...");
            scanf("%d", &memory[cell_of_memory]);
            break;
        case 11:
            printf("%d\n", memory[cell_of_memory]);
            break;
        case 20:
            accumulator = memory[cell_of_memory];
            break;
        case 21:
            memory[cell_of_memory] = accumulator;
            break;
        case 30:
            accumulator += memory[cell_of_memory];
            break;
        case 31:
            accumulator -= memory[cell_of_memory];
            break;
        case 32:
            if(memory[cell_of_memory] == 0)
            {
                error = 32;
            }
            accumulator /= memory[cell_of_memory];
            break;
        case 33:
            accumulator *= memory[cell_of_memory];
            break;
        case 40:
            i = cell_of_memory -1;
            break;
        case 41:
            if(accumulator < 0)
            {
                i = cell_of_memory -1;
            }
            break;
        case 42:
            if(accumulator == 0)
            {
                i = cell_of_memory -1;
            }
            break;
        case 43:
            error = 43;
            break;
        default:
            error = 1;
        }
        if(accumulator > 9999 || accumulator < -9999)
        {
            error = 2;
        }
        if(error != 0)
        {
            break;
        }
    }
    OutputResult(error);
    DampOfMemory(memory);
}

void OutputResult(int error)
{
    if(error == 0)
    {
        printf("\n\n*** Программа выполнена успешно ***\n");
    }
    else if(error == 43)
    {
        printf("*** Симплетрон остановлен...Выполнение программы завершено ***\n");
    }
    else
    {
        switch(error)
        {
        case 1:
            printf("*** Вы пытаетесь ввести несуществующую команду ***\n");
            break;
        case 32:
            printf("*** Вы пытаетесь делить на 0 ***\n");
            break;
        case 2:
            printf("*** Аккумулятор переполнен ***\n");
            break;
        case 43:
            break;
        }
        printf("*** Симплетрон аварийно завершил выполнение программы ***\n");
    }
}

void DampOfMemory(int*memory)
{
    int i, j;
    printf("\n*** Дамп памяти ***\n\n");
    printf("%8d%6d%6d%6d%6d%6d%6d%6d%6d%6d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    for(i = 0; i < 100; i += 10)
    {
        printf("\n%2d", i);
        for(j = i; j < i + 10; j++)
        {
            printf("%+6.4d", memory[j]);
        }
    }
}



