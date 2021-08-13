#! /usr/bin/python
import hashlib
import hmac
import requests
from bs4 import BeautifulSoup

GREEN = "\033[92m"
ENDC = "\033[0m"

def main():
    response = requests.get("http://10.100.102.1/ui/login")
    soup = BeautifulSoup(response.text,'html.parser')
    all_input = soup.find_all('input')
    for inp in all_input:
        if(inp.get('name') == 'nonce'):
            nonce = inp.get('value')
        elif(inp.get('name') == 'code1'):
            code1 = inp.get('value')
        elif(inp.get('name') == 'code2'):
            code2 = inp.get('value')
    password = 'Home013'
    user = 'home'
    userpwd = hmac.new(str(nonce).encode(),msg=password.encode(),digestmod=hashlib.sha256).hexdigest()
    data = {'userName':user,'language':'EN','login':'Login','userPwd':userpwd,'nonce':nonce,'code1':code1,'code2':code2}
    res = requests.post("http://10.100.102.1/ui/login",data=data)
    if("nonce" not in res.text):
        print(GREEN + "User: " + ENDC + user)
        print(GREEN + "Password: " + ENDC + password)
if __name__ == '__main__':
    main()

