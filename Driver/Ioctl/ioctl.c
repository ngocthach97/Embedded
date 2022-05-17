#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/ioctl.h>

#define WR_VALUE _IOR ('a', 'cmd_1', int32_t*)

#define RD_VALUE _IOW ('a', 'cmd_2', int32_t*)

int32_t value = 0;

struct _pchrdev {
	dev_t pnum;
	struct device *pdevice;
	struct class *pclass;
	struct cdev *pcdev;
} pchrdev;

static ssize_t read_file(struct file *pfile, char __user *puser, size_t psize, loff_t *ploff){
	printk("Read file !\n");
	return 0;
}

static ssize_t write_file(struct file *pfile, const char __user *puser, size_t psize, loff_t *ploff){
	printk("Write file !\n");
	return 0;
}

static int open_file(struct inode *pinode, struct file *pfile){
	printk("Open file !\n");
	return 0;
}

static int release_file(struct inode *pinode, struct file *pfile){
	printk("Release file !\n");
	return 0;
}

static long ioctl_file(struct file *pfile, unsigned int cmd, unsigned long arg){
	memset((void *)&value, 0, sizeof(value));
	switch (cmd){
		case RD_VALUE:
			if(copy_to_user((int32_t *)arg , &value, sizeof(value))){
				printk("Cannot set value to user space !\n");
			}
			break;
		case WR_VALUE:
			if(copy_from_user(&value, (int32_t *)arg, sizeof(value))){
				printk("Cannot get value to uesr space !\n");
			}
			printk("value : %d", value);
			break;
		default: 
			break;
	}
	return 0;
}

static struct  file_operations fops = {
	.owner = THIS_MODULE,
	.read = read_file,
	.open = open_file,
	.release = release_file,
	.write = write_file,
	.unlocked_ioctl = ioctl_file,
};

static int __init init_module_timer(void){

	if(alloc_chrdev_region(&pchrdev.pnum, 0, 1 ,"number_chrdev")){
		printk("Cannot alloc number mojor and minor sucess !\n");
		return -1;
	}

	pchrdev.pclass = class_create(THIS_MODULE, "class_chrdev");
	if(pchrdev.pclass == NULL){
		printk("Cannot create class success !\n");
		goto create_class_failed;
	}

	pchrdev.pdevice = device_create(pchrdev.pclass, NULL, pchrdev.pnum, NULL, "device_chrdev");
	if(pchrdev.pdevice == NULL){
		printk("Cannot create device success !\n");
		goto create_device_failed;
	}

	pchrdev.pcdev = cdev_alloc();
	if(pchrdev.pcdev == NULL){
		printk("Cannot alloc cdev success !\n");
	}

	cdev_init(pchrdev.pcdev, &fops);

	if(cdev_add(pchrdev.pcdev, pchrdev.pnum, 1) < 0){
		printk("Cannot add cdev to system !\n");
	}

create_class_failed:
	unregister_chrdev_region(pchrdev.pnum, 1);

create_device_failed:
	class_destroy(pchrdev.pclass);

	printk("Number major %d and munber minor %d \n", MAJOR(pchrdev.pnum), MINOR(pchrdev.pnum));
	printk("Insert module timer success !\n");
	return 0;

}

static void __exit exit_module_timer(void){


	device_destroy(pchrdev.pclass, pchrdev.pnum);

	class_destroy(pchrdev.pclass);

	cdev_del(pchrdev.pcdev);

	unregister_chrdev_region(pchrdev.pnum, 1);

	printk("Remove module timer success !\n");
}

module_init(init_module_timer);
module_exit(exit_module_timer);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NGUYEN");
