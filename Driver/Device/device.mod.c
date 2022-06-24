#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

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
	{ 0xeeab4c1e, "module_layout" },
	{ 0x3af48006, "device_remove_file" },
	{ 0xfae385f3, "bus_remove_file" },
	{ 0xdc70d749, "bus_unregister" },
	{ 0xfda0fdad, "class_unregister" },
	{ 0x172ec4a9, "device_unregister" },
	{ 0xff51779, "device_register" },
	{ 0xf29597ed, "device_create_file" },
	{ 0xefbbe80d, "__class_register" },
	{ 0x9f79bcfb, "bus_create_file" },
	{ 0x75932b95, "bus_register" },
	{ 0xd5973871, "sysfs_create_file_ns" },
	{ 0x81515fc2, "kobject_create_and_add" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0E3DD3ABD9A4B2FEB1EDD83");
