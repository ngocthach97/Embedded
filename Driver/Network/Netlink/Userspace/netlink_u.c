#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <asm/types.h>
#include <linux/netlink.h>
#include <string.h>
#include <unistd.h>
#define NETLINK_USER 17
#define  MAX_PAYLOAD 1024
int fd ;

struct sockaddr_nl addr_sr ,addr_des;

struct nlmsghdr *message;

struct iovec iov;

struct msghdr msg;

int main(int agrc, const char* argv[]){
	fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_USER);
	addr_sr.nl_family = AF_NETLINK;
	addr_sr.nl_pid = getpid();
	addr_sr.nl_groups = 0;
	bind (fd, (struct sockaddr *)& addr_sr , sizeof(addr_sr));
	addr_des.nl_family = AF_NETLINK;
	addr_des.nl_pid = 0;
	addr_des.nl_groups = 0;
	message =(struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
	message->nlmsg_len = NLMSG_SPACE(MAX_PAYLOAD);
	message->nlmsg_pid = getpid();
	message->nlmsg_flags = 0;
	strcpy(NLMSG_DATA(message), "Hello nelink");
	iov.iov_base =(void *)message;
	iov.iov_len = message->nlmsg_len;
	msg.msg_name = (void *)&addr_des;
	msg.msg_namelen = sizeof(addr_des);
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;

	printf("Sending message to kernel\n");
    sendmsg(fd,&msg,0);
 
    //printf("Waiting for message from kernel\n");
 
    /* Read message from kernel */
    // recvmsg(sock_fd, &msg, 0);
    // printf("Received message payload: %s\n", (char *)NLMSG_DATA(nlh));
    close(fd);

	return 0;
}
