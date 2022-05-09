#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <linux/kcmp.h>

static int kcmp(pid_t pid1, pid_t pid2,int type,unsigned long idx1, unsigned long idx2)
{
    return syscall(SYS_kcmp,pid1,pid2,type,idx1,idx2);
}