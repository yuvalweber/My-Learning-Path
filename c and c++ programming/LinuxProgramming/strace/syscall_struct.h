#ifndef SYSCALL_STRUCT_H
#define SYSCALL_STRUCT_H
typedef struct syscall {
    unsigned nargs;
    int (*function)();
    const char* name;
} struct_syscall;
#endif

