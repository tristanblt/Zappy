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
    computePlayerDistanceResource("food", "directionFood")
    computePlayerDistanceResource("linemate", "directionLinemate")
    computePlayerDistanceResource("deraumere", "directionDeraumere")
    computePlayerDistanceResource("sibur", "directionSibur")
    computePlayerDistanceResource("mendiane", "directionMendiane")
    computePlayerDistanceResource("phiras", "directionPhiras")
    computePlayerDistanceResource("thystame", "directionThystame")

def computePlayerDistanceResource(resource, gameMapField):
    x = sys.maxsize
    y = sys.maxsize
    distance = sys.maxsize
    exist = False

    #find nearest item
    for item in ai.src.glob.gameMap:
        if item["type"] != resource:
            continue
        tmpDistance = math.sqrt(math.pow(item["pos"]["x"], 2) + math.pow(item["pos"]["y"], 2))
        if distance > tmpDistance:
            exist = True
            distance = tmpDistance
            x = item["pos"]["x"]
            y = item["pos"]["y"]
    #compute direction of the object
    if exist == False:
        ai.src.glob.gameState[gameMapField] = -1
    elif x == 0 and y == 0:
        ai.src.glob.gameState[gameMapField] = 0
    elif x == 0 and y > 0:
        ai.src.glob.gameState[gameMapField] = 1
    elif x > 0 and y > 0:
        ai.src.glob.gameState[gameMapField] = 2
    elif x > 0 and y == 0:
        ai.src.glob.gameState[gameMapField] = 3
    elif x > 0 and y < 0:
        ai.src.glob.gameState[gameMapField] = 4
    elif x == 0 and y < 0:
        ai.src.glob.gameState[gameMapField] = 5
    elif x < 0 and y < 0:
        ai.src.glob.gameState[gameMapField] = 6
    elif x < 0 and y == 0:
        ai.src.glob.gameState[gameMapField] = 7
    elif x < 0 and y > 0:
        ai.src.glob.gameState[gameMapField] = 8

    #change direction with local rotation
    if ai.src.glob.gameState[gameMapField] > 0:
        lookAt = ai.src.glob.lookAt * 2 + 1
        lookAt = 8 - lookAt
        a = (int((ai.src.glob.gameState[gameMapField] - 1) / 2) + 1)
        if a > 3:
            a = 0
        a = a * 2 + (ai.src.glob.gameState[gameMapField] % 2 == 0)
        ai.src.glob.gameState[gameMapField] = lookAt + a
        if ai.src.glob.gameState[gameMapField] > 8:
            ai.src.glob.gameState[gameMapField] = ai.src.glob.gameState[gameMapField] - 8

