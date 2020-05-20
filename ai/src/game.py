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
    ai.src.glob.gameState = {}
    ai.src.glob.gameState["clientNum"] = 0
    ai.src.glob.gameState["mapSize"] = {}
    ai.src.glob.gameState["mapSize"]["x"] = 0
    ai.src.glob.gameState["mapSize"]["y"] = 0

def startGame(params, mainsock):
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
            requestSelection(mainsock)
    return False

def requestSelection(ms):
    generatePopulation(ms)

def generatePopulation(ms):
    randCmd = random.randrange(0, len(functions))
    functions[randCmd](ms)