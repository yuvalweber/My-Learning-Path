#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

#define PATH_MAX 4096
#define PAGE_SIZE 1024
#define ARRAY_MAX_LEN 100

int checkSymLinkValue(pid_t pid, const char* base_name,char* process)
{
	char link [PATH_MAX];
	char *result = (char *)malloc(PAGE_SIZE);
    char *last_slash;
	int len;

	snprintf(link, sizeof(link), "/proc/%d/%s", pid, base_name);
    //readlink --> reads where link is pointing to
	len = readlink(link, result, PAGE_SIZE - 1);
	result[len] = '\0';
    if(strncmp(process,"/",1) == 0)
    {
        if(strncmp(process,result,strlen(process)) == 0)
        {
            free(result);
            return pid;
        }
    }
    else
    {
        //strrchr return last occurence of string
        last_slash = strrchr(result,'/');
        //if it is null it means it does not have '/'
        if(last_slash != NULL)
        {
            last_slash = (char *)last_slash + 1;
            if(strncmp(process,last_slash,strlen(process)) == 0)
            {
                free(result);
                return pid;
            }
        }
    }
    free(result);
    return -1;
}

//loops through /proc dir and read all links of 'exe' and check which one pointing to the program.
int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("usage: %s <program_name>",argv[0]);
    }

    DIR* d;
    struct dirent *dir;
    char* process = argv[1];
    int results[ARRAY_MAX_LEN];
    int mone = 0;
    int result;
    int dir_num;
    d = opendir("/proc");
    if(d) 
    {
        while((dir = readdir(d)) != NULL)
        {
            dir_num = atoi(dir->d_name);
            if(dir_num != 0)
            {
               result =  checkSymLinkValue(dir_num,"exe",process);
               if(result != -1)
               {
                   results[mone] = result;
                   mone++;
               }
            }
        }
        closedir(d);

        if(mone > 0)
        {
            for(int i=0;i < mone; i++)
            {
                printf("%d ",results[i]);
            }
            printf("\n");
        }
    }
    return(0);
}