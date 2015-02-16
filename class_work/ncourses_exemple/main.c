#define _XOPEN_SOURSE_EXTENDED
#define _POSIX_C_SOURSE 199309L // для норм работы ncourses

#include <sys/ioctl.h> //получение размеров консоли
#include <signal.h> //взаимодествие с ос в виде реагирования на сигналы
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h> //чтобы все грамотно работало с юникодом

void TreatSigWinch(int signo);
void InitialiseProgram();
enum Colors{normal, green, red}; //собственный тип данных colors

int main()
{
    InitialiseProgram();

    attron(COLOR_PAIR(normal));
    printw("Hello world!");
    attroff(COLOR_PAIR(normal));
    refresh(); //обновить экран чтобы все поолучилось
    getch(); // получить код клавиши
    attron(A_BLINK|A_BOLD);
    move(0, 6);
    attron(COLOR_PAIR(green));
    printw("world");
    attroff(COLOR_PAIR(green));
    move(0, 0);
    attron(COLOR_PAIR(red));
    printw("Hello");
    attroff(COLOR_PAIR(red));
    refresh();
    getch();
    endwin();
    return 0;
}

void InitialiseProgram()
{
    setlocale(LC_ALL, "");
    initscr(); //начать экран
    signal(SIGWINCH, TreatSigWinch); //назначаем сигналу SIGWINCH обработчик TreatSigWinch
    if(has_colors() == FALSE)
    {
        endwin();
        fprintf(stderr, "no colors\n");
        exit(1);
    }
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    //init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(normal, COLOR_WHITE, COLOR_BLACK);
    init_pair(green, COLOR_GREEN, COLOR_BLACK);
    init_pair(red, COLOR_RED, COLOR_BLACK);
}

void TreatSigWinch(int signo)
{
    struct winsize size;
    ioctl(1, TIOCGWINSZ, (char *) &size);
    resizeterm(size.ws_row, size.ws_col);
}
