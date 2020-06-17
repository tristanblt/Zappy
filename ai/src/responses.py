##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## responses
##

import json
import ai.src.glob
from ai.src.distances import computePlayerDistances

def removeFromTile(item):
    for it in ai.src.glob.gameMap:
        if (it["type"] == item
        and it["pos"]["x"] == 0
        and it["pos"]["y"] == 0):
            try:
                ai.src.glob.gameMap.remove(it)
            except:
                pass
            return
    return

def initGameResponseClientNum(response):
    if (response == "ko\n"):
        return None
    lineSplit = response.split("\n")
    try:
        ai.src.glob.gameState["clientNum"] = int(lineSplit[0])
        ai.src.glob.currentCommand = initGameResponseMapSize
        return True
    except:
        return False

def initGameResponseMapSize(response):
    if (response == "ko\n"):
        return None
    lineSplit = response.split("\n")
    spaceSplit = lineSplit[0].split(" ")    
    try:
        ai.src.glob.gameState["mapSize"]["x"] = int(spaceSplit[0])
        ai.src.glob.gameState["mapSize"]["y"] = int(spaceSplit[1])
        return True
    except:
        return False

def forwardResponse(response):
    for item in ai.src.glob.gameMap:
        item["pos"]["y"] -= 1
    computePlayerDistances()
    return True

def rightResponse(response):
    tmp = None
    for item in ai.src.glob.gameMap:
        tmp = item["pos"]["x"]
        item["pos"]["x"] = -item["pos"]["y"]
        item["pos"]["y"] = tmp
    computePlayerDistances()
    return True

def leftResponse(response):
    tmp = None
    for item in ai.src.glob.gameMap:
        tmp = -item["pos"]["x"]
        item["pos"]["x"] = item["pos"]["y"]
        item["pos"]["y"] = tmp
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
    return True

def connectNbrResponse(response):
    ai.src.glob.gameState["clientNum"] = int(response)
    #if ai.src.glob.gameState["clientNum"] > 0:
    #    ai.src.glob.gameState["canFork"] = True
    #else:
    #    ai.src.glob.gameState["canFork"] = False
    return True

def forkResponse(response):
    ai.src.glob.gameState["canFork"] = False
    return True

def ejectResponse(response):
    return True

def takeFoodResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbFood"] += 1
        removeFromTile("food")
    return True

def takeLinemateResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbLinemate"] += 1
        removeFromTile("linemate")
    return True

def takeDeraumereResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbDeraumere"] += 1
        removeFromTile("deraumere")
    return True

def takeSiburResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbSibur"] += 1
        removeFromTile("sibur")
    return True

def takeMendianeResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbMendiane"] += 1
        removeFromTile("mendiane")
    return True

def takePhirasResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbPhiras"] += 1
        removeFromTile("phiras")
    return True

def takeThystameResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbThystame"] += 1
        removeFromTile("thystame")
    return True

def setFoodResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbFood"] -= 1
        ai.src.glob.gameMap.append({
            "type": "food",
            "x": 0,
            "y": 0
        })
    return True

def setLinemateResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbLinemate"] -= 1
        ai.src.glob.gameMap.append({
            "type": "linemate",
            "pos": {
                "x": 0,
                "y": 0
            }
        })
    return True

def setDeraumereResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbDeraumere"] -= 1
        ai.src.glob.gameMap.append({
            "type": "deraumere",
            "pos": {
                "x": 0,
                "y": 0
            }
        })
    return True

def setSiburResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbSibur"] -= 1
        ai.src.glob.gameMap.append({
            "type": "sibur",
            "x": 0,
            "y": 0
        })
    return True

def setMendianeResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbMendiane"] -= 1
        ai.src.glob.gameMap.append({
            "type": "mendiane",
            "x": 0,
            "y": 0
        })
    return True

def setPhirasResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbPhiras"] -= 1
        ai.src.glob.gameMap.append({
            "type": "phiras",
            "x": 0,
            "y": 0
        })
    return True

def setThystameResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbThystame"] -= 1
        ai.src.glob.gameMap.append({
            "type": "thystame",
            "x": 0,
            "y": 0
        })
    return True

def incantationResponse(response):
    ai.src.glob.gameState["elevationReady"] = False
    return True
