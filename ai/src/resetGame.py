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
    ai.src.glob.readBuffer = ""
    ai.src.glob.writeBuffer = ""
    ai.src.glob.readQueue = queue.Queue()

    ai.src.glob.currentCommand = None

    ai.src.glob.gameState = {}
    ai.src.glob.gameState["clientNum"] = 0
    ai.src.glob.gameState["teamName"] = ""
    ai.src.glob.gameState["level"] = 1

    ai.src.glob.gameState["mapSize"] = {}
    ai.src.glob.gameState["mapSize"]["x"] = 0
    ai.src.glob.gameState["mapSize"]["y"] = 0
    ai.src.glob.gameState["playerPos"] = {}
    ai.src.glob.gameState["playerPos"]["x"] = 0
    ai.src.glob.gameState["playerPos"]["y"] = 0
    ai.src.glob.gameState["playerRot"] = 0

    ai.src.glob.gameState["starving"] = False
    ai.src.glob.gameState["elevationReady"] = False

    ai.src.glob.gameState["needLook"] = False
    ai.src.glob.gameState["needInventory"] = False
    ai.src.glob.gameState["needExplore"] = 0
    ai.src.glob.gameState["validIncant"] = False

    ai.src.glob.gameState["joinPlayer"] = False

    ai.src.glob.gameState["incantationBroadcast"] = -1
    ai.src.glob.gameState["callBroadcast"] = 0
    ai.src.glob.gameState["bufferBroadcast"] = True
    ai.src.glob.gameState["canMoveBroadcast"] = True

    ai.src.glob.gameState["starveCheckTime"] = 0
    ai.src.glob.gameState["broadcastIncantationCheckTime"] = 0
    ai.src.glob.gameState["connectNbrCheckTime"] = 0

    ai.src.glob.gameState["alreadyFork"] = False

    ai.src.glob.gameState["direction"] = {}
    ai.src.glob.gameState["direction"]["food"] = -1
    ai.src.glob.gameState["direction"]["linemate"] = -1
    ai.src.glob.gameState["direction"]["deraumere"] = -1
    ai.src.glob.gameState["direction"]["sibur"] = -1
    ai.src.glob.gameState["direction"]["mendiane"] = -1
    ai.src.glob.gameState["direction"]["phiras"] = -1
    ai.src.glob.gameState["direction"]["thystame"] = -1

    ai.src.glob.gameState["inventory"] = {}
    ai.src.glob.gameState["inventory"]["food"] = 0
    ai.src.glob.gameState["inventory"]["linemate"] = 0
    ai.src.glob.gameState["inventory"]["deraumere"] = 0
    ai.src.glob.gameState["inventory"]["sibur"] = 0
    ai.src.glob.gameState["inventory"]["mendiane"] = 0
    ai.src.glob.gameState["inventory"]["phiras"] = 0
    ai.src.glob.gameState["inventory"]["thystame"] = 0