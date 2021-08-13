#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    int flags = O_RDWR;
    int written;
    char buffer[4096];
    char* file_name = argv[1];
    int opt =  getopt(argc,argv,"a:");
    if(opt != -1)
    {
        file_name = argv[2];
        flags = flags|O_APPEND;
    }
    if(open(file_name,O_RDONLY) == -1)
    {
        flags = flags|O_CREAT;
    }
    else
    {
        if(!(flags & O_APPEND))
        {
            flags = flags|O_TRUNC;
        }
    }

    int fd = open(file_name,flags,0644);
    if(fd == -1) {perror("open");}
    int nread = read(STDIN_FILENO,buffer,sizeof(buffer));
    if(nread == -1){perror("read");}
    while(nread > 0)
    {
        written = write(STDOUT_FILENO,buffer,nread);
        if(written != nread) {printf("error writing to stdout");}
        written = write(fd,buffer,nread);
        if(written != nread) {printf("error writing to the file");}
        nread = read(STDIN_FILENO,buffer,sizeof(buffer));
        if(nread == -1){perror("read");}
    }
    int rc = close(fd);
    if(rc == -1){perror("close");}
    
}