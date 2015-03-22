#include "f_time.h"

void ConvertTheTime(Time *time);

void InputTime(Time *time)
{
    scanf("%d%d%d", &time->hours, &time->minutes, &time->seconds);
    ConvertTheTime(time);
}


void OutputTime(Time *time)
{
    printf("%02d:%02d:%02d\n", time->hours, time->minutes, time->seconds);
}


void AddSeconds(Time *time, int seconds)
{
    time->seconds += seconds;
    ConvertTheTime(time);
}


int DifferenceBetweenTheTime(Time *time_1, Time *time_2)
{
    int difference;
    difference = (time_1->hours - time_2->hours)*3600 + (time_1->minutes - time_2->minutes)*60 + (time_1->seconds - time_2->seconds);
    return difference;
}


void ConvertTheTime(Time *time)
{
     if(time->seconds > 59)
    {
        time->minutes += time->seconds / 60;
        time->seconds %= 60;
    }
    if(time->minutes > 59)
    {
        time->hours += time->minutes / 60;
        time->minutes %= 60;
    }
    if(time->hours > 23)
    {
        time->hours = 0;
    }
}
