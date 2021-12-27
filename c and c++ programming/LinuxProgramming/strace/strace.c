#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <errno.h>
#include <elf.h>
#include "helperFunctions.h"

int main(int argc, char* argv[])
{
    char *new_argv[] = {argv[1],NULL};
    char *new_envp[] = {NULL};
    struct user_regs_struct regs;
    struct user_regs_struct rc;
    int status;
    char* new_path;
    bool need_to_free = false;
    bool is32 = false;
    Elf64_Ehdr header;
    char* syscallName;
    char* return_code;

    // checking if there are enough arguments
    if (argc != 2)
    {
        printf("usage: %s <path_to_executable>\n",argv[0]);
        return(0);
    }

    // find if executable is in $PATH environment variable
    if(fopen(argv[1],"r") != NULL)
    {
        new_path = argv[1];
    }
    else
    {
        new_path = isInPath(argv[1]);
        if(new_path == NULL)
        {
            printf("%s",strerror(2));
            exit(1);
        }
        need_to_free = true;
    }

    //check if elf and executable and check if 64 or 32 bit.
    FILE* file = fopen(new_path,"rb");
    fread(&header,sizeof(header),1,file);
    // EXECUTABLE can also be ET_DYN because of position independent code.
    if(memcmp(header.e_ident,ELFMAG,SELFMAG) != 0 || (header.e_type != ET_EXEC && header.e_type != ET_DYN))
    {
        printf("%s","file is not executable or not elf format");
        exit(1);
    }
    if(header.e_ident[EI_CLASS] == ELFCLASS32)
    {
        is32 = true;
    }

    
    pid_t child = fork();
    //child process
    if(child == 0)
    {
        //pid addr and data are ignored because the parent is tracing him
        ptrace(PTRACE_TRACEME,0,NULL,NULL);
        execve(new_path,new_argv,new_envp);
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
        // wait is waiting for signal from the child process
        wait(&status);           
        // check if child exited
        while(!WIFEXITED(status))
        {
            ptrace(PTRACE_SYSCALL,child,NULL,NULL);
            wait(&status);
            ptrace(PTRACE_GETREGS,child,NULL,&regs);
            // return syscall name
            syscallName = is32 ? syscallName32((int)regs.orig_rax) : syscallName64((int)regs.orig_rax);
            ptrace(PTRACE_SYSCALL,child,NULL,NULL);
            wait(&status);
            ptrace(PTRACE_GETREGS,child,NULL,&rc);
            if((int)rc.rax < 0 && (int)rc.rax > -135)
            {

                return_code = errorParser(rc.rax);
                fprintf(stderr,"%s(%lld,0x%llx,0x%llx) = %s\n",syscallName,regs.rdi,regs.rsi,regs.rdx,return_code);
            }
            else 
	    {
                fprintf(stderr,"%s(%lld,0x%llx,0x%llx) = %lld\n",syscallName,regs.rdi,regs.rsi,regs.rdx,rc.rax);
	    }
        }
        if(need_to_free)
        {
            free(new_path);
        }
    }
}
