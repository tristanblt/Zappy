##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## event
##

import sys

import ai.src.glob
from ai.src.map import moveInDirection
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
    if response.startswith("Current level: "):
        ai.src.glob.gameState["level"] = int(response.split(" ")[2])
        print("Level " + str(ai.src.glob.gameState["level"]) + " reached !")
        ai.src.glob.gameState["incantationBroadcast"] = -1
        ai.src.glob.gameState["joinPlayer"] = False
        return False
    elif response.startswith("dead"):
        ai.src.glob.AIRunning = False
        return True
    elif response.startswith("message"):
        direction = response.split(" ")[1][0]
        message = response.split(" ")[2:]
        try:
            if (message[0] == ai.src.glob.gameState["teamName"]):
                if (message[1] == "nhi"):
                    if int(message[2]) == ai.src.glob.gameState["level"] and ai.src.glob.gameState["incantationBroadcast"] != 0:
                        ai.src.glob.gameState["incantationBroadcast"] = swapDirection(direction)
                        ai.src.glob.gameState["joinPlayer"] = True
                        ai.src.glob.gameState["broadcastIncantationCheckTime"] = 0
        except:
            pass
        return True
    elif response.startswith("eject"):
        print("Ejected from tile")
        direction = int(response.split(" ")[1])
        if direction == 1:
            direction = 0
        elif direction == 7:
            direction = 1
        elif direction == 5:
            direction = 2
        elif direction == 3:
            direction = 3
        moveInDirection(direction)
        ai.src.glob.gameState["elevationReady"] = False
        return True
    return False