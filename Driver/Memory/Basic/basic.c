#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/mm.h>

struct _chrdev
{
    dev_t num;
    struct class *pclass;
    struct device *pdevice;
    struct cdev *pcdev;

} chrdev;

ssize_t read_file(struct file *pfile, char __user *puser, size_t psize, loff_t *ploff)
{
    printk("Read file !\n");
    return 0;
}

ssize_t write_file(struct file *pfile, const char __user *puser, size_t psize, loff_t *ploff)
{
    printk("Write file !\n");
    return 0;
}

int open_file(struct inode *pinode, struct file *pfile)
{
    printk("Open file !\n");
    return 0;
}

int release_file(struct inode *pinode, struct file *pfile)
{
    printk("Release file !\n");
    return 0;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = open_file,
    .release = release_file,
    .write = write_file,
    .read = read_file,
};

static int __init init_module_memory(void)
{
    if (alloc_chrdev_region(&chrdev.num, 0, 1, "number_chrdev") < 0)
    {
        printk("Cannot alloc number mojor and number minor !\n");
        return -1;
    }
    chrdev.pclass = class_create(THIS_MODULE, "class_chrdev");
    if (chrdev.pclass == NULL)
    {
        printk("Cannot create class !\n");
        goto create_class_failed;
    }

    chrdev.pdevice = device_create(chrdev.pclass, NULL, chrdev.num, NULL, "device_chrdev");
    if (chrdev.pdevice == NULL)
    {
        printk("Cannot create device !\n");
        goto create_device_failed;
    }

    chrdev.pcdev = cdev_alloc();
    if (chrdev.pcdev == NULL)
    {
        printk("Cannot alloc cdev !\n");
    }
    cdev_init(chrdev.pcdev, &fops);

    if (cdev_add(chrdev.pcdev, chrdev.num, 1) < 0)
    {
        printk("Cannot add cdev to system !\n");
    }
    printk("Insert module memory success !\n");
    return 0;

create_device_failed:
    class_destroy(chrdev.pclass);
create_class_failed:
    unregister_chrdev_region(chrdev.num, 1);
    return -1;
}

static void __exit exit_module_memory(void)
{
    printk("Remove module memory success !\n");
}

module_init(init_module_memory);
module_exit(exit_module_memory);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NGUYEN");
