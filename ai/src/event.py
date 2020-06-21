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
    if response.startswith("Current level: "):
        ai.src.glob.gameState["level"] = int(response.split(" ")[2])
        if ai.src.glob.debug:
            print("Level " + str(ai.src.glob.gameState["level"]) + " reached !")
        ai.src.glob.gameState["incantationBroadcast"] = -1
        ai.src.glob.gameState["joinPlayer"] = False
        ai.src.glob.gameState["playerIdLock"] = -1
        ai.src.glob.gameState["needUnlock"] = True
        return False
    if response.startswith("dead"):
        ai.src.glob.AIRunning = False
        return True
    if response.startswith("message"):
        direction = response.split(" ")[1][0]
        message = response.split(" ")[2:]
        try:
            if (message[0] == ai.src.glob.gameState["teamName"]):
                if (message[1] == "unlock"):
                    if int(message[2]) == ai.src.glob.gameState["playerIdLock"]:
                        print("---------------> UNLOCKED %d"%ai.src.glob.gameState["id"])
                        ai.src.glob.gameState["playerIdLock"] = -1
                if (message[1] == "nhi"):
                    callId = int(message[3])
                    if int(message[2]) == ai.src.glob.gameState["level"] and (ai.src.glob.gameState["playerIdLock"] == -1 or callId == ai.src.glob.gameState["playerIdLock"]):
                        ai.src.glob.gameState["incantationBroadcast"] = swapDirection(direction)
                        ai.src.glob.gameState["joinPlayer"] = True
                        ai.src.glob.gameState["broadcastIncantationCheckTime"] = 0
                        ai.src.glob.gameState["playerIdLock"] = callId
        except:
            pass
        return True
    if response.startswith("eject"):
        if ai.src.glob.debug: print("Ejected from tile")
        direction = int(response.split(" ")[1])
        firstPlayer = True
        x = 0
        y = 0

        if direction == 1:
            y = -1
        elif direction == 3:
            x = 1
        elif direction == 5:
            y = 1
        elif direction == 7:
            x = -1

        for item in ai.src.glob.gameMap:
            if (item["type"] == "player"
            and item["pos"]["x"] == 0
            and item["pos"]["y"] == 0
            and firstPlayer):
                firstPlayer = False
            else:
                item["pos"]["x"] += x
                item["pos"]["y"] += y
        computePlayerDistances()
        ai.src.glob.gameState["elevationReady"] = False
        return True
    return False