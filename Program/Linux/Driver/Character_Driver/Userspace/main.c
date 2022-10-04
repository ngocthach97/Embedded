#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/uio.h>
#include <stdint.h>

#define WRITE_VALUE _IOW('a', 'a', int32_t *)
#define READ_VALUE _IOR('a', 'b', int32_t *)

const char *path = "/dev/device_char";

// const char *message_to_kernel = "Nguyen Userspace";

// char message_to_user[30];

int main(const int argc, char *argv[])
{
    // int32_t _write, _read;
    int fd = open(path, O_RDWR);
    if (fd < 0)
    {
        printf("Cannot open file \n");
    }
    // int value_write = write(fd, message_to_kernel, strlen(message_to_kernel));
    // if (value_write < 0)
    // {
    //     printf("Cannot write file \n");
    // }
    // int value_read = read(fd, message_to_user, 30);
    // if (value_read < 0)
    // {
    //     printf("Cannot read file \n");
    // }
    // printf("%s \n", message_to_user);

    // printf("Enter the Value to send\n");
    // scanf("%d", &_write);
    // ioctl(fd, WRITE_VALUE, (int32_t *)&_write);

    // printf("Reading Value from Driver\n");
    // ioctl(fd, READ_VALUE, (int32_t *)&_read);

    // printf("Value is %d\n", _read);

    char *str0 = "hello ";
    char *str1 = "world\n";
    struct iovec iov[2];

    iov[0].iov_base = str0;
    iov[0].iov_len = strlen(str0);
    iov[1].iov_base = str1;
    iov[1].iov_len = strlen(str1);

    ssize_t _writev = writev(fd, iov, 2);

    close(fd);

    return 0;
}