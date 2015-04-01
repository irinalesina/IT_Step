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

void Input(Date *date);
void Output(Date date);
void AddDays(Date *date, int amount_of_days);
long long DifferenceBetweenDates(Date date_1, Date date_2);

#endif // DATE_H_INCLUDED
