#include <net/protocol.h>
#include <net/sock.h>
#include <net/netns/generic.h>
#include <net/net_namespace.h>
#include <linux/module.h>
#include <linux/skbuff.h>
#include <linux/pid_namespace.h>

struct ns_data
{
    struct sock *sk;
};

static unsigned int net_id;

static int icmp_rcv(struct sk_buff *skb)
{
    return 0;
}

static void icmp_err(struct sk_buff *skb, int info)
{
    printk("Handle err ICMP protocol !\n");
}

static struct net_protocol icmp_pl = {
    .handler = icmp_rcv,
    .err_handler = icmp_err,
    .no_policy = 1,
    .netns_ok = 1,
};

static int __net_init icmp_sk_init(struct net *net)
{
    struct ns_data *data = net_generic(net, net_id);
    return 0;
}

static __net_exit void icmp_sk_exit(struct net *net)
{
    struct ns_data *data = net_generic(net, net_id);
    netlink_kernel_release(data->sk);
}

static struct pernet_operations net_ops = {
    .init = icmp_sk_init,
    .exit = icmp_sk_exit,
    .id = &net_id,
    .size = sizeof(struct ns_data),
};

static int __init init_module_icmp(void)
{
    register_pernet_subsys(&net_ops);
    if (inet_add_protocol(&icmp_pl, IPPROTO_ICMP) < 0)
        printk("Cannot add ICMP protocol\n");
    printk("Insert module icmp success !\n");
    return 0;
}
static void __exit exit_module_icmp(void)
{
    unregister_pernet_subsys(&net_ops);
    inet_del_protocol(&icmp_pl, IPPROTO_ICMP);
    printk("Remove module icmp success !\n");
}

module_init(init_module_icmp);
module_exit(exit_module_icmp);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NGUYEN");
