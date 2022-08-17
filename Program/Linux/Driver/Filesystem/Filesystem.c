#include <linux/module.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>

static struct file_system_type fs_type_demo = {
    .name = "type_demo",
};

struct proc_dir_entry *proc_file_entry;

static struct inode_operations inode_pos = {
   // .rename = rename_file_demo,
};

ssize_t read_file_demo (struct file *pfile, char __user * buff, size_t size, loff_t *off){
    printk("Read file !\n");
    return 0;
}

ssize_t write_file_demo (struct file * pfile, const char __user * buff, size_t size, loff_t *off){
    printk("Write file !\n");
    return 0; 
}

int release_file_demo (struct inode * pinode, struct file * pfile){
    printk("Release file !\n");
    return 0;
}

int open_file_demo (struct inode *pinode, struct file *pfile){
    printk("Open file !\n");
    return 0;
}

static struct file_operations file_ops = {
    .read = read_file_demo,
    .write = write_file_demo,
    .release = release_file_demo,
    .open = open_file_demo,
};

static struct proc_ops proc_ops = {

};

static int __init init_module_filesystem(void){
    if(register_filesystem(&fs_type_demo) < 0){
        printk("Cannot register file system ! \n");
    }
    proc_file_entry = proc_create("file_demo", 0, NULL, &proc_ops);
    if(proc_file_entry == NULL)
        return -ENOMEM;
    printk("Insert module filesystem ! \n");
    return 0;
}

static void __exit exit_module_filesystem(void){
    if(unregister_filesystem(&fs_type_demo) < 0){
        printk("Cannot unregister file system ! \n");
    }
     printk("Remove module filesystem ! \n");
}

module_init(init_module_filesystem);
module_exit(exit_module_filesystem);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nguyen");
