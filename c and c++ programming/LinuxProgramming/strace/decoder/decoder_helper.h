#ifndef DECODER_HELPER_H
#define DECODER_HELPER_H
#include <stdio.h>
int read_memory(int pid,void* memory_address,size_t length,char* memory_buffer);
int dec_to_oct(int num);
void unescape_string(char* buffer,unsigned length);
#endif