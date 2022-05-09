#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

int chr_open(struct inode *pinode,struct file *pfile)
{
    printk(KERN_ALERT "perform open");
}
ssize_t chr_read(struct file *pfile,char __user *buffer,size_t length,loff_t *offset)
{
    printk(KERN_ALERT "perform read");
}
ssize_t chr_write(struct file *pfile,const char __user *buffer,size_t length,loff_t *offset)
{
    printk(KERN_ALERT "perform write");
}
int chr_close(struct inode *pinode,struct file *pfile)
{
    printk(KERN_ALERT "perform close");
}

struct file_operations chrdev_operations = {
    .owner   = THIS_MODULE,
    .open    = chr_open,
    .read    = chr_read,
    .write   = chr_write,
    .release = chr_close
};

int char_dev_init()
{
    # MajorNumber, name, operations
    register_chrdev(240,"Simple Char Dev",&chrdev_operations);
}

void char_dev_exit()
{
    unregister_chrdev(240,"Simple Char Dev");
}

module_init(char_dev_init);
module_exit(char_dev_exit);