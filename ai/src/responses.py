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
    firstPlayer = True
    for item in ai.src.glob.gameMap:
        if (item["type"] == "player"
        and item["pos"]["x"] == 0
        and item["pos"]["y"] == 0
        and firstPlayer):
            firstPlayer = False
        else:
            item["pos"]["y"] -= 1
    computePlayerDistances()
    ai.src.glob.gameState["elevationReady"] = False
    return True

def rightResponse(response):
    for item in ai.src.glob.gameMap:
        item["pos"]["x"], item["pos"]["y"] = -item["pos"]["y"], item["pos"]["x"]
    computePlayerDistances()
    return True

def leftResponse(response):
    for item in ai.src.glob.gameMap:
        item["pos"]["x"], item["pos"]["y"] = item["pos"]["y"], -item["pos"]["x"]
    computePlayerDistances()
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
            ai.src.glob.gameMap = [ elem for elem in ai.src.glob.gameMap if not ((elem["pos"]["x"] == x and elem["pos"]["y"] == y) or (elem["pos"]["x"] > 10 or elem["pos"]["x"] < -10 or elem["pos"]["y"] > 10 or elem["pos"]["y"] < -10))]
            items = tile.split(" ")
            for item in items:
                if len(item) <= 0:
                    continue
                ai.src.glob.gameMap.append({"pos": {"x": x, "y": y}, "type": item})
            i += 1
            x += 1
            if i >= pal:
                x = -offset
                y += 1
                pal += 2
                offset += 1
                i = 0
        computePlayerDistances()
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
            it = it.split(" ")
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
        removeFromTile("food")
    else:
        ai.src.glob.gameState["needLook"] = True
    return True

def takeLinemateResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["linemate"] += 1
        removeFromTile("linemate")
    else:
        ai.src.glob.gameState["needLook"] = True
    return True

def takeDeraumereResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["deraumere"] += 1
        removeFromTile("deraumere")
    else:
        ai.src.glob.gameState["needLook"] = True
    return True

def takeSiburResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["sibur"] += 1
        removeFromTile("sibur")
    else:
        ai.src.glob.gameState["needLook"] = True
    return True

def takeMendianeResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["mendiane"] += 1
        removeFromTile("mendiane")
    else:
        ai.src.glob.gameState["needLook"] = True
    return True

def takePhirasResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["phiras"] += 1
        removeFromTile("phiras")
    else:
        ai.src.glob.gameState["needLook"] = True
    return True

def takeThystameResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["thystame"] += 1
        removeFromTile("thystame")
    else:
        ai.src.glob.gameState["needLook"] = True
    return True

def setFoodResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["food"] -= 1
        ai.src.glob.gameMap.append({
            "type": "food",
            "pos": {
                "x": 0,
                "y": 0
            }
        })
    else:
        ai.src.glob.gameState["needInventory"] = True
    return True

def setLinemateResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["linemate"] -= 1
        ai.src.glob.gameMap.append({
            "type": "linemate",
            "pos": {
                "x": 0,
                "y": 0
            }
        })
    else:
        ai.src.glob.gameState["needInventory"] = True
    return True

def setDeraumereResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["deraumere"] -= 1
        ai.src.glob.gameMap.append({
            "type": "deraumere",
            "pos": {
                "x": 0,
                "y": 0
            }
        })
    else:
        ai.src.glob.gameState["needInventory"] = True
    return True

def setSiburResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["sibur"] -= 1
        ai.src.glob.gameMap.append({
            "type": "sibur",
            "pos": {
                "x": 0,
                "y": 0
            }
        })
    else:
        ai.src.glob.gameState["needInventory"] = True
    return True

def setMendianeResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["mendiane"] -= 1
        ai.src.glob.gameMap.append({
            "type": "mendiane",
            "pos": {
                "x": 0,
                "y": 0
            }
        })
    else:
        ai.src.glob.gameState["needInventory"] = True
    return True

def setPhirasResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["phiras"] -= 1
        ai.src.glob.gameMap.append({
            "type": "phiras",
            "pos": {
                "x": 0,
                "y": 0
            }
        })
    else:
        ai.src.glob.gameState["needInventory"] = True
    return True

def setThystameResponse(response):
    if response == "ok":
        ai.src.glob.gameState["inventory"]["thystame"] -= 1
        ai.src.glob.gameMap.append({
            "type": "thystame",
            "pos": {
                "x": 0,
                "y": 0
            }
        })
    else:
        ai.src.glob.gameState["needInventory"] = True
    return True

def incantationResponse(response):
    ai.src.glob.currentCommand = incantationResponseKo
    return True

def incantationResponseKo(response):
    if response.startswith("ko"):
        print("Incantation to level " + str(ai.src.glob.gameState["level"] + 1) + " failed")
        if ai.src.glob.debug:
            print("Incantation to level " + str(ai.src.glob.gameState["level"] + 1) + " failed")
        ai.src.glob.gameState["needExplore"] = 10
        ai.src.glob.gameState["elevationReady"] = False
    ai.src.glob.gameState["incantationBroadcast"] = -1
    return True
