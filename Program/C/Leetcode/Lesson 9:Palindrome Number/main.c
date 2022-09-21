#include <stdio.h>
#include <stdbool.h>

int sumAllNumberInInt(int x)
{
    int n = x;
    int a;
    int sum = 0;
    while (n != 0)
    {
        a = n % 10;
        sum += a;
        n = n / 10;
    }
    return sum;
}

bool isPalindromeInInt (int x){
    int n = x;
    int a;
    int sum = 0;
    while (n != 0)
    {
        a = n % 10;
        sum += a;
        n = n / 10;
    }
    return sum;
}


int main(int agrv, const char *argc[])
{
    // printf("Output %d \n", isPalindromeInInt(1234));

    bool b = isPalindromeInInt(1221);
    return 0;
}