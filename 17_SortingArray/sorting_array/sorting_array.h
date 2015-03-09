#ifndef SORTING_ARRAY_H_INCLUDED
#define SORTING_ARRAY_H_INCLUDED
#define N 100

void SortingSelection(int *array, int size_of_array);
void SortingBuble(int *array, int size_of_array);
void SortingInsertion(int *array, int size_of_array);
void SortingMerge(int *array, int left, int right);
void SortingQuick(int *array, int left, int right);
void SortingHeap(int *array, int size_of_array);
int CheckSorting(int *array, int size_of_array);
#endif // SORTING_ARRAY_H_INCLUDED
