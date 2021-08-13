# Table of Contents
- [configure forwarder](#configure-forwarder)
- [define app](#define-app)

<br>
<br>

# configure forwarder
1) first we run  
```
sudo splunk start --accept-license
```
2) then enter user and password  
and in order to make splunk run on boot run the following command  
```
./splunk enable boot-start
```
3) after that we tell splunk where to forward its data  
```
./splunk add forwarder-server <ip>:<port>
```
4) add directory to monitor (can also add -host <host_name>).
```
./splunk add monitor <path>
```
5) to make this changes take effect restart it  
```
./splunk restart
```

<br>
<br>

# define app

1) first we go to the $SPLUNK_HOME/etc/deployment-apps and make a new directory there  

2) then we reload the deploy server  
```
./splunk reload deploy-server
```
3) then go to the web interface and under forwarder management notice that a new app was added  

4) then we need to add new server class and add the app to the newly created server class.  

5) then we need to add a deployment client.  
 we do this by going to the forwarder in splunk and do this
 ```
./splunk set deploy-poll <deployment-server>:<management_port>
./splunk restart
```

6)  and then in the splunk web we can see that a new
 client is added under forwarder management --> clients 

7) then add the client to the server app by
 entering the server apps and click   
 `add client`

8) now in the client under $SPLUNK_HOME/etc/apps we could see our new app