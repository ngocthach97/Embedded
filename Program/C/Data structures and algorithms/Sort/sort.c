#include "sort.h"
#include <stdio.h>

void Swap(int xp, int yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}

void print_list(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \n", array[i]);
    }
}

void bubble_sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - 1; j > 0; j--)
        {
            if (array[j] > array[j - 1])
            {
                int a = array[j];
                array[j] = array[j - 1];
                array[j - 1] = a;
            }
        }
    }
}

void _partitioning_sort(int array[], int First, int Last)
{
}

void partitioning_sort(int array[], int size)
{
    _partitioning_sort(array, 0, size - 1);
    return;
}

void straight_selection_sort(int array[], int size)
{
}

void straight_insertion_sort(int array[], int size)
{
}