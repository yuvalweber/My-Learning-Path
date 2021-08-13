# Forwarders
Forward data from one Splunk compnent to another.  
(can be from source system to indexer for example, or directly to search head).

<ins>Universal Forwarder:</ins> forward the data that you tell him to the system.  
<ins>Heavy Forwarder:</ins> forward the data and parse the data before sending it.

<br>

# Indexers 
Index and store data.

<br>

# Indexer Cluster Master
Manage indexer Clusters.  
(for example: replication,storage for the cluster,updates,etc...).

<br>

# Search Head 
manage search requests from users.

<br>

# Search Head Cluster Deployer 
Manages baselines and apps for search head cluster members.  
(this is how splunk scales).  
the cluster Deployer is not a member of the cluster.

<br>


# Deployment Server 
Centralized configuration manager.  

<br>

# License Master 
Manage license pools and stacks.  
(other compnents look at this to see that they have valid license).

