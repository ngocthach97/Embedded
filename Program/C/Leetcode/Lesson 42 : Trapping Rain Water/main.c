#include <stdio.h>
#define Size 12

int trap(int *array, int size)
{
    return 0;
}

int main(int agrv, const char *argc[])
{
    int array[Size] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printf("Output = %d\n", trap(array, Size));
    return 0;
}