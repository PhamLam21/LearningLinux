#include<linux/module.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/cdev.h>
#include<linux/slab.h>

#define DRIVER_AUTHOR "PhamLam21 lamchi920@gmail.com"
#define DRIVER_DESC "Hello kernel module"

struct m_foo_dev {
    dev_t dev_num;
    struct class *m_class;
    struct cdev m_cdev;
} mdev;

//Function prototypes
static int __init hello_world_init(void);
static void __exit hello_world_exit(void);
static int m_open(struct inode *inode, struct file *file);
static int m_release(struct inode *inode, struct file *file);
static ssize_t m_read(struct file *file, char __user *user_buf, size_t size, loff_t *offset);
static ssize_t m_write(struct file *file, const char __user *user_buf, size_t size, loff_t *offset);

static struct file_operations fops = 
{
    .owner = THIS_MODULE,
    .open = m_open,
    .release = m_release,
    .read = m_read,
    .write = m_write,
};

static int m_open(struct inode *inode, struct file *file) {
    pr_info("Open file\n");
    return 0;
}
static int m_release(struct inode *inode, struct file *file) {
    pr_info("Close file\n");
    return 0;
}
static ssize_t m_read(struct file *file, char __user *user_buf, size_t size, loff_t *offset) {
    pr_info("Read file\n");
    return 0;
}
static ssize_t m_write(struct file *file, const char __user *user_buf, size_t size, loff_t *offset) {
    pr_info("Write to file\n");
    return 0;
}

static int __init hello_world_init(void) {

    //Allocating device number
    if(alloc_chrdev_region(&mdev.dev_num, 0, 1, "m-dev") < 0) {
        pr_err("Failed to alloc chrdev region\n");
        return -1;
    }

    //Creating struct class
    if((mdev.m_class = class_create("m-class")) == NULL) {
        pr_err("Failed to create struct class\n");
        goto rm_device_numb;
    }

    //Creating device
    if((device_create(mdev.m_class, NULL, mdev.dev_num, NULL, "m-device")) == NULL) {
        pr_err("Failed to create device\n");
        goto rm_class;
    }

    //Creating cdev -> tạo định nghĩa các giao tiếp với device file
    cdev_init(&mdev.m_cdev, &fops);

    //Adding character device to the system
    if((cdev_add(&mdev.m_cdev, mdev.dev_num, 1)) < 0) {
        pr_err("Failed to add the device to the system\n");
        goto rm_device;
    }

    pr_info("Hello world kernel module\n");
    return 0;

rm_device_numb:
    unregister_chrdev_region(mdev.dev_num, 1);
    return -1;
rm_class:
    class_destroy(mdev.m_class);
    return -1;
rm_device:
    device_destroy(mdev.m_class, mdev.dev_num);
    class_destroy(mdev.m_class);
    unregister_chrdev_region(mdev.dev_num, 1);
    return -1;
}

static void __exit hello_world_exit(void) {
    cdev_del(&mdev.m_cdev);
    device_destroy(mdev.m_class, mdev.dev_num);
    class_destroy(mdev.m_class);
    unregister_chrdev_region(mdev.dev_num, 1);
    pr_info("Goodbye\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);