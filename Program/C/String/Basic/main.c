#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char string1[] = "Nguyen Ngoc Thach";
char string2[] = "nguyen ngoc thach";

int main(int agrv, const char *argc[])
{
    memset(string1, '#', 12);

    printf("%s \n", string1);

    int length;

    length = strlen(string1);

    printf("Length string = %d \n", length);

    int value_compare;

    value_compare = strcmp(string1, string2);

    if (value_compare == 0)
    {
        printf("string1 is equal to string2 \n");
    }
    else if (value_compare > 0)
    {
        printf("string2 is less than string1 \n");
    }
    else
    {
        printf("string1 is less than string2 \n");
    }

    printf("%s \n", strcpy(string2, string1));

    
    return 0;
}
