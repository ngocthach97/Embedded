#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SIZE_BUFF 1024

#define PORT_CLIENT 8080

struct sockaddr_in sad_client;

int sock;

char message_send[] = "Hello server !";

char message_recv[SIZE_BUFF];

int main(int argc, const char *argv[])
{

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
		printf("Cannot create socket ! \n");
		return -1;
	}

	sad_client.sin_family = AF_INET;
	sad_client.sin_port = htons(PORT_CLIENT);

	if (connect(sock, (struct sockaddr *)&sad_client, sizeof(sad_client)) < 0)
	{
		printf("Cannot create conect socket ! \n");
		return -1;
	}
	
	while (send(sock, &message_send, strlen(message_send), 0) > 0)
	{
		if (recv(sock, &message_recv, SIZE_BUFF, 0) < 0)
		{
			printf("Cannot receive packet from server !\n");
		}
		printf("value recieve : %s\n", message_recv);
	}

	return 0;
}
