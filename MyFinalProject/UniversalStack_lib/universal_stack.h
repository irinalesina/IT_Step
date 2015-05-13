#ifndef STACK_F_H_INCLUDED
#define STACK_F_H_INCLUDED
#include <stdlib.h>

typedef struct _UniversalStack
{
    void *stack_memory;
    int element_size;
    int element_max_count;
    int top;
}UniversalStack;

int Initialize(UniversalStack *us, int element_size, int element_max_count);//инициализация динамич массива под стек//bool
void Uninitialize(UniversalStack *us);//очистка памяти

int Push(UniversalStack *us, void *element);//bool
int Pop(UniversalStack *us, void *element);//bool
int OnTop(UniversalStack *us, void *element);
int IsEmpty(UniversalStack *us);//bool

#endif // STACK_F_H_INCLUDED
