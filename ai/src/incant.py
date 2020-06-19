##
## EPITECH PROJECT, 2020
## PSU_zappy_2019
## File description:
## incant
##

import random
import ai.src.glob
from ai.src.requests import *

def explore():
    decision = random.randrange(0, 6)
    if decision in [0, 1]:
        lookRequest()
    elif decision in [2, 3]:
        forwardRequest()
    elif decision == 4:
        rightRequest()
    else:
        leftRequest()

def lookForItem(item):
    if ai.src.glob.gameState["direction"][item] in [1, 2, 8]:
        forwardRequest()
    elif ai.src.glob.gameState["direction"][item] in [3, 4, 5]:
        rightRequest()
    elif ai.src.glob.gameState["direction"][item] in [6, 7]:
        leftRequest()
    else:
        explore()

def getNbItemOnPlayerTile(itemName):
    nbItem = 0
    for item in ai.src.glob.gameMap:
        if (item['type'] == itemName
        and item['pos']['x'] == 0
        and item['pos']['y'] == 0):
            nbItem += 1
    return nbItem

def prepareTile(items):
    for item in items:
        nbItemOnTile = getNbItemOnPlayerTile(item)
        if nbItemOnTile < items[item]:
            if ai.src.glob.gameState["inventory"][item] < 1:
                explore()
            else:
                setObjectRequest(item)
            return False
        elif nbItemOnTile > items[item]:
            takeObjectRequest(item)
            return False
        elif getNbItemOnPlayerTile("food") > 0:
            takeObjectRequest("food")
            return False
    return True

def elevation(lvlToAttain, required):
    requiredPlayers = required["requiredPlayers"]
    elevationItems = required["elevationItems"]
    nbPlayersOnTile = getNbItemOnPlayerTile("player")
    for item in elevationItems:
        if (not ai.src.glob.gameState["elevationReady"] and
            ai.src.glob.gameState["inventory"][item] < elevationItems[item]):
            if getNbItemOnPlayerTile(item) > 0:
                takeObjectRequest(item)
            else:
                lookForItem(item)
            return
    ai.src.glob.gameState["elevationReady"] = True
    if prepareTile(elevationItems):
        if nbPlayersOnTile == requiredPlayers:
            if ai.src.glob.gameState["validIncant"] == True:
                broadcastRequest(ai.src.glob.gameState["teamName"] + " gfi " + str(ai.src.glob.gameState["level"]))
                if ai.src.glob.debug:
                    print("Warning teammates that they can do other stuff")
                ai.src.glob.gameState["validIncant"] = False
            else:
                if ai.src.glob.debug:
                    print("Incantation for level %d !" % lvlToAttain)
                incantationRequest()
                ai.src.glob.gameState["validIncant"] = True
        elif nbPlayersOnTile > requiredPlayers:
            if ai.src.glob.debug:
                print("Too much player on tile")
            if random.randrange(0, 5) == 1:
                ejectRequest()
            else:
                lookRequest()
        elif lvlToAttain != 2:
            if ai.src.glob.gameState["callBroadcast"] == True:
                broadcastRequest(ai.src.glob.gameState["teamName"] + " nhi " + str(ai.src.glob.gameState["level"]))
                ai.src.glob.gameState["callBroadcast"] = False
            else:
                lookRequest()
                ai.src.glob.gameState["callBroadcast"] = True
