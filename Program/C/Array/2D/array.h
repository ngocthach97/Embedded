#ifndef ARRAY_2D
#define ARRAY_2D

int **init_matrix(int row, int column);

int **input_matrix(int row, int column, int **);

void output_matrix(int row, int column, int **);

int get_value_max_matrix(int row, int column, int **);

int get_value_min_matrix(int row, int column, int **);

bool search_matrix(int row, int column, int **, int target);

int **sum_two_matrix(int row_1, int column_1, int **, int row_2, int column_2, int **);

int **sub_two_matrix(int row_1, int column_1, int **, int row_2, int column_2, int **);

int **multi_two_matrix(int row_1, int column_1, int **, int row_2, int column_2, int **);

int maximal_square(int row, int column, int **);

int **rotate_right_to_left(int row, int column, int **);

int **rotate_button_to_top(int row, int column, int **);

int **rotate_90(int row, int column, int **);

bool is_triangle_matrix(int row, int column, int **);

int sum_main_diagonal(int row, int column, int **);

int sum_auxiliary_diagonal(int row, int column, int **);

int **construct(int *, int size, int row, int column);

int minPathSum(int row, int column, int **);

#endif