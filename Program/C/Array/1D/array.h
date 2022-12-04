#ifndef ARRAY_1D
#define ARRAY_1D

int getMax(int *, int size);

int getMin(int *, int size);

int getCountEven(int *, int size);

int getCountOdd(int *, int size);

void sort(int *, int size);

int *reverse(int *, int size);

bool find(int *, int size, int target);

int searchInsert(int *, int size, int target);

void printArray(int *, int size);

int *searchRange(int *, int size, int target, int *);

int *removeDuplicates(int *, int size);

int *removeElement(int *, int size, int val);

int maxSubArray(int *, int size);

int maxArea(int* array, int size);

int findDuplicate(int* array, int size);

int thirdMax(int* array, int size);

int splitArray(int* array, int size, int k);

int* twoSum(int* array, int size, int target, int* returnArray);

#endif