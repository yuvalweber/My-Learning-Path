#include "decoder.h"
#include <stdio.h>
#define IMPLEMENTED 0 
#define NOT_IMPLEMENTED 1

int decode_read(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_write(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_open(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_close(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%d)",entry->name,(int)regs->rdi);
	return IMPLEMENTED;
}
int decode_stat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fstat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_lstat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_poll_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_lseek(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mmap(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mprotect(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_munmap(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_brk(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    if((int)regs->rdi == 0)
    {
        snprintf(buffer,4096,"%s(%s)",entry->name,"NULL");
    }
    else
    {
        snprintf(buffer,4096,"%s(0x%llx)",entry->name,regs->rdi);
    }
    return IMPLEMENTED;
}
int decode_rt_sigaction(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rt_sigprocmask(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rt_sigreturn(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ioctl(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pread(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pwrite(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_readv(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_writev(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_access(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pipe(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_select(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_yield(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mremap(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_msync(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mincore(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_madvise(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_shmget(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_shmat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_shmctl(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_dup(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_dup2(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pause(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_nanosleep_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getitimer(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_alarm(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setitimer(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getpid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sendfile64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_socket(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_connect(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_accept(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sendto(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_recvfrom(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sendmsg(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_recvmsg(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_shuown(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_bind(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_listen(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getsockname(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getpeername(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_socketpair(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setsockopt(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getsockopt(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_clone(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fork(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_vfork(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_execve(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_exit(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_wait4(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_kill(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_uname(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_semget(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_semop(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_semctl(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_shmdt(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_msgget(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_msgsnd(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_msgrcv(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_msgctl(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fcntl(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_flock(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fsync(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fdatasync(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_truncate(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ftruncate(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_geents(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getcwd(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_chdir(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fchdir(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rename(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mkdir(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rmdir(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_creat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_link(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_unlink(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_symlink(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_readlink(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_chmod(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fchmod(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_chown(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fchown(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_umask(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_gettimeofday(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getrlimit(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getrusage(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sysinfo(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_times(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ptrace(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getuid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_syslog(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getgid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setuid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setgid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_geteuid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getegid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setpgid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getppid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getpgrp(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setsid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setreuid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setregid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getgroups(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setgroups(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setresuid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getresuid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setresgid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getresgid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getpgid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setfsuid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setfsgid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getsid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_capget(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_capset(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rt_sigpending(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rt_sigtimedwait_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rt_sigqueueinfo(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rt_sigsuspend(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sigaltstack(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_utime(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mknod(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_uselib(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_personality(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ustat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_statfs(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fstatfs(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sysfs(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getpriority(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setpriority(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_setparam(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_getparam(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_setscheduler(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_getscheduler(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_get_priority_max(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_get_priority_min(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_rr_get_interval_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mlock(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_munlock(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mlockall(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_munlockall(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_vhangup(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_modify_ldt(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pivotroot(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sysctl(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_prctl(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_arch_prctl(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_adjtimex64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setrlimit(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_chroot(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sync(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_acct(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_settimeofday(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mount(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_umount2(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_swapon(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_swapoff(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_reboot(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sethostname(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_seomainname(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_iopl(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ioperm(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_create_module(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_init_module(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_delete_module(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_get_kernel_syms(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_query_module(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_quotactl(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_nfsservctl(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getpmsg(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_putpmsg(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_afs_syscall(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_tuxcall(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_security(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_gettid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_readahead(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setxattr(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fsetxattr(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getxattr(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fgetxattr(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_listxattr(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_flistxattr(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_removexattr(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fremovexattr(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_tkill(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_time(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_futex_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_setaffinity(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_getaffinity(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_set_thread_area(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_io_setup(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_io_destroy(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_io_getevents_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_io_submit(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_io_cancel(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_get_thread_area(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_lookup_dcookie(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_epoll_create(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_epoll_ctl_old(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_epoll_wait_old(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_remap_file_pages(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_geents64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_set_tid_address(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_restart_syscall(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_semtimedop_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fadvise64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timer_create(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timer_settime64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timer_gettime64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timer_getoverrun(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timer_delete(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_clock_settime64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_clock_gettime64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_clock_getres_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_clock_nanosleep_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_epoll_wait(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_epoll_ctl(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_tgkill(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_utimes(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_vserver(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mbind(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_set_mempolicy(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_get_mempolicy(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mq_open(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mq_unlink(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mq_timedsend_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mq_timedreceive_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mq_notify(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mq_getsetattr(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_kexec_load(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_waitid(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_add_key(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_request_key(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_keyctl(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ioprio_set(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ioprio_get(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_inotify_init(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_inotify_add_watch(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_inotify_rm_watch(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_migrate_pages(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_openat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mkdirat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mknodat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fchownat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_futimesat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_newfstatat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_unlinkat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_renameat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_linkat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_symlinkat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_readlinkat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fchmodat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_faccessat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pselect6_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ppoll_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_unshare(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_set_robust_list(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_get_robust_list(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_splice(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_tee(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sync_file_range(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_vmsplice(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_move_pages(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_utimensat_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_epoll_pwait(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_signalfd(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timerfd_create(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_eventfd(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fallocate(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timerfd_settime64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timerfd_gettime64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_accept4(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_signalfd4(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_eventfd2(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_epoll_create1(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_dup3(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pipe2(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_inotify_init1(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_preadv(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pwritev(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rt_tgsigqueueinfo(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_perf_event_open(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_recvmmsg_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fanotify_init(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fanotify_mark(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_prlimit64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_name_to_handle_at(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_open_by_handle_at(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_clock_adjtime64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_syncfs(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sendmmsg(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setns(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getcpu(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_process_vm_readv(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_process_vm_writev(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_kcmp(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_finit_module(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_setattr(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_getattr(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_renameat2(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_seccomp(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getrandom(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_memfd_create(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_kexec_file_load(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_bpf(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_execveat(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_userfaultfd(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_membarrier(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mlock2(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_copy_file_range(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_preadv2(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pwritev2(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pkey_mprotect(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pkey_alloc(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pkey_free(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_statx(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_io_pgetevents_time64(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rseq(char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}