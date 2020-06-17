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
    elevationLevel3,
    elevationLevel4,
    elevationLevel5,
    elevationLevel6,
    elevationLevel7,
    elevationLevel8,
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
        if ai.src.glob.gameState['joinPlayer']:
            print("elapsed time since last broadcast : " + str(ai.src.glob.gameState['broadcastIncantationCheckTime']))
            if ai.src.glob.gameState['incantationBroadcast'] == 0:
                inventoryRequest()
                print("---> direction : 0")
                return
            elif ai.src.glob.gameState['broadcastIncantationCheckTime'] > 30:
                ai.src.glob.gameState['joinPlayer'] = False
                return
            if ai.src.glob.gameState['incantationBroadcast'] != -1:
                print("---> direction : "+str(ai.src.glob.gameState['incantationBroadcast']))
                if (ai.src.glob.gameState['incantationBroadcast'] % 2 == 0
                or  ai.src.glob.gameState['incantationBroadcast'] == 1):
                    forwardRequest()
                elif ai.src.glob.gameState['incantationBroadcast'] in [3, 5]:
                    rightRequest()
                else:
                    leftRequest()
                ai.src.glob.gameState['incantationBroadcast'] = -1
                
        else:
            print(ai.src.glob.gameState["level"])
            elevationFunctions[ai.src.glob.gameState["level"] - 1]()




        #if ai.src.glob.gameState["broadcastIncantationCheckTime"] > 30 and ai.src.glob.gameState["incantationBroadcast"] != 0:
        #    ai.src.glob.gameState["incantationBroadcast"] = -1
        #if ai.src.glob.gameState["incantationBroadcast"] == 0:
        #    broadcastRequest("prout mdr")
        #elif ai.src.glob.gameState["incantationBroadcast"] != -1 and ai.src.glob.gameState["bufferBroadcast"] == False:
        #    if ai.src.glob.gameState["incantationBroadcast"] % 2 == 0 or ai.src.glob.gameState["incantationBroadcast"] == 1:
        #        forwardRequest()
        #    elif ai.src.glob.gameState["incantationBroadcast"] in [3, 5]:
        #        rightRequest()
        #    elif ai.src.glob.gameState["incantationBroadcast"] == 7:
        #        leftRequest()
        #    ai.src.glob.gameState["bufferBroadcast"] = True
        #    print("--------------->elevation ritual direction : "+str(ai.src.glob.gameState["incantationBroadcast"]))
        #
        #elif ai.src.glob.gameState["bufferBroadcast"]:
        #    inventoryRequest()
        #    ai.src.glob.gameState["bufferBroadcast"] = False

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



