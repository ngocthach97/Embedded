#include <stdio.h>
#include <sys/socket.h>
#include <pthread.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define SIZE_BUFF 1024
#define PORT_SERVER 8080
#define SIZE_LIST 100

typedef struct
{
	struct sockaddr_in addr_client;
	int sock_client;
	int uid;
} client;

static int uid = 0;

client *list_client[SIZE_LIST];

int sock_server;
int sock_client;
struct sockaddr_in sad_server;
struct sockaddr_in sad_client;
char message_recv[SIZE_BUFF];
char message_send[] = "hello world";
pthread_mutex_t p_mutex;
pthread_t p_therad;
void *a;

void add_list(client *client)
{
	pthread_mutex_lock(&p_mutex);
	for (int i = 0; i < SIZE_LIST; i++)
	{
		if (!list_client[i])
		{
			list_client[i] = client;
			break;
		}
	}
	pthread_mutex_unlock(&p_mutex);
}

void *function_handle_thread(void *data)
{
	client *cli = (client *)data;

	while (recv(cli->sock_client, &message_recv, SIZE_BUFF, 0) > 0)
	{
		printf("value recieve : %s\n", message_recv);
		if (send(cli->sock_client, &message_send, strlen(message_send), 0) < 0)
		{
			printf("Cannot receive packet to client !\n");
		}
	}
	return NULL;
}

int main(int argc, const char *argv[])
{
	if (pthread_mutex_init(&p_mutex, NULL) < 0)
	{
		printf("Cannot create mutex !\n");
	}

	int size_addr = sizeof(sad_client);

	sock_server = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_server < 0)
	{
		printf("Cannot create socket in server !\n");
		return -1;
	}
	sad_server.sin_family = AF_INET;
	sad_server.sin_port = htons(PORT_SERVER);
	sad_server.sin_addr.s_addr = INADDR_ANY;
	if (bind(sock_server, (struct sockaddr *)&sad_server, sizeof(sad_server)) < 0)
	{
		printf("Cannot create bind in server !\n");
	}
	if (listen(sock_server, 3) < 0)
	{
		printf("Cannot create listen in server !\n");
	}
	while (1)
	{
		sock_client = accept(sock_server, (struct sockaddr *)&sad_client, (socklen_t *)&size_addr);
		if (sock_client < 0)
		{
			printf("Cannot create accept in server to client !\n");
		}
		client *cli = (client *)malloc(sizeof(client));
		cli->addr_client = sad_client;
		cli->sock_client = sock_client;
		cli->uid = uid++;
		add_list(cli);

        pthread_create(&p_therad, NULL, &function_handle_thread, (void*)cli);
		
		if (sock_client < 0)
		{
			return -1;
		}
	}
	return 0;
}
