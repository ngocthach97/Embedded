#include <linux/module.h>

static int __init init_module_memory(void){
    printk("Insert module memory success !\n");
    return 0;
}

static void __exit exit_module_memoty(void){
    printk("Remove module memory success !\n");
}

module_init(init_module_memory);
module_exit(exit_module_memoty);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NGUYEN");    
