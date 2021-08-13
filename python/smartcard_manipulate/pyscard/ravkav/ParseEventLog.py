#! /usr/bin/python
from smartcard.CardType import AnyCardType
from smartcard.CardRequest import CardRequest
from smartcard.util import toBytes,toHexString
from prettytable import PrettyTable
from RavKavHelper.parser import parse_line_types_code,parse_issuer_code,parse_event_type_code
import datetime
from time import mktime
import sys

GREEN = "\033[92m"
RED = "\033[91m"
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
	print(RED + "[x] please enter your card" + ENDC)
	sys.exit()

def parseEventLog(cardservice,event_file,record_number):
    command = toBytes("00 A4 00 00 02 " + event_file + " 19")
    res,sw1,sw2 = cardservice.connection.transmit(command)
    if(toHexString([sw1,sw2]) == "90 00"):
        command = toBytes("00 B2 " + record_number + "04 1D")
        res,sw1,sw2 = cardservice.connection.transmit(command)
        if(toHexString([sw1,sw2]) == "90 00"):
            eventInfo = {}
            EPOCH = mktime(datetime.datetime(1997,1,1).timetuple())
            hexResponse = toHexString(res).replace(" ","")
            response = bin(int(hexResponse,16))[2:].zfill(232)
            issuer = parse_issuer_code(str(int(response[3:11],2)))
            eventInfo['Issuer'] = issuer
            Line_Type = parse_line_types_code(str(int(response[15:19],2)))
            eventInfo['LineType'] = Line_Type
            evenType = parse_event_type_code(str(int(response[19:23],2)))
            eventInfo['EventType'] = evenType
            evenTime = (datetime.datetime.fromtimestamp(int(response[23:53],2) + EPOCH) + datetime.timedelta(hours=2)).strftime("%d/%m/%Y %H:%M:%S")
            eventInfo['EventTime'] = evenTime
            locationBitMap = str(int(response[116:123],2))
            if(locationBitMap & 1 > 0):
                if(issuer == 'Israel Railways'):
                    railStation = 
            return eventInfo
        else:
            print(RED + "[x] Failed to Read Event Log Record" + ENDC)
    else:
        print(RED + "[x] Failed to Select Event Log File" + ENDC)

def main():
    cardservice = connect()
    event_file = "20 10"
    for i in range(1,7):
        record_number = "0" + str(i)
        eventLog = parseEventLog(cardservice,event_file,record_number)
        print(eventLog)

if __name__ == '__main__':
    main()
