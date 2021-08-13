# Commands
1) debug program
```
gdb <program>
```
2) if the code compiled with debugging symbols we can see the code like this
```
list
```
3) set assembly to intel syntax
```
set disassembly-flavor intel
```
4) disassamble a function
```
disassamble <function name>
```
5) run the file with args
```
run <args>
```
6) show registers info  
```
info registers
```
7) set a breakpoint
```
break <function name>
```
8) set a breakpoint in specific address
```
break <address>
```
9) single step forwarder
```
si
```
10) next instruction (jump over all the function)
```
ni
```
11) set register value
```
set $eax=<value>
```
12) show string in specific location in memory
```
x/s <address>
```
13) show value in register:  
```
x/wx $esp
```
14) delete all the breakpoints:
```
del
```
15) define hook-stop that will execute some dgb commands when we stop at breakpoint:  
```
define hook-stop
info registers
x/24wx $esp --> print the stack
x/2i $eip   --> print next 2 instructions
end
```
16) to continue running:
```
c
```

17) print adress of functions from libc
```
print system
```

18) set value of address
```
set{int}<adress>=<where you want it to jump to>
```
19) see backtrace
```
backtrace
```

20) we can define a varriable of struct and give it is adress like this:  
```
set $i1 = (stuct internet*)0x804a008
print *$i1
```
21) print atrribute of struct object you defined  
```
print $i1->name
```
22) examine the adress that in the attribute
```
x $i1->name
```
23) show address of variable  
```
x/wx &variable
```

24) run commands when you hit a breakpoint  
```
command
```
25) open a binary with its dump file  
```
gdb <path to executable> <path to dump file>
```
26) open gb with already running process  
```
gdb -p `pidof <executable>`
```
27) follow child processes  
```
set follow-fork-mode child
```
28) see the plt table  
```
info function @plt
```
29) see memory maps of program
```
info proc map
```

30) get to the got entry fast
```
info functions <libc function>
x/3i <the address you got>
```

32) show virtual memory locations and permissions on it  
(if peda is installed).
```
vmmap
```

33) print type of something
```
ptype <something>
```
34) connect to remote gdb  
```
Target remote <ip>:<port>
```
35) follow parent
```
set follow-fork-mode parent
```

36) shows also the stack frame of backtraced function  
```
backtrace full
```

37) run a command in gdb and exit
```
gdb -q --batch -ex "<command>"
```

38) attach to gdb with symbols
```
gdb -q --pid=<pid> --symbols=<the_file>
```
39) investigate core dump.
``` 
gdb -q -c ./core
```
40) Displays information about debugged binary and loaded sections
```
info files
```