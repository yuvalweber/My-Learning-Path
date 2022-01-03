#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <sys/uio.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "decoder_helper.h"
int i;

int read_memory(int pid,void* memory_address,size_t length,char* memory_buffer)
{
    struct iovec local[1];
    local[0].iov_base = calloc(length, sizeof(char));
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

int dec_to_oct(int num)
{
    int octal=0, rem, i=1;
    while(num != 0)
    {   
        rem = num%8;
        octal = (rem*i) + octal; 
        num = num/8;
        i= i*10;                         
    }
    return octal;
}

void unescape_string(char* buffer,unsigned length)
{
    unsigned buffer_length = length * 3;
    char temp_buffer[buffer_length];
    int temp_buffer_mone = 0;
    int number;
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
                    number = dec_to_oct((int)buffer[i]);
                    if(number < 10)
                    {
                        sprintf(temp_buffer + temp_buffer_mone, "\\%01o", buffer[i]);
                        temp_buffer_mone+=2;
                    }
                    else if(number > 10 && number < 100)
                    {
                        sprintf(temp_buffer + temp_buffer_mone, "\\%02o", buffer[i]);
                        temp_buffer_mone+=3;
                    }
                    else
                    {
                        sprintf(temp_buffer + temp_buffer_mone, "\\%03o", buffer[i]);
                        temp_buffer_mone+=4;
                    }
                    break;
            }
        }
    }
    strcpy(buffer,temp_buffer);
}