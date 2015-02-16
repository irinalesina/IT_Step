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

enum Colors {normal, green, red}; //собственный тип данных colors

char close_cell[4] = "\342\227\206"; //символ ромбик для закрытых коеток
char flagged_cell[4] = "\342\227\204"; //треугольник для возможных бомб

enum State {opened, hidden, flagged}; // 0 1 2

#define ROWS 15
#define COLUMNS 17

void FieldsInit(int fog_of_war[][COLUMNS], int field[][COLUMNS], int rows, int columns);
void FieldsDraw(int fog_of_war[][COLUMNS], int field[][COLUMNS], int rows, int columns);

int main()
{
    InitialiseProgram();
    int fog_of_war[ROWS][COLUMNS], field[ROWS][COLUMNS];

    FieldsInit(fog_of_war, field, ROWS, COLUMNS);

    fog_of_war[2][2]=opened;
    fog_of_war[2][3]=opened;
    fog_of_war[2][4]=opened;
    fog_of_war[2][5]=opened;
    fog_of_war[2][6]=flagged;

    FieldsDraw(fog_of_war, field, ROWS, COLUMNS);

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

void RunAround(int field[][COLUMNS], int rows, int columns, int a, int b);
void Inc(int field[][COLUMNS], int rows, int columns, int i, int j);

void FieldsInit(int fog_of_war[][COLUMNS], int field[][COLUMNS], int rows, int columns)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            fog_of_war[i][j] = hidden;
            field[i][j] = 0;
        }
    }
    int amount_of_cells = rows * columns, amount_of_bomb = 10;
    for(i = 0; i < amount_of_bomb; i++)
    {
        int bomb_position = rand() % amount_of_cells;
        int bomb_i = bomb_position / columns;
        int bomb_j = bomb_position % rows;
        field[bomb_i][bomb_j] = 9;
        RunAround(field, rows, columns, bomb_i ,bomb_j);
    }
}

void RunAround(int field[][COLUMNS], int rows, int columns, int a, int b)
{
    int i, j;
    for(i = a - 1; i < a + 2; i++)
    {
        for(j = b - 1; j < b + 2; j++)
        {
            Inc(field, rows, columns, i, j);
        }
    }
}

void Inc(int field[][COLUMNS], int rows, int columns, int i, int j)
{
    if(i >= 0 && j >= 0 && i < rows && j < columns && field[i][j] < 9)
    {
        ++field[i][j];
    }
}


void FieldsDraw(int fog_of_war[][COLUMNS], int field[][COLUMNS], int rows, int columns)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            move(i, j);
            if(fog_of_war[i][j] == opened)
            {
                if(field[i][j] == 0)
                {
                    printw(" ");
                }
                else
                {
                    printw("%d", field[i][j]);
                }
            }
            else if(fog_of_war[i][j] == hidden)
            {
                printw("%s", close_cell);
            }
            else if(fog_of_war[i][j] == flagged)
            {
                printw("%s", flagged_cell);
            }
            else
            {
                endwin();
                fprintf(stderr, "interanl error: \nimposible value for fog.\n");
                exit(1);
            }
        }
    }
}
