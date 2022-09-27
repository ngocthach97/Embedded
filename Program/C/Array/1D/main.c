#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Size 10

int get_value_max_array1D(int array[], int size)
{
  int a = array[0];
  for (int i = 0; i < size; i++)
  {
    if (array[i] > a)
    {
      a = array[i];
    }
  }
  return a;
}

int get_value_min_array1D(int array[], int size)
{
  int a = array[0];
  for (int i = 0; i < size; i++)
  {
    if (array[i] < a)
    {
      a = array[i];
    }
  }
  return a;
}

int get_count_even_number1D(int array[], int size)
{
  int count = 0;
  for (int i = 0; i < size; i++)
  {
    if ((array[i] % 2) == 0)
    {
      count++;
    }
  }
  return count;
}

int get_count_odd_number1D(int array[], int size)
{
  int count = 0;
  for (int i = 0; i < size; i++)
  {
    if ((array[i] % 2) != 0)
    {
      count++;
    }
  }
  return count;
}

int *sort_array1D(int array[], int size)
{
  for (int j = size - 1; j > 0; j--)
  {
    for (int i = 0; i < size - 1; i++)
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

int *reverse_array1D(int array[], int size)
{
  int a = 0;
  for (int i = 0; i < (size / 2); i++)
  {
    a = array[i];
    array[i] = array[size - 1 - i];
    array[size - 1 - i] = a;
  }
  return array;
}

bool find_array1D(int array[], int a, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (array[i] == a)
    {
      return true;
    }
  }
  return false;
}

void print_array1D(int array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("A[%d] = %d \n", i, array[i]);
  }
}

int main(const int argc, char *argv[])
{
  int array[Size] = {1, 4, 6, 3, 9, 78, 16, 2, -1, -10};
  printf("%d \n", get_value_max_array1D(array, Size));
  printf("%d \n", get_value_min_array1D(array, Size));
  return 0;
}