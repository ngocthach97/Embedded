<h1> File I/O Buffering </h1>

1. Kernel Buffering of File I/O: The Buffer Cache

When working with disk files, the read() and write() system calls don’t directly initiate disk access. Instead, they simply copy data between a user-space buffer and a buffer in the kernel buffer cache

2. Buffering in the stdio Library

int setvbuf(FILE *stream, char *buf, int mode, size_t size);

The setbuf() function is layered on top of setvbuf(), and performs a similar task.

void setbuf(FILE *stream, char *buf);

int fflush(FILE *stream);

3. Controlling Kernel Buffering of File I/O

The fsync() system call causes the buffered data and all metadata associated with the
open file descriptor fd to be flushed to disk.


![: buffering](../../Image/IO%20buffering.png)