#ifndef ARRAY_1D
#define ARRAY_1D

int get_value_max_array1D(int *, int size);

int get_value_min_array1D(int *, int size);

int get_count_even_number1D(int *, int size);

int get_count_odd_number1D(int *, int size);

void sort_array1D(int *, int size);

int *reverse_array1D(int *, int size);

bool find_array1D(int *, int size, int target);

int searchInsert(int *, int size, int target);

void print_array1D(int *, int size);

int *searchRange(int *, int size, int target, int *);

int *removeDuplicates(int *, int size);

int *removeElement(int *, int size, int val);

int maxSubArray(int *, int size);

int *removeDuplicatesII(int *, int size);

bool containsNearbyDuplicate(int* , int size, int k);

#endif