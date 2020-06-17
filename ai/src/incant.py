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
    print("Looking for : "+item + " (direction "+str(ai.src.glob.gameState["direction"+item])+")")
    if ai.src.glob.gameState["direction"+item] in [1, 2, 8]:
        print("fwd")
        forwardRequest()
    elif ai.src.glob.gameState["direction"+item] in [3, 4, 5]:
        print("rt")
        rightRequest()
    elif ai.src.glob.gameState["direction"+item] in [6, 7]:
        print("lt")
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
            print("<---"+item)
            setObjectRequest(item)
            return False
        elif nbItemOnTile > items[item]:
            print("--->"+item)
            takeObjectRequest(item)
            return False
        elif getNbItemOnPlayerTile("food") > 0:
            takeObjectRequest("food")
            return False
    return True

def elevationLevel2():
    elevationItems = {
        "linemate": 1,
        "deraumere": 0,
        "sibur": 0,
        "mendiane": 0,
        "phiras": 0,
        "thystame": 0
    }
    if not ai.src.glob.gameState["elevationReady"] and getNbItemOnPlayerTile("linemate") > 0:
        takeObjectRequest("linemate")
    elif (not ai.src.glob.gameState["elevationReady"] and
        ai.src.glob.gameState["nbLinemate"] < 1 and
        getNbItemOnPlayerTile("linemate") < 1):
        lookForItem("linemate")
    else:
        ai.src.glob.gameState["elevationReady"] = True
        if (prepareTile(elevationItems)):
            incantationRequest()
            print("UP LEVEL 2 !!!!!!!!!!!!!!!!!!!!!")
    return

def elevationLevel3():
    return

def elevationLevel4():
    return

def elevationLevel5():
    return

def elevationLevel6():
    return

def elevationLevel7():
    return

def elevationLevel8():
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
    
