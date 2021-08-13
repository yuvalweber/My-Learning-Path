#! /usr/bin/python
from smartcard.CardType import AnyCardType
from smartcard.CardRequest import CardRequest
from smartcard.util import toBytes,toHexString
from prettytable import PrettyTable
import sys
import argparse

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

def enumerate_files(cla,cardservice):
    array = []
    for i in range(0x00,0xFF + 1):
        for j in range(0x00,0xFF + 1):
            message = toBytes(cla + " A4 00 00 02")
            message.append(i)
            message.append(j)
            message.append(0)
            res,sw1,sw2 = cardservice.connection.transmit(message)
            if(toHexString([sw1]) == "90" or toHexString([sw1]) == "6C" or toHexString([sw1]) == "61"):
                print(GREEN + "[*] status words: {} {} for file: {} {} in CLA: {}".format(toHexString([sw1]),toHexString([sw2]),toHexString([i]),toHexString([j]),cla) + ENDC)
                array.append("{} {} {}".format(cla,toHexString([i]),toHexString([j])))
    return array

def main():
    parser = argparse.ArgumentParser(description="parsing arguments")
    sgroup = parser.add_argument_group("Main arguments")
    sgroup.add_argument('--cla','-c', dest='cla', help='cla to enumerate_files')
    args = parser.parse_args()

    if(args.cla):
        cla = args.cla
        cardservice = connect()
        files_array = enumerate_files(cla,cardservice)

        FilesTable = PrettyTable()
        FilesTable.field_names = ["CLA","File"]
        for i in files_array:
            cla = i.split()[0]
            file_insert = " ".join(i.split()[1:])
            FilesTable.add_row([cla,file_insert])
        print(GREEN + "[*] enumerated files are:" + ENDC)
        print(FilesTable)
    else:
        print(RED + "[x] you didn't enter a cla variable" + ENDC)

if __name__ == "__main__":
    main()
