#include <stdio.h>
#include <time.h>

#define SIZE 64

size_t check;
time_t tt;
struct tm *tm;
char date_convert[SIZE];

int main(int agrv, const char *argc[])
{
    tt = time(&tt);
    tm = gmtime(&tt);
    printf("%s \n", asctime(tm));
    check = strftime(date_convert, SIZE, "%T %p",tm);
    if(check < 0){
        printf("Error convert date");
    }
    printf("%s \n", date_convert);
    printf("Check !\n");
    return 0;
}