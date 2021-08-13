# Commands

1) first open the executable like that:
```
r2 <path>
```

2) in the start to make the program analyze everything write:  
```
aaa
```
3) to see available functions write
```
afl
```
4) seek to a function
```
s <function>
```
normally we will use:
```
s sym.main
```
5) show disassamble of function we seek to
```
pdf
```
6) reopen file in debugger mode:
```
doo
```
7) continue execution:  
```
dc
```
8) step one forward
```
ds
```

9) make break point in place you choose:
```
db <address>
```

10) show cpu and registers:
```
dr
```

11) set varriable
```
dr rip=<address>
```

12) set flags
```
dr zf=<value>
```
13) enter visual mode (show jumps and stuffs):  
```
VV
```

14) show evrything pretty(stucks,pointers):
```
V!
```

15) show the disassambly of the next rip
```
pd 1
```

16) print this in json format:
```
pdj 1
```

17) seek for the current rip value  
```
sr rip
```
18) add assembly description to understand assembly better  
```
e asm.describe = true
```
