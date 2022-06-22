#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <sys/uio.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>
#include "decoder_helper.h"
int i;

int read_memory(int pid,void* memory_address,size_t length,char* memory_buffer)
{
    struct iovec local[1];
    local[0].iov_base = calloc(length+1, sizeof(char));
    local[0].iov_len = length;

    struct iovec remote[1];
    remote[0].iov_base = memory_address;
    remote[0].iov_len = length;
    ssize_t nread = process_vm_readv(pid, local, 1, remote, 1, 0);
    if(nread > 0)
    {
        snprintf(memory_buffer,length,"%s",(char *)local[0].iov_base);
        free(local[0].iov_base);
    }
    return (int)nread;
}

void unescape_string(char* buffer,unsigned length)
{
    unsigned buffer_length = length * 3;
    char temp_buffer[buffer_length];
    int temp_buffer_mone = 0;
    int len_to_add;
    for(i=0;i<length;i++)
    {
        if (isprint(buffer[i]) && buffer[i] != '\'' && buffer[i] != '\"' && buffer[i] != '\\' && buffer[i] != '\?')
        {
            sprintf(temp_buffer + temp_buffer_mone,"%c",buffer[i]);
            temp_buffer_mone++;
        }
        else
        {
            switch (buffer[i])
            {
                case '\a':  strcpy(temp_buffer + temp_buffer_mone, "\\a");temp_buffer_mone+=2; break;
                case '\b':  strcpy(temp_buffer + temp_buffer_mone, "\\b");temp_buffer_mone+=2; break;
                case '\f':  strcpy(temp_buffer + temp_buffer_mone, "\\f");temp_buffer_mone+=2; break;
                case '\n':  strcpy(temp_buffer + temp_buffer_mone, "\\n");temp_buffer_mone+=2; break;
                case '\r':  strcpy(temp_buffer + temp_buffer_mone, "\\r");temp_buffer_mone+=2; break;
                case '\t':  strcpy(temp_buffer + temp_buffer_mone, "\\t");temp_buffer_mone+=2; break;
                case '\v':  strcpy(temp_buffer + temp_buffer_mone, "\\v");temp_buffer_mone+=2; break;
                case '\\':  strcpy(temp_buffer + temp_buffer_mone, "\\\\");temp_buffer_mone+=2; break;
                case '\'':  strcpy(temp_buffer + temp_buffer_mone, "\\'");temp_buffer_mone+=2; break;
                case '\"':  strcpy(temp_buffer + temp_buffer_mone, "\\\"");temp_buffer_mone+=2; break;
                case '\?':  strcpy(temp_buffer + temp_buffer_mone, "\\\?");temp_buffer_mone+=2; break;
                case '\0':  strcpy(temp_buffer + temp_buffer_mone, "\\0");temp_buffer_mone+=2; break;
                default:
                    sprintf(temp_buffer + temp_buffer_mone,"\\%o",buffer[i]);
                    len_to_add = strlen(temp_buffer + temp_buffer_mone);
                    temp_buffer_mone += len_to_add;
                    break;
            }
        }
    }
    strcpy(buffer,temp_buffer);
}

char* decode_mprotect_flags(int prot)
{
    char access[77] = {""};
    int flag = 0;

    if(prot == PROT_NONE)
    {
        strcat(access,STRINGIFY(PROT_NONE));
    }
    else
    {
        if(prot & PROT_READ)
        {
            if(!flag)
            {
                strcat(access,STRINGIFY(PROT_READ));
                flag = 1;
            }
            else
            {
                strcat(access,"|");
                strcat(access,STRINGIFY(PROT_READ));
            }
        }
        if(prot & PROT_WRITE)
        {
            if(!flag)
            {
                strcat(access,STRINGIFY(PROT_WRITE));
                flag = 1;
            }
            else
            {
                strcat(access,"|");   
                strcat(access,STRINGIFY(PROT_WRITE));
            }
        }
        if(prot & PROT_EXEC)
        {
            if(!flag)
            {
                strcat(access,STRINGIFY(PROT_EXEC));
                flag = 1;
            }
            else
            {
                strcat(access,"|");  
                strcat(access,STRINGIFY(PROT_EXEC));
            }
        }
        if(prot & PROT_GROWSUP)
        {
            if(!flag)
            {
                strcat(access,STRINGIFY(PROT_GROWSUP));
                flag = 1;
            }
            else
            {
                strcat(access,"|");  
                strcat(access,STRINGIFY(PROT_GROWSUP));
            }
        }
        if(prot & PROT_GROWSDOWN)
        {
            if(!flag)
            {
                strcat(access,STRINGIFY(PROT_GROWSDOWN));
                flag = 1;
            }
            else
            {
                strcat(access,"|");  
                strcat(access,STRINGIFY(PROT_GROWSDOWN));
            }
        }
    }
    return strdup(access);
}
