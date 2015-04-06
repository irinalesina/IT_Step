#ifndef SADDLE_POINT_H_INCLUDED
#define SADDLE_POINT_H_INCLUDED
#include <iostream>
#include <cstdlib>

using namespace std;

void OutputMatrix(int *matrix, int rows, int columns);
void FillMatrix(int *matrix, int rows, int columns);
int SaddlePoint(int *matrix, int rows, int columns, int *result);

#endif // SADDLE_POINT_H_INCLUDED
