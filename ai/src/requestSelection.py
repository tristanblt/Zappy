##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## requestSelection
##

import ai.src.glob

from ai.src.requests import *
from ai.src.incant import *

elevationFunctions = [
    elevationLevel2,
    # elevationLevel3,
    # elevationLevel4,
    # elevationLevel5,
    # elevationLevel6,
    # elevationLevel7,
    # elevationLevel8,
]

def requestSelection(mainsock):
    if updateFood():
        return
    if ai.src.glob.gameState["starving"] or ai.src.glob.gameState["level"] == 8:
        if foodAtPlayerPosition():
            print("food on player tile")
            takeObjectRequest("food")
        elif itemInMap("food"):
            print("food in map")
            lookForItem("food")
        else:
            print("explore")
            explore()
    else:
        if ai.src.glob.gameState["level"] < 8:
            elevationFunctions[ai.src.glob.gameState["level"] - 1]()

def updateFood():
    if ai.src.glob.gameState["starveCheckTime"] >= 100:
        inventoryRequest()
        ai.src.glob.gameState["starveCheckTime"] = 0
        return True
    if ai.src.glob.gameState["starving"]:
        if ai.src.glob.gameState["nbFood"] > 10:
            ai.src.glob.gameState["starving"] = False
    else:
        if ai.src.glob.gameState["nbFood"] < 3:
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



