##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## responses
##

import ai.src.glob

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

    return True

def rightResponse(response):
    ai.src.glob.lookAt -= 1
    if (ai.src.glob.lookAt < 0):
        ai.src.glob.lookAt = 3
    return True

def leftResponse(response):
    ai.src.glob.lookAt += 1
    if (ai.src.glob.lookAt > 3):
        ai.src.glob.lookAt = 0
    return True

def lookResponse(response):
    x = 0
    y = 0
    i = 0
    pal = 1
    response = response.replace('[', '') 
    response = response.replace(']', '') 
    cases = response.split(",")
    for case in cases:
        for item in ai.src.glob.gameMap:
            if item["pos"]["x"] == x and item["pos"]["y"] == y:
                ai.src.glob.gameMap.remove(item)
        items = case.split(" ")
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
    #calculer les distance avec les objets pour le gameState - fonction : computePlayerDistances()
    return True

def inventoryResponse(response):
    #print(response)
    return True

def broadcastResponse(response):
    #print(response)
    return True

def connectNbrResponse(response):
    ai.src.glob.gameState["clientNum"] = int(response)
    return True

def forkResponse(response):
    if ai.src.glob.gameState["canFork"]:
        ai.src.glob.reward += 10
    else:
        ai.src.glob.reward -= 20
    return True

def ejectResponse(response):
    #print(response)
    return True

#faire un take par objet
def takeObjectResponse(response):
    #print(response)
    return True

#faire un set par objet
def setObjectResponse(response):
    #print(response)
    return True

def incantationResponse(response):
    #print(response)
    return True
