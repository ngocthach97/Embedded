#include <linux/fs.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>

struct _chrdev_typedef
{
	dev_t num;
	struct task_struct *pthread1;
	struct task_struct *pthread2;
	struct device *pdevice;
	struct class *pclass;
	struct cdev *pcdev;
} pchrdev;

DEFINE_SPINLOCK(p_spinlock);

int value_global = 0;

static int i_link (struct dentry * d_dty ,struct inode * s_inode ,struct dentry *s_dty){
	d_dty->d_parent = s_dty;
	d_dty->d_inode = s_inode;
	return 0;
}

static struct inode_operations inode_op = {
	.link = i_link,
};


int function_handle_thread1(void *data)
{
	while (!kthread_should_stop())
	{
		if (!spin_is_locked(&p_spinlock))
		{
			printk("spin_lock is not locked in thread 1 !\n");
		}
		spin_lock(&p_spinlock);
		value_global++;
		printk("value global in thread 1 = %d", value_global);
		spin_unlock(&p_spinlock);
		msleep(1000);
	}
	return 0;
}

int function_handle_thread2(void *data)
{
	while (!kthread_should_stop())
	{
		if (!spin_is_locked(&p_spinlock))
		{
			printk("spin_lock is not locked in thread 2 !\n");
		}
		spin_lock(&p_spinlock);
		value_global--;
		printk("value global in thread 2 = %d", value_global);
		spin_unlock(&p_spinlock);
		msleep(1000);
	}
	return 0;
}

ssize_t write_file(struct file *pfile, const char __user *puser, size_t psize, loff_t *ploff_t)
{
	char *buff = NULL;
	buff = kzalloc(psize, GFP_KERNEL);
	if (copy_from_user(buff, puser, psize) != 0)
	{
		return -EFAULT;
	}
	printk("Write file ! \n");
	printk("%s", buff);
	return 0;
}

ssize_t read_file(struct file *pfile, char __user *puser, size_t psize, loff_t *ploff_t)
{
	char *buff = NULL;
	buff = kzalloc(psize, GFP_KERNEL);
	memset(buff, 0, 1024);
	if (copy_to_user(puser, buff, psize) != 0)
	{
		return -EFAULT;
	}
	printk("Read file ! \n");
	return 0;
}

int open_file(struct inode *pinode, struct file *pfile)
{
	struct inode *in = pinode;
	in->i_op = &inode_op;
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

	if (alloc_chrdev_region(&pchrdev.num, 0, 1, "nguyen_device") != 0)
	{
		printk("Cannot alloc major and minor ! \n");
	}

	printk("Number major = %d , Munber minor = %d \n", MAJOR(pchrdev.num), MINOR(pchrdev.num));

	pchrdev.pclass = class_create(THIS_MODULE, "class device");

	if (pchrdev.pclass == NULL)
	{
		printk("Cannot create class ! \n");
	}

	pchrdev.pdevice = device_create(pchrdev.pclass, NULL, pchrdev.num, NULL, "nguyen_device");

	if (IS_ERR(pchrdev.pdevice))
	{
		printk("Cannot create device ! \n");
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

	pchrdev.pthread1 = kthread_run(function_handle_thread1, NULL, "thread_1");
	if (IS_ERR(pchrdev.pthread1))
	{
		printk("Cannot create thread 1 ! \n");
	}

	pchrdev.pthread2 = kthread_run(function_handle_thread2, NULL, "thread_2");
	if (IS_ERR(pchrdev.pthread2))
	{
		printk("Cannot create thread 2 ! \n");
	}

	printk("Insert module success ... ! \n");
	return 0;
}

static void __exit exit_module_driver(void)
{

	kthread_stop(pchrdev.pthread1);

	kthread_stop(pchrdev.pthread2);

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
MODULE_SUPPORTED_DEVICE("nguyen_device");
