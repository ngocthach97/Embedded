#include <linux/module.h>

static int __init init_module_share_memory(void){
    printk("Insert module share memory success !\n");
    return 0;
}
static void __exit exit_module_share_memory(void){
   printk("Remove module share memory success !\n");
}

module_init(init_module_share_memory);
module_exit(exit_module_share_memory);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NGUYEN");