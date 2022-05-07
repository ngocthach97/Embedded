#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define FILE_DEVICE "/dev/nguyen_device"

#define BUFF_SIZE 1024 

int open_file(void){
	int fd = open(FILE_DEVICE, O_RDWR);	
	if(fd < 0){
		printf("Cannot open file ! \n");
	}
	return fd;
}

void close_file(int fd){
	close(fd);
}

void write_file(void){
	char buff[BUFF_SIZE];
	printf("Enter your message: ");
	scanf(" %[^\n]s", buff);
	int fd = open_file();
	int value = write(fd, buff, strlen(buff) + 1);
	close_file(fd);
	if(value == -1){
		printf("Cannot write file ! \n");
	}
}

void read_file(void){
	char buff[BUFF_SIZE];
	int fd = open_file();
	int value = read(fd, buff, BUFF_SIZE);
	close_file(fd);
	if (value == -1){
		printf("Cannot read file ! \n");
	}
	printf("Value = %s \n",buff);
}

int main(int argc , const char* argv[]){
	write_file();
	read_file();
	return 0;
}
