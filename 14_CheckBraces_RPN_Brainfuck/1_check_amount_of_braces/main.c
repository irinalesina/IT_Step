#include <stdio.h>
#include <stdlib.h>
#include "../../work_with_array/work_with_array.h"
#include "stack.h"

int main()
{
    char array_of_braces[100], enter;
    int size_of_array, i;
    printf("Enter amount of braces: ");
    scanf("%d%c", &size_of_array, &enter);
    printf("Enter array of braces: ");
    InputCharArray(array_of_braces, size_of_array);
    int result_correct = 1;
    for(i = 0; i < size_of_array; i++)
    {
        if(array_of_braces[i] == '(' || array_of_braces[i] == '[' || array_of_braces[i] == '{')
        {
            Push(array_of_braces[i]);
        }
        else if(array_of_braces[i] == ')' || array_of_braces[i] == ']' || array_of_braces[i] == '}')
        {
            if(IsStackEmpty())
            {
                result_correct = 0;
                break;
            }
            char pop_element = Pop();
            if((pop_element == '(' && array_of_braces[i] != ')') ||
               (pop_element == '[' && array_of_braces[i] != ']') ||
               (pop_element == '{' && array_of_braces[i] != '}'))
            {
                result_correct = 0;
                break;
            }

        }
    }
    if(result_correct)
    {
        printf("Result: correct!");
    }
    else
    {
        printf("Result: incorrect!");
    }

    return 0;
}
