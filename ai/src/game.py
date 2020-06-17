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

def startGame(params, mainsock):
    resetGame()
    ai.src.requests.initGameRequest(params["name"])

    while ai.src.glob.AIRunning:
        selectHandler(mainsock)
        while True:
            try:
                response = ai.src.glob.readQueue.get_nowait()
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
