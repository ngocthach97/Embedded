#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

#define SIZE 10

int main(int argc, const char *grav[])
{
    int array[SIZE] = {45, 55, 25, 20, 15, 5, 25, 30, 10, 3};
    bubble_sort(array, SIZE);
    print_list(array, SIZE);
    return 0;
}
