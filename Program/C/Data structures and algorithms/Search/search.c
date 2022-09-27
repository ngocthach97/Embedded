#include "search.h"
#include <stdbool.h>
#include <stdio.h>
void print_list(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \n", array[i]);
    }
}

bool linear_search(int array[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            return true;
        }
    }
    return false;
}

bool binary_search(int array[], int size, int target)
{
    int first = 0;
    int last = size - 1;
    while (first <= last)
    {
        int middle = (first + last) / 2;
        if (array[middle] == target)
        {
            return true;
        }
        else if (array[middle] > target)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }
    return false;
}