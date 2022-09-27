#include <stdio.h>
#include <stdlib.h>

#include "search.h"

#define SIZE 10

int main(int argc, const char *grav[])
{
    int array[SIZE] = {45, 55, 25, 20, 15, 10, 5, 0, -5, -10};
    printf("%d \n", linear_search(array, SIZE, 10));
    printf("%d \n", binary_search(array, SIZE, 10));
    // print_list(array, SIZE);
    return 0;
}
