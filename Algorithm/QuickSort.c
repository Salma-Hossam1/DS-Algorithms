#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void swap(int *num1, int *num2);
int partition(int *list, int start, int end);
void QuickSort(int *list, int start, int end);

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
int partition(int *list, int start, int end)
{
    int pivot = list[end];
    int pivot_index = start;
    for (int i = start; i <= (end - 1); i++)
    {
        if (list[i] <= pivot)
        {
            swap(&list[i], &list[pivot_index]);
            pivot_index++;
        }
    }
    swap(&list[pivot_index], &list[end]);
    return pivot_index;
}
void QuickSort(int *list, int start, int end)
{
    int partition_index;
    if (start < end)
    {
        partition_index = partition(list, start, end);
        QuickSort(list, start, partition_index - 1);
        QuickSort(list, partition_index + 1, end);
    }
}
