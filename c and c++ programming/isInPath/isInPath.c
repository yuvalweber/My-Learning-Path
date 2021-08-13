#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <errno.h>

//FixMe: maybe vulnerable to buffer overflow
char* isInPath(char* program_name)
{
    char* path = getenv("PATH");
    char* splittedPath = strtok(path,":");
    while(splittedPath != NULL)
    {
        char* path_to_check = malloc(sizeof(char*));
        strcpy(path_to_check,splittedPath);
        strcat(path_to_check,"/");
        strcat(path_to_check,program_name);
        if(fopen(path_to_check,"r") != NULL)
        {
            return path_to_check;
        }
        splittedPath = strtok(NULL,":");
    }
    char* error_to_print = strerror(2);
    printf(error_to_print);
    exit(1);
}

int main(int argc, char* argv[])
{
    char* path = isInPath(argv[1]);
    printf(path);
    free(path);
}