##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## game
##

import time
import queue
import numpy as np
import json
import sys

import ai.src.glob
from ai.src.requests import *
from ai.src.event import eventHandler
from ai.src.error import exceptionError
from ai.src.select import selectHandler
from ai.src.resetGame import resetGame
from ai.src.requestSelection import requestSelection

def startGame(params, mainsock, id):
    resetGame()
    ai.src.requests.initGameRequest(params["name"])
    ai.src.glob.gameState["teamName"] = params["name"]
    ai.src.glob.debug = params["debug"]

    while ai.src.glob.AIRunning:
        selectHandler(mainsock)
        while True:
            try:
                response = ai.src.glob.readQueue.get_nowait()
                if not eventHandler(response):
                    command = ai.src.glob.currentCommand
                    if command == None:
                        break
                    ai.src.glob.currentCommand = None
                    if not command(response):
                        mainsock.close()
                        exit(84)
            except queue.Empty:
                #print("Queue empty")
                break
        if ai.src.glob.currentCommand is None:
            if ai.src.glob.debug:
                nb = 0
                for i in ai.src.glob.gameMap:
                    if i["type"] == "food":
                        nb += 1
                print(str(id) + ") (" + str(ai.src.glob.gameState["level"]) + ") [%d"%ai.src.glob.gameState["incantationBroadcast"]+"] {" + str(nb) + "}", end="")
            requestSelection(mainsock)
