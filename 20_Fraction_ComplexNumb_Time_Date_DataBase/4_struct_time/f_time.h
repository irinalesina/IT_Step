#ifndef F_TIME_H_INCLUDED
#define F_TIME_H_INCLUDED

typedef struct _Time
{
    int hours;
    int minutes;
    int seconds;
}Time;

void InputTime(Time *time);
void OutputTime(Time *time);
void AddSeconds(Time *time, int seconds);
int DifferenceBetweenTheTime(Time *time_1, Time *time_2);

#endif // F_TIME_H_INCLUDED
