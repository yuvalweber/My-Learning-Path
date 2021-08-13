#! /usr/bin/python3
from samba.credentials import Credentials
from samba.param import LoadParm
from samba.dcerpc.drsuapi import DsReplicaGetInfoRequest1,DRSUAPI_DS_REPLICA_INFO_NEIGHBORS
from samba import nttime2string
from samba.netcmd.drs import drsuapi_connect
import datetime

class Context:
    def __init__(self,server,lp,creds):
        self.server = server
        self.lp = lp
        self.creds = creds

lp = LoadParm()
creds = Credentials()
creds.guess(lp)
creds.set_username("Administrator")
creds.set_password("AdMatayOctober")
creds.set_workstation("")
creds.set_domain("")
ctx = Context("ip_of_dc",lp,creds)
drsuapi_connect(ctx)
req = DsReplicaGetInfoRequest1()
req.info_type = DRSUAPI_DS_REPLICA_INFO_NEIGHBORS
(info_type,info) = ctx.drsuapi.DsReplicaGetInfo(ctx.drsuapi_handle,1,req)
current_time = datetime.datetime.now()
for dc in info.array:
    if(dc.naming_context_dn == 'DC=example,DC=com'):
        dictonary = {}
        dictonary['source'] = "ip_of_dc"
        dictonary['namingcontext'] = dc.naming_context_dn
        last_success = nttime2string(dc.last_success)
        difference = current_time - datetime.datetime.strptime(last_success.rsplit(' ',1)[0],'%a %B %d %H:%M:%S %Y')
        if(difference.total_seconds() > 0):
            dictonary['time_from_last_success'] = str(difference)
        else:
            dictonary['time_from_last_success'] = "0 seconds"
        dictonary['Destination'] = str(dc.source_dsa_obj_dn).split(",")[1].split("CN=")[1]
        error_code,error = dc.result_last_attempt
        if(error_code == 0):
            error = "last replication was successfull"
        dictonary['message'] = error
    else:
        continue

print("Source: {}\nDestination: {}\nLast Replicate: {} ago\nError: {}".format(dictonary['source'],dictonary['Destination'],dictonary['time_from_last_success'],dictonary['message']))


