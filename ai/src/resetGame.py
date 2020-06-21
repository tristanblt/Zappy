##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## resetGame
##

import ai.src.glob
import queue

def resetGame():
    ai.src.glob.AIRunning = True

    # socket buffer management
    ai.src.glob.readBuffer = ""
    ai.src.glob.writeBuffer = ""
    ai.src.glob.readQueue = queue.Queue()
    ai.src.glob.currentCommand = None

    # game informations
    ai.src.glob.gameState = {}
    ai.src.glob.gameState["id"] = -1
    ai.src.glob.gameState["clientNum"] = 0
    ai.src.glob.gameState["teamName"] = ""
    ai.src.glob.gameState["mapSize"] = {}
    ai.src.glob.gameState["mapSize"]["x"] = 0
    ai.src.glob.gameState["mapSize"]["y"] = 0
    ai.src.glob.gameState["level"] = 1

    # state if the player is starving
    ai.src.glob.gameState["starving"] = False

    # incantation utils
    ai.src.glob.gameState["elevationReady"] = False
    ai.src.glob.gameState["validIncant"] = False

    # for next command handling
    ai.src.glob.gameState["needLook"] = False
    ai.src.glob.gameState["needInventory"] = False
    ai.src.glob.gameState["needExplore"] = 0
    ai.src.glob.gameState["needUnlock"] = False

    # broadcast handling
    ai.src.glob.gameState["joinPlayer"] = False
    ai.src.glob.gameState["incantationBroadcast"] = -1
    ai.src.glob.gameState["callBroadcast"] = 0
    ai.src.glob.gameState["bufferBroadcast"] = True
    ai.src.glob.gameState["playerIdLock"] = -1

    # counter for time handling (in frequency server unit)
    ai.src.glob.gameState["starveCheckTime"] = 0
    ai.src.glob.gameState["broadcastIncantationCheckTime"] = 0
    ai.src.glob.gameState["connectNbrCheckTime"] = 0

    # true if the player as fork
    ai.src.glob.gameState["alreadyFork"] = False

    # closest direction for every item
    ai.src.glob.gameState["direction"] = {}
    ai.src.glob.gameState["direction"]["food"] = -1
    ai.src.glob.gameState["direction"]["linemate"] = -1
    ai.src.glob.gameState["direction"]["deraumere"] = -1
    ai.src.glob.gameState["direction"]["sibur"] = -1
    ai.src.glob.gameState["direction"]["mendiane"] = -1
    ai.src.glob.gameState["direction"]["phiras"] = -1
    ai.src.glob.gameState["direction"]["thystame"] = -1

    # number of item in inventory
    ai.src.glob.gameState["inventory"] = {}
    ai.src.glob.gameState["inventory"]["food"] = 0
    ai.src.glob.gameState["inventory"]["linemate"] = 0
    ai.src.glob.gameState["inventory"]["deraumere"] = 0
    ai.src.glob.gameState["inventory"]["sibur"] = 0
    ai.src.glob.gameState["inventory"]["mendiane"] = 0
    ai.src.glob.gameState["inventory"]["phiras"] = 0
    ai.src.glob.gameState["inventory"]["thystame"] = 0
