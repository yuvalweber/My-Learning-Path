# Table of Contents
- [crack hashes](#crack-hashes)
- [crack zip](#crack-zip)
- [WordList](#WordList)

<br>
<br>

# crack hashes
normally we will generate a wordlist using crunch
### example: 
```
crunch <min len> <max len> -t <template> -o <save file to>
```
then we will use hashcat to crack the specific hash using our wordlist.  
### example:
we will crack md5 hash
```
hashcat -m 0 <hash> <wordlist file>
```
-m = 0 (md5)  
(we can also use john if we want).

<br>
<br>

# crack zip
to crack a password of a zip or a rar file we will show 2 methods.  
one with john and one with hashcat.  

<br>

## <ins>john</ins>
first we will use zip2john for getting the hash of the zip.  
(if it is a rar file we will use rar2john).  
we will then save the output to a file (for example hash.txt).  
then we will use john for cracking the hash like that.
### example:
```
john --format <zip or rar> <hash file>
```
<br>

## <ins>hashcat</ins>
for hashcat it is simpler.  
if we want to crack zip we will do it like that.
### example:
```
hashcat -m 13600 <hash> <wordlist>
```
and for rar we will find the module number.  
if you want to find the mode number for specific file do it like that.
### example:
```
hashcat --help|grep -i rar

  12500 | RAR3-hp                                          | Archives
  13000 | RAR5                                             | Archives

```
from that we can conclude that the mode number we need is 13000.

<br>
<br>


# WordList
if you want to find a suggested wordlists i recommend checking the following git repo:  
https://github.com/danielmiessler/SecLists