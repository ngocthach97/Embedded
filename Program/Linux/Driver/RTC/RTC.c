#include <linux/module.h>
#include <linux/rtc.h>
#include <linux/device.h>
#include <linux/platform_device.h>

static int rtc_ioctl_demo(struct device *dev, unsigned int cmd, unsigned long arg)
{
    return 0;
}

static int rtc_read_time_demo(struct device *dev, struct rtc_time *rtc_time)
{
    return 0;
}

static int rtc_set_time_demo(struct device *dev, struct rtc_time *rtc_time)
{
    return 0;
}

static int rtc_read_alarm_demo(struct device *dev, struct rtc_wkalrm *rtc_wkalrm)
{
    return 0;
}

static int rtc_set_alarm_demo(struct device *dev, struct rtc_wkalrm *rtc_wkalrm)
{
    return 0;
}

static int rtc_proc_demo(struct device *dev, struct seq_file *seq_file)
{
    return 0;
}

static int rtc_alarm_irq_enable_demo(struct device *dev, unsigned int enabled)
{
    return 0;
}

static int rtc_read_offset_demo(struct device *dev, long *offset)
{
    return 0;
}

static int rtc_set_offset_demo(struct device *dev, long offset)
{
    return 0;
}

static struct rtc_class_ops rtc_pos_demo = {
    .ioctl = rtc_ioctl_demo,
    .read_time = rtc_read_time_demo,
    .set_time = rtc_set_time_demo,
    .read_alarm = rtc_read_alarm_demo,
    .set_alarm = rtc_set_alarm_demo,
    .proc = rtc_proc_demo,
    .alarm_irq_enable = rtc_alarm_irq_enable_demo,
    .read_offset = rtc_read_offset_demo,
    .set_offset = rtc_set_offset_demo,
};

static int fake_rtc_probe(struct platform_device *pdev)
{
    return 0;
}

static int fake_rtc_remove(struct platform_device *pdev)
{
    return 0;
}

static struct platform_driver plf_drv = {
    .probe = fake_rtc_probe,
    .remove = fake_rtc_remove,
    .driver = {
        .name = KBUILD_MODNAME,
        .owner = THIS_MODULE,
    },
} ;

static int __init init_module_rtc(void)
{
    platform_driver_register(&plf_drv);
    printk("Insert module RTC success ! \n");
    return 0;
}
static void __exit exit_module_rtc(void)
{
    platform_driver_unregister(&plf_drv);
    printk("Remove module RTC success ! \n");
}

module_init(init_module_rtc);
module_exit(exit_module_rtc);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NGUYEN");