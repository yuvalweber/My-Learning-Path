#include "helperFunctions.h"
#include "syscall_struct.h"
#include "decoder/decoder.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

struct_syscall sys_ent[] = {
#include "syscalls_64.h"
};

const char* errorNames[] = {"EPERM","ENOENT","ESRCH","EINTR","EIO","ENXIO","E2BIG","ENOEXEC","EBADF","ECHILD","EAGAIN","ENOMEM","EACCES","EFAULT","ENOTBLK","EBUSY","EEXIST","EXDEV","ENODEV","ENOTDIR","EISDIR","EINVAL","ENFILE","EMFILE","ENOTTY","ETXTBSY","EFBIG","ENOSPC","ESPIPE","EROFS","EMLINK","EPIPE","EDOM","ERANGE","EDEADLK","ENAMETOOLONG","ENOLCK","ENOSYS","ENOTEMPTY","ELOOP","EWOULDBLOCK","ENOMSG","EIDRM","ECHRNG","EL2NSYNC","EL3HLT","EL3RST","ELNRNG","EUNATCH","ENOCSI","EL2HLT","EBADE","EBADR","EXFULL","ENOANO","EBADRQC","EBADSLT","EDEADLOCK","EBFONT","ENOSTR","ENODATA","ETIME","ENOSR","ENONET","ENOPKG","EREMOTE","ENOLINK","EADV","ESRMNT","ECOMM","EPROTO","EMULTIHOP","EDOTDOT","EBADMSG","EOVERFLOW","ENOTUNIQ","EBADFD","EREMCHG","ELIBACC","ELIBBAD","ELIBSCN","ELIBMAX","ELIBEXEC","EILSEQ","ERESTART","ESTRPIPE","EUSERS","ENOTSOCK","EDESTADDRREQ","EMSGSIZE","EPROTOTYPE","ENOPROTOOPT","EPROTONOSUPPORT","ESOCKTNOSUPPORT","EOPNOTSUPP","EPFNOSUPPORT","EAFNOSUPPORT","EADDRINUSE","EADDRNOTAVAIL","ENETDOWN","ENETUNREACH","ENETRESET","ECONNABORTED","ECONNRESET","ENOBUFS","EISCONN","ENOTCONN","ESHUTDOWN","ETOOMANYREFS","ETIMEDOUT","ECONNREFUSED","EHOSTDOWN","EHOSTUNREACH","EALREADY","EINPROGRESS","ESTALE","EUCLEAN","ENOTNAM","ENAVAIL","EISNAM","EREMOTEIO","EDQUOT","ENOMEDIUM","EMEDIUMTYPE","ECANCELED","ENOKEY","EKEYEXPIRED","EKEYREVOKED","EKEYREJECTED","EOWNERDEAD","ENOTRECOVERABLE","ERFKILL","EHWPOISON","ENOTSUP"};

char* isInPath(char* program_name)
{
    char* path = getenv("PATH");
    char* splittedPath = strtok(path,":");
    char* path_to_check = malloc(sizeof(char*));
    FILE* file;
    while(splittedPath != NULL)
    {
        strcpy(path_to_check,splittedPath);
        strcat(path_to_check,"/");
        strcat(path_to_check,program_name);
        file = fopen(path_to_check,"r"); 
        if(file != NULL)
        {
            fclose(file);
            return path_to_check;
        }
        splittedPath = strtok(NULL,":");
    }
    free(path_to_check);
    return NULL;
}

char* syscallParser64(int child,struct user_regs_struct *regs)
{
    
    struct syscall *sys64 = (struct syscall *)&sys_ent[regs->orig_rax];
    sys64->function(child,buffer,regs,sys64);
    return buffer;
}

char* errorParser(long long unsigned errorNum)
{
    char err[256]; 
    snprintf(err,sizeof(err),"-1 %s (%s)",errorNames[(errorNum * -1) -1],strerror(errorNum * -1));
    return strdup(err);
}
