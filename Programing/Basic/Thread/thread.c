#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_t thread_1;

pthread_t thread_2;

void *a;

int value_global;

pthread_mutex_t p_mutex;

pthread_attr_t p_thread_attr ;

void *function_handle_thread(void *data)
{
	pthread_mutex_lock(&p_mutex);
	for (int i = 0; i < 50000; i++)
	{
		value_global++;
	}
	pthread_mutex_unlock(&p_mutex);
	return data;
};

int main(int argc, const char *argv[])
{
	if(pthread_mutex_init(&p_mutex, NULL) == 0){
		printf("Create mutex success !\n");
	}

	if(pthread_attr_init(&p_thread_attr) == 0){
		printf("Create attribute thread success !\n");
	}

	if(pthread_attr_setschedpolicy(&p_thread_attr,SCHED_OTHER) == 0){
		printf("Set attribute schedule  policy thread success !\n");
	}

	// create thread 1
	if (pthread_create(&thread_1, &p_thread_attr, function_handle_thread, "Thread 1") == 0)
	{
		printf("Create success thread 1!\n");
	}
	else
	{
		printf("Cannot create thread 1!\n");
	}

	// create thread 2
	if (pthread_create(&thread_2, &p_thread_attr, function_handle_thread, "Thread 2") == 0)
	{
		printf("Create success thread 2!\n");
	}
	else
	{
		printf("Cannot create thread 2!\n");
	}

	if (pthread_join(thread_1, &a) != 0)
	{
		printf("Cannot join thread 1!\n");
	}

	if (pthread_join(thread_2, &a) != 0)
	{
		printf("Cannot join thread 2!\n");
	}

	printf("Value = %d\n",value_global);

	pthread_mutex_destroy(&p_mutex);

	pthread_attr_destroy(&p_thread_attr);
	return 0;
}
