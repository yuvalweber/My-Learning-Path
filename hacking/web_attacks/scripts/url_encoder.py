#! /usr/bin/python3
from urllib.parse import quote_plus
import sys
if(len(sys.argv) > 1):
    print(quote_plus(sys.argv[1]))
else:
    print("usage: url_encoder.py <url>")
