#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/ioport.h>

struct my_gpios
{
    int reset_gpio;
    int led_gpio;
};

static struct my_gpios needed_gpios = {
    .reset_gpio = 47,
    .led_gpio = 41,
};

static int probe_demo(struct platform_device *plf_drv)
{
    printk("Probe platform ! \n");
    return 0;
}

static int remove_demo(struct platform_device *plf_drv)
{
    printk("Remove platform ! \n");
    return 0;
}

static void shutdown_demo(struct platform_device *plf_drv)
{
    printk("Shutdown platform ! \n");
}

static int suspend_demo(struct platform_device *plf_drv, pm_message_t state)
{
    printk("Suspend platform ! \n");
    return 0;
}

static int resume_demo(struct platform_device *plf_drv)
{
    printk("Resume platform ! \n");
    return 0;
}

static struct platform_driver plf_drv = {
    .probe = probe_demo,
    .remove = remove_demo,
    .shutdown = shutdown_demo,
    .suspend = suspend_demo,
    .resume = resume_demo,
};

static struct resource resource_demo = {
    .name = "resource_demo",
};

static struct platform_device plf_dev = {
    .name = "platform_device_demo",
    .resource = &resource_demo,
    .dev.platform_data= &needed_gpios,
};

static int __init init_platform(void)
{
    platform_driver_register(&plf_drv);
    platform_device_register(&plf_dev);
    printk("Insert module platform success ! \n");
    return 0;
}

static void __exit exit_platform(void)
{
    platform_driver_unregister(&plf_drv);
    platform_device_unregister(&plf_dev);
    printk("Remove module platform success ! \n");
}

module_init(init_platform);
module_exit(exit_platform);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NGUYEN");
