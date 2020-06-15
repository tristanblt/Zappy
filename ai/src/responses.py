##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## responses
##

import json
import ai.src.glob
from ai.src.distances import computePlayerDistances
from ai.src.incant import checkIncant


def initGameResponse(response):
    if (response == "ko\n"):
        return None
    lineSplit = response.split("\n")
    spaceSplit = lineSplit[1].split(" ")    
    try:
        ai.src.glob.gameState["clientNum"] = int(lineSplit[0])
        ai.src.glob.gameState["mapSize"]["x"] = int(spaceSplit[0])
        ai.src.glob.gameState["mapSize"]["y"] = int(spaceSplit[1])
        return True
    except:
        return False

def forwardResponse(response):
    x = 0
    y = 0

    if ai.src.glob.lookAt == 0:
        y = 1
    elif ai.src.glob.lookAt == 1:
        x = 1
    elif ai.src.glob.lookAt == 2:
        y = -1
    elif ai.src.glob.lookAt == 3:
        x = -1
    
    for item in ai.src.glob.gameMap:
        item["pos"]["x"] += x
        item["pos"]["y"] += y
    computePlayerDistances()
    return True

def rightResponse(response):
    ai.src.glob.lookAt -= 1
    if (ai.src.glob.lookAt < 0):
        ai.src.glob.lookAt = 3
    computePlayerDistances()
    return True

def leftResponse(response):
    ai.src.glob.lookAt += 1
    if (ai.src.glob.lookAt > 3):
        ai.src.glob.lookAt = 0
    computePlayerDistances()
    return True

def lookResponse(response):
    x = 0
    y = 0
    i = 0
    pal = 1
    response = response.replace('[', '').replace(']', '').replace('\n', '')
    tiles = response.split(",")
    for tile in tiles:
        for item in ai.src.glob.gameMap:
            if item["pos"]["x"] == x and item["pos"]["y"] == y:
                ai.src.glob.gameMap.remove(item)
        items = tile.split(" ")
        for item in items:
            if (len(item) <= 0):
                continue
            ai.src.glob.gameMap.append({"pos": {"x": x, "y": y}, "type": item})
        i += 1
        x += 1
        if i >= pal:
            x = -pal
            y += 1
            pal += 2
            i = 0
    computePlayerDistances()
    ai.src.glob.gameState["canIncant"] = checkIncant()
    print(ai.src.glob.gameState["canIncant"])
    return True

def inventoryResponse(response):
    inventory = {}
    response = response.replace('[ ', '').replace(' ]', '').replace('\n', '')
    for it in response.split(', '):
        it = it.split()
        inventory[it[0]] = int(it[1])
    ai.src.glob.gameState["nbFood"] = inventory["food"]
    ai.src.glob.gameState["nbLinemate"] = inventory["linemate"]
    ai.src.glob.gameState["nbDeraumere"] = inventory["deraumere"]
    ai.src.glob.gameState["nbSibur"] = inventory["sibur"]
    ai.src.glob.gameState["nbMendiane"] = inventory["mendiane"]
    ai.src.glob.gameState["nbPhiras"] = inventory["phiras"]
    ai.src.glob.gameState["nbThystame"] = inventory["thystame"]
    return True

def broadcastResponse(response):
    #print(response)
    return True

def connectNbrResponse(response):
    ai.src.glob.gameState["clientNum"] = int(response)
    if ai.src.glob.gameState["clientNum"] > 0:
        ai.src.glob.gameState["canFork"] = True
    else:
        ai.src.glob.gameState["canFork"] = False
    return True

def forkResponse(response):
    return True

def ejectResponse(response):
    #print(response)
    return True

def takeFoodResponse(response):
    return True

def takeLinemateResponse(response):
    return True

def takeDeraumereResponse(response):
    return True

def takeSiburResponse(response):
    return True

def takeMendianeResponse(response):
    return True

def takePhirasResponse(response):
    return True

def setFoodResponse(response):
    return True

def setLinemateResponse(response):
    return True

def setDeraumereResponse(response):
    return True

def setSiburResponse(response):
    return True

def setMendianeResponse(response):
    return True

def setPhirasResponse(response):
    return True

def incantationResponse(response):
    #print(response)
    return True
