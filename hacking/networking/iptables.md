# commands
1) redirect 22 port to 2222
```
iptables -t nat -A PREROUTING -p tcp --dport 22 -j REDIRECT --to-ports 2222
```
2) see all iptables roles
```
iptables -t nat -L
```