#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x40de06c2, "class_create" },
	{ 0x93ada30f, "device_create" },
	{ 0xd80df4e9, "cdev_init" },
	{ 0x6c41f6ee, "cdev_add" },
	{ 0x4c03a563, "random_kmalloc_seed" },
	{ 0x4c4e3f94, "kmalloc_caches" },
	{ 0x6b85d260, "__kmalloc_cache_noprof" },
	{ 0xc3d833bc, "device_destroy" },
	{ 0xe6ecd6ca, "class_destroy" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xc99bfeed, "cdev_del" },
	{ 0x37a0cba, "kfree" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x122c3a7e, "_printk" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x6402a1d1, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C70B3D8CB6643E2F23F6529");
