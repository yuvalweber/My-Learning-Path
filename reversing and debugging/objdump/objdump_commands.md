# Commands

1) examine the disassembly of file
```
objdump -D <path_to_file>
```
2) examine dissasembly of file and show with intel flavor
```
objdump -D <path_to_file> -M intel
```
3) grep main
```
objdump -D <path_to_file> -M intel|grep -A 20 main.:
```
4) show dtors of file  
```
objdump -s -j .dtors <path to file>
```
5) show memory areas and their protection  
```
objdump -h <path to file>
```
6) show plt table  
```
objdump -d -j .plt <path to file>
```
7) show memory address  
```
objdump -R <path to file>
```
8) see symbols and vars in .bss
```
objdump -t <path_to_file>
```
