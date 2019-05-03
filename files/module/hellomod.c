#include <linux/module.h>	// included for all kernel modules
#include <linux/kernel.h>	// included for KERN_INFO
#include <linux/init.h>		// included for __init and __exit macros
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/errno.h>
#include <linux/sched.h>	// task_struct requried for current_uid()
#include <linux/cred.h>		// for current_uid();
#include <linux/slab.h>		// for kmalloc/kfree
#include <linux/uaccess.h>	// copy_to_user
#include <linux/string.h>
#include <linux/device.h>
#include <linux/cdev.h>

static dev_t devnum;
static struct cdev c_dev;
static struct class *clazz;

static unsigned int counter = 0;

static int hellomod_dev_open(struct inode *i, struct file *f) {
	printk(KERN_INFO "hellomod: device opened.\n");
	return 0;
}

static int hellomod_dev_close(struct inode *i, struct file *f) {
	printk(KERN_INFO "hellomod: device closed.\n");
	return 0;
}

static ssize_t hellomod_dev_read(struct file *f, char __user *buf, size_t len, loff_t *off) {
	printk(KERN_INFO "hellomod: read %zu bytes @ %llu.\n", len, *off);
	return len;
}

static ssize_t hellomod_dev_write(struct file *f, const char __user *buf, size_t len, loff_t *off) {
	printk(KERN_INFO "hellomod: write %zu bytes @ %llu.\n", len, *off);
	return len;
}

static long hellomod_dev_ioctl(struct file *fp, unsigned int cmd, unsigned long arg) {
	printk(KERN_INFO "hellomod: ioctl cmd=%u arg=%lu.\n", cmd, arg);
	return 0;
}

static const struct file_operations hellomod_dev_fops = {
	.owner = THIS_MODULE,
	.open = hellomod_dev_open,
	.read = hellomod_dev_read,
	.write = hellomod_dev_write,
	.unlocked_ioctl = hellomod_dev_ioctl,
	.release = hellomod_dev_close
};

static int hellomod_proc_read(struct seq_file *m, void *v) {
	seq_printf(m, "hello, world! (%d)\n", counter);
	return 0;
}

static int hellomod_proc_open(struct inode *inode, struct  file *file) {
	counter++;
	return single_open(file, hellomod_proc_read, NULL);
}

static const struct file_operations hellomod_proc_fops = {
	.owner = THIS_MODULE,
	.open = hellomod_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};

static char *hellomod_devnode(struct device *dev, umode_t *mode) {
	if(mode == NULL) return NULL;
	*mode = 0666;
	return NULL;
}

static int __init hellomod_init(void)
{
	// create char dev
	if(alloc_chrdev_region(&devnum, 0, 1, "updev") < 0)
		return -1;
	if((clazz = class_create(THIS_MODULE, "upclass")) == NULL)
		goto release_region;
	clazz->devnode = hellomod_devnode;
	if(device_create(clazz, NULL, devnum, NULL, "hello_dev") == NULL)
		goto release_class;
	cdev_init(&c_dev, &hellomod_dev_fops);
	if(cdev_add(&c_dev, devnum, 1) == -1)
		goto release_device;
	// create proc
	proc_create("hello_proc", 0, NULL, &hellomod_proc_fops);
	//
	printk(KERN_INFO "hellomod: initialized.\n");
	return 0;    // Non-zero return means that the module couldn't be loaded.

release_device:
	device_destroy(clazz, devnum);
release_class:
	class_destroy(clazz);
release_region:
	unregister_chrdev_region(devnum, 1);
	return -1;
}

static void __exit hellomod_cleanup(void)
{
	remove_proc_entry("hello_proc", NULL);

	cdev_del(&c_dev);
	device_destroy(clazz, devnum);
	class_destroy(clazz);
	unregister_chrdev_region(devnum, 1);

	printk(KERN_INFO "hellomod: cleaned up.\n");
}

module_init(hellomod_init);
module_exit(hellomod_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Chun-Ying Huang");
MODULE_DESCRIPTION("The unix programming course demo kernel module.");

