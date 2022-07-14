#include <linux/module.h>

static int __init init_module_filesystem(void){
    printk("Insert module filesystem ! \n");
    return 0;
}

static void __exit exit_module_filesystem(void){
     printk("Remove module filesystem ! \n");
}

module_init(init_module_filesystem);
module_exit(exit_module_filesystem);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nguyen");