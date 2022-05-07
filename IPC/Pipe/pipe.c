#include <stdio.h>
#include <unistd.h>
#include <string.h>
int pipe_fd[2];

void parentToChild(void){
	close(pipe_fd[1]);
	char buff[128];
	if(read(pipe_fd[0],buff,128) == -1){
		printf("Cannot read pipe \n");
	}
	printf("Value = %s \n",buff);
	close(pipe_fd[0]);

}

void childToParent(void){
	close(pipe_fd[0]);
	char *value = "Just for fun";
	if(write(pipe_fd[1] , value , strlen(value)+1) == -1){
		printf("Cannot write pipe \n");
	}
	close(pipe_fd[1]);
}

int main(int argc,char *argv[]){
	pid_t childPid ;
	if(pipe(pipe_fd) == -1){
		printf("create pipe faild \n");
	}
	switch(childPid = fork()){
		case -1 :
			printf("error create process \n");
			break;
		case 0 :
			printf("process child \n");
			childToParent();
			break;
		default :
			printf("process parent \n");
			parentToChild();
			break;	

	}
	return 0 ;
}
