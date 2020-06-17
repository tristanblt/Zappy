##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## event
##

import sys

import ai.src.glob
from ai.src.distances import computePlayerDistances

def swapDirection(direction):
    if direction == "8":
        return 2
    elif direction == "2":
        return 8
    elif direction == "7":
        return 3
    elif direction == "3":
        return 7
    elif direction == "6":
        return 4
    elif direction == "4":
        return 6
    return int(direction)

def eventHandler(response):
    # broadcast
    # eject
    #print(response)
    if response.startswith("Current level: "):
        print("megapute")
        ai.src.glob.gameState["level"] = int(response.split(" ")[2])
        # ai.src.glob.gameState["incantationBroadcast"] = -1
        # ai.src.glob.gameState["callBroadcast"] = 0
        # ai.src.glob.gameState["bufferBroadcast"] = False
        # ai.src.glob.gameState["elevationReady"] = False
        ai.src.glob.gameState["joinPlayer"] = False
        return True
    if response.startswith("dead"):
        ai.src.glob.AIRunning = False
        return True
    if response.startswith("message"):
        direction = response.split(" ")[1][0]
        message = response.split(" ")[2:]
        try:
            if message[0] == ai.src.glob.gameState["teamName"]:
                if message[1] == "nhi":
                    if int(message[2]) == ai.src.glob.gameState["level"]:
                        ai.src.glob.gameState["incantationBroadcast"] = swapDirection(direction)
                        ai.src.glob.gameState["joinPlayer"] = True
                        ai.src.glob.gameState["broadcastIncantationCheckTime"] = 0
        except:
            pass
        return True
    if response.startswith("eject"):
        print("tu t fé tej gronul")
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
        return True
    return False