#! /usr/bin/python
from smartcard.CardType import AnyCardType
from smartcard.CardRequest import CardRequest
from smartcard.util import toBytes,toHexString
from prettytable import PrettyTable
import sys

GREEN = "\033[92m"
RED = "\033[91m"
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

def enumerate_CLAs(cardservice):
    array = []
    for i in range(0x00,0xFF + 1):
        message = toBytes("A4 04 00")
        message.insert(0,i)
        res,sw1,sw2 = cardservice.connection.transmit(message)
        if(toHexString([sw1]) != '6E' and toHexString([sw1])!= '68'):
            array.append(toHexString([i]))
    return array

def main():
    cardservice = connect()
    clas_array = enumerate_CLAs(cardservice)

    CLATable  = PrettyTable()
    CLATable.field_names = ["CLA"]
    for i in clas_array:
        CLATable.add_row([str(i)])

    print(GREEN +"[*] Valid CLA bytes:\n" + ENDC)
    print(CLATable)

if __name__ == "__main__":
    main()
