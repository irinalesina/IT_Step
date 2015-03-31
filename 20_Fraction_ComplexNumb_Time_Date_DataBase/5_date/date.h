#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>


typedef struct _Date
{
    int day;
    int month;
    int year;
}Date;

void Input(Data *data);
void Output(Data data);
void AddDays(Data *data, int amount_of_days);
int DifferenceBetweenDates(Data data_1, Data data_2);

#endif // DATE_H_INCLUDED
