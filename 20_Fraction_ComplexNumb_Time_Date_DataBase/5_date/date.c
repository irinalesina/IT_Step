#include "date.h"


int CheckDate(Date date);
int CheckLeapYear(int year);
int DayInMonth(int month, int year);
int DaysInCurrentYear(int month, int year);
long long DifferenceBetweenCurrentYearAndStartYear(int year, int start_year);

void Input(Date *date)
{
    int check;
    printf("\nEnter date:\n");
    do
    {
        printf("day: ");
        scanf("%d", &date->day);
        printf("month: ");
        scanf("%d", &date->month);
        printf("year: ");
        scanf("%d", &date->year);

        check = CheckDate(*date);
        if(!check)
            printf("Error, you enter invalid date!\n");
    }while(!check);
}


void Output(Date date)
{
    printf("%02d.%02d.%d\n", date.day, date.month, date.year);
}


void AddDays(Date *date, int amount_of_days)
{
    int day_in_month;
    date->day += amount_of_days;
    do
    {
        day_in_month = DaysInMonth(date->month, date->year);
        date->day -= day_in_month;
        date->month += 1;
        if(date->month > 12)
        {
            date->month -= 12;
            date->year += 1;
        }
    }while(date->day > day_in_month);
}


long long DifferenceBetweenDates(Date date_1, Date date_2)
{
    long long days, days_1 = 0, days_2 = 0;
    int start_year = date_1.year < date_2.year ? date_1.year : date_2.year;

    days_1 += date_1.day;//+количество дней в текущем месяце
    date_1.month--;
    days_1 += DaysInCurrentYear(date_1.month, date_1.year);//количество дней в текущем году
    days_1 += DifferenceBetweenCurrentYearAndStartYear(date_1.year, start_year);//разница в днях между текущим годом и годом отсчета

    days_2 += date_2.day;//+количество дней в текущем месяце
    date_2.month--;
    days_2 += DaysInCurrentYear(date_2.month, date_2.year);//количество дней в текущем году
    days_2 += DifferenceBetweenCurrentYearAndStartYear(date_2.year, start_year);//разница в днях между текущим годом и годом отсчета

    days = date_1.year > date_2.year ? (days_1 - days_2) : (days_2 - days_1);
    return days;
}


int CheckDate(Date date)
{
    int day_in_month = DaysInMonth(date.month, date.year);
    if(date.month > 0 && date.month <= 12 && date.day > 0 && date.day <= day_in_month)
    {
        return 1;
    }
    return 0;
}


int CheckLeapYear(int year)
{
    if(year % 400 == NULL)
        return 1;
    else if(year % 4 == NULL && year % 100 != 0)
        return 1;
    return 0;
}


int DaysInMonth(int month, int year)
{
    switch(month)
        {
        case 2:
            {
                if(CheckLeapYear(year))
                    return 29;
                else
                    return 28;
            }
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
            return 31;
        case 4:
        case 6:
        case 8:
        case 10:
        case 12:
            return 30;
        }
}


int DaysInCurrentYear(int month, int year)
{
    int days = 0;
    while(month)
    {
        days += DaysInMonth(month, year);
        month--;
    }
    return days;
}


long long DifferenceBetweenCurrentYearAndStartYear(int year, int start_year)
{
    long long days = 0;
    while(year >= start_year)
    {
        if(CheckLeapYear(year))
            days += 366;
        else
            days += 365;
        year--;
    }
    return days;
}


