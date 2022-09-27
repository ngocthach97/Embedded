#include <linux/netdevice.h>
#include <linux/module.h>
#include <linux/kernel.h>

struct net_device net[2];

static int __init init_net_driver(void)
{
    prink("Insert module success ! \n");
    return 0;
}

static void __exit exit_net_driver(void)
{
    prink("Remove module success ! \n");
}

module_init(init_net_driver);
module_exit(exit_net_driver);
MODULE_LICENSE("GPL");
