#ifndef HELPER_H    
#define HELPER_H
char* isInPath(char* program_name);
char* syscallName64(int syscallNumber);
char* syscallName32(int syscallNumber);

extern const char* syscallName64_array[];
extern const char* syscallName32_array[];
#endif
