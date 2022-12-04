#include <stdbool.h>
#include "array.h"
#include <stdio.h>
#include <limits.h>
int getMax(int *array, int size)
{
    int value = *(array);
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) > value)
        {
            value = *(array + i);
        }
    }
    return value;
}

int getMin(int *array, int size)
{
    int value = *(array);
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) < value)
        {
            value = *(array + i);
        }
    }
    return value;
}

int getCountEven(int *array, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        int even = *(array + i) % 2;
        if (even == 0)
        {
            count++;
        }
    }
    return count;
}

int getCountOdd(int *array, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        int odd = *(array + i) % 2;
        if (odd != 0)
        {
            count++;
        }
    }
    return count;
}

void sort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - 1; j > 0; j--)
        {
            if (*(array + j) > *(array - 1 + j))
            {
                int value = *(array + j);
                *(array + j) = *(array - 1 + j);
                *(array - 1 + j) = value;
            }
        }
    }
}

int *reverse(int *array, int size)
{
    int reverse[size];
    for (int i = 0; i < size; i++)
    {
        reverse[i] = *(array + size - 1 - i);
    }
    int *b = reverse;
    return b;
}

bool find(int *array, int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) == target)
        {
            return true;
        }
    }
    return false;
}

int searchInsert(int *array, int size, int target)
{
    int position = -1;
    for (int i = 0; i < size; i++)
    {
        position++;
        if (*(array + i) == target)
        {
            return position;
        }
    }
    return position;
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \n", *(array + i));
    }
}

int *searchRange(int *array_input, int size, int target, int *array_output)
{
    int position = -1;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        position++;
        if (*(array_input + i) == target)
        {
            *(array_output + index) = position;
            index++;
        }
    }
    for (int i = index; i < size; i++)
    {
        *(array_output + i) = -1;
    }
    return array_output;
}

int *removeDuplicates(int *array, int size)
{
    int array_out[size];
    int *p = array_out;
    int index = 1;
    int other = *array;
    *p = *array;
    for (int i = 0; i < size; i++)
    {
        if (other != *(array + i))
        {
            *(p + index) = *(array + i);
            other = *(array + i);
            index++;
        }
    }
    for (int i = index; i < size; i++)
    {
        *(p + i) = -1;
    }
    return p;
}

int *removeElement(int *array, int size, int val)
{
    int array_out[size];
    int *p = array_out;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) != val)
        {
            *(p + index) = *(array + i);
            index++;
        }
    }
    for (int i = index; i < size; i++)
    {
        *(p + i) = -1;
    }
    return p;
}

int maxSubArray(int *array, int size)
{
    int max = *array;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += *(array + j);
            if (sum > max)
            {
                max = sum;
            }
        }
    }
    return max;
}


int maxArea(int* array, int size){
    int areaMax = 0; 
    for(int i = 0; i < size; i++){
        int height = *(array+i);
        for(int j = i; j < size; j++){
            int H = *(array+j);
            int width = j-i;
            if(height > H){
                int area = H*width;
                if(area > areaMax){
                    areaMax = area ;
                }
            }
            else{
                int area = height*width;
                if(area > areaMax){
                    areaMax = area ;
                }
            }
        }
    }
    return areaMax ;
}

int findDuplicate(int* array, int size){
    for(int i = 0; i < size ; i ++){
        int num = *(array+i);
        for(int j = i+1; j< size ; j++){
            int run = *(array+j);
            if(num == run){
                return num;
            }
        }
    }
    return -1;
}

int thirdMax(int* array, int size){
    int maxFirst = *(array);
    for(int i = 0 ; i < size ; i++){
        if(*(array+i) > maxFirst){
            maxFirst = *(array+i);
        }
    }
    int maxSecond = INT_MIN; 
    for(int i = 0 ; i < size ; i++){
        if(*(array+i) > maxSecond && *(array+i) < maxFirst){
            maxSecond = *(array+i) ;
        }
    }
    int maxThird = INT_MIN; 
    for(int i = 0 ; i < size ; i++){
        if(*(array+i) > maxThird && *(array+i) < maxSecond){
             maxThird = *(array+i) ;
        }
    }
    return maxThird;
}

int splitArray(int* array, int size, int k){
    int max = 0;
    for(int i = 0; i < size-k+1 ; i++){
        int sum = 0 ;
        for(int j = i ; j < i+k ; j++){
            sum = sum +(*(array+j)); 
        }
        if(sum > max){
            max = sum;
        }
    }
    return max;
}

int* twoSum(int* array, int size, int target, int* returnArray){
    for(int i = 0  ; i < size ; i++){
        int value1 = *(array+i);
        for(int j = i+1 ; j < size ; j ++){
        int value2 = *(array+j);
            int sum = value1 + value2;
            if(sum == target){
                *(returnArray+0)=i;
                *(returnArray+1)=j;
                return returnArray;
            }
            else{
                *(returnArray+0)=-1;
                *(returnArray+1)=-1;
            }
        }
    }
    return returnArray;
}