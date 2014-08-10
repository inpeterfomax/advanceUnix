#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x58334a4a, "module_layout" },
	{ 0x588c94e4, "kobject_put" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x90f73b9b, "cdev_alloc" },
	{ 0x281c1af5, "cdev_del" },
	{ 0x9ad71be8, "cdev_init" },
	{ 0x6980fe91, "param_get_int" },
	{ 0xd8e484f0, "register_chrdev_region" },
	{ 0x363e731f, "device_destroy" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xbb4214b0, "filp_close" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xff964b25, "param_set_int" },
	{ 0x580684ac, "kobject_create_and_add" },
	{ 0xb72397d5, "printk" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0xb4390f9a, "mcount" },
	{ 0xb457a6fd, "device_create" },
	{ 0x658e0cf7, "cdev_add" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xcff6d41c, "class_destroy" },
	{ 0x55ca06d9, "__class_create" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0x795d18c7, "filp_open" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "2F38D51F0D1122AF3780DDA");
