#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Dung ham signal de tao signal

void function_handle_signal(int data){
	if(data == 2){
		printf("Function handle signal ! \n");
	}
}
int main(int argc, const char *argv[])
{
	printf("Wait handle signal\n");
	if(signal(SIGINT, function_handle_signal) == SIG_ERR){
		printf("Cannot create signal");
	}
	for(;;);
	return 0;
}

// Dung ham sigaction de tao signal

void function_handle_signal(int data)
{
	if (data == 2)
	{
		printf("Function handle signal \n");
	}
}

struct sigaction p_sigaction;

int main(int argc, const char *argv[])
{
	p_sigaction.sa_handler = &function_handle_signal;
	p_sigaction.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &p_sigaction, NULL) == -1)
	{
		printf("Cannot create signal ! \n");
	}
	for (;;);
	return 0;
}