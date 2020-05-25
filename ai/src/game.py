##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## game
##

import time
import tensorflow
import random
import select
import queue
import random
import numpy as np

import ai.src.glob
from ai.src.requests import *
from ai.src.event import eventHandler
from ai.src.error import exceptionError

functions = [
    ai.src.requests.forwardRequest,
    ai.src.requests.rightRequest,
    ai.src.requests.leftRequest,
    ai.src.requests.lookRequest,
    ai.src.requests.inventoryRequest,
    ai.src.requests.forkRequest,
    ai.src.requests.ejectRequest,
    ai.src.requests.incantationRequest
    #ai.src.requests.broadcastRequest,
    #ai.src.requests.takeObjectRequest,
    #ai.src.requests.setObjectRequest,
]

def resetGame():
    ai.src.glob.AIRunning = True
    ai.src.glob.readQueue = queue.Queue()
    ai.src.glob.writeQueue = queue.Queue()
    ai.src.glob.currentCommand = None
    ai.src.glob.reward = 0
    ai.src.glob.gameState = {}
    ai.src.glob.gameState["clientNum"] = 0
    ai.src.glob.gameState["mapSize"] = {}
    ai.src.glob.gameState["mapSize"]["x"] = 0
    ai.src.glob.gameState["mapSize"]["y"] = 0
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

def startGame(params, mainsock, model):
    recordStates = []

    resetGame()
    ai.src.requests.initGameRequest(mainsock, params["name"])
    while ai.src.glob.AIRunning:
        readable, writable, exceptional = select.select([mainsock], [mainsock], [mainsock])
        for s in readable:
            data = s.recv(1024)
            if data:
                ai.src.glob.readQueue.put(data.decode())
            else:
                mainsock.close()
                exit(84)
        for s in writable:
            try:
                next_cmd = ai.src.glob.writeQueue.get_nowait()
            except queue.Empty:
                pass
            else:
                s.send(next_cmd.encode())
        for s in exceptional:
            mainsock.close()
            exit(84)
        while True:
            try:
                response = ai.src.glob.readQueue.get_nowait()
                if not eventHandler(response):
                    if not ai.src.glob.currentCommand(response):
                        mainsock.close()
                        exit(84)
                    ai.src.glob.currentCommand = None
            except queue.Empty:
                break
        if ai.src.glob.currentCommand is None:
            requestSelection(mainsock, model)
    if ai.src.glob.reward > 0:
        # fit all record of the game
        print("dscs")

    return False

def requestSelection(ms, model):
    if random.randrange(0, 2) == 0:
        requestRandom(ms)
    else:
        print(model.predict(np.array([[
            ai.src.glob.gameState["directionFood"],
            ai.src.glob.gameState["directionLinemate"],
            ai.src.glob.gameState["directionDeraumere"],
            ai.src.glob.gameState["directionSibur"],
            ai.src.glob.gameState["directionMendiane"],
            ai.src.glob.gameState["directionPhiras"],
            ai.src.glob.gameState["directionThystame"],
            ai.src.glob.gameState["nbFood"],
            ai.src.glob.gameState["nbLinemate"],
            ai.src.glob.gameState["nbDeraumere"],
            ai.src.glob.gameState["nbSibur"],
            ai.src.glob.gameState["nbMendiane"],
            ai.src.glob.gameState["nbPhiras"],
            ai.src.glob.gameState["nbThystame"],
            ai.src.glob.gameState["canFork"],
            ai.src.glob.gameState["canIncant"]
        ]])))
        requestRandom(ms)


def requestRandom(ms):
    randCmd = random.randrange(0, len(functions))
    functions[randCmd](ms)