#! /usr/bin/python3
import requests
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders
from bs4 import BeautifulSoup
from os import stat
from datetime import datetime
from prettytable import PrettyTable
from helperFunctions.CreateTable import CreateTable

## Mailing Configuration ##
def sendEmail():
    msg = MIMEMultipart()
    msg['From'] = "<censored>"
    msg['To'] = "yuval199985@gmail.com"
    msg['Subject'] = "Important Crypto Update!!!"

    part = MIMEBase('application', "octet-stream")
    part.set_payload(open("CoinsTable.xlsx", "rb").read())
    encoders.encode_base64(part)
    part.add_header('Content-Disposition', 'attachment; filename="CoinsTable.xlsx"')
    msg.attach(part)

    s = smtplib.SMTP("smtp.gmail.com",587)
    s.starttls()
    s.login("<censored>","<censored>")
    s.sendmail("<censored>","yuval199985@gmail.com",msg.as_string())
    s.quit()

def isSentToday():
    today = datetime.now()
    if(datetime.fromtimestamp(stat("./helperFunctions/sent.txt").st_mtime).strftime("%Y %m/%d") != today.strftime("%Y %m/%d")):
        return False
    return True

if(not isSentToday()):
    CreateTable()
    sendEmail()
    with open("./helperFunctions/sent.txt","w") as writer:
        writer.write("yes")

