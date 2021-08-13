import pickle
import requests
from bs4 import BeautifulSoup

def CreateFileForCoins():
    safemoon = {"Coin":"safemoon","PriceCost":73,"ammount":76635172}
    uniswap = {"Coin":"uniswap","PriceCost":294.522,"ammount":10.28}
    ftx = {"Coin":"ftx-token","PriceCost":298.4218,"ammount":5.99}
    venus = {"Coin":"venus","PriceCost":293.94,"ammount":9}
    coins = [safemoon, uniswap, ftx, venus]
    # coinsArray = []

    # for coin in coins:
    #     res = BeautifulSoup(coin.text,"html.parser")
    #     currentPrice = str(res.find("div",{"class":"priceValue___11gHJ"}).get_text()).replace("$","")
    #     coinName = coin.request.path_url.split("/")[2]
    #     temp = {"Coin":coinName, "Price": currentPrice}
    #     coinsArray.append(temp)

    with open('Prices.pickle', 'wb') as handle:
        pickle.dump(coins, handle, protocol=pickle.HIGHEST_PROTOCOL)

# with open('filename.pickle', 'rb') as handle:
#     b = pickle.load(handle)

# ftx = 298.4218$ (5.99)
# uniswap = 294.522$ (10.28)
# venus = 293.94$ (9)
# safemoon = 73$ (76,635,172)
CreateFileForCoins()