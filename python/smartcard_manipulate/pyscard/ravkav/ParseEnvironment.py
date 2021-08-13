#! /usr/bin/python
from smartcard.CardType import AnyCardType
from smartcard.CardRequest import CardRequest
from smartcard.util import toBytes,toHexString
from prettytable import PrettyTable
from RavKavHelper.parser import parse_country_code,parse_issuer_code,parse_profile_code 
import datetime
from time import mktime
import sys

GREEN = "\033[92m"
RED = "\033[91m"
CYAN = "\033[96m"
YELLOW = "\033[93m"
ENDC = "\033[0m"

def connect():
    try:
        cardtype = AnyCardType()
        cardrequest = CardRequest(cardType=cardtype)
        cardservice = cardrequest.waitforcard()
        cardservice.connection.connect()
        return cardservice
    except:
        print(RED + "[x] please enter your card" +ENDC)
        sys.exit()


def parseEnvironment(cardservice,environment_file):
    command = toBytes("00 A4 00 00 02 20 00 19")
    res,sw1,sw2 = cardservice.connection.transmit(command)
    command = toBytes("00 A4 00 00 02 " + environment_file + " 19")
    res,sw1,sw2 = cardservice.connection.transmit(command)
    if(toHexString([sw1,sw2]) == "90 00"):
        command = toBytes("00 B2 01 04 1D")
        res,sw1,sw2 = cardservice.connection.transmit(command)
        if(toHexString([sw1,sw2]) == "90 00"):
            userInfo = {}
            EPOCH = mktime(datetime.datetime(1997,1,1).timetuple())
            hexResponse = toHexString(res).replace(" ","")
            response = bin(int(hexResponse,16))[2:].zfill(232)
            country = parse_country_code(hex(int(response[3:15],2))[2:])
            userInfo["Country"] = country
            issuer = parse_issuer_code(str(int(response[15:23],2)))
            userInfo["Issuer"] = issuer
            dateofissue = datetime.datetime.fromtimestamp(int(response[49:63],2) * 24 * 3600 + EPOCH).strftime("%d/%m %Y")
            userInfo['DateOfIssue'] = dateofissue
            enddate = datetime.datetime.fromtimestamp(int(response[63:77],2) * 24 * 3600 + EPOCH).strftime("%d/%m %Y")
            userInfo['EndDate'] = enddate
            birthdate = hexResponse[26:28] + "/" + hexResponse[24:26] + " " + hexResponse[20:24]
            userInfo["Birthdate"] = birthdate
            profiles = {}
            FirstProfile = parse_profile_code(str(int(response[186:192],2)))
            FirstProfileValid = datetime.datetime.fromtimestamp(int(response[192:206],2) * 24 * 3600 + EPOCH).strftime("%d/%m %Y")
            if(FirstProfileValid == datetime.datetime.fromtimestamp(EPOCH).strftime("%d/%m %Y")):
                FirstProfileValid = enddate
            profiles[FirstProfile] = FirstProfileValid
            SecondProfile = parse_profile_code(str(int(response[206:212],2)))
            SecondProfileValid = datetime.datetime.fromtimestamp(int(response[212:226],2) * 24 * 3600 + EPOCH).strftime("%d/%m %Y")
            if(SecondProfileValid == datetime.datetime.fromtimestamp(EPOCH).strftime("%d/%m %Y")):
                SecondProfileValid = enddate
            profiles[SecondProfile] = SecondProfileValid
            userInfo['Profiles'] = profiles

        else:
            print(RED + "[x] Failed to Read environment Record" + ENDC)
    else:
        print(RED + "[x] Failed to Select environment file" + ENDC)
    return userInfo

def getCardNumber(cardservice,num_file):
    command = toBytes("00 A4 00 00 02 " + num_file + " 19")
    res,sw1,sw2 = cardservice.connection.transmit(command)
    if(toHexString([sw1,sw2]) == "90 00"):
        command = toBytes("00 B2 01 04 1D")
        res,sw1,sw2 = cardservice.connection.transmit(command)
        if(toHexString([sw1,sw2]) == "90 00"):
            hexResponse = toHexString(res).replace(" ","")
            cardNumber = int(hexResponse[0:8],16)
            return cardNumber
        else:
            print(RED + "[x] Failed to Read CardNumber Record" + ENDC)
    else:
            print(RED + "[x] Failed to Read CardNumber File" + ENDC)
def main():        
    environment_file = "20 01"
    num_file = "00 02"
    cardservice = connect()
    cardNumber = getCardNumber(cardservice,num_file)
    userInfo = parseEnvironment(cardservice,environment_file)
    profiles = userInfo['Profiles']
    profilesKeys = list(profiles.keys())
    print(YELLOW + "\n====================" + ENDC)
    print(YELLOW + u"\u2551"+ "    RavKav Info   " + u"\u2551" + ENDC)
    print(YELLOW + "====================" + ENDC)
    print(GREEN  + "\nCard Number: " + ENDC + str(cardNumber))
    print(GREEN  + "Country: " + ENDC + userInfo['Country'])
    print(GREEN  + "Issuer: " + ENDC + userInfo['Issuer'])
    print(GREEN  + "Date of issue: " + ENDC + userInfo['DateOfIssue'])
    print(GREEN  + "End date: " + ENDC + userInfo['EndDate'])
    print(GREEN  + "Birthdate: " + ENDC + userInfo['Birthdate'])
    print(GREEN  + "Profiles:" + ENDC)
    print(CYAN   + "\tProfile: " + ENDC + profilesKeys[0])
    print(CYAN   + "\tValid until : " + ENDC + profiles[profilesKeys[0]])
    print(CYAN   + "\n\tProfile: " + ENDC + profilesKeys[1])
    print(CYAN   + "\tValid until : " + ENDC + profiles[profilesKeys[1]])
    
if __name__ == '__main__':
    main()
