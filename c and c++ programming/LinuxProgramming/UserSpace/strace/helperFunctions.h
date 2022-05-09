#ifndef HELPER_H    
#define HELPER_H
#include <sys/user.h>
char* isInPath(char* program_name);
char* syscallParser64(int child,struct user_regs_struct *regs);
char* errorParser(long long unsigned errorNum);
extern const char* errorNames[];
char buffer[4096];
#endif
