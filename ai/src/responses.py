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
    ai.src.glob.reward += 1
    return True

def rightResponse(response):
    ai.src.glob.lookAt -= 1
    if (ai.src.glob.lookAt < 0):
        ai.src.glob.lookAt = 3
    computePlayerDistances()
    ai.src.glob.reward += 1
    return True

def leftResponse(response):
    ai.src.glob.lookAt += 1
    if (ai.src.glob.lookAt > 3):
        ai.src.glob.lookAt = 0
    computePlayerDistances()
    ai.src.glob.reward += 1
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
    ai.src.glob.reward += 5
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
    ai.src.glob.reward += 3
    return True

def broadcastResponse(response):
    return True

def connectNbrResponse(response):
    ai.src.glob.gameState["clientNum"] = int(response)
    #if ai.src.glob.gameState["clientNum"] > 0:
    #    ai.src.glob.gameState["canFork"] = True
    #else:
    #    ai.src.glob.gameState["canFork"] = False
    #ai.src.glob.reward += 1
    return True

def forkResponse(response):
    ai.src.glob.gameState["canFork"] = False
    return True

def ejectResponse(response):
    return True

def takeFoodResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbFood"] += 1
        ai.src.glob.reward += 100
        removeFromTile("food")
    else:
        ai.src.glob.reward -= 40
    return True

def takeLinemateResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbLinemate"] += 1
        ai.src.glob.reward += 10
        removeFromTile("linemate")
    else:
        ai.src.glob.reward -= 40
    return True

def takeDeraumereResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbDeraumere"] += 1
        ai.src.glob.reward += 10
        removeFromTile("deraumere")
    else:
        ai.src.glob.reward -= 40
    return True

def takeSiburResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbSibur"] += 1
        ai.src.glob.reward += 10
        removeFromTile("sibur")
    else:
        ai.src.glob.reward -= 40
    return True

def takeMendianeResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbMendiane"] += 1
        ai.src.glob.reward += 10
        removeFromTile("mendiane")
    else:
        ai.src.glob.reward -= 40
    return True

def takePhirasResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbPhiras"] += 1
        ai.src.glob.reward += 10
        removeFromTile("phiras")
    else:
        ai.src.glob.reward -= 40
    return True

def takeThystameResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbThystame"] += 1
        ai.src.glob.reward += 10
        removeFromTile("thystame")
    else:
        ai.src.glob.reward -= 40
    return True

def setFoodResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbFood"] -= 1
        ai.src.glob.reward -= 0
        ai.src.glob.gameMap.append({
            "type": "food",
            "x": 0,
            "y": 0
        })
    else:
        ai.src.glob.reward -= 40
    return True

def setLinemateResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbLinemate"] -= 1
        ai.src.glob.reward += 10
        ai.src.glob.gameMap.append({
            "type": "linemate",
            "x": 0,
            "y": 0
        })
    else:
        ai.src.glob.reward -= 40
    return True

def setDeraumereResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbDeraumere"] -= 1
        ai.src.glob.reward += 10
        ai.src.glob.gameMap.append({
            "type": "deraumere",
            "x": 0,
            "y": 0
        })
    else:
        ai.src.glob.reward -= 40
    return True

def setSiburResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbSibur"] -= 1
        ai.src.glob.reward += 10
        ai.src.glob.gameMap.append({
            "type": "sibur",
            "x": 0,
            "y": 0
        })
    else:
        ai.src.glob.reward -= 40
    return True

def setMendianeResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbMendiane"] -= 1
        ai.src.glob.reward += 10
        ai.src.glob.gameMap.append({
            "type": "mendiane",
            "x": 0,
            "y": 0
        })
    else:
        ai.src.glob.reward -= 40
    return True

def setPhirasResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbPhiras"] -= 1
        ai.src.glob.reward += 10
        ai.src.glob.gameMap.append({
            "type": "phiras",
            "x": 0,
            "y": 0
        })
    else:
        ai.src.glob.reward -= 40
    return True

def setThystameResponse(response):
    if response == "ok":
        ai.src.glob.gameState["nbThystame"] -= 1
        ai.src.glob.reward += 10
        ai.src.glob.gameMap.append({
            "type": "thystame",
            "x": 0,
            "y": 0
        })
    else:
        ai.src.glob.reward -= 40
    return True

def incantationResponse(response):
    return True
