#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

#define Size 4

int main(const int argc, char *argv[])
{
  int array[Size] = {11,15,2,7};
  int returnArray[2];
  int* x = twoSum(array, Size, 9,returnArray);
  printArray(x,2);
  return 0;
}