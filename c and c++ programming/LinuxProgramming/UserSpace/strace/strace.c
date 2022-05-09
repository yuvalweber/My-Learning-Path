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

int main(int argc, char* argv[],char* envp[])
{
    struct user_regs_struct regs;
    struct user_regs_struct rc;
    int status;
    char* new_path;
    bool need_to_free = false;
    Elf64_Ehdr header;
    char* syscallName;
    char* return_code;
    FILE* path_file;

    // checking if there are enough arguments
    if (argc != 2)
    {
        printf("usage: %s <path_to_executable>\n",argv[0]);
        return(0);
    }

    // find if executable is in $PATH environment variable
    path_file = fopen(argv[1],"r");
    if (path_file != NULL)
    {
        new_path = argv[1];
        fclose(path_file);
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
    //FIXME: need to implement 32bit, meanwhile just 64 supported.
    if(header.e_ident[EI_CLASS] == ELFCLASS32)
    {
        fprintf(stderr,"32bit not supported, maybe add in the future");
    }
    fclose(file);
    
    pid_t child = fork();
    //child process
    if(child == 0)
    {
        //pid addr and data are ignored because the parent is tracing him
        ptrace(PTRACE_TRACEME,0,NULL,NULL);
        //FIXME: add all argv parameters and not just argv[1]
        execve(new_path,argv + 1,envp);
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
            syscallName = syscallParser64(child,&regs);
            ptrace(PTRACE_SYSCALL,child,NULL,NULL);
            wait(&status);
            ptrace(PTRACE_GETREGS,child,NULL,&rc);
            if((int)rc.rax < 0 && (int)rc.rax > -135)
            {
                return_code = errorParser(rc.rax);
                fprintf(stderr,"%s = %s\n",syscallName,return_code);
                free(return_code);
            }
            else 
	        {
                if((unsigned)rc.rax > 1000000)
                {
                    fprintf(stderr,"%s = 0x%llx\n",syscallName,rc.rax);
                }
                else
                {
                    fprintf(stderr,"%s = %llu\n",syscallName,rc.rax);
                }
	        }
            syscallName = NULL;
        }
        if(need_to_free)
        {
            free(new_path);
        }
    }
}
