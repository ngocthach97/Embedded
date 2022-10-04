#include <stdbool.h>
#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int **init_matrix(int row, int column)
{
    int **matrix;
    matrix = malloc(row * sizeof *matrix);
    for (int i = 0; i < row; i++)
    {
        matrix[i] = malloc(column * sizeof *matrix[i]);
    }
    return matrix;
}

void output_matrix(int row, int column, int **matrix)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("A[%d][%d] = %d \t", i, j, *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int **input_matrix(int row, int column, int **matrix)
{
    int num;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &num);
            *(*(matrix + i) + j) = num;
        }
    }
    return matrix;
}

int get_value_max_matrix(int row, int column, int **matrix)
{
    int max = *(matrix)[0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (*(*(matrix + i) + j) > max)
            {
                max = *(*(matrix + i) + j);
            }
        }
    }
    return max;
}

int get_value_min_matrix(int row, int column, int **matrix)
{
    int min = *(matrix)[0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (*(*(matrix + i) + j) < min)
            {
                min = *(*(matrix + i) + j);
            }
        }
    }
    return min;
}

bool search_matrix(int row, int column, int **matrix, int target)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (*(*(matrix + i) + j) == target)
            {
                return true;
            }
        }
    }
    return false;
}

int **sum_two_matrix(int row_1, int column_1, int **matrix_1, int row_2, int column_2, int **matrix_2)
{
    int **sum;
    if (row_1 == row_2 && column_1 == column_2)
    {
        sum = init_matrix(row_1, column_1);
        for (int i = 0; i < row_1; i++)
        {
            for (int j = 0; j < column_1; j++)
            {
                *(*(sum + i) + j) = *(*(matrix_1 + i) + j) + *(*(matrix_2 + i) + j);
            }
        }
    }
    return sum;
}

int **sub_two_matrix(int row_1, int column_1, int **matrix_1, int row_2, int column_2, int **matrix_2)
{
    int **sub;
    if (row_1 == row_2 && column_1 == column_2)
    {
        sub = init_matrix(row_1, column_1);
        for (int i = 0; i < row_1; i++)
        {
            for (int j = 0; j < column_1; j++)
            {
                *(*(sub + i) + j) = *(*(matrix_1 + i) + j) - *(*(matrix_2 + i) + j);
            }
        }
    }
    return sub;
}

int **multi_two_matrix(int row_1, int column_1, int **matrix_1, int row_2, int column_2, int **matrix_2)
{
    int **multi;
    if (column_1 == row_2)
    {
        multi = init_matrix(row_1, column_2);
        for (int i = 0; i < row_1; i++)
        {
            for (int j = 0; j < column_2; j++)
            {
                *(*(multi + i) + j) = 0;
                for (int k = 0; k < column_1; k++)
                {
                    *(*(multi + i) + j) += (*(*(matrix_1 + i) + k)) * (*(*(matrix_2 + k) + j));
                }
            }
        }
    }
    return multi;
}

int **rotate_right_to_left(int row, int column, int **matrix)
{
    int **_rotate;
    _rotate = init_matrix(row, column);

    for (int j = 0; j < column; j++)
    {
        for (int i = 0; i < row; i++)
        {
            *(*(_rotate + i) + j) = *(*(matrix + i) + column - 1 - j);
        }
    }
    return _rotate;
}

int **rotate_button_to_top(int row, int column, int **matrix)
{
    int **_rotate;
    _rotate = init_matrix(row, column);

    for (int j = 0; j < column; j++)
    {
        for (int i = 0; i < row; i++)
        {
            *(*(_rotate + i) + j) = *(*(matrix + row - 1 - i) + j);
        }
    }
    return _rotate;
}

int **rotate_90(int row, int column, int **matrix)
{
    int **_rotate;
    _rotate = init_matrix(row, column);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            *(*(_rotate + i) + j) = *(*(matrix + j) + i);
        }
    }
    return _rotate;
}

int sum_main_diagonal(int row, int column, int **matrix)
{
    int sum = 0;
    for (int j = 0; j < column; j++)
    {
        for (int i = 0; i < row; i++)
        {
            if (j == i)
            {
                sum += *(*(matrix + i) + j);
            }
        }
    }
    return sum;
}

int sum_auxiliary_diagonal(int row, int column, int **matrix)
{
    int sum = 0;
    for (int j = 0; j < column; j++)
    {
        for (int i = 0; i < row; i++)
        {
            if (j + i == column - 1)
            {
                sum += *(*(matrix + i) + j);
            }
        }
    }
    return sum;
}

int **construct(int *array, int size, int row, int column)
{
    int **convert;
    if (size / row == column)
    {
        convert = init_matrix(row, column);
        int index = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                *(*(convert + i) + j) = *(array + index);
                index++;
            }
        }
    }
    return convert;
}

int minPathSum(int row, int column, int **matrix)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (i == 0 || (j == 2 && j != 0))
            {
                sum += *(*(matrix + i) + j);
            }
        }
    }
    return sum;
}