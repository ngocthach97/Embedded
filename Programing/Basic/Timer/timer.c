#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/times.h>

#define SIZE 64

struct timeval tv;
struct timezone tz;

size_t check;
time_t tt;
struct tm *tm;
char date_convert[SIZE];

clock_t check_process_time;
struct tms tms;

int main(int agrv, const char *argc[])
{
    gettimeofday(&tv, &tz);
    printf("Seconds since 00:00:00, 1 Jan 1970 UTC = %ld \n", tv.tv_sec);
    printf("Additional microseconds = %ld \n", tv.tv_usec);

    tt = time(&tt);

    tm = gmtime(&tt);

    printf("%s", asctime(tm));

    check = strftime(date_convert, SIZE, "%T %p", tm);
    if (check < 0)
    {
        printf("Error convert date");
    }
    printf("%s \n", date_convert);

    check_process_time = times(&tms);

    printf("User CPU time used by caller = %ld \n", tms.tms_utime);

    printf("System CPU time used by caller = %ld \n", tms.tms_stime);

    printf("User CPU time of all (waited for) children = %ld \n", tms.tms_cutime);

    printf("System CPU time of all (waited for) children = %ld \n", tms.tms_cstime);
    
    return 0;
}