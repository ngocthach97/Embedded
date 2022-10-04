#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
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

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe49bb82b, "module_layout" },
	{ 0x9b323606, "device_destroy" },
	{ 0x24f11544, "cdev_del" },
	{ 0xd5511368, "kthread_stop" },
	{ 0x41c0a893, "class_destroy" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x37a3f7a8, "wake_up_process" },
	{ 0x22bab5f, "kthread_create_on_node" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd047ef18, "cdev_add" },
	{ 0xa2822610, "cdev_init" },
	{ 0x6225a11a, "cdev_alloc" },
	{ 0x6126cf1d, "device_create" },
	{ 0x5c7f3cc9, "__class_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xf9a482f9, "msleep" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x92997ed8, "_printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F8C8F802629A764DDD31359");
