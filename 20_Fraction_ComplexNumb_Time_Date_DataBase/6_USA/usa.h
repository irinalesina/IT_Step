#ifndef USA_H_INCLUDED
#define USA_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct _USA
{
    char state[20];
    char capital[20];
    int area;
    int population;
}USA;


void Output();
void SaveData();
int LoadData();
int DeleteData(int position);
void AddData();
void SortDatabase(int field, int direction);

#endif // USA_H_INCLUDED
