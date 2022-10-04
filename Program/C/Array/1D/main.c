#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

#define Size 5

int main(const int argc, char *argv[])
{
  int array[Size] = {5,4,-1,7,8};

  printf("%d", maxSubArray(array, Size));
  return 0;
}