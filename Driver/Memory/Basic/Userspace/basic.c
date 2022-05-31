#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
const int SIZE = 4096; 
const char Path[] = "/dev/device_chrdev";

int fd ;
int main(int argv, const char *argc[]){
    
    fd = open(Path, O_RDWR);
    if(fd < 0){
        printf("Cannot open file !\n");
        return -1;
    }
    if(mmap(NULL, SIZE, PROT_WRITE, MAP_SHARED,  fd, 0) == MAP_FAILED){
        printf("Cannot mmap !\n");
    }
    printf("pid = %d",getpid());

    return 0;
}