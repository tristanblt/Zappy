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
    ai.src.glob.gameState["mapSize"] = {}
    ai.src.glob.gameState["mapSize"]["x"] = 0
    ai.src.glob.gameState["mapSize"]["y"] = 0
    ai.src.glob.gameState["level"] = 1

    ai.src.glob.gameState["starving"] = False
    ai.src.glob.gameState["elevationReady"] = False

    ai.src.glob.gameState["needLook"] = False
    ai.src.glob.gameState["needInventory"] = False
    ai.src.glob.gameState["needExplore"] = 0
    # ai.src.glob.gameState["needForward"] = False

    ai.src.glob.gameState["joinPlayer"] = False

    ai.src.glob.gameState["incantationBroadcast"] = -1
    ai.src.glob.gameState["callBroadcast"] = 0
    ai.src.glob.gameState["bufferBroadcast"] = True
    ai.src.glob.gameState["canMoveBroadcast"] = True

    ai.src.glob.gameState["starveCheckTime"] = 0
    ai.src.glob.gameState["broadcastIncantationCheckTime"] = 0
    ai.src.glob.gameState["connectNbrCheckTime"] = 0

    ai.src.glob.gameState["alreadyFork"] = False

    ai.src.glob.gameState["directionFood"] = -1
    ai.src.glob.gameState["directionLinemate"] = -1
    ai.src.glob.gameState["directionDeraumere"] = -1
    ai.src.glob.gameState["directionSibur"] = -1
    ai.src.glob.gameState["directionMendiane"] = -1
    ai.src.glob.gameState["directionPhiras"] = -1
    ai.src.glob.gameState["directionThystame"] = -1
    ai.src.glob.gameState["nbFood"] = 0
    ai.src.glob.gameState["nbLinemate"] = 0
    ai.src.glob.gameState["nbDeraumere"] = 0
    ai.src.glob.gameState["nbSibur"] = 0
    ai.src.glob.gameState["nbMendiane"] = 0
    ai.src.glob.gameState["nbPhiras"] = 0
    ai.src.glob.gameState["nbThystame"] = 0
    ai.src.glob.gameState["canFork"] = True
    ai.src.glob.gameState["canIncant"] = False
