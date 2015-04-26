#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct _Database
{
    char question[100] = {0};
    char yes[100] = {0};
    char no[100] = {0};
}Database;

typedef struct _Help
{
    char question[100] = {0};
    char yes[100] = {0};
    char no[100] = {0};
}Help;

int ReadFromDatabase(Database *node);
void EnterNewKnowledge(Help *new_node, Database node);

#endif // FUNCTIONS_H_INCLUDED
