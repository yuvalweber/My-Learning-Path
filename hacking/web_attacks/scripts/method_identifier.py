#! /usr/bin/python3
import socket
import sys
import re
import ssl

GREEN = "\033[92m"
YELLOW = "\033[93m"
CYAN = "\033[96m"
ENDC = "\033[0m"

template = "{} / HTTP/1.1\r\nHost: {}\r\n\r\n"

valid_requests_type = ["GET","HEAD","PUT","DELETE","OPTIONS","TRACE","PATCH","POST"]
if(len(sys.argv) == 1):
    print("Usage: method_indetifier.py <url>")
    print("Example: method_identifier.py http://www.google.com")
    sys.exit()

website = sys.argv[1]
port = 80

if(website.split("://")[0] == "https"):
    port = 443

server_info = []
host = website.split("://")[1] 

def extract_headers(headers):
    try:
        dict_headers = {}
        splitted = headers[0].split(b"\r\n") 
        for i in splitted:
            key = i.split(b":")[0].decode()
            value = i.split(b":",1)[1].decode()
            dict_headers[key] = value
        return dict_headers
    except:
        return dict_headers

def check_valid_types(host,port):
    global server_info
    for method in valid_requests_type:
        client = socket.socket()
        client.settimeout(3)
        if(port == 443):
            client = ssl.wrap_socket(client,ssl_version=ssl.PROTOCOL_SSLv23)
        client.connect((host,port))
        client.send((template.format(method,host)).encode())
        response = b''
        while True:
            try:
                output = client.recv(4096)
                response = response + output
                if(output == b"0\r\n\r\n" or output == b"" or len(re.findall(b"</html>",response)) > 0):
                    break

            except (socket.timeout,ssl.SSLError):
                break

        if(response != b'' and len(re.findall(b"301",response.split(b"\n")[0])) > 0):
            if(re.findall(b"(?:Server|server|SERVER): (.*)\n",response) and server_info == b''):
                server_info = re.findall(b"(?:Server|server|SERVER): (.*)\n",response)[0]

            new_location = re.findall(b"(?:Location|location|LOCATION): (.*)\n",response)[0]
            host = new_location.split("://")[1].replace("/","").replace("\r","")
            if(new_location.split("://")[0] == "https"):
                port = 443
            client.close()
            return host,port
        
        print(CYAN + "[DEBUG] checking {} METHOD".format(method) + ENDC)
        if(response != b'' and len(re.findall(b"400|405|501",response.split(b"\n")[0])) == 0):
            print(GREEN + "[*] Method: {} Allowed :)".format(method) + ENDC)
            if(re.findall(b"(?:Server|server|SERVER): (.*)\n",response)):
                if(re.findall(b"(?:Server|server|SERVER): (.*)\n",response)[0] not in server_info):
                    server_info.append(re.findall(b"(?:Server|server|SERVER): (.*)\n",response)[0])
        if(len(sys.argv) > 2):            
            if(sys.argv[2] == '-v' or sys.argv[2] == '--verbose'):
                headers = re.findall(b"\r\n(.*)\r\n\r\n",response,flags=re.DOTALL)
                dict_headers = extract_headers(headers)
                print(dict_headers)
        client.close()

is_ssl = check_valid_types(host,port)
if(is_ssl != None):
    host = is_ssl[0]
    port = is_ssl[1]
    check_valid_types(host,port)
if(len(server_info) > 0):
    if(len(server_info) > 1):
        print(YELLOW + "\n\nWeb Server may has firewall because we got some Server headers that they are: " + ENDC + b",".join(server_info).replace(b"\r",b"").decode())
    else:
        print(YELLOW + "\n\nWeb Server:  "+ ENDC + "{}".format(b" ".join(server_info).decode()) + ENDC)
