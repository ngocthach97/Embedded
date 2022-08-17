#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/stat.h>
#include <linux/sysfs.h>
#include <linux/pnp.h>
#include <linux/mod_devicetable.h>

static const struct pnp_device_id pnp_table_demo = {

};

static void remove_pnp_demo(struct pnp_dev *dev){
    printk("Remove pnp ! \n");
}

static struct pnp_driver pnp_demo = {
    .name = "pnp_demo",
    .id_table = &pnp_table_demo,
    .remove = remove_pnp_demo,
};

struct kobject *kobject_demo;

// Kobject type
void release_kobj_type_demo(struct kobject *kobj)
{
    printk("release_kobject_type_demo !\n");
}

struct kobj_type kobj_type_demo = {
    .release = release_kobj_type_demo,
};

// Bus type
int match_bus_demo(struct device *dev, struct device_driver *drv)
{
    printk("Match bus ! \n");
    return 0;
}

int remove_bus_demo(struct device *dev)
{
    printk("Remove bus ! \n");
    return 0;
}

int uevent_bus_demo(struct device *dev, struct kobj_uevent_env *env)
{
    return 0;
}

struct bus_type bus_type_demo = {
    .name = "bus_demo",
    .match = match_bus_demo,
    .remove = remove_bus_demo,
    .uevent = uevent_bus_demo,
};

// Bus attribute
ssize_t demo_show(struct bus_type *bus, char *buf)
{
    return 0;
}

ssize_t demo_store(struct bus_type *bus, const char *buf, size_t count)
{
    return 0;
}

static  BUS_ATTR_WO(demo);

// Device driver
int remove_device_driver_demo(struct device *dev)
{
    return 0;
}

struct device_driver device_driver_demo = {
    .name = "device_driver_demo",
    .bus = &bus_type_demo,
    .remove = remove_device_driver_demo,
};

// Class
void class_release_demo(struct class *class)
{
    printk("Release class success ! \n");
}

struct class class_demo = {
    .name = "class_demo",
    .class_release = class_release_demo,
};

// Device type
void release_device_type(struct device *dev){
     printk("Release device type success ! \n");
}

struct device_type device_type_demo = {
    .name = "device_type_demo",
    .release = release_device_type,
};

// Device Attribute
ssize_t show_device_demo(struct device *dev, struct device_attribute *attr, char *buf)
{
    return 0;
}

ssize_t store_device_demo(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
    return 0;
}

DEVICE_ATTR(device, S_IWUSR, show_device_demo, store_device_demo);

struct device device_demo = {
    .init_name = "device_demo",
    .type = &device_type_demo,
    .bus = &bus_type_demo,
    .driver = &device_driver_demo,
    .class = &class_demo,
};

int __init init_module_device(void)
{
    kobject_demo = kobject_create_and_add("kobject_demo", NULL);

    kobject_demo->ktype = &kobj_type_demo ;

    if(sysfs_create_file(kobject_demo, NULL)){
	    printk("Cannot create file sysfs ! \n");
    }

    if (bus_register(&bus_type_demo) < 0)
    {
        printk("Cannot register bus type success ! \n");
    }
    if (bus_create_file(&bus_type_demo, &bus_attr_demo))
    {
        printk("Cannot create bus file success ! \n");
    }

    if (class_register(&class_demo) < 0){
        printk("Cannot create class success ! \n");
    }

    if (device_create_file(&device_demo, &dev_attr_device))
    {
        printk("Cannot create device file success ! \n");
    }

    if (device_register(&device_demo) < 0){
       printk("Cannot register device success ! \n"); 
    }
    if(pnp_register_driver(&pnp_demo) < 0){
        printk("Cannot register pnp driver ! \n");
    }
    printk("Insert module success ! \n");
    return 0;
}

void __exit exit_module_device(void)
{
    device_unregister(&device_demo);
    class_unregister(&class_demo);
    bus_unregister(&bus_type_demo);
    bus_remove_file(&bus_type_demo, &bus_attr_demo);
    device_remove_file(&device_demo, &dev_attr_device);
    pnp_unregister_driver(&pnp_demo);
    printk("Remove module success ! \n");
}

module_init(init_module_device);
module_exit(exit_module_device);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NGUYEN");
