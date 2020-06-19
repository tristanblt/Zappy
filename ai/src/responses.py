##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## responses
##

import json
import ai.src.glob
from ai.src.map import *
from ai.src.distances import computePlayerDistances

def initGameResponseClientNum(response):
    if response.startswith("ko"):
        return None
    lineSplit = response.split("\n")
    try:
        ai.src.glob.gameState["clientNum"] = int(lineSplit[0])
        ai.src.glob.currentCommand = initGameResponseMapSize
        return True
    except:
        return False

def initGameResponseMapSize(response):
    if response.startswith("ko"):
        return None
    lineSplit = response.split("\n")
    spaceSplit = lineSplit[0].split(" ")
    try:
        ai.src.glob.gameState["mapSize"]["x"] = int(spaceSplit[0])
        ai.src.glob.gameState["mapSize"]["y"] = int(spaceSplit[1])
        ai.src.glob.gameMap = [[[]] * ai.src.glob.gameState["mapSize"]["x"] for i in range(ai.src.glob.gameState["mapSize"]["y"])]
        return True
    except:
        return False

def forwardResponse(response):
    moveInDirection(-1)
    ai.src.glob.gameState["elevationReady"] = False
    return True

def rightResponse(response):
    rotatePlayer(1)
    return True

def leftResponse(response):
    rotatePlayer(-1)
    return True

def lookResponse(response):
    try:
        x = 0
        y = 0
        i = 0
        pal = 1
        offset = 1
        response = response.replace('[', '').replace(']', '').replace('\n', '')
        tiles = response.split(",")
        for tile in tiles:
            items = tile.split(" ")
            updateTileItems(items, x, y)
            i += 1
            x += 1
            if i >= pal:
                x = -offset
                y += 1
                pal += 2
                offset += 1
                i = 0
    except:
        pass
    return True
    

def inventoryResponse(response):
    try:
        if response == "ko":
            return True
        inventory = {}
        response = response.replace('[ ', '').replace(' ]', '').replace('\n', '')
        for it in response.split(', '):
            it = it.split()
            inventory[it[0]] = int(it[1])
        ai.src.glob.gameState["inventory"]["food"] = inventory["food"]
        ai.src.glob.gameState["inventory"]["linemate"] = inventory["linemate"]
        ai.src.glob.gameState["inventory"]["deraumere"] = inventory["deraumere"]
        ai.src.glob.gameState["inventory"]["sibur"] = inventory["sibur"]
        ai.src.glob.gameState["inventory"]["mendiane"] = inventory["mendiane"]
        ai.src.glob.gameState["inventory"]["phiras"] = inventory["phiras"]
        ai.src.glob.gameState["inventory"]["thystame"] = inventory["thystame"]
    except:
        pass
    return True

def broadcastResponse(response):
    return True

def connectNbrResponse(response):
    try:
        ai.src.glob.gameState["clientNum"] = int(response)
    except:
        pass
    return True

def forkResponse(response):
    ai.src.glob.gameState["canFork"] = False
    return True

def ejectResponse(response):
    return True

def takeFoodResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["food"] += 1
        removeFromPlayerTile("food")
    else:
        ai.src.glob.gameState["needLook"] = True
    return True

def takeLinemateResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["linemate"] += 1
        removeFromPlayerTile("linemate")
    else:
        ai.src.glob.gameState["needLook"] = True
    return True

def takeDeraumereResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["deraumere"] += 1
        removeFromPlayerTile("deraumere")
    else:
        ai.src.glob.gameState["needLook"] = True
    return True

def takeSiburResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["sibur"] += 1
        removeFromPlayerTile("sibur")
    else:
        ai.src.glob.gameState["needLook"] = True
    return True

def takeMendianeResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["mendiane"] += 1
        removeFromPlayerTile("mendiane")
    else:
        ai.src.glob.gameState["needLook"] = True
    return True

def takePhirasResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["phiras"] += 1
        removeFromPlayerTile("phiras")
    else:
        ai.src.glob.gameState["needLook"] = True
    return True

def takeThystameResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["thystame"] += 1
        removeFromPlayerTile("thystame")
    else:
        ai.src.glob.gameState["needLook"] = True
    return True

def setFoodResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["food"] -= 1
        addToPlayerTile("food")
    else:
        ai.src.glob.gameState["needInventory"] = True
    return True

def setLinemateResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["linemate"] -= 1
        addToPlayerTile("linemate")
    else:
        ai.src.glob.gameState["needInventory"] = True
    return True

def setDeraumereResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["deraumere"] -= 1
        addToPlayerTile("deraumere")
    else:
        ai.src.glob.gameState["needInventory"] = True
    return True

def setSiburResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["sibur"] -= 1
        addToPlayerTile("sibur")
    else:
        ai.src.glob.gameState["needInventory"] = True
    return True

def setMendianeResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["mendiane"] -= 1
        addToPlayerTile("mendiane")
    else:
        ai.src.glob.gameState["needInventory"] = True
    return True

def setPhirasResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["phiras"] -= 1
        addToPlayerTile("phiras")
    else:
        ai.src.glob.gameState["needInventory"] = True
    return True

def setThystameResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["thystame"] -= 1
        addToPlayerTile("thystame")
    else:
        ai.src.glob.gameState["needInventory"] = True
    return True

def incantationResponse(response):
    #ai.src.glob.gameState["elevationReady"] = False
    ai.src.glob.currentCommand = incantationResponseKo
    return True

def incantationResponseKo(response):
    if response.startswith("ko"):
        print("Incantation to level " + str(ai.src.glob.gameState["level"] + 1) + " failed")
        ai.src.glob.gameState["needExplore"] = 10
        ai.src.glob.gameState["elevationReady"] = False
    ai.src.glob.gameState["incantationBroadcast"] = -1
    return True
