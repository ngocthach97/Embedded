#include <stdio.h>
#include <stdbool.h>

bool isValid(char * s){
    return true ;
}

int main(int agrv, const char *argc[])
{
    char * s = "({[]})" ;
    bool b = isValid(s);
    return 0;
}