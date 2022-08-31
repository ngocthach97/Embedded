#include <linux/module.h>

static int __init init_module_netfilter_demo(void)
{
    printk("Insert module netfilter successfully ! \n");
    return 0;
}

static void __exit exit_module_netfilter_demo(void)
{
    printk("Exit module netfilter successfully ! \n");
}

module_init(init_module_netfilter_demo);
module_exit(exit_module_netfilter_demo);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NGUYEN");
MODULE_DESCRIPTION("MODULE NETFILTER");