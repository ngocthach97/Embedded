#include <linux/module.h>
#include <linux/netlink.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <net/sock.h>
#include <net/net_namespace.h>
#define NETLINK_TEST 17

struct _pnetlink{
	struct sock *psock;
} pnetlink;

void netlink_input(struct sk_buff *skb){
	struct nlmsghdr *nlh = NULL;
	if(skb == NULL){
		printk("socket buff is NULL !\n");
		return;
	}
	nlh = (struct nlmsghdr *)skb->data;
	printk("Received netlink message payload: %s\n", (char *)NLMSG_DATA(nlh));
}

struct netlink_kernel_cfg netlink_cfg = {
	.input = netlink_input,
};

static int __init init_module_netlink(void){
	pnetlink.psock = netlink_kernel_create(&init_net,NETLINK_TEST,&netlink_cfg);
	printk("Insert module netlink success ! \n");
	return 0;
}

static void __exit exit_module_netlink(void){
	sock_release(pnetlink.psock->sk_socket);
	printk("Remove module netlink success !\n");
}

module_init(init_module_netlink);
module_exit(exit_module_netlink);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("NGUYEN");
MODULE_DESCRIPTION("MODULE NETLINK");
