##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## requestSelection
##

import ai.src.glob

from ai.src.requests import *
from ai.src.incant import *
'''
elevationFunctions = [
    elevationLevel2,
    elevationLevel3,
    elevationLevel4,
    elevationLevel5,
    elevationLevel6,
    elevationLevel7,
    elevationLevel8,
]'''

elevationRequired = [
    {
        "requiredPlayers":1,
        "elevationItems": {
            "linemate": 1,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0
        }
    },
    {
        "requiredPlayers":2,
        "elevationItems": {
            "linemate": 1,
            "deraumere": 1,
            "sibur": 1,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0
        }
    },
    {
        "requiredPlayers":2,
        "elevationItems": {
            "linemate": 2,
            "deraumere": 0,
            "sibur": 1,
            "mendiane": 0,
            "phiras": 2,
            "thystame": 0
        }
    },
    {
        "requiredPlayers":4,
        "elevationItems": {
            "linemate": 1,
            "deraumere": 1,
            "sibur": 2,
            "mendiane": 0,
            "phiras": 1,
            "thystame": 0
        }
    },
    {
        "requiredPlayers":4,
        "elevationItems": {
            "linemate": 1,
            "deraumere": 2,
            "sibur": 1,
            "mendiane": 3,
            "phiras": 0,
            "thystame": 0
        }
    },
    {
        "requiredPlayers":6,
        "elevationItems": {
            "linemate": 1,
            "deraumere": 2,
            "sibur": 3,
            "mendiane": 0,
            "phiras": 1,
            "thystame": 0
        }
    },
    {
        "requiredPlayers":6,
        "elevationItems": {
            "linemate": 2,
            "deraumere": 2,
            "sibur": 2,
            "mendiane": 2,
            "phiras": 2,
            "thystame": 1
        }
    },
]

def requestSelection(mainsock):
    if ai.src.glob.gameState["needLook"]:
        lookRequest()
        ai.src.glob.gameState["needLook"] = False
        return
    if ai.src.glob.gameState["needInventory"]:
        inventoryRequest()
        ai.src.glob.gameState["needInventory"] = False
        return
    if updateFood():
        return
    if ai.src.glob.gameState["starving"] or ai.src.glob.gameState["level"] == 8:
        print("Searching food because starving")
        ai.src.glob.gameState["incantationBroadcast"] = -1
        ai.src.glob.gameState["joinPlayer"] = False
        if foodAtPlayerPosition():
            takeObjectRequest("food")
        elif itemInMap("food"):
            lookForItem("food")
        else: 
            explore()
    else:
        if ai.src.glob.gameState["needExplore"] > 0:
            ai.src.glob.gameState["needExplore"] -= 1
            explore()
            return
        if ai.src.glob.gameState['joinPlayer']:
            print("Joining member of your team for level " + str(ai.src.glob.gameState["level"] + 1) + " incantation", end="")
            if ai.src.glob.gameState['incantationBroadcast'] == 0:
                inventoryRequest()
                return
            elif ai.src.glob.gameState['broadcastIncantationCheckTime'] > 30:
                ai.src.glob.gameState['joinPlayer'] = False
                return
            if ai.src.glob.gameState['incantationBroadcast'] != -1:
                if (ai.src.glob.gameState['incantationBroadcast'] % 2 == 0
                or  ai.src.glob.gameState['incantationBroadcast'] == 1):
                    forwardRequest()
                elif ai.src.glob.gameState['incantationBroadcast'] in [3, 5]:
                    rightRequest()
                else:
                    leftRequest()
                ai.src.glob.gameState['incantationBroadcast'] = -1
            else:
                inventoryRequest()
                
        else:
            elevation(ai.src.glob.gameState["level"] + 1, elevationRequired[ai.src.glob.gameState["level"] - 1])
            # elevationFunctions[ai.src.glob.gameState["level"] - 1]()

def updateFood():
    if ai.src.glob.gameState["starveCheckTime"] >= 100:
        inventoryRequest()
        ai.src.glob.gameState["starveCheckTime"] = 0
        return True
    if ai.src.glob.gameState["starving"]:
        if ai.src.glob.gameState["nbFood"] > 15:
            ai.src.glob.gameState["starving"] = False
    else:
        if ai.src.glob.gameState["nbFood"] < 7:
            ai.src.glob.gameState["elevationReady"] = False
            ai.src.glob.gameState["starving"] = True

def foodAtPlayerPosition():
    if getNbItemOnPlayerTile("food") > 0:
        return True
    else:
        return False

def itemInMap(itemType):
    for item in ai.src.glob.gameMap:
        if item['type'] == itemType:
            return True
    return False



