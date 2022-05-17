#include <linux/module.h>
#include <linux/jiffies.h>
#include <linux/timekeeping.h>
#include <uapi/linux/time.h>

struct _timer {
	unsigned long time_sys;
	struct timespec64 tm;
	struct timespec64 tn;
} timer;

static int __init init_module_timer(void){

	//get system uptime
	timer.time_sys = jiffies;
	printk("time insert : %lu", timer.time_sys);
	// get wall time micro
	ktime_get_ts64(&timer.tm);

	// get wall time nano
	 ktime_get_real_ts64(&timer.tn);

	printk("Insert module timer success !\n");
	return 0;
}
static void __exit exit_module_timer(void){

	//get system uptime
	timer.time_sys = jiffies;
	printk("time remove : %lu", timer.time_sys);
	printk("Remove module timer success !\n");
}

module_init(init_module_timer);
module_exit(exit_module_timer);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NGUYEN");
