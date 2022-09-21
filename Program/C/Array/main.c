#include <stdio.h>
#include <stdlib.h>
#define Size 10

#define x 3

#define y 3

// Array 1D
int get_value_max_array1D(int array[])
{
  int a = array[0];
  for (int i = 0; i < Size; i++)
  {
    if (array[i] > a)
    {
      a = array[i];
    }
  }
  return a;
}

int get_value_min_array1D(int array[])
{
  int a = array[0];
  for (int i = 0; i < Size; i++)
  {
    if (array[i] < a)
    {
      a = array[i];
    }
  }
  return a;
}

int get_count_even_number1D(int array[])
{
  int count = 0;
  for (int i = 0; i < Size; i++)
  {
    if ((array[i] % 2) == 0)
    {
      count++;
    }
  }
  return count;
}

int get_count_odd_number1D(int array[])
{
  int count = 0;
  for (int i = 0; i < Size; i++)
  {
    if ((array[i] % 2) != 0)
    {
      count++;
    }
  }
  return count;
}

int *sort_array1D(int array[])
{
  for (int j = Size - 1; j > 0; j--)
  {
    for (int i = 0; i < Size - 1; i++)
    {
      int a = 0;
      if (array[i] < array[i + 1])
      {
        a = array[i];
        array[i] = array[i + 1];
        array[i + 1] = a;
      }
    }
  }
  return array;
}

int *reverse_array1D(int array[])
{
  int a = 0;
  for (int i = 0; i < (Size / 2); i++)
  {
    a = array[i];
    array[i] = array[Size - 1 - i];
    array[Size - 1 - i] = a;
  }
  return array;
}

int find_array1D(int array[], int a)
{
  for (int i = 0; i < Size; i++)
  {
    if (array[i] == a)
    {
      return 1;
    }
  }
  return 0;
}

void print_array1D(int array[])
{
  for (int i = 0; i < Size; i++)
  {
    printf("A[%d] = %d \n", i, array[i]);
  }
}

// Array 2D

int get_value_max_array2D(int array[x][y])
{
  int a = 0;
  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      if (a < array[i][j])
      {
        a = array[i][j];
      }
    }
  }
  return a;
}

int get_value_min_array2D(int array[x][y])
{
  int a = 0;
  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      if (a > array[i][j])
      {
        a = array[i][j];
      }
    }
  }
  return a;
}

int main(const int argc, char *argv[])
{
  int row = 0;
  int column = 0;
  FILE *file;
  file = fopen("data.txt", "r");
  if (file == NULL)
  {
    printf("no such file./n");
    return 0;
  }
  fscanf(file, "Row:%d\nColumn:%d\n", &row,&column);
  printf("%d  %d\n", row, column);
  int array[row][column];
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      fscanf(file, "%d\t", &array[i][j]);
    }
  }
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      printf("%d \t", array[i][j]);
    }
     printf("\n");
  }
  fclose(file);
  return 0;
}
