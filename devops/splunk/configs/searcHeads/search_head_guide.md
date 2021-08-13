# Table of Contents
- [config search head](#config-search-head)
- [configure deployer](#configure-deployer)
- [search head commands](#search-head-commands)

<br>
<br>

# config search head
```
sudo ./splunk init shcluster-config
-auth <username>:<password>
-mgmt_uri <URI>:<management_port>
-replication_port <replication_port>
-replication_factor <number>
-conf_deploy_fetch_url <URL>:<management_port>
-secret <security_key>
-shcluster_label <label>
```
<br>
<br>

# configure deployer
1)  to configure to deployer we edit the file /opt/splunk/etc/system/local/servers.conf,
 and add a stanza for the shcluster  
  <b>for example:  </b>
 ```
[shclustering]
pass4Symmkey = <security key>
shcluster_label = <cluser name>
```

2) after that we need to bring up captain from one of the searcHeads.
```
./splunk bootstrap shcluster-captain
-servers_list "<URI>:<management_port>,..."
-auth <username>:<password>
```

3) if we want to add a member to the shcluster after the bootstrap already configured  
```
./splunk add shcluster-member -current_member_uri <URI>:<management_port>
```

<br>
<br>

# search head commands
1) see splunk shcluster status  
```
./splunk show shcluster-status -auth <username>:<password>
```