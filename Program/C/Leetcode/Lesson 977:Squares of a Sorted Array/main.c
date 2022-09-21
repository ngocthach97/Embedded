#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define Size 5

void sortArray(int *input, int size)
{
    int a;
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (*(input + j) >= *(input + j + 1))
            {
                a = *(input + j);
                *(input + j) = *(input + j + 1);
                *(input + j + 1) = a;
            }
        }
    }
}

int *sortedSquares(int *input, int size)
{
    int *a;
    int ouput[size];
    a = ouput;
    for (int i = 0; i < size; i++)
    {
        int b = *(input + i);
        ouput[i] = b * b;
    }
    sortArray(a, size);
    return a;
}

void printArray(int *input, int size){
    for (int i = 0; i < size; i++)
    {
       printf("%d   ", *(input+i));
    }
    printf("\n");
}

int search(int* input, int size, int target){
    for (int i = 0; i < size; i++)
    {
        if(*(input + i) == target){
            return i;
        }
    }
    return -1;
}

int main(int agrv, const char *argc[])
{
    int input[Size] = {-2, 4, 3, 2, 100};
    int *b = sortedSquares(input, Size);
    printArray(b, Size);

    printf("%d", search(input, Size, 3));
    return 0;
}