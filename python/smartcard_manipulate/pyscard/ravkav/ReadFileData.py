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

def read_file_data(cardservice,path):
    file = open(path)
    content = file.readlines()
    array_files = []
    array_records = []

    for i in content:
        file_i = i.replace('"','')
        command = toBytes("00 A4 00 00 02 " +file_i+  " 19")
        res,sw1,sw2 = cardservice.connection.transmit(command)
        array_files.append(file_i + " " + toHexString(res))
        j = 1
        while(toHexString([sw1]) != "6A" and toHexString([sw1]) != "69"):
            record_j = toHexString([j])
            command = toBytes("00 B2 " + record_j +  " 04 1D")
            res,sw1,sw2 = cardservice.connection.transmit(command)
            if(toHexString([sw1]) != "6A" and toHexString([sw2]) != 69):
                array_records.append(file_i + " " + record_j + " " + toHexString(res))
            j += 1
    return array_files,array_records

def main():
    parser = argparse.ArgumentParser(description="parsing arguments")
    sgroup = parser.add_argument_group("Main arguments")
    sgroup.add_argument('--file','-f', dest='file', help='path to file contain file names')
    args = parser.parse_args()

    if(args.file):
        cardservice = connect()
        array_files,array_records = read_file_data(cardservice,args.file)
        FilesTable  = PrettyTable()
        RecordsTable = PrettyTable()
        FilesTable.field_names = ["File","Command","Response"]
        RecordsTable.field_names = ["File","Record","Command","Response"]

        for i in array_files:
            file_name = i.split()[0] + " " + i.split()[1]
            response = i.split(" ",2)[2]
            command = "SELECT FILE"
            FilesTable.add_row([file_name,command,response])

        for j in array_records:
            file_name = j.split()[0] + " " + j.split()[1]
            record_name = j.split()[2]
            response = j.split(" ",3)[3]
            command = "READ RECORD"
            if(response != "00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00" and response != ""):
                RecordsTable.add_row([file_name,record_name,command,response])

        print(GREEN + "\n[*] Files Table:" + ENDC)
        print(FilesTable)
        print(GREEN + "\n[*] Records Table:" + ENDC)
        print(RecordsTable)
    else:
        print(RED + "[x] you must enter the file parameter" + ENDC)

if __name__ == "__main__":
    main()
