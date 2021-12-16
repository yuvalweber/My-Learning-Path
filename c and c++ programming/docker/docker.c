#ifndef _GNU_SOURCE
#define _GNU_SOURCE 
#endif

#include <sched.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/mount.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "docker.h"

//generate random string
char* gen_random_string(char* str, size_t size)
{
    srand(time(0));
    const char charset[] = "abcdefghijklmnopqrstuvwxyz1234567890";
    if(size)
    {
        --size;
        for(size_t n = 0; n < size ; n++)
        {
            int key = rand() % (int) (sizeof charset -1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

//create new proc file system
void mount_procfs()
{
    if(mkdir("/proc",0755) == -1)
    {
        if(errno != EEXIST)
        {
            perror("failed creating /proc");
        }
    }
    if(mount("proc","/proc","proc",0,NULL) == -1)
    {
        perror("failed mounting procfs");
    }
}

// leaving no way to escape the jail(because we have changed the new root of the filesystem,
// and we also in a new mount namespace than the other processes in the system).
void pivot_root_trick()
{
    char * mount_point = "./alpine";
    mount(mount_point,mount_point,NULL,MS_BIND | MS_PRIVATE | MS_REC,NULL);
    chdir(mount_point);
    mkdir("./old_root",0755);
    pivot_root(".","./old_root");
    chdir("/");
    umount2("./old_root",MNT_DETACH);
    rmdir("./old_root");
}

/*
    clone new pid and uts and mount namespace,
    set the hostname,
    and remounting the / of the process
*/

void new_hostname_pid_ns()
{
    const int flags = CLONE_NEWUTS|CLONE_NEWPID|CLONE_NEWNS;
    char hostname[12];
    gen_random_string(hostname,12); 
    if(unshare(flags) == -1) perror("unshare failed");
    if(sethostname(hostname,strlen(hostname))) perror("failed to set hostname");
    if(mount("none", "/" , NULL , MS_REC|MS_PRIVATE , NULL) == -1) perror("failed to mount /");

}

void docker(int argc, char* argv[],char* envp[])
{
    new_hostname_pid_ns();
    pivot_root_trick();
    pid_t child_pid = fork();
    int status;
    if(child_pid == 0) //means we are in the child process
    {
        mount_procfs();
        pid_t grandchild = fork();
        if(grandchild == 0) //means we are in grandchild process
        {
            if(execve(argv[0], &argv[0],envp) == -1)
            {
                perror("exec has failed");
            }
        }
        while(wait(&status) != -1);
        perror("init is dead");
    }
    while(wait(&status) != -1);
}

int main(int argc , char* argv[])
{
    if(argc != 3)
    {
        printf("usage: smoker run alpine\n");
        exit(1);
    }
    else 
    {
        if(strcmp(argv[1],"run") == 0 && strcmp(argv[2],"alpine") == 0)
        {
            int new_argc = 0;
            char* new_argv[] = {"/bin/sh"};
	    char* new_envp[] = {"PS1=[\\u@\\h \\W]\\\\$ "};
            docker(new_argc ,  new_argv , new_envp);
        }
        else
        {
            printf("usage: smoker run alpine\n");
        }
    }

    exit(0);
}
