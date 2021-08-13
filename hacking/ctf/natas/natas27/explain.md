# <ins>Explain</ins>
1) because the length of username is 64 when we create longer one 
 it will truncate it to 64.  
 spaces count as nothing, and if we create natas + ' ' *64 + 'something',
 then our username will be natas28.

2) because we chose the password we could leak its data from the database.
3) as you can see in dumpData, it will loop all over the results and print them.

4) now have two natas28 users, so it will print all of their passwords, if we login.
