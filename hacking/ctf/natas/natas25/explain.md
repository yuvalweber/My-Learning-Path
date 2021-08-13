# <ins>Explain</ins>
1) first as we can see in the source code it is pretty obvious that we are looking at directory traversal vulnerabilty
 because the program replace every ../ with "" .

2) we can go around if we use ....//.  
 now if we replace ../ with "", we still left with ../

## <ins>POC:</ins>  
now if we want for example to read the /etc/passwd file we could for example use the following link:
http://natas25.natas.labs.overthewire.org/?lang=....//....//....//....//....//etc/passwd

i also noticed we can use the user-agent to read file like that:
\<? php include "/etc/natas_webpass/natas26"; ?>  
and read the log the session write to and there we could see the password.
