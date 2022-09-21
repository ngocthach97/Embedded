#include <stdio.h>

#define size 10

void twoSum(int num[], int target)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - 1; j > 0; j--)
        {
            if (num[i] + num[j] == target)
            {
                printf("a[0] = %d\n", i);
                printf("a[1] = %d\n", j);
            }
        }
    }
}

int main(int agrv, const char *argc[])
{
    int num[size] = {1, 3, 6, 4, 10, 2, 5, 7, 8, 9};
    twoSum(num, 3);
    return 0;
}
