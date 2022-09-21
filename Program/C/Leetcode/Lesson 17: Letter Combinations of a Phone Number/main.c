#include <stdio.h>
#include <stdlib.h>

#define Size 8

// struct Data
// {
//     char *array;
// };

// struct Node
// {
//     int index;
//     struct Data data;
// };

// struct Data data[Size] = {
//     {"a", "b", "c"},
//     {"d", "e", "f"},
//     {"g", "h", "i"},
//     {"j", "k", "l"},
//     {"m", "n", "o"},
//     {"p", "q", "r", "s"},
//     {"t", "u", "v"},
//     {"w", "x", "y", "z"}
// };

// struct Node list[Size] ;

char *array[8]={
    {"a", "b", "c"},
    {"d", "e", "f"},
    {"g", "h", "i"},
    {"j", "k", "l"},
    {"m", "n", "o"},
    {"p", "q", "r", "s"},
    {"t", "u", "v"},
    {"w", "x", "y", "z"}
};

int main(int agrv, const char *argc[])
{   
    printf("Output %c\n", *(array[1])+1);
    return 0;
}