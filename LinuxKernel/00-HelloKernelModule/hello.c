#include<linux/module.h> //Thu vien dinh nghia macro module_init và module_exit
#include<linux/fs.h> //Thu vien allocate major&minor number

#define DRIVER_AUTHOR "PhamLam21 lamchi920@gmail.com"
#define DRIVER_DESC "hello kernel module"

//Constructor
static int __init hello_world_init(void) {
    printk(KERN_INFO "Hello world kernel module!\n");
    return 0;
}

static void __exit hello_world_exit(void) {
    printk(KERN_INFO "Goodbye\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);