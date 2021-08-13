#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    char *new_argv[] = {NULL};
    char *new_envp[] = {NULL};
    struct user_regs_struct regs;
    struct user_regs_struct rc;
    int status;

    //checking if there are enough arguments
    if (argc != 2)
    {
        printf("usage: strace <path_to_executable>\n");
        return(0);
    }

    else
    {
        pid_t child = fork();

        //child process
        if(child == 0)
        {
            //pid addr and data are ignored because the parent is tracing him
            ptrace(PTRACE_TRACEME,0,NULL,NULL);
            execve(argv[1],new_argv,new_envp);
            // if execve returns it mean it failed
            perror("execve");
            return(1);
        }

        //fork failed
        else if(child == -1)
        {
            perror("fork");
            return(1);
        }

        //parent process
        else
        {
            wait(&status);           
            while(status == 1407)
            {
                ptrace(PTRACE_GETREGS,child,NULL,&regs);
                ptrace(PTRACE_SYSCALL,child,NULL,NULL);
                ptrace(PTRACE_GETREGS,child,NULL,&rc);
                printf("%lld(%lld,%lld,%lld) = %lld\n",regs.orig_rax,regs.rbx,regs.rcx,regs.rdx,rc.orig_rax);
                wait(&status);
            }
        }
    }
}