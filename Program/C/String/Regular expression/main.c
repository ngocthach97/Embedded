#include <stdio.h>
#include <regex.h>

int main(int agrv, const char *argc[])
{
    regex_t regex;

    int value;

    value = regcomp(&regex, "[0-9]", 0);

    value = regexec(&regex, "icecream", 0, NULL, 0);

    if (value == 0)
    {
        printf("Pattern found.\n");
    }
    else if (value == REG_NOMATCH)
    {
        printf("Pattern not found.\n");
    }
    else
    {
        printf("An error occured.\n");
    }
    return 0;
}
