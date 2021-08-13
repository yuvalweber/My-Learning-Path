# commands
1) scanning the network
```
nmap -sP <ip>/<prefix>
```
or  
```
nmap -sn <ip>/<prefix>
```
2) scan all the ports of ip and more info
```
nmap -A -T4 -p- <ip>
```


3) for scanning udp
```
nmap -sU -T4 <ip>
```

4) check for ms17_010 (eternalblue)
```
nmap -p 445 --script=smb-vuln-ms17-010 <ip>
```

5) run all scripts
```
nmap --script=all <ip>
```
6) scanning services and their version
```
nmap -sV <ip>
```
7) scan default ports, their versions, and default scripts
```
nmap -sC -sV <ip>
```
