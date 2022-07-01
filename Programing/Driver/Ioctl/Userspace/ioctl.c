#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/ioctl.h>
#include <poll.h>
// #define WR_VALUE _IOR ('a', 'cmd_1', int32_t*)

// #define RD_VALUE _IOW ('a', 'cmd_2', int32_t*)
 
int main(int argc , const char *argv[])
{
        int fd;
        int32_t value, number;
        struct pollfd plf;

        printf("\nOpening Driver\n");
        fd = open("/dev/device_chrdev", O_RDWR);
        if(fd < 0) {
                printf("Cannot open device file...\n");
                return 0;
        }

        plf.fd = fd;
        plf.events = ( POLLIN | POLLRDNORM | POLLOUT | POLLWRNORM );
 
        // printf("Enter the Value to send\n");
        // scanf("%d",&number);
        // printf("Writing Value to Driver\n");
        // ioctl(fd, WR_VALUE, (int32_t*) &number); 
 
        // printf("Reading Value from Driver\n");
        // ioctl(fd, RD_VALUE, (int32_t*) &value);
        // printf("Value is %d\n", value);

        if(poll(&plf, (unsigned long)1, 5000) < 0){
                printf("Error !\n");
        }
        printf("Closing Driver\n");
        close(fd);
}