#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/ip.h>
#include <net/ip.h>
#include <linux/ethtool.h>

struct _net_driver
{
    struct net_device_stats status;
};

struct net_device *net;

int ndo_init_net(struct net_device *dev)
{
    printk("Init module success !");
    return 0;
}

void ndo_uninit_net(struct net_device *dev)
{
    printk("Uninit module success !");
}

int ndo_open_net(struct net_device *dev)
{
    netif_start_queue(dev);
    return 0;
}

int ndo_stop_net(struct net_device *dev)
{
    netif_stop_queue(dev);
    return 0;
}

netdev_tx_t ndo_start_xmit_net(struct sk_buff *skb, struct net_device *dev)
{
    return 0;
}

int ndo_do_ioctl_net(struct net_device *dev, struct ifreq *ifr, int cmd){
    return 0;
}

struct net_device_ops net_ops = {
    .ndo_init = ndo_init_net,
    .ndo_uninit = ndo_uninit_net,
    .ndo_open = ndo_open_net,
    .ndo_stop = ndo_stop_net,
    .ndo_start_xmit = ndo_start_xmit_net,
    .ndo_do_ioctl = ndo_do_ioctl_net,
};

struct header_ops net_header_ops = {

};

struct ethtool_ops net_ethtool_ops = {

};
void setup_driver(struct net_device *net_dev)
{
    ether_setup(net_dev);
    net_dev->netdev_ops = &net_ops;
    net_dev->header_ops = &net_header_ops;
    net_dev->ethtool_ops = &net_ethtool_ops;
}

static int __init init_net_driver(void)
{
    struct _net_driver *net_driver;

    net_driver = kzalloc(sizeof(struct _net_driver), GFP_KERNEL);
    if (!net_driver)
        return -ENOMEM;

    net = alloc_netdev(sizeof(struct _net_driver), "sn%d", NET_NAME_UNKNOWN, setup_driver);

    register_netdev(net);

    printk("Insert module success ! \n");

    return 0;
}

static void __exit exit_net_driver(void)
{
    unregister_netdev(net);
    printk("Remove module success ! \n");
}

module_init(init_net_driver);
module_exit(exit_net_driver);
MODULE_LICENSE("GPL");
