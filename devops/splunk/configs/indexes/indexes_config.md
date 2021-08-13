# Table of Contents
- [configure indexes](#configure-indexes)
- [indexes.conf file options](#indexes.conf-file-option)

<br>
<br>

# configure indexes
one of the important splunk directory is /opt/splunk/etc/system/default.  
it contains the default indexs.conf also.  
if we define in indexes.conf the value frozenTimePeriodsInSecs ,
 we can decide how much time spluk will retain data.

<br>

# indexes.conf file options
1) global settings are under the [default]  stanza .

2) per index options define in the [\<index>] stanza.

3) per provider option (external provider like hadoop,perfmon) define in the [\<provider>:] stanza.

4) per provider family options (like things that come together, [hadoop,hive] ) define in the [\<provider>-\<family>:] stanza.

5) per virtual index family (let splunk access data in other resources).