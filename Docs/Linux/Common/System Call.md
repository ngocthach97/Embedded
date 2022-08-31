Adding A System Call To The Linux Kernel In Ubuntu

1. Add system call

sudo apt update && sudo apt upgrade -y

sudo apt install build-essential libncurses-dev libssl-dev libelf-dev bison flex -y

wget -P ~/ https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.15.1.tar.gz  

tar -xvf ~/linux-5.15.1.tar.gz -C ~/

cd ~/linux-5.15.1/

mkdir demo

nvim demo/demo.c

#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0(demo)

{
    printk("Hello World, I am system call \n");
    return 0;
}

nvim demo/Makefile

obj-y := demo.o

nvim Makefile

kernel/ certs/ mm/ fs/ ipc/ security/ crypto/ block/ demo/

nvim include/linux/syscalls.h

asmlinkage long sys_demo(void);

nvim arch/x86/entry/syscalls/syscall_64.tbl

449     common  demo                sys_demo

nproc

make -j4

sudo make modules_install -j4

sudo make install -j4

sudo update-grub

sudo reboot

2. Test system call

nvim test.c


#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define __NR_test 449

long demo_syscall(void)
{
    return syscall(__NR_test);
}

int main(int argc, char *argv[])
{
    long activity;
    activity = demo_syscall();

    if(activity < 0)
    {
        perror("Sorry, Your system call appears to have failed.");
    }

    else
    {
        printf("Congratulations,  Your system call is functional. Run the command dmesg in the terminal and find out!\n");
    }

    return 0;
}

gcc -o test test.c

./test

dmesg

--> "Hello World, I am system call"