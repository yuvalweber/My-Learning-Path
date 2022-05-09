#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../kcmp/kcmp.h"

int main(int argc, char* argv[])
{
    //first
    int newfd;
    int newflags;
    char* file_name = argv[1];
    int fd = open(file_name,O_RDONLY);
    if(fd == -1) {perror("open");exit(1);}
    newfd = dup(fd);

    //check if they are using the same file
    int rc = kcmp(getpid(),getpid(),KCMP_FILE,fd,newfd);
    if(rc == 0){printf("same file was opened\n");}

    //second
    off_t curr = lseek(fd,0,SEEK_CUR);
    printf("first file offset is %ld\n",curr);
    int flags = fcntl(fd,F_GETFL);
    if(flags & O_APPEND){printf("first file opened in append mode\n");}
    else{printf("first file didn't open in append mode\n");}
    
    //third
    off_t new_offset = 10;
    lseek(newfd,new_offset,SEEK_SET);
    flags |= O_APPEND;
    fcntl(newfd,F_SETFL,flags);
    
    //fourth
    curr = lseek(fd,0,SEEK_CUR);
    printf("now offset is %ld for both files\n",curr);
    newflags = fcntl(fd,F_GETFL);
    if(newflags & O_APPEND){printf("file opened in append mode\n");}
    close(fd);
    close(newfd);
    return(0);

}