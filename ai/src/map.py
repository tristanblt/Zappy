##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## map
##

import ai.src.glob
from ai.src.distances import computePlayerDistances

def itemInMap(itemType):
    for elemX in ai.src.glob.gameMap:
        for elemY in elemX:
            for elem in elemY:
                if elem == itemType:
                    return True
    return False

def removeFromPlayerTile(item):
    playerX = ai.src.glob.gameState["playerPos"]["x"]
    playerY = ai.src.glob.gameState["playerPos"]["y"]

    try:
        ai.src.glob.gameMap[playerX][playerY].remove(item)
    except:
        pass
    return

def addToPlayerTile(item):
    playerX = ai.src.glob.gameState["playerPos"]["x"]
    playerY = ai.src.glob.gameState["playerPos"]["y"]

    ai.src.glob.gameMap[playerX][playerY].append(item)
    return

def getNbItemOnPlayerTile(itemName):
    nbItems = 0
    playerX = ai.src.glob.gameState["playerPos"]["x"]
    playerY = ai.src.glob.gameState["playerPos"]["y"]
    print(playerX)
    print(playerY)
    for i in ai.src.glob.gameMap[playerX][playerY]:
        nbItems += 1
    return nbItems
    

def moveInDirection(direction):
    x = 0
    y = 0

    if direction == -1:
        direction = ai.src.glob.gameState["playerRot"]

    if direction == 0:
        y = -1
    elif direction == 1:
        x = 1
    elif direction == 2:
        y = 1
    elif direction == 3:
        x = -1
    
    ai.src.glob.gameState["playerPos"]["x"] += x
    ai.src.glob.gameState["playerPos"]["y"] += y

    if ai.src.glob.gameState["playerPos"]["x"] < 0:
        ai.src.glob.gameState["playerPos"]["x"] = ai.src.glob.gameState["mapSize"]["x"] - 1
    elif ai.src.glob.gameState["playerPos"]["x"] >= ai.src.glob.gameState["mapSize"]["x"]:
        ai.src.glob.gameState["playerPos"]["x"] = 0
    elif ai.src.glob.gameState["playerPos"]["y"] < 0:
        ai.src.glob.gameState["playerPos"]["y"] = ai.src.glob.gameState["mapSize"]["y"] - 1
    elif ai.src.glob.gameState["playerPos"]["y"] >= ai.src.glob.gameState["mapSize"]["y"]:
        ai.src.glob.gameState["playerPos"]["y"] = 0

    computePlayerDistances()

def rotatePlayer(direction):
    ai.src.glob.gameState["playerRot"] += direction

    if ai.src.glob.gameState["playerRot"] < 0:
        ai.src.glob.gameState["playerRot"] = 3
    elif ai.src.glob.gameState["playerRot"] > 3:
        ai.src.glob.gameState["playerRot"] = 0
    computePlayerDistances()

def updateTileItems(items, relX, relY):
    for i in ai.src.glob.gameState["playerRot"]:
        tmp = relX
        relX = -relY
        relY = tmp

    absX = ai.src.glob.gameState["playerPos"]["x"] + relX
    absY = ai.src.glob.gameState["playerPos"]["y"] + relY

    if absX < 0:
        absX = ai.src.glob.gameState["mapSize"]["x"] - 1
    elif absX >= ai.src.glob.gameState["mapSize"]["x"]:
        absX = 0
    elif absY < 0:
        absY = ai.src.glob.gameState["mapSize"]["y"] - 1
    elif absY >= ai.src.glob.gameState["mapSize"]["y"]:
        absY = 0

    ai.src.glob.gameMap[absX][absY] = []
    for item in items:
        if (len(item) <= 0):
            continue
        ai.src.glob.gameMap[absX][absY].append(item)
    computePlayerDistances()
