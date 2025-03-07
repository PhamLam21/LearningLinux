#include<linux/module.h>
#include<linux/fs.h>
#include<linux/device.h>

#define DRIVER_AUTHOR "PhamLam21 lamchi920@gmail.com"
#define DRIVER_DESC "Hello kernel module"

struct m_foo_dev {
    dev_t dev_num;
    struct class *m_class;
} mdev;

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

    pr_info("Hello world kernel module\n");
    return 0;

rm_device_numb:
    unregister_chrdev_region(mdev.dev_num, 1);
    return -1;
rm_class:
    class_destroy(mdev.m_class);
    return -1;
}

static void __exit hello_world_exit(void) {
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