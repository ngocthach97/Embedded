#include <linux/fs.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/mutex.h>

struct _chrdev
{
    dev_t num;
    struct task_struct *pthread1;
    struct task_struct *pthread2;
    struct device *pdevice;
    struct class *pclass;
    struct cdev *pcdev;
    struct mutex pmutex;
} pchrdev;

int value_global = 0;

int function_handle_thread1(void *data)
{
    while (!kthread_should_stop())
    {
        mutex_lock(&pchrdev.pmutex);
        value_global++;
        printk("value global in thread 1 = %d", value_global);
        mutex_unlock(&pchrdev.pmutex);
        msleep(1000);
    }
    return 0;
}

int function_handle_thread2(void *data)
{
    while (!kthread_should_stop())
    {
        mutex_lock(&pchrdev.pmutex);
        value_global++;
        printk("value global in thread 2 = %d", value_global);
        mutex_unlock(&pchrdev.pmutex);
        msleep(1000);
    }
    return 0;
}

ssize_t write_file(struct file *pfile, const char __user *puser, size_t psize, loff_t *ploff_t)
{
    printk("Write file ! \n");
    return 0;
}

ssize_t read_file(struct file *pfile, char __user *puser, size_t psize, loff_t *ploff_t)
{
    printk("Read file ! \n");
    return 0;
}

int open_file(struct inode *pinode, struct file *pfile)
{
    printk("Open file ! \n");
    return 0;
}

int release_file(struct inode *pinode, struct file *pfile)
{
    printk("Release file ! \n");
    return 0;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .read = read_file,
    .write = write_file,
    .release = release_file,
    .open = open_file,
};

static int __init init_module_driver(void)
{

    if (alloc_chrdev_region(&pchrdev.num, 0, 1, "number_device") != 0)
    {
        printk("Cannot alloc major and minor ! \n");
        return -1;
    }

    printk("Number major = %d , Munber minor = %d \n", MAJOR(pchrdev.num), MINOR(pchrdev.num));

    pchrdev.pclass = class_create(THIS_MODULE, "class_device");
    if (pchrdev.pclass == NULL)
    {
        printk("Cannot create class ! \n");
        goto failed_create_class;
    }

    pchrdev.pdevice = device_create(pchrdev.pclass, NULL, pchrdev.num, NULL, "nguyen_device");
    if (IS_ERR(pchrdev.pdevice))
    {
        printk("Cannot create device ! \n");
        goto failed_create_device;
    }

    pchrdev.pcdev = cdev_alloc();

    if (pchrdev.pcdev == NULL)
    {
        printk("Cannot alloc cdev !\n");
    }

    cdev_init(pchrdev.pcdev, &fops);

    if (cdev_add(pchrdev.pcdev, pchrdev.num, 1) < 0)
    {
        printk("Cannot add cdev to system ! \n");
    }

    mutex_init(&pchrdev.pmutex);

    pchrdev.pthread1 = kthread_run(function_handle_thread1, NULL, "thread_1");
    if (!pchrdev.pthread1)
    {
        printk("Cannot create thread 1 ! \n");
        goto failed_create_device;
    }

    pchrdev.pthread2 = kthread_run(function_handle_thread2, NULL, "thread_2");
    if (!pchrdev.pthread2)
    {
        printk("Cannot create thread 2 ! \n");
        goto failed_create_device;
    }

failed_create_class:
    unregister_chrdev_region(pchrdev.num, 1);

failed_create_device:
    class_destroy(pchrdev.pclass);

    printk("Insert module success ... ! \n");
    return 0;
}

static void __exit exit_module_driver(void)
{

    kthread_stop(pchrdev.pthread1);

    kthread_stop(pchrdev.pthread2);

    // mutex_destroy(&pchrdev.pmutex);

    cdev_del(pchrdev.pcdev);

    device_destroy(pchrdev.pclass, pchrdev.num);

    class_destroy(pchrdev.pclass);

    unregister_chrdev_region(pchrdev.num, 1);

    printk("Remove module success ... ! \n");

}

module_init(init_module_driver);
module_exit(exit_module_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nguyen");
MODULE_VERSION("0.0.1");
MODULE_DESCRIPTION("Just for fun !");
