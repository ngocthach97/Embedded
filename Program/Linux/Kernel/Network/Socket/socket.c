#include <linux/module.h>
#include <net/sock.h>
#include <net/protocol.h>
#include <linux/net.h> 


static int	demo_rcv(struct sk_buff *skb){
    return 0;
}

static int demo_err(struct sk_buff *skb, unsigned int info){
    return 0;
}

static const struct net_protocol demo_protocol = {
    .handler = demo_rcv,
    .err_handler = demo_err,
    .no_policy = 1,
    .netns_ok = 1,
};

void demo_close(struct sock *sk, long timeout)
{

}

int	demo_connect(struct sock *sk, struct sockaddr *uaddr, int addr_len){
    return 0;
}

int	demo_disconnect(struct sock *sk, int flags){
    return 0;
}

struct sock * demo_accept(struct sock *sk, int flags, int *err, bool kern){
    return NULL;
}

int	demo_ioctl(struct sock *sk, int cmd, unsigned long arg){
    return 0;
}

int demo_init_sock(struct sock *sk){
    return 0;
}

void demo_destroy(struct sock *sk){

}

void demo_shutdown(struct sock *sk, int how){

}

int demo_setsockopt(struct sock *sk, int level,int optname, sockptr_t optval,unsigned int optlen){
    return 0;
}

int demo_getsockopt(struct sock *sk, int level, int optname, char __user *optval, int __user *option){
    return 0;
}

int demo_sendmsg(struct sock *sk, struct msghdr *msg, size_t len){
    return 0;
}

int demo_recvmsg(struct sock *sk, struct msghdr *msg, size_t len, int noblock, int flags, int *addr_len){
    return 0;
}

int demo_bind(struct sock *sk, struct sockaddr *addr, int addr_len){
    return 0;
}

struct proto demo_prot = {
    .name = "Demo",
    .owner = THIS_MODULE,
    .close = demo_close,
    .connect = demo_connect,
    .disconnect = demo_disconnect,
    .accept = demo_accept,
    .ioctl = demo_ioctl,
    .init = demo_init_sock,
    .destroy = demo_destroy,
    .shutdown = demo_shutdown,
    .setsockopt = demo_setsockopt,
    .getsockopt = demo_getsockopt,
    .sendmsg = demo_sendmsg,
    .recvmsg = demo_recvmsg,
    .bind = demo_bind,
};


// static const struct proto_ops demo_prot_ops = {
//     .owner = THIS_MODULE,
//     .release = release_prot_ops,
//     .bind = bind_prot_ops,
//     .connect = connect_prot_ops,
// };

static int __init init_module_socket_demo(void)
{
    int rc = 0 ;
    rc = proto_register(&demo_prot, 0);
    if (rc < 0)
        goto out;
    rc = inet_add_protocol(&demo_protocol ,IPPROTO_ICMP); 
    printk("Insert module socket successfully ! \n");
    return 0;
out:
    return rc;
}

static void __exit exit_module_socket_demo(void)
{
    proto_unregister(&demo_prot);
    inet_del_protocol(&demo_protocol, IPPROTO_ICMP);
    printk("Exit module socket successfully ! \n");
}

module_init(init_module_socket_demo);
module_exit(exit_module_socket_demo);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NGUYEN");
MODULE_DESCRIPTION("MODULE SOCKET");
