##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## game
##

import time

import ai.src.glob
from ai.src.requests import *
from ai.src.error import exceptionError

def startGame(params, mainsock):
    gameConfig = initGameRequest(mainsock, params["name"])
    if gameConfig == None:
        exceptionError("Team doesn't exist")
    print("Connection: ok")

    while ai.src.glob.AIRunning:
        requestSelection(mainsock)

def requestSelection(ms):
    print("ai move")
    rightRequest(ms)
