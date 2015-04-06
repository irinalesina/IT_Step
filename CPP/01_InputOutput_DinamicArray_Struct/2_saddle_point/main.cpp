#include <iostream>
#include <cstdlib>
#include "saddle_point.h"

using namespace std;
int main()
{
    int rows, columns, amount_of_saddle_point;
    cout << "Enter amount of elements: ";
    cin >> rows >> columns;

    int *matrix = new int[rows*columns]();
    if(!matrix)
    {
        cout << "Memory allocation failed!\n";
        exit(1);
    }

    int *result = new int[rows*columns]();
    if(!result)
    {
        delete [] matrix;
        matrix = NULL;
        cout << "Memory allocation failed!\n";
        exit(1);
    }

    FillMatrix(matrix, rows, columns);
    OutputMatrix(matrix, rows, columns);

    amount_of_saddle_point = SaddlePoint(matrix, rows, columns, result);
    if(amount_of_saddle_point == NULL)
    {
        cout << "You don't have saddle point!" << endl;
    }
    else
    {
        cout << "You have " << amount_of_saddle_point << " saddle point(s):\n";
        int i;
        for(i = 0; i < amount_of_saddle_point; i++)
        {
            cout << i+1 << '.';
            cout << ' ' << matrix[result[i]];
            cout << '[' << result[i]/columns + 1 << ',' << result[i]%columns + 1 << ']' << endl;
        }
    }
    delete [] matrix;
    delete [] result;
    matrix = NULL;
    result = NULL;
    return 0;
}
