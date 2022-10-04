#include <stdbool.h>
#include "array.h"
#include <stdio.h>

int get_value_max_array1D(int *array, int size)
{
    int value = *(array);
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) > value)
        {
            value = *(array + i);
        }
    }
    return value;
}

int get_value_min_array1D(int *array, int size)
{
    int value = *(array);
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) < value)
        {
            value = *(array + i);
        }
    }
    return value;
}

int get_count_even_number1D(int *array, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        int even = *(array + i) % 2;
        if (even == 0)
        {
            count++;
        }
    }
    return count;
}

int get_count_odd_number1D(int *array, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        int odd = *(array + i) % 2;
        if (odd != 0)
        {
            count++;
        }
    }
    return count;
}

void sort_array1D(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - 1; j > 0; j--)
        {
            if (*(array + j) > *(array - 1 + j))
            {
                int value = *(array + j);
                *(array + j) = *(array - 1 + j);
                *(array - 1 + j) = value;
            }
        }
    }
}

int *reverse_array1D(int *array, int size)
{
    int reverse[size];
    for (int i = 0; i < size; i++)
    {
        reverse[i] = *(array + size - 1 - i);
    }
    int *b = reverse;
    return b;
}

bool find_array1D(int *array, int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) == target)
        {
            return true;
        }
    }
    return false;
}

int searchInsert(int *array, int size, int target)
{
    int position = -1;
    for (int i = 0; i < size; i++)
    {
        position++;
        if (*(array + i) == target)
        {
            return position;
        }
    }
    return position;
}

void print_array1D(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \n", *(array + i));
    }
}

int *searchRange(int *array_input, int size, int target, int *array_output)
{
    int position = -1;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        position++;
        if (*(array_input + i) == target)
        {
            *(array_output + index) = position;
            index++;
        }
    }
    for (int i = index; i < size; i++)
    {
        *(array_output + i) = -1;
    }
    return array_output;
}

int *removeDuplicates(int *array, int size)
{
    int array_out[size];
    int *p = array_out;
    int index = 1;
    int other = *array;
    *p = *array;
    for (int i = 0; i < size; i++)
    {
        if (other != *(array + i))
        {
            *(p + index) = *(array + i);
            other = *(array + i);
            index++;
        }
    }
    for (int i = index; i < size; i++)
    {
        *(p + i) = -1;
    }
    return p;
}

int *removeElement(int *array, int size, int val)
{
    int array_out[size];
    int *p = array_out;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) != val)
        {
            *(p + index) = *(array + i);
            index++;
        }
    }
    for (int i = index; i < size; i++)
    {
        *(p + i) = -1;
    }
    return p;
}

int maxSubArray(int *array, int size)
{
    int max = *array;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += *(array + j);
            if (sum > max)
            {
                max = sum;
            }
        }
    }
    return max;
}

int *removeDuplicatesII(int *array, int size)
{
    
}

bool containsNearbyDuplicate(int *array, int size, int k)
{

} 