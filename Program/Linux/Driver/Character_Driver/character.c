#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/platform_device.h>
#include <linux/mod_devicetable.h>
#include <linux/device/driver.h>
#include <linux/uio.h>

#define WRITE_VALUE _IOW('a', 'a', int32_t *)
#define READ_VALUE _IOR('a', 'b', int32_t *)

int32_t value = 0;

struct _char_driver
{
    dev_t dev_char;
    struct class *class_char;
    struct device *device_char;
    struct cdev *cdev_char;
} char_driver;

int open_file(struct inode *inode, struct file *file)
{
    printk("Open file ! \n");
    return 0;
}

int release_file(struct inode *inode, struct file *file)
{
    printk("Release file ! \n");
    return 0;
}

ssize_t read_file(struct file *file, char __user *user_buff, size_t len, loff_t *loff)
{
    char kernel_buff[30] = "Nguyen Kernelspace";
    if (copy_to_user(user_buff, kernel_buff, 30))
        return -EFAULT;
    printk("Read file ! \n");
    return 0;
}

ssize_t write_file(struct file *file, const char __user *user_buff, size_t len, loff_t *loff)
{
    char *kernel_buff = kzalloc(len, GFP_KERNEL);
    if (copy_from_user(kernel_buff, user_buff, len))
        return -EFAULT;
    printk("%s \n", kernel_buff);
    printk("Write file ! \n");
    return 0;
}

long unlocked_ioctl_file(struct file *, unsigned int cmd, unsigned long arg)
{
    switch (cmd)
    {
    case WRITE_VALUE:
        if (copy_from_user(&value, (int32_t *)arg, sizeof(value)))
            return -EFAULT;
        printk("write number %d! \n", value);
        break;
    case READ_VALUE:
        if (copy_to_user((int32_t *)arg, &value, sizeof(value)))
            return -EFAULT;
        break;
    default:
        break;
    }
    return 0;
}

ssize_t read_iter_file(struct kiocb *kb, struct iov_iter *ii)
{
    printk("Read iter ! \n ");
    return 0;
}

ssize_t write_iter_file(struct kiocb *kb, struct iov_iter *ii)
{
    size_t length = iov_iter_count(ii);
    struct iovec iv = iov_iter_iovec(ii);
    printk("Write iter %ld ! \n", length);
    printk("%ld ! \n", iv.iov_len);
    printk("%p ! \n", iv.iov_base);
    return 0;
}

struct file_operations file_ops = {
    .owner = THIS_MODULE,
    .open = open_file,
    .release = release_file,
    .read = read_file,
    .write = write_file,
    .unlocked_ioctl = unlocked_ioctl_file,
    .read_iter = read_iter_file,
    .write_iter = write_iter_file,
};

int probe_char(struct platform_device *pdev)
{
    return 0;
}
int remove_char(struct platform_device *pdev)
{
    return 0;
}
void shutdown_char(struct platform_device *pdev)
{
}
int suspend_char(struct platform_device *pdev, pm_message_t state)
{
    return 0;
}
int resume_char(struct platform_device *pdev)
{
    return 0;
}

struct platform_driver char_pdrv =
    {
        .probe = probe_char,
        .remove = remove_char,
        .shutdown = shutdown_char,
        .suspend = suspend_char,
        .resume = resume_char,
        .driver = {
            .name = "char_driver",
            .owner = THIS_MODULE,
        },
};

static int __init init_module_character(void)
{
    int value;
    value = alloc_chrdev_region(&char_driver.dev_char, 0, 1, "char_num");
    if (value != 0)
    {
        printk("Cannot allocation major and minor number ! \n");
    }
    printk("Major number %d and Minor number %d \n", MAJOR(char_driver.dev_char), MINOR(char_driver.dev_char));
    char_driver.class_char = class_create(THIS_MODULE, "class char");
    if (char_driver.class_char == NULL)
    {
        printk("Cannot create class ! \n");
    }
    char_driver.device_char = device_create(char_driver.class_char, NULL, char_driver.dev_char, NULL, "device_char");
    if (char_driver.device_char == NULL)
    {
        printk("Cannot create device ! \n");
    }
    char_driver.cdev_char = cdev_alloc();
    cdev_init(char_driver.cdev_char, &file_ops);
    value = cdev_add(char_driver.cdev_char, char_driver.dev_char, 1);
    if (value < 0)
    {
        printk("Cannot add device to system !\n");
    }

    platform_driver_register(&char_pdrv);
    printk("Insert module success ! \n");
    return 0;
}

static void __exit exit_module_character(void)
{
    cdev_del(char_driver.cdev_char);

    device_destroy(char_driver.class_char, char_driver.dev_char);

    class_destroy(char_driver.class_char);

    unregister_chrdev_region(char_driver.dev_char, 1);

    platform_driver_unregister(&char_pdrv);

    printk("Remove module success ! \n");
}

module_init(init_module_character);
module_exit(exit_module_character);
MODULE_LICENSE("GPL");