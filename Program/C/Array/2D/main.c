#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

int main(const int argc, char *argv[])
{
  int row = 3;
  int column = 3;
  int **matrix = input_matrix(row, column, init_matrix(row, column));
  printf("%d", minPathSum(row, column, matrix));
  return 0;
}