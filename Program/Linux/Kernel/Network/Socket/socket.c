#include <linux/module.h>
#include <linux/net.h>

struct proto_ops demo_ops = {

};

static int __init init_socket_module(void)
{
    printk("Insert module success ! \n");
    return 0;
}

static void __exit exit_socket_module(void)
{
    printk("Remove module success ! \n");
}

module_init(init_socket_module);
module_exit(exit_socket_module);
MODULE_LICENSE("GPL");