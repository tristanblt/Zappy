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
    item = item.capitalize()
    if ai.src.glob.gameState["direction"+item] in [1, 2, 8]:
        forwardRequest()
    elif ai.src.glob.gameState["direction"+item] in [3, 4, 5]:
        rightRequest()
    elif ai.src.glob.gameState["direction"+item] in [6, 7]:
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
            if ai.src.glob.gameState["nb"+item.capitalize()] < 1:
                # ai.src.glob.gameState['elevationReady'] = False
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

def elevationLevel2():
    requiredPlayers = 1
    elevationItems = {
        "linemate": 1,
        "deraumere": 0,
        "sibur": 0,
        "mendiane": 0,
        "phiras": 0,
        "thystame": 0
    }
    for item in elevationItems:
        if (not ai.src.glob.gameState["elevationReady"] and
            ai.src.glob.gameState["nb" + item.capitalize()] < elevationItems[item]):
            if getNbItemOnPlayerTile(item) > 0:
                takeObjectRequest(item)
            else:
                lookForItem(item)
            return
    ai.src.glob.gameState["elevationReady"] = True
    if prepareTile(elevationItems):
        if getNbItemOnPlayerTile("player") == requiredPlayers:
            print("Incantation for level 2 !")
            incantationRequest()
        else:
            ejectRequest()

def elevationLevel3():
    requiredPlayers = 2
    elevationItems = {
        "linemate": 1,
        "deraumere": 1,
        "sibur": 1,
        "mendiane": 0,
        "phiras": 0,
        "thystame": 0
    }
    for item in elevationItems:
        if (not ai.src.glob.gameState["elevationReady"] and
            ai.src.glob.gameState["nb" + item.capitalize()] < elevationItems[item]):
            if getNbItemOnPlayerTile(item) > 0:
                takeObjectRequest(item)
            else:
                lookForItem(item)
            return
    ai.src.glob.gameState["elevationReady"] = True
    if (prepareTile(elevationItems)):
        if getNbItemOnPlayerTile("player") == requiredPlayers:
            incantationRequest()
            print("Incantation for level 3 !")
        elif getNbItemOnPlayerTile("player") > requiredPlayers:
            ejectRequest()
        else:
            if ai.src.glob.gameState["callBroadcast"] == True:
                broadcastRequest(ai.src.glob.gameState["teamName"] + " nhi " + str(ai.src.glob.gameState["level"]))
                ai.src.glob.gameState["callBroadcast"] = False
            else:
                lookRequest()
                ai.src.glob.gameState["callBroadcast"] = True



def elevationLevel4():
    requiredPlayers = 2
    elevationItems = {
        "linemate": 2,
        "deraumere": 0,
        "sibur": 1,
        "mendiane": 0,
        "phiras": 2,
        "thystame": 0
    }
    for item in elevationItems:
        if (not ai.src.glob.gameState["elevationReady"] and
            ai.src.glob.gameState["nb" + item.capitalize()] < elevationItems[item]):
            if getNbItemOnPlayerTile(item) > 0:
                takeObjectRequest(item)
            else:
                lookForItem(item)
            return
    ai.src.glob.gameState["elevationReady"] = True
    if (prepareTile(elevationItems)):
        if getNbItemOnPlayerTile("player") == requiredPlayers:
            incantationRequest()
            print("Incantation for level 4 !")
        elif getNbItemOnPlayerTile("player") > requiredPlayers:
            ejectRequest()
        else:
            if ai.src.glob.gameState["callBroadcast"] < 1:
                broadcastRequest(ai.src.glob.gameState["teamName"] + " nhi " + str(ai.src.glob.gameState["level"]))
                ai.src.glob.gameState["callBroadcast"] += 1
            else:
                lookRequest()
                ai.src.glob.gameState["callBroadcast"] = 0

def elevationLevel5():
    requiredPlayers = 4
    elevationItems = {
        "linemate": 1,
        "deraumere": 1,
        "sibur": 2,
        "mendiane": 0,
        "phiras": 1,
        "thystame": 0
    }
    for item in elevationItems:
        if (not ai.src.glob.gameState["elevationReady"] and
            ai.src.glob.gameState["nb" + item.capitalize()] < elevationItems[item]):
            if getNbItemOnPlayerTile(item) > 0:
                takeObjectRequest(item)
            else:
                lookForItem(item)
            return
    ai.src.glob.gameState["elevationReady"] = True
    if (prepareTile(elevationItems)):
        if getNbItemOnPlayerTile("player") == requiredPlayers:
            incantationRequest()
            print("Incantation for level 5 !")
        elif getNbItemOnPlayerTile("player") > requiredPlayers:
            ejectRequest()
        else:
            if ai.src.glob.gameState["callBroadcast"] < 1:
                broadcastRequest(ai.src.glob.gameState["teamName"] + " nhi " + str(ai.src.glob.gameState["level"]))
                ai.src.glob.gameState["callBroadcast"] += 1
            else:
                lookRequest()
                ai.src.glob.gameState["callBroadcast"] = 0
    return

def elevationLevel6():
    requiredPlayers = 4
    elevationItems = {
        "linemate": 1,
        "deraumere": 2,
        "sibur": 1,
        "mendiane": 3,
        "phiras": 0,
        "thystame": 0
    }
    for item in elevationItems:
        if (not ai.src.glob.gameState["elevationReady"] and
            ai.src.glob.gameState["nb" + item.capitalize()] < elevationItems[item]):
            if getNbItemOnPlayerTile(item) > 0:
                takeObjectRequest(item)
            else:
                lookForItem(item)
            return
    ai.src.glob.gameState["elevationReady"] = True
    if (prepareTile(elevationItems)):
        if getNbItemOnPlayerTile("player") == requiredPlayers:
            incantationRequest()
            print("Incantation for level 6 !")
        elif getNbItemOnPlayerTile("player") > requiredPlayers:
            ejectRequest()
        else:
            if ai.src.glob.gameState["callBroadcast"] < 1:
                broadcastRequest(ai.src.glob.gameState["teamName"] + " nhi " + str(ai.src.glob.gameState["level"]))
                ai.src.glob.gameState["callBroadcast"] += 1
            else:
                lookRequest()
                ai.src.glob.gameState["callBroadcast"] = 0
    return

def elevationLevel7():
    requiredPlayers = 6
    elevationItems = {
        "linemate": 1,
        "deraumere": 2,
        "sibur": 3,
        "mendiane": 0,
        "phiras": 1,
        "thystame": 0
    }
    for item in elevationItems:
        if (not ai.src.glob.gameState["elevationReady"] and
            ai.src.glob.gameState["nb" + item.capitalize()] < elevationItems[item]):
            if getNbItemOnPlayerTile(item) > 0:
                takeObjectRequest(item)
            else:
                lookForItem(item)
            return
    ai.src.glob.gameState["elevationReady"] = True
    if (prepareTile(elevationItems)):
        if getNbItemOnPlayerTile("player") == requiredPlayers:
            incantationRequest()
            print("Incantation for level 7 !")
        elif getNbItemOnPlayerTile("player") > requiredPlayers:
            ejectRequest()
        else:
            if ai.src.glob.gameState["callBroadcast"] < 1:
                broadcastRequest(ai.src.glob.gameState["teamName"] + " nhi " + str(ai.src.glob.gameState["level"]))
                ai.src.glob.gameState["callBroadcast"] += 1
            else:
                lookRequest()
                ai.src.glob.gameState["callBroadcast"] = 0
    return

def elevationLevel8():
    requiredPlayers = 6
    elevationItems = {
        "linemate": 2,
        "deraumere": 2,
        "sibur": 2,
        "mendiane": 2,
        "phiras": 2,
        "thystame": 1
    }
    for item in elevationItems:
        if (not ai.src.glob.gameState["elevationReady"] and
            ai.src.glob.gameState["nb" + item.capitalize()] < elevationItems[item]):
            if getNbItemOnPlayerTile(item) > 0:
                takeObjectRequest(item)
            else:
                lookForItem(item)
            return
    ai.src.glob.gameState["elevationReady"] = True
    if (prepareTile(elevationItems)):
        if getNbItemOnPlayerTile("player") == requiredPlayers:
            incantationRequest()
            print("Incantation for level 8 ! GG WP")
        elif getNbItemOnPlayerTile("player") > requiredPlayers:
            ejectRequest()
        else:
            if ai.src.glob.gameState["callBroadcast"] < 1:
                broadcastRequest(ai.src.glob.gameState["teamName"] + " nhi " + str(ai.src.glob.gameState["level"]))
                ai.src.glob.gameState["callBroadcast"] += 1
            else:
                lookRequest()
                ai.src.glob.gameState["callBroadcast"] = 0
    return

'''
def checkIncant():
    level = ai.src.glob.gameState['level']
    nbPlayers = getNbItemOnPlayerTile("player")
    nbLinemate = getNbItemOnPlayerTile("linemate")
    nbDeraumere = getNbItemOnPlayerTile("deraumere")
    nbSibur = getNbItemOnPlayerTile("sibur")
    nbMendiane = getNbItemOnPlayerTile("mendiane")
    nbPhiras = getNbItemOnPlayerTile("phiras")
    nbThystame = getNbItemOnPlayerTile("thystame")

    if (ai.src.glob.gameState['nbFood'] < 3):
        return False
    if (level == 1
    and nbLinemate == 1):
        return True
    if (level == 2
    and nbPlayers == 2
    and nbLinemate == 1
    and nbDeraumere == 1
    and nbSibur == 1):
        return True
    if (level == 3
    and nbPlayers == 2
    and nbLinemate == 2
    and nbSibur == 1
    and nbPhiras == 2):
        return True
    if (level == 4
    and nbPlayers == 4
    and nbLinemate == 1
    and nbDeraumere == 1
    and nbSibur == 2
    and nbPhiras == 1):
        return True
    if (level == 5
    and nbPlayers == 4
    and nbLinemate == 1
    and nbDeraumere == 2
    and nbSibur == 1
    and nbMendiane == 3):
        return True
    if (level == 6
    and nbPlayers == 6
    and nbLinemate == 1
    and nbDeraumere == 2
    and nbSibur == 3
    and nbPhiras == 1):
        return True
    if (level == 7
    and nbPlayers == 6
    and nbLinemate == 2
    and nbDeraumere == 2
    and nbSibur == 2
    and nbMendiane == 2
    and nbPhiras == 2
    and nbThystame == 1):
        return True
    return False
    '''
    
