
#include <linux/module.h> 

static int __init init_module_driver(void)
{
	printk("Device Driver Insert...Done! \n");
	return 0;
}

static void __exit exit_module_driver(void)
{
	printk("Device Driver Remove...Done! \n");
}

module_init(init_module_driver);
module_exit(exit_module_driver);

MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("Nguyen"); 
MODULE_DESCRIPTION("Nguyen"); 
MODULE_SUPPORTED_DEVICE("Just For Fun"); 
