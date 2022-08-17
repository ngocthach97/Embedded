#include <stdio.h>
#include <unistd.h>

pid_t child;

int main(int argc, const char *argv[])
{
	child = fork();
	switch (child)
	{
	case -1:
		printf("Cannot create child process !\n");
		break;
	// process child
	case 0:
		printf("Create child process success !\n");
		printf("Process ID %d and Process ID parent %d \n", getpid(), getppid());
		for(;;);
		break;
	// process parent
	default:
		// printf("Process ID %d and Process ID parent %d \n", getpid(), getppid());
		break;
	}
	return 0;
}
