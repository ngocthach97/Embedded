#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/slab.h>

static struct net_device *net_dev[2];

struct net_data
{
    int status;
};

static int net_init(struct net_device *dev)
{
    return 0;
}

static int net_open(struct net_device *dev)
{
    return 0;
}

static int net_stop(struct net_device *dev)
{
    return 0;
}

static int net_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
    return 0;
}

static struct net_device_ops net_ops = {
    .ndo_init = net_init,
    .ndo_open = net_open,
    .ndo_stop = net_stop,
    .ndo_start_xmit = net_start_xmit,
};

void setup_net(struct net_device *dev)
{
    struct net_data *net_data;
    ether_setup(dev);
    dev->netdev_ops = &net_ops;
    net_data = netdev_priv(dev);
    memset(net_data, 0, sizeof(struct net_data));
}

void netdev_cleanup(void)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        if (net_dev[i])
        {
            unregister_netdev(net_dev[i]);
            free_netdev(net_dev[i]);
        }
    }
}
static int __init init_module_network(void)
{
    int i;

    struct net_data *net_data;

    net_data = kzalloc(sizeof(struct net_data), GFP_KERNEL);

    if (!net_data)
        return -ENOMEM;

    net_dev[0] = alloc_netdev(sizeof(struct net_data), "%dnd", NET_NAME_UNKNOWN, setup_net);

    net_dev[1] = alloc_netdev(sizeof(struct net_data), "%dnd", NET_NAME_UNKNOWN, setup_net);

    if (net_dev[0] == NULL || net_dev[1] == NULL) {
		goto out;
	}

    net_data = netdev_priv(net_dev[0]);

	net_data = netdev_priv(net_dev[1]);

    for (i = 0; i < 2; i++)
    {
        if (register_netdev(net_dev[i]))
        {
            printk("Cannot register net device success !\n");
            goto out;
        }
    }

    printk("Insert module network driver success !\n");
    return 0;
out:
    netdev_cleanup();
    return -ENODEV;
}
static void __exit exit_module_network(void)
{
    netdev_cleanup();
    printk("Remove module network driver success !\n");
}

module_init(init_module_network);
module_exit(exit_module_network);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NGUYEN");