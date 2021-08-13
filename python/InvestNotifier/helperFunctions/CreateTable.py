import pandas as pd
import requests
import pickle
from bs4 import BeautifulSoup


def findValueInArray(arr,coinName):
    for i in arr:
        if(i['Coin'] == coinName):
            return i

def CreateTable():
    coinOldStatus = []
    with open('./helperFunctions/Prices.pickle', 'rb') as handle:
        coinOldStatus = pickle.load(handle)

    safemoon = requests.get("https://coinmarketcap.com/currencies/safemoon")
    uniswap = requests.get("https://coinmarketcap.com/currencies/uniswap")
    ftx = requests.get("https://coinmarketcap.com/currencies/ftx-token")
    venus = requests.get("https://coinmarketcap.com/currencies/venus")
    coins = [safemoon, uniswap, ftx, venus]
    coinsArray = []
    Coinsum = 0

    for coin in coins:
        res = BeautifulSoup(coin.text,"html.parser")
        raisePercent = res.find("span",{"class":"sc-15yy2pl-0 gEePkg"}).getText()
        classes = res.find("span",{"class":"sc-15yy2pl-0 gEePkg"}).findNext().attrs['class'][0]
        currentPrice = float(res.find("div",{"class":"priceValue___11gHJ"}).get_text().replace('$',''))
        coinName = coin.request.path_url.split("/")[2]
        arr = findValueInArray(coinOldStatus,coinName)
        currentValue = round(currentPrice * arr['ammount'],2)
        oldValue = arr['PriceCost']
        MoneyEarned = round(currentValue - oldValue,2)
        raisePercentNew = round((currentValue / oldValue) * 100 - 100,2)
        if(raisePercentNew < 0):
            raisePercentNew = "- " + str(raisePercentNew) + "%"
        else:
            raisePercentNew = "+ " + str(raisePercentNew) + "%"

        Coinsum += MoneyEarned

        if('up' in classes):
            Title = 'Raise Percent 24h'
            raisePercent = "+ " + raisePercent
        else:
            Title = 'Down Percent 24h'
            raisePercent = "- " + raisePercent

        oldValue = str(oldValue) + "$"
        currentValue = str(currentValue) + "$"
        if(MoneyEarned > 0):
            MoneyEarned = "+ " + str(MoneyEarned) + "$"
        else:
            MoneyEarned = "- " + str(MoneyEarned) + "$"
        
        temp = {"Coin":coinName, "OldValue": oldValue ,"CurrentValue": currentValue,"Raise Percent 24h": raisePercent,"Money Earned": MoneyEarned, "Raise Percent": raisePercentNew,"Total":""}
        coinsArray.append(temp)
    
    if(Coinsum > 0):
        Coinsum = "+ " + str(round(Coinsum,2)) + "$"
    else:
        Coinsum = "- " + str(round(Coinsum,2)) + "$"
        
    coinsArray.append({"Coin":"", "OldValue": "" ,"CurrentValue": "","Raise Percent 24h": "","Money Earned": "", "Raise Percent": "","Total":Coinsum})
    coins = [x['Coin'] for x in coinsArray]
    raisePercents24h = [x['Raise Percent 24h'] for x in coinsArray]
    oldValues = [x['OldValue'] for x in coinsArray]
    CurrentValues = [x['CurrentValue'] for x in coinsArray]
    raisePercents = [x['Raise Percent'] for x in coinsArray]
    MoneyEarneds = [x['Money Earned'] for x in coinsArray]
    Totals = [x['Total'] for x in coinsArray]

    df = pd.DataFrame({'Coin': coins,
                   "OldValue": oldValues,
                   "CurrentValue": CurrentValues,
                   Title: raisePercents24h,
                   "Raise Percent": raisePercents,
                   "Money Earned": MoneyEarneds,
                   "Total Earned":Totals
                   })

    writer = pd.ExcelWriter("CoinsTable.xlsx", engine='xlsxwriter')
    df.to_excel(writer, sheet_name='CoinsStatus', startrow=1, header=False, index=False)
    workbook = writer.book
    worksheet = writer.sheets['CoinsStatus']
    (max_row, max_col) = df.shape
    column_settings = []
    for header in df.columns:
        column_settings.append({'header': header})
    worksheet.add_table(0, 0, max_row, max_col - 1, {'columns': column_settings})
    worksheet.set_column(0, max_col - 1, 12)
    # if(down):
    #     df.style.apply(['background-color: lime'])
    # else:
    #     df.style.apply(['background-color: red'])
    writer.save()