#include <linux/module.h>
#include <linux/pci.h>
#include <linux/mod_devicetable.h>

static struct pci_device_id table = {

};

static struct pci_driver pci ={
    .name = "pci_demo",
    .id_table = &table
};

static int __init init_module_PCI(void)
{
    if(pci_register_driver(&pci) < 0){
        printk("Cannot register driver pci ! \n");
    }
    printk("Insert module success ! \n");
    return 0;
}

static void __exit exit_module_PCI(void)
{
    pci_unregister_driver(&pci);
    printk("Remove module success ! \n");
}

module_init(init_module_PCI);
module_exit(exit_module_PCI);

MODULE_AUTHOR("NGUYEN");
MODULE_LICENSE("GPL");
