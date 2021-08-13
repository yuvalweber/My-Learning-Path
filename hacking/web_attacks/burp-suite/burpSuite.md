# Table of Contents
- [configure](#configure)
- [brute force with burp](#brute-force-with-burp)
<br>
<br>

# configure
1)  first open firefox  
2) then click on the 3 lines on the top right and pick preferences  
3) scroll down and under network settings choose settings  
4) then pick manual proxy and write 127.0.0.1 and in port write 8080  
5) pick "use this proxy server for all protocols  
6) after that open burpsuite,click next --> next    
7) there under proxy pick intercept on and keep clicking forward as you get to the website.  
8) if you have a cert error go to http://burp/, download the cert
and then go to   
preferences --> privacy and security -->
#certificates --> view certificates --> import, and pick the cert.

<br>
<br>

# brute force with burp
1) intercept the packet for logging, then right click on burp-suite screen
and choose "send to intruder", and the click forward.  

2) go to intruder, pick positions, click clear (the upper one), because we are brute forcing the username and password, we pick the attack type - "cluster bomb".  

3) highlight the values you want to brute force, and click "add".

4) then go to payloads tab and pick under payload set "1"(because we brute force
two values,so the first is username and second is password).  

5) under payload options add wordlist.
and then we pick payload set "2" and there under payload options
pick default passwords.  

6) then click on intruder and click on attack,  
if succeeded we can see in the results on the length probably, something different.  


