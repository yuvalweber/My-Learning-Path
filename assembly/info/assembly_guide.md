# Table of Contents
- [Tricks](#Tricks)
- [Compiling](#compiling)
- [disassamble](#disassamble)
- [syscalls](#syscalls)

<br>
<br>

# Tricks
you can make a jump instuction only 2 bit by using jump short.
### example: 
``` 
jmp short 
```
<br>

# Compiling
for compiling we will use the nasm command combined with the ld command.
### example for 32bit: 
``` 
nasm -f elf32 <.s file>
gcc -m32 <.o file> -o <file>
```
### example for 64bit:
```
nasm -f <.s file>
ld <.o file>
```
<br>

# disassamble
for disassamble we will use the ndisasm command
### example for 32bit:
```
ndisasm -b32 <elf file>
```
### example for 64bit:
```
ndisasm <elf file>
```
<br>

# syscalls
if you downloaded gcc than you should have all the header files.  
if you want to know the syscall number for specific function you can read it in the header files.
<br>
### <ins>for 32 bit</ins>: /usr/include/asm/unistd_32.h
### <ins>for 64 bit</ins>: /usr/include/asm/unistd_64.h

### for example in the 64bit file the syscall number 1 is write
```
#define __NR_write 1
```