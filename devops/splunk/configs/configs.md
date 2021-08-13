# Table of Contents
- [config types](#config-types)
    * [inputs.conf](#inputs.conf)
    * [props.conf](#props.conf)
    * [transforms.conf](#transforms.conf)
    * [indexes.conf](#indexes.conf)
- [scripted inputs](#scripted-inputs)
- [splunk commands](#splunk-commands)
    * [btool](#btool)
    * [normal commands](#normal-commands)

<br>
<br>

# config types
## <ins>inputs.conf</ins>
Governs data inputs such as forwarders and file system monitroing.
(also defines indexes).

<br>

## <ins>props.conf</ins>
Governs indexing property behavior.

<br>

## <ins>transforms.conf</ins>
Settings and values that Govern data transformation.

<br>

## <ins>indexes.conf</ins>
define settings and pathes for indexes and their buckets.

<br>
<br>

# scripted inputs
 1) first we need to go to splunk web  
 2) then go to settings --> data inputs --> scripts,  
 and pick if want to make it locally or remotly.

 <br>
 <br>

 # splunk commands
 ## <ins>btool</ins>
1) show transforms config files   
```
splunk cmd btool transforms list
```
2) search for specific app  
```
splunk cmd btool --app=<app_name> transforms list
```
3) see where splunk getting is value from  
```
splunk cmd btool transform list --debug
```
4) check for typo
```
splunk cmd btool check
```

<br>

## <ins>normal commands</ins>
1) check hash of db  
```
splunk check-integrity -bucketPath <path_to_bucket> -verbose
```