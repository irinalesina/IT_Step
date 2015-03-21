#ifndef STACK_F_H_INCLUDED
#define STACK_F_H_INCLUDED
#include <stdbool.h>

void Push(int element);
int Pop();
int OnTop(int *element);
int IsEmpty();

#endif // STACK_F_H_INCLUDED
