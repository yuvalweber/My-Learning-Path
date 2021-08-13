# patching binaries
<ins>patching binaries with vim :</ins>  
1) lets first open the binary with vim
```
vim <binary>
```
2) now change it to hex 
```
:%!xxd
```
3) after that look for the patterns of hex you found, and edit what you want.

4) now after you modify the file, you need to transfer it back to bytes
```
:%!xxd -r
```
5) now just save the file
```
:wq!
```