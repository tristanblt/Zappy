##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## distances
##

import ai.src.glob
import sys
import math

def computePlayerDistances():
    computePlayerDistanceResource("food")
    computePlayerDistanceResource("linemate")
    computePlayerDistanceResource("deraumere")
    computePlayerDistanceResource("sibur")
    computePlayerDistanceResource("mendiane")
    computePlayerDistanceResource("phiras")
    computePlayerDistanceResource("thystame")

def computePlayerDistanceResource(resource):
    x = sys.maxsize
    y = sys.maxsize
    distance = sys.maxsize
    exist = False

    #find nearest item
    for elemX in range(len(ai.src.glob.gameMap)):
        for elemY in range(len(ai.src.glob.gameMap[elemX])):
            for elem in ai.src.glob.gameMap[elemX][elemY]:
                if elem != resource:
                    continue
                tmpDistance = math.sqrt(math.pow(elemX - ai.src.glob.gameState["playerPos"]["x"], 2) + math.pow(elemY - ai.src.glob.gameState["playerPos"]["y"], 2))
                if distance > tmpDistance:
                    exist = True
                    distance = tmpDistance
                    x = elemX
                    y = elemY

    x = x - ai.src.glob.gameState["playerPos"]["x"]
    y = y - ai.src.glob.gameState["playerPos"]["y"]

    #compute direction of the object
    if exist == False:
        ai.src.glob.gameState["direction"][resource] = -1
    elif x == 0 and y == 0:
        ai.src.glob.gameState["direction"][resource] = 0
    elif x == 0 and y > 0:
        ai.src.glob.gameState["direction"][resource] = 1
    elif x > 0 and y > 0:
        ai.src.glob.gameState["direction"][resource] = 2
    elif x > 0 and y == 0:
        ai.src.glob.gameState["direction"][resource] = 3
    elif x > 0 and y < 0:
        ai.src.glob.gameState["direction"][resource] = 4
    elif x == 0 and y < 0:
        ai.src.glob.gameState["direction"][resource] = 5
    elif x < 0 and y < 0:
        ai.src.glob.gameState["direction"][resource] = 6
    elif x < 0 and y == 0:
        ai.src.glob.gameState["direction"][resource] = 7
    elif x < 0 and y > 0:
        ai.src.glob.gameState["direction"][resource] = 8

    #change direction with local rotation
    if ai.src.glob.gameState["direction"][resource] > 0:
        lookAt = ai.src.glob.lookAt * 2 + 1
        lookAt = 8 - lookAt
        a = (int((ai.src.glob.gameState["direction"][resource] - 1) / 2) + 1)
        if a > 3:
            a = 0
        a = a * 2 + (ai.src.glob.gameState["direction"][resource] % 2 == 0)
        ai.src.glob.gameState["direction"][resource] = lookAt + a
        if ai.src.glob.gameState["direction"][resource] > 8:
            ai.src.glob.gameState["direction"][resource] = ai.src.glob.gameState["direction"][resource] - 8

