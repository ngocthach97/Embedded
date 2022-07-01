#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/interrupt.h>
#include <linux/irqreturn.h>

struct _pchrdev {
	dev_t num;
	struct class *pclass;
	struct device *pdevice;
	struct cdev *pcdev;
} pchrdev;

int data = 0;

static int short_irq = 6;

irqreturn_t  irq_service(int irq, void *dev_id){
	printk("value %d",*(int *)dev_id);
	return IRQ_HANDLED;
}

int open_file (struct inode *pinode , struct file *pfile){
	printk("Open file !\n");
	return 0;
}

int release_file(struct inode *pinode , struct file *pfile){
	printk("Release file !\n");
	return 0;
}

ssize_t read_file(struct file *pfile , char __user * puser, size_t size, loff_t *ploff){
	printk("Read file ! \n");
	return 0; 
}

ssize_t write_file (struct file *pfile, const char __user *puser, size_t size, loff_t *ploff){
	printk("Write file ! \n");
	return 0;
}
static struct  file_operations fops = {
	.owner = THIS_MODULE,
	.read = read_file,
	.write = write_file,
	.open = open_file,
	.release = release_file,
};

int __init init_module_char(void){

	if(alloc_chrdev_region(&pchrdev.num,0,1,"pchar_number") < 0){
		printk("Cannot alloc number major and minor ! \n");
		goto failed_alloc_number ;
	}
	printk("Number major = %d , Number mimor = %d",MAJOR(pchrdev.num),MINOR(pchrdev.num));

	pchrdev.pclass = class_create(THIS_MODULE,"class_pchar");
	if(pchrdev.pclass == NULL){
		printk("Cannot create class success !\n");
		goto failed_create_class; 
	}

	pchrdev.pdevice = device_create(pchrdev.pclass, NULL, pchrdev.num, NULL , "pchar_device");
	if(pchrdev.pdevice == NULL){
		printk("Cannot create device success !\n");
		goto failed_create_device;
	}

	pchrdev.pcdev = cdev_alloc();
	if(pchrdev.pcdev == NULL){
		printk("Cannot alloc cdev success !\n");
	}

	cdev_init(pchrdev.pcdev, &fops);
	if(cdev_add(pchrdev.pcdev,pchrdev.num, 1) < 0){
		printk("Cannot add device in system !\n");
	}
	if(request_irq(short_irq, irq_service, 0,"interrupt", (void *)&data)){
		printk("Cannot register interrupt success !\n");
	}
	printk("Insert module success !\n");
	return 0 ;

failed_create_device:
	class_destroy(pchrdev.pclass);
		
failed_create_class:
	unregister_chrdev_region(pchrdev.num, 1);

failed_alloc_number :
	return -1;
	
}

void __exit exit_module_char(void){

	cdev_del(pchrdev.pcdev);

	device_destroy(pchrdev.pclass, pchrdev.num);

	class_destroy(pchrdev.pclass);

	unregister_chrdev_region(pchrdev.num, 1);

	free_irq(short_irq, NULL);

	printk("Remove module success !\n");
}

module_init(init_module_char);
module_exit(exit_module_char);

MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("Nguyen"); 
MODULE_DESCRIPTION("Just for fun"); 
MODULE_VERSION("0.01");
MODULE_SUPPORTED_DEVICE("Nguyen");
