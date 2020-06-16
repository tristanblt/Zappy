##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## game
##

import time
import random
import queue
import random
import numpy as np
import json
import sys

import ai.src.glob
from ai.src.requests import *
from ai.src.event import eventHandler
from ai.src.error import exceptionError
from ai.src.select import selectHandler

functions = [
    ai.src.requests.forwardRequest,
    ai.src.requests.rightRequest,
    ai.src.requests.leftRequest,
    ai.src.requests.lookRequest,
    ai.src.requests.connectNbrRequest,
    ai.src.requests.inventoryRequest,
    ai.src.requests.forkRequest,
    ai.src.requests.incantationRequest,
    ai.src.requests.takeFoodRequest,
    ai.src.requests.takeLinemateRequest,
    ai.src.requests.takeDeraumereRequest,
    ai.src.requests.takeSiburRequest,
    ai.src.requests.takeMendianeRequest,
    ai.src.requests.takePhirasRequest,
    ai.src.requests.takeThystameRequest,
    ai.src.requests.setFoodRequest,
    ai.src.requests.setLinemateRequest,
    ai.src.requests.setDeraumereRequest,
    ai.src.requests.setSiburRequest,
    ai.src.requests.setMendianeRequest,
    ai.src.requests.setPhirasRequest,
    ai.src.requests.setThystameRequest,
    #ai.src.requests.ejectRequest,
    #ai.src.requests.broadcastRequest,
]

def resetGame():
    ai.src.glob.AIRunning = True
    ai.src.glob.readBuffer = ""
    ai.src.glob.writeBuffer = ""
    ai.src.glob.readQueue = queue.Queue()

    ai.src.glob.currentCommand = None

    ai.src.glob.gameState = {}
    ai.src.glob.gameState["clientNum"] = 0
    ai.src.glob.gameState["mapSize"] = {}
    ai.src.glob.gameState["mapSize"]["x"] = 0
    ai.src.glob.gameState["mapSize"]["y"] = 0
    ai.src.glob.gameState["level"] = 1

    # ?????
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

def startGame(params, mainsock):
    resetGame()
    ai.src.requests.initGameRequest(params["name"])

    while ai.src.glob.AIRunning:
        selectHandler(mainsock)
        while True:
            try:
                response = ai.src.glob.readQueue.get_nowait()
                print(response)
                if not eventHandler(response):
                    command = ai.src.glob.currentCommand
                    ai.src.glob.currentCommand = None
                    if not command(response):
                        mainsock.close()
                        exit(84)
            except queue.Empty:
                break
        if ai.src.glob.currentCommand is None:
            requestSelection(mainsock)

def requestSelection(mainsock):
    