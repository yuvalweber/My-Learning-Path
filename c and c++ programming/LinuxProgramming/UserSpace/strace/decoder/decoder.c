#include "decoder.h"
#include "decoder_helper.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

#define IMPLEMENTED 0 
#define NOT_IMPLEMENTED 1

char memory_buffer[4096]; 
unsigned length = 0;
char path[256];

int decode_read(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    if(regs->rdx > 32){length = 32;}
    else{length = regs->rdx;}
    sprintf(path,"/proc/%d/fd/%llu",pid,regs->rdi);
    int fd = open(path,O_RDONLY);
    if(fd < 0 ){perror("open in read");}
    if(read(fd,memory_buffer,length) < 0){perror("read in read");};
    if(close(fd) < 0){perror("close in read");};
    unescape_string(memory_buffer,length);
    snprintf(buffer,4096,"%s(%llu,\"%s\"...,%llu)",entry->name,regs->rdi,memory_buffer,regs->rdx);
	return IMPLEMENTED;
}
int decode_write(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    if(regs->rdx > 32){length = 32;}
    else{length = regs->rdx;}
    read_memory(pid,(void *)regs->rsi,(size_t)length,memory_buffer); 
    unescape_string(memory_buffer,length);
    snprintf(buffer,4096,"%s(%llu,\"%s\"...,%llu)",entry->name,regs->rdi,memory_buffer,regs->rdx);
	return IMPLEMENTED;
}
int decode_open(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_close(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%d)",entry->name,(int)regs->rdi);
	return IMPLEMENTED;
}
int decode_stat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fstat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_lstat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_poll_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_lseek(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mmap(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mprotect(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    char* protections = decode_mprotect_flags(regs->rdx);
    snprintf(buffer,4096,"%s(0x%llx,%llu,%s)",entry->name,regs->rdi,regs->rsi,protections);
    free(protections);
	return IMPLEMENTED;
}
int decode_munmap(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(0x%llx,%llu)",entry->name,regs->rdi,regs->rsi);
	return IMPLEMENTED;
}
int decode_brk(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
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
int decode_rt_sigaction(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rt_sigprocmask(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rt_sigreturn(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ioctl(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pread(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pwrite(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_readv(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_writev(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_access(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    char access[15] = {""};
    int flag = 0;
    int number = regs->rsi;

    if(number == F_OK)
    {
        strcat(access,STRINGIFY(F_OK));
    }
    else
    {
        if(number & R_OK)
        {
            if(!flag)
            {
                strcat(access,STRINGIFY(R_OK));
                flag = 1;
            }
            else
            {
                strcat(access,"|");
                strcat(access,STRINGIFY(R_OK));
            }
        }
        if(number & W_OK)
        {
            if(!flag)
            {
                strcat(access,STRINGIFY(W_OK));
                flag = 1;
            }
            else
            {
                strcat(access,"|");   
                strcat(access,STRINGIFY(W_OK));
            }
        }
        if(number & X_OK)
        {
            if(!flag)
            {
                strcat(access,STRINGIFY(X_OK));
                flag = 1;
            }
            else
            {
                strcat(access,"|");  
                strcat(access,STRINGIFY(X_OK));
            }
        }
    }
    read_memory(pid,(void *)regs->rdi,(size_t)PATH_MAX,memory_buffer);
    snprintf(buffer,4096,"%s(\"%s\", %s)",entry->name,memory_buffer,access);
	return IMPLEMENTED;
}
int decode_pipe(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_select(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_yield(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mremap(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_msync(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mincore(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_madvise(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_shmget(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_shmat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_shmctl(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_dup(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_dup2(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pause(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_nanosleep_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getitimer(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_alarm(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setitimer(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getpid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sendfile64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_socket(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_connect(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_accept(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sendto(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_recvfrom(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sendmsg(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_recvmsg(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_shuown(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_bind(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_listen(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getsockname(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getpeername(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_socketpair(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setsockopt(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getsockopt(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_clone(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fork(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_vfork(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_execve(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_exit(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_exit_group(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu)",entry->name,regs->rdi);
	return IMPLEMENTED;
}
int decode_wait4(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_kill(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_uname(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_semget(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_semop(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_semctl(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_shmdt(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_msgget(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_msgsnd(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_msgrcv(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_msgctl(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fcntl(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_flock(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fsync(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fdatasync(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_truncate(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ftruncate(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_geents(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getcwd(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_chdir(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fchdir(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rename(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mkdir(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rmdir(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_creat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_link(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_unlink(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_symlink(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_readlink(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_chmod(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fchmod(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_chown(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fchown(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_umask(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_gettimeofday(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getrlimit(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getrusage(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sysinfo(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_times(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ptrace(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getuid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_syslog(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getgid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setuid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setgid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_geteuid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getegid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setpgid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getppid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getpgrp(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setsid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setreuid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setregid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getgroups(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setgroups(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setresuid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getresuid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setresgid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getresgid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getpgid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setfsuid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setfsgid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getsid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_capget(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_capset(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rt_sigpending(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rt_sigtimedwait_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rt_sigqueueinfo(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rt_sigsuspend(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sigaltstack(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_utime(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mknod(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_uselib(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_personality(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ustat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_statfs(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fstatfs(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sysfs(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getpriority(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setpriority(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_setparam(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_getparam(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_setscheduler(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_getscheduler(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_get_priority_max(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_get_priority_min(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_rr_get_interval_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mlock(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_munlock(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mlockall(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_munlockall(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_vhangup(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_modify_ldt(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pivotroot(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sysctl(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_prctl(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_arch_prctl(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    char *code;
    switch(regs->rdi)
    {
        case ARCH_SET_CPUID:
            code = STRINGIFY(ARCH_SET_CPUID);
            break;
        case ARCH_GET_CPUID:
            code = STRINGIFY(ARCH_GET_CPUID);
            break;
        case ARCH_SET_FS:
            code = STRINGIFY(ARCH_SET_FS);
            break;
        case ARCH_GET_FS:
            code = STRINGIFY(ARCH_GET_FS);
            break;
        case ARCH_SET_GS:
            code = STRINGIFY(ARCH_SET_GS);
            break;
        case ARCH_GET_GS:
            code = STRINGIFY(ARCH_GET_GS);
            break;
    }
    snprintf(buffer,4096,"%s(%s,0x%llx)",entry->name,code,regs->rsi);
	return IMPLEMENTED;
}
int decode_adjtimex64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setrlimit(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_chroot(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sync(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_acct(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_settimeofday(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mount(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_umount2(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_swapon(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_swapoff(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_reboot(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sethostname(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_seomainname(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_iopl(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ioperm(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_create_module(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_init_module(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_delete_module(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_get_kernel_syms(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_query_module(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_quotactl(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_nfsservctl(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getpmsg(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_putpmsg(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_afs_syscall(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_tuxcall(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_security(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_gettid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_readahead(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setxattr(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fsetxattr(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getxattr(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fgetxattr(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_listxattr(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_flistxattr(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_removexattr(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fremovexattr(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_tkill(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_time(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_futex_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_setaffinity(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_getaffinity(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_set_thread_area(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_io_setup(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_io_destroy(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_io_getevents_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_io_submit(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_io_cancel(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_get_thread_area(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_lookup_dcookie(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_epoll_create(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_epoll_ctl_old(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_epoll_wait_old(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_remap_file_pages(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_geents64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_set_tid_address(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(0x%llx)",entry->name,regs->rdi);
	return IMPLEMENTED;
}
int decode_restart_syscall(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_semtimedop_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fadvise64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timer_create(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timer_settime64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timer_gettime64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timer_getoverrun(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timer_delete(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_clock_settime64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_clock_gettime64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_clock_getres_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_clock_nanosleep_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_epoll_wait(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_epoll_ctl(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_tgkill(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_utimes(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_vserver(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mbind(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_set_mempolicy(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_get_mempolicy(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mq_open(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mq_unlink(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mq_timedsend_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mq_timedreceive_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mq_notify(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mq_getsetattr(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_kexec_load(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_waitid(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_add_key(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_request_key(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_keyctl(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ioprio_set(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ioprio_get(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_inotify_init(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_inotify_add_watch(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_inotify_rm_watch(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_migrate_pages(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_openat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mkdirat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mknodat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fchownat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_futimesat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_newfstatat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_unlinkat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_renameat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_linkat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_symlinkat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_readlinkat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fchmodat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_faccessat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pselect6_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_ppoll_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_unshare(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_set_robust_list(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(0x%llx,%llu)",entry->name,regs->rdi,regs->rsi);
	return IMPLEMENTED;
}
int decode_get_robust_list(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_splice(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_tee(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sync_file_range(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_vmsplice(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_move_pages(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_utimensat_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_epoll_pwait(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_signalfd(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timerfd_create(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_eventfd(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fallocate(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timerfd_settime64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_timerfd_gettime64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_accept4(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_signalfd4(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_eventfd2(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_epoll_create1(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_dup3(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pipe2(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_inotify_init1(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_preadv(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pwritev(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rt_tgsigqueueinfo(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_perf_event_open(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_recvmmsg_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fanotify_init(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_fanotify_mark(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_prlimit64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_name_to_handle_at(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_open_by_handle_at(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_clock_adjtime64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_syncfs(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sendmmsg(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_setns(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getcpu(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_process_vm_readv(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_process_vm_writev(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_kcmp(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_finit_module(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_setattr(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_sched_getattr(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_renameat2(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_seccomp(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_getrandom(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_memfd_create(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_kexec_file_load(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_bpf(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_execveat(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_userfaultfd(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_membarrier(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_mlock2(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_copy_file_range(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_preadv2(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pwritev2(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pkey_mprotect(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(0x%llx,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pkey_alloc(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_pkey_free(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_statx(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_io_pgetevents_time64(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}
int decode_rseq(int pid,char* buffer,struct user_regs_struct *regs, struct syscall *entry)
{
    snprintf(buffer,4096,"%s(%llu,%llu,%llu)",entry->name,regs->rdi,regs->rsi,regs->rdx);
	return NOT_IMPLEMENTED;
}