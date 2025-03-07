#include<linux/module.h>
#include<linux/fs.h>

#define DRIVER_AUTHOR "PhamLam21 lamchi920@gmail.com"
#define DRIVER_DESC "Hello kernel module"

struct m_foo_dev{
    dev_t dev_num;
} mdev;

static int __init hello_world_init(void) {
    //Dynamic allocating device number
    if(alloc_chrdev_region(&mdev.dev_num, 0, 1, "m-cdev") < 0) {
        pr_err("Failed to alloc chrdev region\n");
        return -1;
    }

    //Static allocating device number
    // mdev.dev_num = MKDEV(509, 0);
    // register_chrdev_region(&mdev.dev_num, 1, "m-cdev");

    pr_info("Major = %d Minor = %d\n", MAJOR(mdev.dev_num), MINOR(mdev.dev_num));
    pr_info("Hello world kernel module\n");

    return 0;
}

static void __exit hello_world_exit(void) {
    //Unallocating device number
    unregister_chrdev_region(mdev.dev_num, 1);
    pr_info("Goodbye\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);